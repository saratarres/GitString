all : test_string

test_string : test_string.o test_string.cpp
	g++ -o  test_string test_string.cpp  test_string.o

ppm.o : String.h String.cpp
	g++ -o test_string.o -c String.cpp


clean :
	rm *.o

mrproper : clean
	rm ppm
