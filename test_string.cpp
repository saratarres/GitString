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
	String Nouvelle_chaine = String();
	/*	printf(" %d",Nouvelle_chaine.size());
	int res = Nouvelle_chaine.empty(3);
	printf("%d\n",res);
	res = Nouvelle_chaine.empty(0);
	printf("%d\n",res);*/
    
    String NewString = String("holachicos");
    NewString.resize(4);
	printf("%d\n",NewString.size());
	printf("%d\n",NewString.at(4));

	NewString.resize(8);
	printf("%d\n",NewString.size());
	printf("%d\n",NewString.at(4));

	//printf(" %d\n",Nouvelle_chaine.size());

	//Nouvelle_chaine.clear();
	//printf(" %d",Nouvelle_chaine.size());



  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

