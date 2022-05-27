#ifndef CONTAINERS_VECTOR_HPP
#define CONTAINERS_VECTOR_HPP

#include <memory>
#include "iterator.hpp"
#include "utils.hpp"

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		/*****************/
		/* Public Fields */
		/*****************/
		public:
			typedef				T										value_type;
			typedef				Alloc									allocator_type;
			typedef				std::size_t								size_type;
			typedef				std::ptrdiff_t							difference_type;
			typedef typename	Alloc::reference						reference;
			typedef typename	Alloc::const_reference					const_reference;
			typedef	typename	Alloc::pointer							pointer;
			typedef typename	Alloc::const_pointer					const_pointer;
			typedef typename	ft::vector_iterator<pointer>			iterator;
			typedef typename	ft::vector_iterator<const_pointer>		const_iterator;
			typedef	typename	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	typename	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		/******************/
		/* Private Fields */
		/******************/
		private:
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			T*				_data;

		/*********************/
		/* Private Functions */
		/*********************/
		private:

			void _check_capacity(size_type needed) {
				if (needed <= _capacity) return;


				if (needed > max_size())
					throw std::out_of_range("ft::vector::max_capacity_reached");
				else if (needed > (_capacity * 2))
					reserve(needed);
				else
					reserve(2 * _capacity);
			}

		/********************/
		/* Public Functions */
		/********************/
		public:

			//Constructors

			explicit vector(const allocator_type& alloc = allocator_type()) : _capacity(0), _alloc(alloc) {
				_size = 0;
			}

			explicit vector (size_type n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type()) : _capacity(n), _alloc(alloc) {
					_data = _alloc.allocate(n);
					_size = n;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_data + i, val);
				}

			template <class InputIterator>
         	vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _data(NULL) {
				assign(first, last);
			}

			vector (const vector& x) : _size(x._size), _capacity(x._size), _alloc(x._alloc), _data(nullptr) {
				this->_data = _alloc.allocate(this->_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_data[i], x._data[i]);
			}

			//Functions

			void 		reserve (size_type new_capacity) {
				if (new_capacity > max_size())
					throw std::out_of_range("ft::vector::out_of_bounds");
				if (new_capacity <= _capacity) return;

				T* new_data = _alloc.allocate(new_capacity);
				for (size_type i = 0; i < _size; i++) //construct current data into new data
					_alloc.construct(new_data + i, _data[i]);
				for (size_type i = 0; i < _size; i++) //destroy current data
					_alloc.destroy(_data + i);
				_capacity = new_capacity;
				_data = new_data; //set current data to new data
			}

			void 		resize (size_type n, value_type val = value_type()) {
				_check_capacity(n);
				if (n < _size) {
					for (size_type i = n; i > _size; i--)
						_alloc.destroy(_data + (i - 1));
				} else if (n > _size) {
					for (size_type i = _size; i < n; i++)
						push_back(val);
				}
				_size = n;
			}

//Any elements held in the container before the call are destroyed and replaced by newly constructed elements 
//(no assignments of elements take place).

