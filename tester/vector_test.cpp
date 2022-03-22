#include "tester.hpp"

void test_vector_constructors(){
	std::cout << BOLD << LIGHTBLUE << "Testing the constructors" << END << std::endl;
	std::allocator<int> mem;
	ivector t(mem);
	std::cout << "Default constructor with int as template parameter :" << std::endl;
	print_vector_status("Vector",t);
	std::cout << "Fill constructor with size and initialization :" << std::endl;
	ivector t2(10,25);
	print_vector_status("Vector",t2);
	std::cout << "Range constructor with a size of 10 and a range of initialization from 0 to 10 :" << std::endl;
	int range[10] = {0,1,2,3,4,5,6,7,8,9};
	ivector t3(range, range + 10);
	print_vector_status("Vector",t3);
	std::cout << "Copy constructor to the Range constructor :" << std::endl;
	ivector t4(t3);
	print_vector_status("Vector",t4);
	std::cout << "Operator= of vector t4 with a push_back added:" << std::endl;
	ivector t5(3);
	t4.push_back(250);
	t5 = t4;
	print_vector_status("Vector",t5);
}

void test_vector_element_access(){
	std::cout << BOLD << LIGHTBLUE << "Testing the element access" << END << std::endl;
	int range[50]; for (int i = 0; i < 50;i++){range[i] = i;};
	ivector t(range, range + 50);
	std::cout << "Element acces from a vector<int> with a range of 50 :" << std::endl;
	print_vector_element_status(t);
	std::cout << std::endl << "Element acces from a const vector<int> with a range of 50 :" << std::endl;
	const ivector t2(range, range + 50);
	print_vector_element_status_const(t2);
	std::cout << std::endl << "Element acces from a const vector<std::string> with a 15 element :" << std::endl;
	std::string srange[15];for (int i = 0; i < 15;i++){for (int j = 0; j < 5; j++){srange[i].insert(j, 1,i + 64);}};
	svector t3(srange,srange + 15);
	print_vector_element_status(t3);
	std::cout << std::endl << "Element acces from a const vector<std::string> with a 15 element :" << std::endl;
	const svector t4(srange,srange + 15);
	print_vector_element_status_const(t4);
}

void test_vector_iterator_int(std::string str[4]){
	typedef ivector ftvector;

	int range[50]; for (int i = 0; i < 50;i++){range[i] = i;};
	ftvector t(range, range + 50),t3(range, range + 50);
	ftvector::iterator it = t.begin(),ite = t.end() - 1;
	ftvector::const_iterator cit = t.begin(),cite = t.end() - 1;
	ftvector::reverse_iterator rit = t.rbegin(),rite = t.rend() - 1;
	ftvector::const_reverse_iterator crit = t.rbegin(), crite = t.rend() - 1;
	std::cout << "Testing vector_iterator with a vector<int> range of 50 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::iterator >(str[0],it,ite);
	std::cout << std::endl << "Testing const_vector_iterator with a vector<int> range of 50 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::const_iterator >(str[1],cit,cite);
	std::cout << std::endl << "Testing reverse_vector_iterator with a vector<int> range of 50 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::reverse_iterator >(str[2],rit,rite);
	std::cout << std::endl << "Testing const_reverse_vector_iterator with a vector<int> range of 50 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::const_reverse_iterator >(str[3],crit,crite);
	std::cout << std::endl << END;
}

