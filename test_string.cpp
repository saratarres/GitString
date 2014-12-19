//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>



// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "String.h"



// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================








// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  printf("Hello World, here the geeks are !\n");
	String Nouvelle_chaine ("holachicas");
	int i ;

	//Test clear methods
	//Nouvelle_chaine.clear();
	//printf("%d	%s\n", Nouvelle_chaine.size(),Nouvelle_chaine.Get_string());
	

	//Test size methods 

	printf("%lu\n", Nouvelle_chaine.size());

	//test Get_string
 
	printf(" %s\n", Nouvelle_chaine.Get_string());

	/*	
	printf(" %d",Nouvelle_chaine.size());
	int res = Nouvelle_chaine.empty(3);
	printf("%d\n",res);
	res = Nouvelle_chaine.empty(0);
	printf("%d\n",res);*/
    
  	
  //NewString.resize(4);
	//printf("%d\n",NewString.size());
	//printf("%d\n",NewString.at(4));

	//NewString.resize(8);
	//printf("%d\n",NewString.size());
	//printf("%d\n",NewString.at(4));

	//printf(" %d\n",Nouvelle_chaine.size());

	//Nouvelle_chaine.clear();
	//printf(" %d",Nouvelle_chaine.size());


	char a = 'c';
	//Nouvelle_chaine += a;
	//printf(" %s\n", Nouvelle_chaine.Get_string());

		
	//------------------------------ TEST operator+ ----------------------------
	
	printf("TEST OPERATOR +=\n");
	printf("operator += for a character\n");
	a = 'b';
	Nouvelle_chaine += a;
	printf(" %s\n", Nouvelle_chaine.Get_string());
	printf("%lu\n", Nouvelle_chaine.size());


	printf("operator += for a string\n");
	String FirstString ("AyAyAy");
	String SecondString ("caramba");
	FirstString += SecondString;
	printf("%s\n", FirstString.Get_string());

	printf("operator += for a char*\n");
	String stringtest("hola");
	char* toto ="quetal";
	stringtest += toto;
	printf("%s\n", stringtest.Get_string());




	//----------------------------- Operator = TEST: ----------------------------

	printf("TEST OPERATOR =\n");
	printf("operator = for two strings\n");
	String NewString ("holachicos");
	Nouvelle_chaine  = NewString;
	printf("%s\n", Nouvelle_chaine.Get_string());
	
	printf("operator = for a char\n");
	Nouvelle_chaine = 'f';
	printf("%s\n",Nouvelle_chaine.Get_string());
	



	
	printf("operator = for a char* and a string\n");
	char * s = new char[3];
	s[0]='H';
	s[1]='I';
	s[2]='!';


	String MyTestString = (s);
	printf("%s\n", MyTestString.Get_string());
	delete [] s;


//----------------------------- Operator [] TEST: ----------------------------

	printf("TEST OPERATOR []\n");
	char c = MyTestString[0];
	printf("%c\n",c);
	


  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

