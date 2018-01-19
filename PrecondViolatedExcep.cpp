/*Name: Clare Meyer
 *Class: EECS268
 *professor: Gibbons
 *Lab: Surya Tej Nimmakayala, Fri 9:00AM
 *PrecondViolatedExcep.cpp
 *description:this is the implementation of the PrecondViolatedExcep class
 */

#include "PrecondViolatedExcep.h"
#include <string>

//precondition: the PrecondViolatedExcep has not been defined 
//postcondition: the PrecondViolatedExcep has been declared
//return type: none
PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error(message)
{

}