void test_vector_iterator_string(std::string str[4]){
	typedef svector ftvector;

	std::string range[15];
	for (int i = 0; i < 15;i++){for (int j = 0; j < 5; j++){range[i].insert(j, 1,i + 64);}};
	ftvector t(range, range + 15), t3(range, range + 15);
	ftvector::iterator it = t.begin(),ite = t.end() - 1;
	ftvector::const_iterator cit = t.begin(),cite = t.end() - 1;
	ftvector::reverse_iterator rit = t.rbegin(),rite = t.rend() - 1;
	ftvector::const_reverse_iterator crit = t.rbegin(), crite = t.rend() - 1;
	std::cout << "Testing vector_iterator with a vector<std::string> with 15 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::iterator >(str[0],it,ite);
	std::cout << str[0] << "operator->c_str()\t" << END << "= " << LIGHTORANGE << it.operator->()->c_str() << END << std::endl;
	std::cout << std::endl << "Testing const_vector_iterator with a vector<std::string> with 15 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::const_iterator >(str[1],cit,cite);
	std::cout << str[1] << "operator->c_str()\t" << END << "= " << LIGHTORANGE << cit.operator->()->c_str() << END << std::endl;
	std::cout << std::endl << "Testing reverse_vector_iterator with a vector<std::string> with 15 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::reverse_iterator >(str[2],rit,rite);
	std::cout << str[2] << "operator->c_str()\t" << END << "= " << LIGHTORANGE << rit.operator->()->c_str() << END << std::endl;
	std::cout << std::endl << "Testing const_reverse_vector_iterator with a vector<std::string> with 15 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::const_reverse_iterator >(str[3],crit,crite);
	std::cout << str[3] << "operator->c_str()\t" << END << "= " << LIGHTORANGE << crit.operator->()->c_str() << END << std::endl;
	std::cout << END <<std::endl;
	std::cout << "Testing iterator comparison operator t.begin() and t.begin() :" << std::endl;
	print_operators("Iterator.",(ftvector::iterator(t.begin())),(ftvector::iterator(t.begin())));
	std::cout << "Testing iterator comparison operator t.begin() and t.end() :" << std::endl;
	print_operators("Iterator.",(ftvector::iterator(t.begin())),(ftvector::iterator(t.end())));
	std::cout << "Testing iterator comparison operator *t.begin() and *t3.begin() :" << std::endl;
	print_operators("Iterator.",*(ftvector::iterator(t.begin())),*(ftvector::iterator(t3.begin())));
}

void test_iterator_const(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing vector and map iterators const comparison" << END << std::endl;
	ivector t(15,100);
	ismap m;
	m.insert(ispair(15,"Bonjour"));

	ismap::iterator mit = m.begin();
	ismap::const_iterator mcit = m.begin();
	ismap::reverse_iterator mrit = m.rbegin();
	ismap::const_reverse_iterator mcrit = m.rbegin();

	ivector::iterator it = t.begin();
	ivector::const_iterator cit = t.begin();
	ivector::reverse_iterator rit = t.rbegin();
	ivector::const_reverse_iterator crit = t.rbegin();
	if (cit == it)
		std::cout << "vector const iterator and iterator can compare" << END << std::endl;
	if (crit == rit)
		std::cout << "vector const reverse iterator and reverse iterator can compare" << END << std::endl;
	if (mcit == mit)
		std::cout << "map const iterator and iterator can compare" << END << std::endl;
	if (mcrit == mrit)
		std::cout << "map const reverse iterator and reverse iterator can compare" << END << std::endl;
}

void test_vector_iterators(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing vector's iterators" << END << std::endl;
	std::string str(RIGHTARROW);str.append("Iterator");str.append(".");str.append(LIGHTYELLOW);
	std::string str2(RIGHTARROW);str2.append("CIterator");str2.append(".");str2.append(LIGHTYELLOW );
	std::string str3(RIGHTARROW);str3.append("RIterator");str3.append(".");str3.append(LIGHTYELLOW );
	std::string str4(RIGHTARROW);str4.append("CRIterator");str4.append(".");str4.append(LIGHTYELLOW);
	std::string cpstr[4]; cpstr[0] = str; cpstr[1] = str2; cpstr[2] = str3; cpstr[3] = str4;
	test_vector_iterator_int(cpstr);
	test_vector_iterator_string(cpstr);
	test_iterator_const();
}

void test_vector_clear(){
	std::string str(RIGHTARROW);str.append("Vector");str.append(".");str.append(LIGHTYELLOW);
	ivector t(15,150);
	std::cout << "Testing clear() with a vector<std::vector> with 15 elements :\nBefore : ";
	for(ivector::iterator it = t.begin(); it != t.end();it++) {std::cout << *it << " ";}
	std::cout << std::endl;
	print_vector_status("Vector",t);
	t.clear();
	std::cout << "After : ";
	for(ivector::iterator it = t.begin(); it != t.end();it++) {std::cout << *it << " ";}
	std::cout << std::endl;
	print_vector_status("Vector",t);
	svector t2(15,std::string("tutu"));
	std::cout << "Testing clear() with a vector<std::string> with 15 elements :\nBefore : ";
	for(svector::iterator it = t2.begin(); it != t2.end();it++) {std::cout << *it << " ";}
	std::cout << std::endl;
	print_vector_status("Vector",t2);
	t2.clear();
	std::cout << "After : ";
	for(svector::iterator it = t2.begin(); it != t2.end();it++) {std::cout << *it << " ";}
	std::cout << std::endl;
	print_vector_status("Vector",t2);
}

