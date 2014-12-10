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
    int Get_capacity (void) const;
    int size(void) const ;
    int length(void) const; //size and length are twin brother :) 
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
		

		void clear();

    //Declaration of c_str() Method
		const char* c_str() const;

		//declaration of of operatoir Method

		String& operator= (const String& str);


	
	//Declaration of clear Method
		//void clear(void);

        //Declaration of empty Method
          //if length is 0 returns 0, if not returns 1.
        int empty ();

        //Declaration of reserve
        void reserve (int n);





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


	int length;
	static int MAX_SIZE;
	char* _string;
	int capacity;

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

