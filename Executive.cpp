#include "Executive.h"
#include "Shirts.h"
#include "colors.h"
#include "Sorts.h"
#include "Embroids.h"
//#include "BinarySearchTree.h"
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

Executive::Executive()
{
  adding=0;
  snsCode="null";
  productName="null";
  purchaseRate=0;
  casePrice=0.0;
  dozenPrice=0.0;
  piecePrice=0.0;
  productCategory="null";
  numberShirts=0;
  cases=0;
  dozens=0;
  pieces=0;
  distributorChoice="null";
  fileName="null";
  embroidery="null";
  finalPrice=0.0;
}


void Executive::Distributor()
{
  ifstream inFile;

  inFile.open(fileName);

  std::string ppurchaseRate;
  std::string ccasePrice;
  std::string ddozenPrice;
  std::string ppiecePrice;

  int stop=0;
  int check=0;
  std::string holding="null";

  int i=0;
  while(!inFile.eof())
  {
    if(check==0)
    {
      getline(inFile, holding);
      check=1;
    }
    else
    {
      std::getline(inFile, snsCode, ',');

      if(inFile.peek()=='"')
      {
        inFile.ignore(',','"');
        std::getline(inFile, productName, '"');
        std::getline(inFile, productName, ',');
      }
      else
      {
        std::getline(inFile, productName, ',');
      }

      std::getline(inFile, ppurchaseRate, ',');
      purchaseRate=std::stoi(ppurchaseRate);

      std::getline(inFile, ccasePrice, ',');
      casePrice=std::stod(ccasePrice);

      std::getline(inFile, ddozenPrice, ',');
      dozenPrice=std::stod(ddozenPrice);

      std::getline(inFile, ppiecePrice, ',');
      piecePrice=std::stod(ppiecePrice);

      std::getline(inFile, productCategory);

      if(stop==0)
      {
        Shirts s1;
        s1= Shirts(snsCode, productName, purchaseRate, casePrice, dozenPrice, piecePrice, productCategory);

        try
        {
          shirtsTree->add(s1);
        }
        catch(DuplicateEntryError& e)
        {
          e.what();
        }
      }

      i++;
    }
  }
  inFile.close();
}

