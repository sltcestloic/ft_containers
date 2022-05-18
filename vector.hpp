#ifndef CONTAINERS_VECTOR_HPP
#define CONTAINERS_VECTOR_HPP

#include <memory>
#include "iterator.hpp"

#include <iostream>
#include <iterator>

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		/*****************/
		/* Public Fields */
		/*****************/
		public:
			typedef				T							value_type;
			typedef				Alloc						allocator_type;
			typedef				std::size_t					size_type;
			typedef				std::ptrdiff_t				difference_type;
			typedef typename	Alloc::reference			reference;
			typedef typename	Alloc::const_reference		const_reference;
			typedef	typename	Alloc::pointer				pointer;
			typedef typename	Alloc::const_pointer		const_pointer;
			typedef				pointer						iterator;
			typedef				const_pointer				const_iterator;

		/******************/
		/* Private Fields */
		/******************/
		private:
			T*				_data;
			size_t			_size;
			size_t			_capacity;
			allocator_type	_alloc;

		/*********************/
		/* Private Functions */
		/*********************/
		private:

			void _check_capacity(size_type needed) {
				if (needed <= _capacity - _size) return;

				if (needed > max_size())
					throw std::out_of_range("ft::vector::max_capacity_reached");
				else if (needed > (_capacity * 2)) {
					reserve(needed);
					_capacity = needed;
				} else {
					reserve(2 * _capacity);
					_capacity *= 2;
				}
			}

		/********************/
		/* Public Functions */
		/********************/
		public:

			//Constructors

			explicit vector(const allocator_type& alloc = allocator_type()) : _capacity(0), _alloc(alloc) {
			}

			explicit vector (size_type n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type()) : _capacity(n), _alloc(alloc) {
					_alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_data + i, val);
					std::cout << "called constructor 2\n";
				}

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
				assign(first, last);
			}

			vector (const vector& x) {
				assign(x._begin, x._end);
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
				_alloc.deallocate(_data, _capacity); //deallocate current data
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

			template <class InputIterator>
			void 		assign (InputIterator first, InputIterator last) {
				if (_capacity < last - first) {
					clear();
					_alloc.deallocate(_data, _capacity);
				}
				_alloc.allocate(last - first);
				while (first != last) {
					_alloc.construct(_data + _size, *first);
					first++;
					_size++;
				}
			}

			void swap (vector& x) {
				vector copy(this);
				assign(x.begin(), x.end());
				x = copy;
			}

			void 		assign (size_type n, const value_type& val);

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
				if (empty()) return;
				_alloc.destroy(_data + (--_size));
			}


			
			
			reference 	at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("ft::vector::out_of_range");
				return _data[n];
			}

			reference 	operator[] (size_type n) { return _data[n]; }
			bool		empty() const { return _size == 0; }
			size_type	max_size() const { return 4611686018427387903; }			
			size_type	size() const { return _size; }
			size_type	capacity() const { return _capacity; }
			reference 	back() { return _data[_size - 1]; }
			reference	front() { return _data[0]; }
			iterator	begin() const { return _data; }
			iterator	end() const { return _data + (_size - 1); }

			// vector		&operator=(vector &ref) {
			// 	this->_data = ref._data; 
			// }

	};
}

#endif