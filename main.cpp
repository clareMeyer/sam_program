//main.cpp

#include "Executive.h"
#include <iostream>
#include <string>

int main()
{
        //safeguard for if the required information was not passed in
        /*if(argc< 2)
        {
                std::cout<<"You need two parameters"<<'\n';
        }*/
        //if all information needed was there this runs
      //  else
      //  {
                //reads the first argument passed as the fileName of the txt file
                //std::string fileName=argv[1];
                //calls the executive class and created an instance where the information from that class is executed

                Executive e1;
                //running the program
                e1.run();
      //  }
        return(0);
}