double Executive::embroideryCost(int number)
{
  int stitch=0;

  embroidsTree=new BinarySearchTree<std::string, Embroids>();

  ifstream inFile;

  inFile.open("embroideryCosts.txt");

  std::string type;
  double first;
  double second;
  double last;

  std::string ffirst;
  std::string ssecond;
  std::string llast;
  std::string holding;

  int check=0;
  while(!inFile.eof())
  {
    if(check==0)
    {
      getline(inFile, holding);
      check=1;
    }

      inFile.ignore(',','"');
      std::getline(inFile, type, '"');
      inFile.ignore(',',',');

    std::getline(inFile, ffirst, ',');
    first=std::stod(ffirst);

    std::getline(inFile, ssecond, ',');
    second=std::stod(ssecond);

    std::getline(inFile, llast);
    last=std::stod(llast);


    Embroids E1;
    E1= Embroids(type, first, second, last);

    try
    {
      embroidsTree->add(E1);
    }
    catch(DuplicateEntryError& e)
    {
      e.what();
    }
  }
    inFile.close();

  std::cout<<"What type of embroidery? (10,000 stitches-15,000...): ";
  std::cin>>stitch;

  if(stitch==10000)
  {
    Embroids embro=embroidsTree->getEntry("10,000 stitches");

    if(number<1)
    {
      throw PrecondViolatedExcep("have to have at least one shirt");
    }
    else if(number<48)
    {
      double holding=0.0;
      holding=number*(embro.getFirst());
      std::cout<<holding<<'\n';
      return(number*(embro.getFirst()));
    }
    else if(number<286)
    {
      return(number*(embro.getSecond()));
    }
    return(number*(embro.getLast()));
  }
  else if(stitch==11000)
  {
    Embroids embro=embroidsTree->getEntry("11,000 stitches");

    if(number<1)
    {
      throw PrecondViolatedExcep("have to have at least one shirt");
    }
    else if(number<48)
    {
      double holding=0.0;
      holding=number*(embro.getFirst());
      std::cout<<holding<<'\n';
      return(number*(embro.getFirst()));
    }
    else if(number<286)
    {
      return(number*(embro.getSecond()));
    }
    return(number*(embro.getLast()));
  }
  else if(stitch==12000)
  {
    Embroids embro=embroidsTree->getEntry("12,000 stitches");

    if(number<1)
    {
      throw PrecondViolatedExcep("have to have at least one shirt");
    }
    else if(number<48)
    {
      double holding=0.0;
      holding=number*(embro.getFirst());
      std::cout<<holding<<'\n';
      return(number*(embro.getFirst()));
    }
    else if(number<286)
    {
      return(number*(embro.getSecond()));
    }
    return(number*(embro.getLast()));
  }
  else if(stitch==13000)
  {
    Embroids embro=embroidsTree->getEntry("13,000 stitches");

    if(number<1)
    {
      throw PrecondViolatedExcep("have to have at least one shirt");
    }
    else if(number<48)
    {
      double holding=0.0;
      holding=number*(embro.getFirst());
      std::cout<<holding<<'\n';
      return(number*(embro.getFirst()));
    }
    else if(number<286)
    {
      return(number*(embro.getSecond()));
    }
    return(number*(embro.getLast()));
  }
  else if(stitch==14000)
  {
    Embroids embro=embroidsTree->getEntry("14,000 stitches");

    if(number<1)
    {
      throw PrecondViolatedExcep("have to have at least one shirt");
    }
    else if(number<48)
    {
      double holding=0.0;
      holding=number*(embro.getFirst());
      std::cout<<holding<<'\n';
      return(number*(embro.getFirst()));
    }
    else if(number<286)
    {
      return(number*(embro.getSecond()));
    }
    return(number*(embro.getLast()));
  }
  else if(stitch==15000)
  {
    Embroids embro=embroidsTree->getEntry("15,000 stitches");

    if(number<1)
    {
      throw PrecondViolatedExcep("have to have at least one shirt");
    }
    else if(number<48)
    {
      double holding=0.0;
      holding=number*(embro.getFirst());
      std::cout<<holding<<'\n';
      return(number*(embro.getFirst()));
    }
    else if(number<286)
    {
      return(number*(embro.getSecond()));
    }
    return(number*(embro.getLast()));
  }
  else
  {
    std::cout<<"thats not an option"<<'\n';
  }
  return(0);
}

double Executive::colorsCost(int number)
{
  std::string numColors="0";

  colorsTree=new BinarySearchTree<std::string, colors>();

  ifstream inFile;

  inFile.open("colorCost.txt");

  std::string type;
  double first;
  double second;
  double third;
  double fourth;
  double fifth;

  std::string ffirst;
  std::string ssecond;
  std::string tthird;
  std::string ffourth;
  std::string ffifth;

  std::string holding;

  int check=0;
  while(!inFile.eof())
  {
    if(check==0)
    {
      getline(inFile, holding);
      check=1;
    }

    std::getline(inFile, type, ',');

    std::getline(inFile, ffirst, ',');
    first=std::stod(ffirst);

    std::getline(inFile, ssecond, ',');
    second=std::stod(ssecond);

    std::getline(inFile, tthird, ',');
    third=std::stod(tthird);

    std::getline(inFile, ffourth, ',');
    fourth=std::stod(ffourth);

    std::getline(inFile, ffifth);
    fifth=std::stod(ffifth);


    colors C1;
    C1= colors(type, first, second, third, fourth, fifth);

    try
    {
      colorsTree->add(C1);
    }
    catch(DuplicateEntryError& e)
    {
      e.what();
    }
  }
    inFile.close();

  std::string stringColor;

  std::cout<<"How many colors? (1-6): ";
  std::cin>>numColors;
  std::cout<<'\n';

  colors daColor=colorsTree->getEntry(numColors);

  if(numberShirts<48)
  {
    return(number*(daColor.getFirst()));
  }
  else if(numberShirts<72)
  {
    return(number*(daColor.getSecond()));
  }
  else if(numberShirts<144)
  {
    return(number*(daColor.getThird()));
  }
  else if(numberShirts<288)
  {
    return(number*(daColor.getFourth()));
  }
  else
  {
    return(number*(daColor.getFifth()));
  }
  std::cout<<"thats not an option"<<'\n';
  return(0);
}

