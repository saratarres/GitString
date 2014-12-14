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
  size_t i;
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

char* String :: Get_string(void) const 
{

	return _string;
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

/* This method stores a string in the Heap with the content of the ancient one but
with the new capacity.
Parameter: n that's the value that we want as capacity.
Return: no return
*/
void String::reserve (size_t n)
{
  if (n>MAX_SIZE){
  	printf("ERROR\n");
  	printf("The string will exceed MAX_SIZE.\n");

  }

  if (n<MAX_SIZE && capacity<n){
  capacity=n;
  char * tmp = new char [capacity];
  size_t i;

  //Read the original string and we copy the chars into a temporary one.
  for (i=0; i<length; i++){
  	tmp[i]=_string[i];
  }
  while(i>=length && i<capacity){
  	tmp[i]='0';
  }
  
  //Write a copy of the temporary string into the real one
  _string=new char[n];
  length=n;
  for(i=0;i<n;i++){
  	_string[i]=tmp[i];
  }
  delete[] tmp; 
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


//Implementation of Operator= Student 1

String& String :: operator= (const String& str)
{

//Recovering size of str 

  int taille = str->length();
  int i;


// Verification that the size is not longer than MAX_SIZE

  if (taille > MAX_SIZE)
    {
    printf("The length is too long !!!");
    return *this ;
    }

// Verification that the size is not more longer than capacity

  else if (taille < MAX_SIZE && taille > capacity)
    {
    printf("The length is longer than the capacity !!");
    this->reserve(taille);
    
    for (i=0;i<taille;i++)
      {
		_string[i] = str.Get_string()[i];
      }
  	 return *this;
  }


// Replace string b by string a 

  else {
    for(i=0;i<this->length;i++){
      _string[i] =str.Get_string()[i];
    }

    return *this;
  }
    
    
}


//Implementation of operator+= methods 

String& String :: operator+= (char c) 
{

//Creation of new string 

  String my_new_string = String();
  my_new_string.capacity = this.capacity();
  my_new_string.length = this.size() +1 ;

  int i;

//Replace the character of this in my_new_string

  for (i =0;i< this->size();i++){
    my_new_string->c_str()[i] = this->c_str()[i];
  }

//Add char c

  my_new_string->c_str()[length] = c;
  
  return my_new_string;

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

		length = str.length;
		reserve(length);
	  _string = str._string ;
		
		return _string ;
}

		
*/

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
