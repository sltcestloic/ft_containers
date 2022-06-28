#ifndef CONTAINERS_UTILS_HPP
#define CONTAINERS_UTILS_HPP

namespace ft {

	/*****************/
	/*   enable_if   */
	/*****************/


	template <class T, T v>
	class integral_constant
	{
	public:
		const static T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		const value_type operator()() const { return value; }
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <class T>
	struct is_integral : public false_type {};

	template <class T>
	struct is_integral<const T> : public is_integral<T> {};

	template <class T>
	struct is_integral<volatile const T> : public is_integral<T> {};

	template <class T>
	struct is_integral<volatile T> : public is_integral<T> {};

	template <>
	struct is_integral<unsigned char> : public true_type {};

	template <>
	struct is_integral<unsigned short> : public true_type {};

	template <>
	struct is_integral<unsigned int> : public true_type {};

	template <>
	struct is_integral<unsigned long> : public true_type {};

	template <>
	struct is_integral<signed char> : public true_type {};

	template <>
	struct is_integral<short> : public true_type {};

	template <>
	struct is_integral<int> : public true_type {};

	template <>
	struct is_integral<long int> : public true_type {};

	template <>
	struct is_integral<long long int> : public true_type {};

	template <>
	struct is_integral<unsigned long long int> : public true_type {};

	template <>
	struct is_integral<char> : public true_type {};

	template <>
	struct is_integral<bool> : public true_type {};

	// If B is true, std::enable_if has a public member typedef type,
	// equal to T; otherwise, there is no member typedef.
	template <bool B, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> { typedef T type; };


	/*******************/
	/* equal / compare */
	/*******************/


	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2)
	{
		while (first1 != last1)
			if (*first1++ != *first2++)
				return false;
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1!=last1) {
			if (!pred(*first1,*first2)) 
			return false;
			++first1; ++first2;
		}
		return true;
	}
	// From https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	/* //Sert juste pour la fonctions qui print l'arbre
	struct Trunk
	{
		Trunk *prev;
		std::string str;
	
		Trunk(Trunk *prev, std::string str)
		{
			this->prev = prev;
			this->str = str;
		}
	};

	void showTrunks(Trunk *p)
	{
		if (p == nullptr)
			return;
		showTrunks(p->prev);
		std::cout << p->str;
	}
			
	template <class value_type>
	void printTree(node<value_type>* root, Trunk *prev, bool isLeft)
	{
		if (root == nullptr)
			return;
		std::string prev_str = "    ";
		Trunk *trunk = new Trunk(prev, prev_str);
	
		printTree(root->right, trunk, true);
	
		if (!prev)
			trunk->str = "———";
		else if (isLeft)
		{
			trunk->str = "┌———";
			prev_str = "    |";
		}
		else {
			trunk->str = "└──";
			prev->str = prev_str;
		}
	
		showTrunks(trunk);
		if (root->color == RED)
			std::cout << "\033[31m" << root->data.first << "\033[0m" << std::endl;
		else
			std::cout << root->data.first << std::endl;
			
		if (prev) {
			prev->str = prev_str;
		}
		trunk->str = "    |";
	
		printTree(root->left, trunk, false);
	} */
}

#endif