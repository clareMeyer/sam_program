/*Name: Clare Meyer
 *Class: EECS268
 *professor: Gibbons
 *Lab: Surya Tej Nimmakayala, Fri 9:00AM
 *DuplicateEntryError.h
 *description:this is the header file for the DuplicateEntryError class
 */

#ifndef DUPLICATE_ENTRY_ERROR
#define DUPLICATE_ENTRY_ERROR

#include <stdexcept>
#include <string>

using namespace std;

class DuplicateEntryError : public logic_error
{
public:

  //precondition: the DuplicateEntryError has not been defined
  //postcondition: the DuplicateEntryError has been declared
  //return type: none
   DuplicateEntryError(const string& message = "");
}; // end DuplicateEntryError
#endif
