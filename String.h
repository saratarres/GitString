//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __STRING__H__
#define __STRING_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <string.h>



// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================






class String
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    String(void);

    //Copy constructor 
    String (const String& stringacopier);
    
    //constructor c_tring
    String(const char* c_string);

		


    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~String(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    size_t Get_capacity (void) const;
    size_t size(void) const ;
    size_t length(void) const; //size and length are twin brother :) 
    size_t max_size(void) const;

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

      //Declaration of reserve (capacity setter only if needed)
        void reserve (size_t n);

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
		

		void clear();

    //Declaration of c_str() Method
		const char* c_str() const;


    //Declaration of empty Method
      //if length is 0 returns 0, if not returns 1.
        size_t empty ();

    //Operator =
        String& operator= (const char* s);

        String& operator= (const String& str);

	//Declaration of resize methode ! 
	void resize(size_t n);







    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Template_class(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
		//String(const String &String)
    //{
      //printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
     // exit(EXIT_FAILURE);
    //};


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================


	size_t length;
	static size_t MAX_SIZE;
	char* _string;
	size_t capacity;

};



// ===========================================================================
//                              Getters' definitions
// ===========================================================================




// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __STRING_H__

