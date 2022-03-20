#include "tester.hpp"
#include <time.h>
#include <cstdlib>
#ifndef NAMESPACE
#define NAMESPACE ft

#endif
int main()
{
	ft::pair<const int,double> pair(12,25);
	pair.~pair();
// 	srand(time(NULL));
// 	struct timespec ts1;
// 	ismap t;

// 	std::cout << "Performance Tests" << std::endl;
// 	std::cout << "Testing Map" << std::endl;
// 	std::cout << "The important part of performance for a map is the insertion,the deletion and the search" << std::endl;
// 	std::cout << "for the first test i'll create 1 millions of randoms keys object" << std::endl;
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&ts1);
// 	for (int i=0; i< 1000000;i++){t.insert(ispair(rand(),std::string("Bonjour")));}
// 	struct timespec ts2;
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&ts2);
// 	double result = 1000.0*ts2.tv_sec + 1e-6*ts2.tv_nsec - (1000.0*ts1.tv_sec + 1e-6*ts1.tv_nsec);
// 	std::cout << "time elapsed: " << result << " ms" << std::endl;
// 	ismap t2;
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&ts1);
// 	t2.insert(ispair(0,std::string("Bonjour")));
// 	for (int i=1; i< 1000000;i++){t2.insert(t2.begin(),ispair(i,std::string("Bonjour")));}
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&ts2);
// 	result = 1000.0*ts2.tv_sec + 1e-6*ts2.tv_nsec - (1000.0*ts1.tv_sec + 1e-6*ts1.tv_nsec);
// 	std::cout << "time elapsed: " << result << " ms" << std::endl;
// 	std::cout << "for the second test i'll delete the key from two differente ways" << std::endl;
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&ts1);
// 	t.clear();
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&ts2);
// 	result = 1000.0*ts2.tv_sec + 1e-6*ts2.tv_nsec - (1000.0*ts1.tv_sec + 1e-6*ts1.tv_nsec);
// 	std::cout << "time elapsed for the clear function: " << result << " ms" << std::endl;
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&ts1);
// 	t2.erase(t2.begin(),t2.end());
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&ts2);
// 	result = 1000.0*ts2.tv_sec + 1e-6*ts2.tv_nsec - (1000.0*ts1.tv_sec + 1e-6*ts1.tv_nsec);
// 	std::cout << "time elapsed for the erase function: " << result << " ms" << std::endl;
}
