#include "vector.hpp"

#include <iostream>
#include <vector>
#include <list>

using namespace std;

/* int main() {
	ft::vector<int> vec;
	std::vector<int> stdvec;


	for (int i = 0; i < 6; i++) {
		stdvec.push_back(i * 10);
		vec.push_back(i * 10);
		cout << stdvec.at(i) << endl;
		cout << vec.at(i) << endl;
	}

	stdvec.resize(3);
	vec.resize(3);
	
	cout << stdvec.size() << endl;
	cout << vec.size() << endl;

	cout << stdvec.at(2) << endl;
	cout << vec.at(2) << endl;

	cout << stdvec.back() << endl;
	cout << vec.back() << endl;

	stdvec.pop_back();
	vec.pop_back();

	cout << stdvec.back() << endl;
	cout << vec.back() << endl;
} */

#define TESTED_NAMESPACE std
#define TESTED_TYPE int

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> foo(3, 15);
	TESTED_NAMESPACE::vector<TESTED_TYPE> bar(5, 42);
	
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_foo = foo.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	foo.swap(bar);

	std::cout << "AFTER SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;

	return (0);
}