void Executive::run()
{
  shirtsTree=new BinarySearchTree<std::string, Shirts>();

  std::string emboridery="no";
  distributorChoice="null";

  std::cout<<"Pick Distributor (Alpha or SS): ";
  std::cin>>distributorChoice;

  if(distributorChoice=="Alpha")
  {
    fileName="alphaPriceList.txt";
  }
  else if(distributorChoice=="SS")
  {
    fileName="ssPriceList.txt";
  }
  else
  {
    throw NotFoundException("this is not a valid distributor");
  }

  std::string shirtChoice;

  Distributor();

  std::cout<<"SNS CODE: ";
  std::cin>>shirtChoice;

  std::cout<<"number of shirts: ";
  std::cin>>numberShirts;

  int shirtsLeft=numberShirts;

  if(shirtsTree->contains(shirtChoice)==true)
  {
    Shirts theShirt=shirtsTree->getEntry(shirtChoice);
    int numberInCase=theShirt.getPurchaseRate();
    double casePrice=theShirt.getCasePrice();
    double dozenPrice=theShirt.getDozenPrice();
    double piecePrice=theShirt.getPiecePrice();

    cases=numberShirts/numberInCase;
    shirtsLeft=shirtsLeft-(cases*numberInCase);
    dozens=shirtsLeft/12;
    shirtsLeft=shirtsLeft-(dozens*12);
    pieces=shirtsLeft;

    std::cout<<"cases: "<<cases<<'\n';
    std::cout<<"dozens: "<<dozens<<'\n';
    std::cout<<"pieces: "<<pieces<<'\n';

    std::cout<<'\n';
    std::cout<<"case price: "<<casePrice<<'\n';
    std::cout<<"dozen price: "<<dozenPrice<<'\n';
    std::cout<<"piece price: "<<piecePrice<<'\n';
    std::cout<<'\n';

    finalPrice=finalPrice+((cases*numberInCase)*casePrice)+((dozens*12)*dozenPrice)+(piecePrice*pieces);
  }

  std::string choiceHere="null";

  std::cout<<"heat, embroidery, or screenPrint: ";
  std::cin>>choiceHere;
  std::cout<<'\n';

  if(choiceHere=="embroidery")
  {
    try
    {
      std::cout<<"shirts number: "<<numberShirts<<'\n';
      try
      {
        adding=embroideryCost(numberShirts);
      }
      catch(NotFoundException& e)
      {
        e.what();
      }

    }
    catch(PrecondViolatedExcep& e)
    {
      e.what();
    }
    std::cout<<"cost of embroidery: "<<adding<<'\n';
    finalPrice=finalPrice+adding;
  }

  else if(choiceHere=="heat")
  {
    int number=0;
    std::cout<<"max location number: ";
    int maxLocations=0;
    std::cin>>maxLocations;

    double locations[maxLocations];

    for(int i=0; i<maxLocations; i++)
    {
      std::cout<<"number of shirts with location number "<<i+1<<": ";
      std::cin>>number;
      locations[i]=number;
      std::cout<<"locations: "<<i+1<<'\n';
      std::cout<<"shirts: "<<locations[i]<<'\n';

      locations[i]=(locations[i]*(i+1)*1.5);
      adding=adding+locations[i];
      std::cout<<adding<<'\n';
    }

    std::cout<<"cost of heat seal: $"<<adding<<'\n';
    finalPrice=finalPrice+adding;
  }

  else
  {
    adding=colorsCost(numberShirts);

    std::cout<<"amount added from colors page: $"<<adding<<'\n';
    finalPrice=finalPrice+adding;
  }

  std::cout<<"Final price: $"<<finalPrice<<'\n';
  std::cout<<"Price per shirt: $"<<finalPrice/numberShirts<<'\n';

}

Executive::~Executive()
{
  delete shirtsTree;

  if(embroidery=="yes")
  {
    delete embroidsTree;
  }
}
