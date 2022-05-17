#include "vector.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
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
}