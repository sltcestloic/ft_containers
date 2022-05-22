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

#define TESTED_NAMESPACE ft
#define TESTED_TYPE int

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

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

#include "iterator.hpp"

int main () {
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printSize(vct);
	return (0);
}
