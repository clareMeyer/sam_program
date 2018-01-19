/*Name: Clare Meyer
 *Class: EECS268
 *professor: Gibbons
 *Lab: Surya Tej Nimmakayala, Fri 9:00AM
 *NotFoundException.cpp
 *description:this is the implementation of the NotFoundException class
 */

#include "NotFoundException.h"
#include <string>

//precondition: the PrecondViolatedExcep has not been defined
//postcondition: the PrecondViolatedExcep has been declared
//return type: none
NotFoundException::NotFoundException(const string& message): logic_error(message)
{

}
