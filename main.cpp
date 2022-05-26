#include <iostream>
#include <string>

using namespace std;

#ifdef STL_CONTAINERS
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	//#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif


template <class T>
void show_cap(ft::vector<T>& vec) {
	std::cout << vec.size() << " - " << vec.capacity() << std::endl;
}

template <class T>
void show(ft::vector<T>& vec) {
	show_cap(vec);
	std::cout << vec.front() << " - " << vec[1] << " - " << vec.at(2) << " - " << vec.back() << std::endl;
}

template <class T>
void print(ft::vector<T>& vec) {
	typename ft::vector<T>::iterator first = vec.begin();
	typename ft::vector<T>::iterator last = vec.end();
	while (first < last)
	{
		std::cout << *first << std::endl;
		first++;
	}
}

void test1() {
	cout << "========== TEST 1 ==========" << endl;

	ft::vector<std::string> vec;
	cout << "Default constructor + push_back" << endl;
	for (size_t i = 0; i < 9; i++)
		vec.push_back("hello");
	show_cap(vec); print(vec);

	cout << "Constructor with size" << endl;
	ft::vector<std::string> vec2(9);
	show_cap(vec2); print(vec2);

	cout << "Constructor with size and value" << endl;
	ft::vector<std::string> vec3(9, "hello");
	show_cap(vec3); print(vec3);

	cout << "Constructor with two iterators" << endl;
	ft::vector<std::string> vec4(vec.begin(), vec.end());
	show_cap(vec4); print(vec4);

	cout << "Copy constructor" << endl;
	ft::vector<std::string> vec5(vec);
	show_cap(vec5); print(vec5);
}

void test2() {
	cout << "========== TEST 2 ==========" << endl;
}

int main() {
	test1();
}