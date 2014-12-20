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

char* String::Get_string(void) const 
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
	_string = NULL ;
} 


//Implementation of c_str() methods

const char* String::c_str() const {

  size_t i;		
  char* cstr = new char [ length +1 ];
  cstr [length + 1] = '\0';
		
  for (i=0; i<length+1 ;i++){	
    cstr[i] = _string[i];
  }

				
   return cstr;

}

// =======================================================================
//                                Operators
// =======================================================================


//////////////////////////////////////////////////////////////////////////
//                        Implementation of Operator= methods
//////////////////////////////////////////////////////////////////////////


//Student 1

String& String :: operator= (const String& str)
{

//Recovering size of str 

  int taille = str.Get_length();
  int i;


// Verification that the size is not longer than MAX_SIZE

  if (taille > MAX_SIZE)
    {
    printf("The length is too long !!!\n");
    return *this ;
    }

// Verification that the size is not more longer than capacity

  else if (taille < MAX_SIZE && taille > capacity)
    {
    printf("The length is longer than the capacity !!\n");
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

String& String :: operator= (char c)
{
 
  //Creation of new string 

  String my_new_string = String();
  my_new_string.capacity = sizeof(char);
  my_new_string.length = 1 ;

  //introduce char c

  char* data= new char[2];
  data[0]='c';
  data[1]='\0';
  
  //return the string
  
  clear();
  
  this->_string=data;
  this->length=1;
  this->capacity=sizeof(char);



  return *this;
  
  
}
  


//Implementation of operator= Student 3


String& String :: operator= (const char* s){
    
    this->length=Get_length();
    
    reserve(this->length);

     this->_string = new char[this->length]; 
    
    for (size_t j=0;j<length;j++){
      _string[j]=s[j];
    }
    return *this;

  }




/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Implementation of operator+= methods
///////////////////////////////////////////////////////////////////////////////////////////// 

String& String :: operator+= (char c) 
{

//Creation of new string 


  //String my_new_string = String() ;
  //my_new_string.capacity = capacity;
  //my_new_string.length = length +1 ;

	char* my_new_string = new char [length + 2 ];

  int i;

//Replace the character of this in my_new_string

  for (i =0;i<length;i++){
    my_new_string[i] = _string[i];
  }

//Add char c

  //my_new_string [this-> size() +1] = 'c';
  my_new_string [length] = c ;
  my_new_string [length+1]= '\0';
	
	String* my_new_string2 =new String(my_new_string);
	printf(" %s\n", my_new_string2->Get_string());

	//*this=*my_new_string2;
	
  
  return *my_new_string2;

}

String& String:: operator+= (const char* s)
{
  //calcul de la longeur de la nouvelle chaîne

  size_t i=0;
  size_t j;
  while(s[i]!='\0'){
	  i++;
  }
  //creation of a new char* data

  char* data= new char[length+i+1];
  
  //put the _string in data 

  for (j =0;j<length;j++){
    data[j] = _string[j];
  }
  //add char* s to data

  for(j=length;j<length+i;j++){
    data[j] = s[j-length];
    
  }
  //add \0 for data to be a string
  data[length+i]='\0';
  
  size_t x = length+i;

  clear();
  this->_string=data;
  this->length=x;
  this->capacity=(length+i)*sizeof(char);



  return *this;



}


String& String:: operator+= (const String& str)
{
  // We get the length of the string we want to add.
  size_t length2=str.Get_length();


  size_t i;

  //We create a temporary stirng to save the information of the second string
  char * tmp = new char [length2];
  char * _s = str.Get_string();
  for (i = 0; i < length2; ++i)
  {
   tmp[i]=_s[i]; 
  }

  //We set the size of the new string
  size_t lengthplus=length+length2;

  //New _string for the string result
  char * _stringplus = new char [lengthplus];

  //We read and copy the first string
  for ( i=0; i < length ; i++)
  {
    _stringplus[i]=_string[i];
  }
  //We copy the temporary string after the end of the first one with i=length(of the first string)
  for (size_t j=0 ;j < length2; j++)
  {
    _stringplus[i]=tmp[j];
    i=i+1;
  }

  
  this->_string=_stringplus;
  this->length=lengthplus;
  this->capacity=lengthplus;

  delete [] tmp;
  delete [] _stringplus;

  return *this;
}


//Operator []: Returns the adress of a character located in a position send in 
//parameter:

char& String::operator[] (size_t pos)
{

  char* character;

  length=Get_length();

  _string=Get_string();

   size_t i;
   //We do pos-1 to have the first case of the array as number 1 instead of 0.
   --pos;

  if(pos>this->length-1){
    printf("ERROR position bigger than length\n");
    exit(EXIT_FAILURE);
  } else if(pos==this->length){
    character='\0';
    return *character;
  }else if (pos!= this->length){
    return _string[pos];
  }
}



// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
