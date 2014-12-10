all : test_string

test_string : String.o test_string.cpp
	g++ -g -o test_string test_string.cpp  String.o

String.o : String.h String.cpp
	g++ -g -o String.o -c String.cpp


clean :
	rm *.o

mrproper : clean
	rm test_string
