#include "tester.hpp"

void test_vector_modifiers(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing vector's modifiers" << END << std::endl;
	int range[10] = {0,1,2,3,4,5,6,7,8,9};
	ivector t,t2(10),t3(t2),t4(15,20),t5(range,range + 10),t6 = t4;
	t2.push_back(12);
	t3.reserve(15);
	ivector i[6] = {t,t2,t3,t4,t5,t6};

	svector s,s2(10);
	for (int i = 0; i < 10; i++){s2[i] = "0";};
	std::string srange[10] = {"0","1","2","3","4","5","6","7","8","9"};
	svector s3(s2),s4(15,std::string("20")),s5(srange,srange + 10),s6;
	s2.push_back("12");
	for (int i = 0; i < 10; i++){s2[i] = "0";};
	s3.reserve(15);
	s6 = s4;
	svector sd[6] = {s,s2,s3,s4,s5,s6};

	test_vector_clear();
	test_vector_insert(i,sd);
	test_vector_erase(i,sd);
	test_vector_push_pop(i,sd);
	test_vector_resize(i,sd);
	test_vector_swap(i,sd);
	test_vector_max_size(i,sd);
	test_vector_reserve(i,sd);
	test_vector_assign(i,sd);
}

void all_vector_test(){
	std::cout << BOLD << UNDERLINE << ORANGE << "TESTING FT::VECTOR" << END << std::endl;
	std::cout << "The vector is a sequence container that encapsulates dynamic size array" << std::endl << std::endl;
	test_vector_constructors();
	test_vector_element_access();
	test_vector_iterators();
	test_vector_modifiers();
}

void all_stack_test(){
	std::cout << BOLD << UNDERLINE << ORANGE << "TESTING FT::STACK" << END << std::endl;
	std::cout << "The stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure. *cppreference.com\n" << std::endl;
	test_stack_constructor_capacity();
	test_stack_element_access();
	test_stack_modifiers();
	test_stack_operators();
	std::cout << std::endl << std::endl;
}

void test_map_modifiers(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing map modifier member function" << END << std::endl;
	test_map_clear();
	test_map_insert();
	test_map_erase();
	test_map_swap();
}

void test_map_observers(){
	std::cout << BOLD << LIGHTBLUE << "Testing map observers function" << END << std::endl;
	test_map_key_comp();
	test_map_value_comp();
}

void test_map_non_member(){
	std::cout <<std::endl << BOLD << LIGHTBLUE << "Testing map non member function" << END << std::endl;
	test_ft_swap_specialization();
	test_equality_operators();
}

void test_map_lookup(){
	std::cout <<std::endl << BOLD << LIGHTBLUE << "Testing map Lookup function" << END << std::endl;
	test_map_count();
	test_map_find();
	test_map_equal_range();
}
void all_map_test(){
	std::cout << BOLD << UNDERLINE << ORANGE << "TESTING FT::MAP" << END << std::endl;
	std::cout << "The map is a sorted associative container that contains key-value pairs with unique keys" << std::endl << std::endl;
	test_map_constructor_capacity();
	test_map_element_access();
	test_map_iterators();
	test_map_modifiers();
	test_map_lookup();
	test_map_observers();
	test_map_non_member();
}

int main()
{
	all_stack_test();
	all_vector_test();
	all_map_test();
	return 0;
}
