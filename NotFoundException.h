/*Name: Clare Meyer
 *Class: EECS268
 *professor: Gibbons
 *Lab: Surya Tej Nimmakayala, Fri 9:00AM
 *NotFoundException.h
 *description:this is the header file for the NotFoundException class
 */

#ifndef NOTFOUNDEXCEPTION
#define NOTFOUNDEXCEPTION

#include <stdexcept>
#include <string>

using namespace std;

class NotFoundException : public logic_error
{
public:
   //precondition: there has not been an error found becuase the item was not found
   //postcondition: an error was found and dealt with
   //returnType: none
   NotFoundException(const string& message = "");
}; // end PrecondViolatedExcep
#endif
