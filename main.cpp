#include "vector.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ft::vector<int> vec;
	std::vector<int> stdvec;

	stdvec.push_back(20);
	vec.push_back(20);

	cout << stdvec.at(0) << endl;
	cout << vec.at(0) << endl;
}