template <class T,typename U>
void test_vector_insert_unit(T * vector, U val)
{
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		typename T::iterator it = test[i].insert(test[i].begin(),val);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "insert\t\t" << END << "= "<<LIGHTORANGE << "NULL" << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "insert\t\t" << END << "= "<<LIGHTORANGE << *it << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		typename T::iterator it = test[i].insert(test[i].end(),val);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "insert\t\t" << END << "= "<<LIGHTORANGE << "NULL" << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "insert\t\t" << END << "= "<<LIGHTORANGE << *it << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

template <class T,typename U>
void test_vector_insert_fill(T * vector,int count, U val)
{
	T test[6] = {T(vector[0]), T(vector[1]), vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		test[i].insert(test[i].begin(),count,val);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		test[i].insert(test[i].end(),count,val);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}


template <class T,typename InputIt>
void test_vector_insert_range(T * vector,InputIt first, InputIt last)
{
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		test[i].insert(test[i].begin(),first,last);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		test[i].insert(test[i].end(),first,last);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}


template <class T,typename U>
void test_vector_assign_unit(T * vector,typename T::size_type count, U val)
{
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		test[i].assign(count,val);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		test[i].assign(count,val);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

template <class T,typename InputIt>
void test_vector_assign_range(T * vector,InputIt first, InputIt last)
{
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		test[i].assign(first,last);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		test[i].assign(first,last);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

template <typename T>
void test_vector_erase_unit(T * vector){
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 1; i < 6; i++)
	{
		typename T::iterator it = test[i].erase(test[i].begin() + i);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "erase\t\t" << END << "= "<<LIGHTORANGE << "NULL" << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "erase\t\t" << END << "= "<<LIGHTORANGE << *it << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((vector[i].size() == 10)?"\t\t\t\t\t\t\t":((vector[i].size() == 11)?"\t\t\t\t\t\t":((vector[i].size() == 15)?"\t\t\t\t":"tutu"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

template <typename T>
void test_vector_erase_range(T * vector){
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 1; i < 6; i++)
	{
		typename T::iterator it = test[i].erase(test[i].begin(),test[i].begin() + i);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "erase\t\t" << END << "= "<<LIGHTORANGE << "NULL" << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "erase\t\t" << END << "= "<<LIGHTORANGE << *it << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((vector[i].size() == 10)?"\t\t\t\t\t\t\t":((vector[i].size() == 11)?"\t\t\t\t\t\t":((vector[i].size() == 15)?"\t\t\t\t":"tutu"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

void test_vector_insert(ivector * t, svector * s){
	std::cout << BOLD << UNDERLINE << "Testing member function insert :" << END << std::endl;
	std::cout << "Testing insert on a bunch of vector<int> and with a single value of 25" << std::endl;
	test_vector_insert_unit(t, 25);

	std::cout << "Testing insert on a bunch of vector<string> and with a single value of 25" << std::endl;
	test_vector_insert_unit(s, std::string("25"));

	std::cout << "Testing insert on a bunch of vector<int> and with 10 values of 99" << std::endl;
	test_vector_insert_fill(t, 10, 99);

	std::cout << "Testing insert on a bunch of vector<string> and with 10 values of 99" << std::endl;
	test_vector_insert_fill(s, 10, std::string("99"));

	std::cout << "Testing insert on a bunch of vector<int> and with a range of 0 to 9" << std::endl;
	test_vector_insert_range(t, t[5].begin(), t[5].end());

	std::cout << "Testing insert on a bunch of vector<string> and with a range of 0 to 9" << std::endl;
	test_vector_insert_range(s, s[5].begin(), s[5].end());
}

void test_vector_erase(ivector * i, svector * s){
	std::cout << BOLD << UNDERLINE << "Testing member function erase :" << END << std::endl;
	std::cout << "Testing erase on a bunch of vector<int>" << std::endl;
	test_vector_erase_unit(i);

	std::cout << "Testing erase on a bunch of vector<string>" << std::endl;
	test_vector_erase_unit(s);

	std::cout << "Testing erase on a bunch of vector<int> and with a range" << std::endl;
	test_vector_erase_range(i);

	std::cout << "Testing erase on a bunch of vector<string> and with a range" << std::endl;
	test_vector_erase_range(s);

}

void test_vector_push_pop(ivector * i, svector * s){
	ivector test[6] = {i[0], i[1], i[2], i[3], i[4], i[5]};
	svector test2[6] = {s[0], s[1], s[2], s[3], s[4], s[5]};
	std::cout << BOLD << UNDERLINE << "Testing member function push_back and pop_back :" << END << std::endl;
	std::cout << "Adding 10 elements to each vector :" << std::endl;
	for (int k = 0; k < 6;k++){
		for (int j = 0; j < 10; j++){
			if (j % 3 == 0){
				std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
				for(svector::iterator it = test2[k].begin(); it != test2[k].end();it++) {std::cout << *it << " ";};std:: cout << END << std::endl;
				print_vector_status("Vector",test2[k]);
				std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
				for(ivector::iterator it = test[k].begin(); it != test[k].end();it++) {std::cout << *it << " ";};std:: cout << END << std::endl;
				print_vector_status("Vector",test[k]);
			}
			test[k].push_back(k + 52);
			test2[k].push_back(std::string((test2[4].data() + k)->c_str()));
		}
	}
	std::cout << "Deleting all the elements in the vector :" << std::endl;
	for (int k = 0; k < 6;k++){
		for (ivector::size_type j = test[k].size(); j > 0; j--){
			test[k].pop_back();
		}
		for (svector::size_type j = test2[k].size(); j > 0; j--){
			test2[k].pop_back();
		}
			print_vector_status("Vector",test2[k]);
			print_vector_status("Vector",test[k]);
	}
}

void test_vector_resize(ivector * i, svector *s)
{
	ivector test[6] = {i[0], i[1], i[2], i[3], i[4], i[5]};
	svector test2[6] = {s[0], s[1], s[2], s[3], s[4], s[5]};
	std::cout << BOLD << UNDERLINE << "Testing member function resize :" << END << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Before :" << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(ivector::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";};std:: cout << END << std::endl;
		print_vector_status("Vector",test[i]);
		std::cout << "After :" << std::endl;
		test[i].resize(i * 5,32);
		test2[i].resize(i * 5);
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(ivector::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";};std:: cout << END << std::endl;
		print_vector_status("Vector",test[i]);
	}
}

void test_vector_swap(ivector * t, svector * s)
{
	ivector test[6] = {t[0], t[1], t[2], t[3], t[4], t[5]};
	svector test2[6] = {s[0], s[1], s[2], s[3], s[4], s[5]};

	std::cout << BOLD << UNDERLINE << "Testing member function swap :" << END << std::endl;
	std::cout << "Swapping the 1st container with the fifth container :" << END << std::endl;
	std::cout << "Before :" << std::endl;
	print_vector_status("Vector",test[0]);
	print_vector_status("Vector",test[5]);
	test[0].swap(test[5]);
	std::cout << "After :" << std::endl;
	print_vector_status("Vector",test[0]);
	print_vector_status("Vector",test[5]);
}

void test_vector_max_size(ivector * t, svector * s){
	std::cout << BOLD << UNDERLINE << "Testing member function max_size :" << END << std::endl;
	for (int i = 0; i < 6; i++){
		std::cout << RIGHTARROW << "Ivector["<<i<< "]." << LIGHTYELLOW << "max_size\t\t" << END << "= "<<LIGHTORANGE << t[i].max_size() << END << "\t\t\t\t" << RIGHTARROW << "Svector["<< i <<"]." << LIGHTYELLOW << "max_size\t\t" << END << "= "<<LIGHTORANGE << s[i].max_size() << END << std::endl;
	}
	std::cout << std::endl;
}

void test_vector_reserve(ivector * t, svector * s){
	ivector test[6] = {t[0], t[1], t[2], t[3], t[4], t[5]};
	svector test2[6] = {s[0], s[1], s[2], s[3], s[4], s[5]};
	for (int i = 0; i < 6; i++) {
		print_vector_status("Vector",test[i]);
		test[i].reserve(100);
		print_vector_status("Vector",test[i]);
	}
}

void test_vector_assign(ivector * t, svector * s){
	std::cout << BOLD << UNDERLINE << "Testing member function assign :" << END << std::endl;
	std::cout << "Testing assign on a bunch of vector<int> and with a single value of 25" << std::endl;
	test_vector_assign_unit(t, 25, 99);

	std::cout << "Testing assign on a bunch of vector<string> and with a single value of 25" << std::endl;
	test_vector_assign_unit(s, 25, std::string("99"));

	std::cout << "Testing assign on a bunch of vector<int> and with a range of 0 to 9" << std::endl;
	test_vector_assign_range(t, t[5].begin(), t[5].end());

	std::cout << "Testing assign on a bunch of vector<string> and with a range of 0 to 9" << std::endl;
	test_vector_assign_range(s, s[5].begin(), s[5].end());

}
