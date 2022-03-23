SRC_TESTER = $(addprefix tester/,map_test.cpp vector_test.cpp stack_test.cpp)

FLAG = -Wall -Wextra -Werror

FLAGSTD = -std=c++98

CXX = c++

SHELL = bash

all : test difftest perf

difftest:
	diff <(./ft_test) <(./std_test) | less > diff_test.ansi

test: ft_test std_test

perf: ft_perf std_perf

ft_test:
	$(CXX) $(FLAG) -DNAMESPACE=ft tester/maintest.cpp $(SRC_TESTER) -o ft_test

std_test:
	$(CXX) $(FLAG) -DNAMESPACE=std tester/maintest.cpp $(SRC_TESTER) -o std_test

ft_perf:
	$(CXX) $(FLAG) -std=c++98 -DNAMESPACE=ft tester/binary.cpp $(SRC_TESTER) -o ft_perf

std_perf:
	$(CXX) $(FLAG) -std=c++98 -DNAMESPACE=std tester/binary.cpp $(SRC_TESTER) -o std_perf

rm:
	rm -rf ft_test
	rm -rf std_test
	rm -rf diff_test.ansi
	rm -rf ft_perf
	rm -rf std_perf

re: rm all
