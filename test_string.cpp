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
	printf(" %s\n", Nouvelle_chaine.Get_string());
	String NewString ("holachicos");
	Nouvelle_chaine  = NewString;
	printf(" %s\n", Nouvelle_chaine.Get_string());
	char a = 'c';
	Nouvelle_chaine += a;
	printf(" %s\n", Nouvelle_chaine.Get_string());

	/*	printf(" %d",Nouvelle_chaine.size());
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

	//Operator = TEST:
	char * s = new char[3];

	s[1]='H';
	s[2]='I';
	s[3]='!';

	String MyTestString;
	printf("%s\n",MyTestString.operator=(s);

	delete [] s;



  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

