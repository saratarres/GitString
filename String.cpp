//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "String.h"
#include <string.h>




//############################################################################
//                                                                           #
//                           Class String                                    #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
size_t String::MAX_SIZE=100;
// ===========================================================================
//                                  Constructors
// ===========================================================================
String::String(void)
{
	length = 0;
	_string = NULL;
	capacity = 0;
}

String::String (const String& str)
{

	length = str.size();
	//_string = str.c_string();
	capacity = str.Get_capacity();
	
}

String::String(const char* c_string)
{
	size_t i=0;
	size_t j=0;
	while(c_string[i]!='\0'){
	  i++;
	}
	length = i;
	capacity = i*sizeof(char);
	_string = new char [i];
        for(j=0;j<i;j++){
	  _string[j]=c_string[j];
	}

}

// ===========================================================================
//                                  Destructor
// ===========================================================================
String::~String(void)
{
  delete _string;
  _string = NULL ;
  length = 0;
  capacity = 0;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

char* String::at(size_t pos)
{
  return &(_string[pos]);
}


void String::resize(size_t n)
{
  int i;
  char* new_string = new char[n];
  for(i=0;i<n;i++)
  {
  new_string[i]=_string[i];
  }
  delete _string;
  _string = new char[n];
  for(i=0;i<n;i++)
  {
   _string[i]=new_string[i];
  }
  delete new_string;
  length=n;

}

size_t String::size(void) const
{
  return length;
}
                
size_t String::Get_length(void) const
{
  return length;
}
size_t String::max_size(void) const
{
  return MAX_SIZE;
}
		
size_t String::Get_capacity (void) const
{
  return capacity;
}

size_t String::empty()
{
  if(size()==0)
  {
    return 0;
  }
  if (size()!=0){
    return 1;
  }
}


void String::reserve (size_t n)
{
  if (capacity<n){
  capacity=n;
  }
}


void String::clear(void)
{
  length = 0;
}


//Implementation of _str() methods

	const char* String::c_str() const {

		size_t i;		
		char* cstr = new char [ length +1 ];
		cstr [length + 1] = '\0';
		
		for (i=0; i<length+1 ;i++){	
		  cstr[i] = _string[i];
		}

				
		return cstr;

	}

// Operator =

/*String& String :: operator= (const char* s){

		String& new_string = String& String(s);
		
		size_t i=0;
		
		while (s[i]!='\0'){
			new_string.length = new_string.length + 1;
			i++;
		}
		//reserve(0);
		new_string._string = new char[capacity + 1]; 
		
		for (size_t j=0;j<length+1;j++){
			new_string._string[j]=s[j];
		}
		//reserve(0);


		return new_string;

	}
		

String& String :: operator= (const String& str)
{

	  _string = str._string ;
		
		return str ;
}

		
*/

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
