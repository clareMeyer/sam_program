//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-5.
    @file PrecondViolatedExcep.h */

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
  
  //precondition: the PrecondViolatedExcep has not been defined
  //postcondition: the PrecondViolatedExcep has been declared
  //return type: none
   PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep
#endif
