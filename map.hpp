#ifndef CONTAINERS_MAP_HPP
#define CONTAINERS_MAP_HPP

#include <functional>
#include "utils.hpp"
#include "iterator.hpp"

namespace ft {

	template < class Key,                                     // map::key_type
           class T,                                      	 // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > class map
	{
		private:
			typedef 			Key											key_type;
			typedef 			T											mapped_type;
			typedef 			ft::pair<const key_type, mapped_type>		value_type;
			typedef 			Compare										key_compare;
			typedef				Alloc										allocator_type;
			typedef typename	allocator_type::reference					reference;
			typedef typename	allocator_type::const_reference				const_reference;
			typedef typename	allocator_type::pointer						pointer;
			typedef typename	allocator_type::const_pointer				const_pointer;

			// From https://www.cplusplus.com/reference/map/map/value_comp/
			class map<Key,T,Compare,Alloc>::value_compare : binary_function<value_type,value_type,bool> {
				protected:
					key_compare		comp;

					value_compare (key_compare c) : comp(c) {}

				public:
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			}

		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
			
			template <class InputIterator>
 			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {

			}

			map (const map& x) {}

			map& operator= (const map& x) {}

			~map() {}
			
	};
}


#endif