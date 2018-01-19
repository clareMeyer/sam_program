/*Name: Clare Meyer
 *Class: EECS268
 *professor: Gibbons
 *Lab: Surya Tej Nimmakayala, Fri 9:00AM
 *DuplicateEntryError.cpp
 *description:this is the implementation of the DuplicateEntryError class
 */

#include "DuplicateEntryError.h"
#include <string>

//precondition: the DuplicateEntryError has not been defined
//postcondition: the DuplicateEntryError has been declared
//return type: none
DuplicateEntryError::DuplicateEntryError(const string& message): logic_error(message)
{

}