//This causes an automatic reallocation of the allocated storage space if -and only if-
//the new vector size surpasses the current vector capacity.
			template <class InputIterator>
			void 		assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {				
				if (_size)
					clear();
				if ((size_type)(last - first) > _capacity)
				 	reserve(last - first);
				while (first != last) {
					_alloc.construct(_data + _size, *first);
					first++;
					_size++;
				}
			}

			void 		assign (size_type n, const value_type& val) {
				if (_size)
					clear();
 				if (n > _capacity)
				 	reserve(n);
				for (; n > 0; n--) {
					_alloc.construct(_data + _size, val);
					_size++;
				}
			};

			iterator erase (iterator position) {
				return erase(position, position + 1);
			}

			iterator erase (iterator first, iterator last) {
				size_type	erase_index = first - this->begin();
				size_type	erase_amount = last - first;
				size_type 	i = erase_index;

				if (erase_amount == 0) return iterator(this->begin() + erase_index);

				while (erase_index < _size - erase_amount) {
					_alloc.destroy(&_data[erase_index]);
					_alloc.construct(&_data[erase_index], _data[erase_index + erase_amount]);
					erase_index++;
				}
				_size -= erase_amount;
				return iterator(this->begin() + i);
			}

			void swap (vector& x) {
				std::swap(x._data, this->_data);
				std::swap(x._size, this->_size);
				std::swap(x._capacity, this->_capacity);
			}

			void 		clear () {
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_size = 0;
			}

			void		 push_back (const value_type &val) {
				_check_capacity(_size + 1);
				_alloc.construct(_data + _size, val);
				_size++;
			}

			void		pop_back() {
				_alloc.destroy(_data + (--_size));
			}


			iterator insert (iterator position, const value_type& val) {
				difference_type difference = position - this->begin();
				insert(position, 1, val);
				return iterator(begin() + difference);
			}

			void insert (iterator position, size_type n, const value_type& val) {
				size_type	insert_begin = 0;
				size_type	insert_end = 0;
				size_type	end = _size + n - 1;


				insert_begin = position - this->begin();
				insert_end = insert_begin + n;
				_check_capacity(_size + (insert_end - insert_begin));
				_size += n;
				
				while (end >= insert_end) {
					_alloc.construct(&_data[end], _data[end - n]);
					_alloc.destroy(&_data[end - n]);
					end--;
				}
			
				while (insert_begin < insert_end) {
					_alloc.construct(_data + insert_begin, val);
					insert_begin++;
				}
			}

			template <class InputIterator>
    		void insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				size_type	n = (size_type)(last - first);
				size_type	insert_begin = 0;
				size_type	insert_end = 0;
				size_type	end = _size + n - 1;


				insert_begin = position - this->begin();
				insert_end = insert_begin + n;				
				_check_capacity(_size + (insert_end - insert_begin));
				_size += n;

				while (end >= insert_end) {
					_alloc.construct(&_data[end], _data[end - n]);
					_alloc.destroy(&_data[end - n]);
					end--;
				}

				while (insert_begin < insert_end) {
					_alloc.construct(_data + insert_begin, *first);
					insert_begin++;
					first++;
				}
			}
			
			
			reference 	at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("ft::vector::out_of_range");
				return _data[n];
			}

			const_reference at (size_type n) const {
				if (n >= _size)
					throw std::out_of_range("ft::vector::out_of_range");
				return _data[n];
			}

			reference 			operator[] (size_type n) { return _data[n]; }
			bool				empty() const { return _size == 0; }
			size_type			max_size() const { return _alloc.max_size(); }			
			size_type			size() const { return _size; }
			size_type			capacity() const { return _capacity; }
			reference 			back() { return _data[_size - 1]; }
			const_reference 	back() const { return _data[_size - 1]; }
			reference			front() { return _data[0]; }
			const_reference 	front() const { return _data[0]; }
			iterator			begin() { return iterator(this->_data); }
			const_iterator		begin() const { return const_iterator(this->_data); }
			iterator			end() { return iterator(this->_data + this->_size); }
			const_iterator		end() const { return const_iterator(this->_data + this->_size); }
			reverse_iterator	rbegin() { return reverse_iterator(end()); }
			reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
			reverse_iterator	rend() { return reverse_iterator(begin()); }
			reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

			vector		&operator=(vector &ref) {
				_check_capacity(ref._size);
				if (_size)
					clear();
				for (size_type i = 0; i < ref._size; i++)
					_alloc.construct(_data + i, ref.at(i));
				_size = ref._size;
				return *this;
			}

	};

	template <typename T, typename Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }

	template <typename T, typename Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs == rhs); }

	template <typename T, typename Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs > rhs); }

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return rhs < lhs; }

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs < rhs); }

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
}

#endif