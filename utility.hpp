#ifndef STL_LIKE_HPP
#define STL_LIKE_HPP

#include <exception>
#include <iostream>

namespace ft
{

	template <class InputIt1, class InputIt2>
	bool equal ( InputIt1 first1, InputIt1 last1, InputIt2 first2){
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
	return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal ( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p){
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
	return true;
	}

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
										InputIterator2 first2, InputIterator2 last2){
			while (first1 != last1)
			{
				if (first2 == last2 || *first2 < *first1) return false;
				else if (*first1 < *first2) return true;
				++first1; ++first2;
			}
		return (first2!=last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp){
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
	return (first1 == last1) && (first2 != last2);
	}
	template <typename T1, typename T2>
	class pair
	{
		public:
			T1 first;
			T2 second;

			pair() : first(), second() {};
			pair(const T1& a, const T2& b) : first(a), second(b) {};
			pair(const pair& copy) : first(copy.first), second(copy.second) {};

			~pair() {};

			pair& operator=(const pair& assign)
			{
				if (this != &assign)
				{
					first = assign.first;
					second = assign.second;
				}
				return (*this);
			}


			friend bool operator==(const pair& lhs, const pair& rhs){
				return ((lhs.first == rhs.first and lhs.second == rhs.second));}

			friend bool operator!=(const pair& lhs, const pair& rhs){
				return (!(lhs == rhs));}

			friend bool operator<(const pair& lhs, const pair& rhs){
				if (lhs.first < rhs.first)
					return true;
				if (lhs.second < rhs.second)
					return true;
				return false;
			}

			friend bool operator<=(const pair& lhs, const pair& rhs){
				if (lhs < rhs)
					return true;
				if (lhs == rhs)
					return true;
				return false;
			}
			friend bool operator>(const pair& lhs, const pair& rhs){return !(lhs <= rhs);}

			friend bool operator>=(const pair& lhs, const pair& rhs){return !(lhs < rhs);}

	}; // pair

	template<typename T1, typename T2>
	pair<T1,T2>make_pair(T1 t,T2 u){
		return pair<T1,T2>(t,u);
	}

	template <class T>
	void swap ( T& a, T& b )
	{
		T c(a); a=b; b=c;
	}

	template <bool B>
	struct enable_if {};

	template <>
	struct enable_if<true> { typedef int type; };	template <typename T>
	struct is_integral { static const bool value = false; };

	template <>
	struct is_integral<bool> { static const bool value = true; };

	template <>
	struct is_integral<char> { static const bool value = true; };

	template <>
	struct is_integral<short> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<long> { static const bool value = true; };

	template <>
	struct is_integral<long long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };

	template <>
	struct is_integral<unsigned short> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long> { static const bool value = true; };

} // namespace ft

#endif
