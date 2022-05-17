#ifndef CONTAINERS_VECTOR_HPP
#define CONTAINERS_VECTOR_HPP

#include <memory>
#include "iterator.hpp"

#include <iostream>

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
			typedef	typename	Alloc::pointer				pointer;


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
				if (_size != _capacity) return;

				if (_size + needed > max_size())
					throw std::length_error("vector::max_capacity_reached");
				else if (_size + needed > (_capacity * 2))
					reserve(_size + needed);
				else
					reserve(2 * _capacity);
			}

		/********************/
		/* Public Functions */
		/********************/
		public:

			//Constructors

			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _data(nullptr) {
				std::cout << "called constructor 1\n";
			};

			explicit vector (size_type n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type()) : _capacity(n) {
					_alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_data + i, val);
					std::cout << "called constructor 2\n";
				}

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
				_alloc.allocate(last - first);
				while (first != last) {
					_alloc.construct(_data + _size, *first);
					first++;
				}
				std::cout << "called constructor 3\n";
			}

			vector (const vector& x) {
				assign(x._begin, x._end);
			}

			//Functions

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last) {
				if (_capacity < last - first) {
					clear();
					_alloc.deallocate(_data, _capacity);
				}
				_alloc.allocate(last - first);
				while (first != last) {
					_alloc.construct(_data + _size, *first);
					first++;
				}
			}


			void assign (size_type n, const value_type& val);

			void clear () {
				for (size_t i = 0; i < _size; i++)
					_alloc.deconstruct(_data[i]);
				_size = 0;
			}

			void push_back (const value_type &val) {
				_check_capacity(_size + 1);
				_alloc.construct(_data + _size, val);
				_size++;
			}

			void reserve (size_type new_capacity) {
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

			reference at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("vector::out_of_bounds");
				return _data[n];
			}

			size_type max_size() {
				return 4611686018427387903;
			}

			// vector		&operator=(vector &ref) {
			// 	this->_data = ref._data; 
			// }

	};
}

#endif