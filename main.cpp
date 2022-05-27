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


// Constructors
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

// reserve, resize, assign
void test2() {
	cout << "========== TEST 2 ==========" << endl;

	ft::vector<std::string> vec(5, "salut");
	cout << "reserve" << endl;
	vec.reserve(9);
	show_cap(vec); print(vec);

	cout << "resize" << endl;
	for (int i = 0; i < 10; i++)
		vec.push_back("hello");
	vec.resize(8);
	show_cap(vec); print(vec);

	ft::vector<std::string> vec2(2);
	cout << "assign iterator" << endl;
	vec2.assign(vec.begin(), vec.end());
	show_cap(vec2); print(vec2);

	ft::vector<std::string> vec3(2);
	cout << "assign value" << endl;
	vec3.assign(12, "ouais ouais ouais"); 
	show_cap(vec3); print(vec3);
}

// erase
void test3() {
	cout << "========== TEST 3 ==========" << endl;

	ft::vector<std::string> vec(8, "YAX3");
	cout << "erase" << endl;
	vec.erase(vec.begin() + 2);
	show_cap(vec); print(vec);	

	ft::vector<std::string> vec3(15, "YAX3");
	cout << "erase range" << endl;
	vec3.erase(vec3.begin() + 2, vec3.begin() + 4);
	show_cap(vec3); print(vec3);

	ft::vector<std::string> vec4(15, "YAX3");
	cout << "erase range same position" << endl;
	vec4.erase(vec4.begin() + 6, vec4.begin() + 6);
	show_cap(vec4); print(vec4);
}

// clear, swap
void test4() {
	cout << "========== TEST 4 ==========" << endl;

	ft::vector<std::string> vec(8, "YAX3");
	cout << "clear" << endl;
	vec.clear();
	show_cap(vec); print(vec);

	ft::vector<std::string> vec2(15, "wsh");
	cout << "swap (member)" << endl;
	ft::vector<std::string> vec3(15, "YAX3");
	vec2.swap(vec3);
	show_cap(vec2); print(vec2);
	show_cap(vec3); print(vec3);

	ft::vector<std::string> vec4(15, "yo man");
	cout << "swap (non-member)" << endl;
	ft::swap(vec4, vec2);
	show_cap(vec2); print(vec2);
	show_cap(vec4); print(vec4);
}

// insert (and [] operator)
void test5() {
	cout << "========== TEST 5 ==========" << endl;

	ft::vector<int> vec(12);
	cout << "insert (1 element)" << endl;
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] = i * 3;
	vec.insert(vec.begin() + 7, 555);
	show_cap(vec); print(vec);

	ft::vector<int> vec2(12);
	for (size_t i = 0; i < vec2.size(); i++)
		vec2[i] = i * 3;
	ft::vector<int> vec3(5, 555);
	cout << "insert (range)" << endl;
	vec2.insert(vec2.begin() + 5, vec3.begin(), vec3.end());
	show_cap(vec2); print(vec2);
}

// push_back, pop_back
void test6() {
	cout << "========== TEST 6 ==========" << endl;

	ft::vector<std::string> vec(5);
	cout << "push_back (no realloc)" << endl;
	vec.assign(4, "yo");
	vec.push_back("cc");
	show_cap(vec); print(vec);

	cout << "push_back (realloc)" << endl;
	for (size_t i = 0; i < 10; i++)
		vec.push_back("yo");
	show_cap(vec); print(vec);

	cout << "pop_back (1 element)" << endl;
	vec.pop_back();
	show_cap(vec); print(vec);

	cout << "pop_back (multiple elements)" << endl;
	for (size_t i = 0; i < 8; i++)
		vec.pop_back();
	show_cap(vec); print(vec);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}