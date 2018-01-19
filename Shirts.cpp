#include "Shirts.h"
#include <string>

Shirts::Shirts()
{

}

Shirts::Shirts(std::string snsCode, std::string productName, int purchaseRate, double casePrice, double dozenPrice
                , double piecePrice, std::string productCategory)
{
  m_snsCode=snsCode;
  m_productName=productName;
  m_purchaseRate=purchaseRate;
  m_casePrice=casePrice;
  m_dozenPrice=dozenPrice;
  m_piecePrice=piecePrice;
  m_productCategory=productCategory;
}

Shirts::Shirts(const Shirts& original)
{
  m_snsCode=original.m_snsCode;
  m_productName=original.m_productName;
  m_purchaseRate=original.m_purchaseRate;
  m_casePrice=original.m_casePrice;
  m_dozenPrice=original.m_dozenPrice;
  m_piecePrice=original.m_piecePrice;
  m_productCategory=original.m_productCategory;
}

std::string Shirts::getProductName()
{
  return(m_productName);
}

double Shirts::getCasePrice()
{
  return(m_casePrice);
}

double Shirts::getDozenPrice()
{
  return(m_dozenPrice);
}

double Shirts::getPiecePrice()
{
  return(m_piecePrice);
}

int Shirts::getPurchaseRate()
{
  return(m_purchaseRate);
}

bool Shirts::operator==(const std::string& ShirtCode)
{
  std::string hold=ShirtCode;

  //boost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_snsCode.compare(hold)==0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

bool Shirts::operator>(const std::string& ShirtCode)
{
  std::string hold=ShirtCode;

  //boost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_snsCode.compare(hold)>0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

//precondition: cannot compare game to string
//postcondition: can compare game to string if <
//returnType: bool
bool Shirts::operator<(const std::string& ShirtCode)
{
  std::string hold=ShirtCode;

  //boost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_snsCode.compare(hold)<0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

//precondition: cannot compare game to game
//postcondition: can compare game to game if <
//returnType: bool
bool Shirts::operator<(const Shirts& shirts)
{
  std::string hold=shirts.m_snsCode;

  //boost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_snsCode.compare(hold)<0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

//precondition: cannot compare game to game
//postcondition: can compare game to game if >
//returnType: bool
bool Shirts::operator>(const Shirts& shirts)
{

  std::string hold=shirts.m_snsCode;

  //boost::to_lower(m_name);
  //boost::to_lower(hold );

  if(m_snsCode.compare(hold)>0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

//precondition: cannot compare game to game
//postcondition: can compare game to game if ==
//returnType: bool
bool Shirts::operator==(const Shirts& shirts)
{
  std::string hold=shirts.m_snsCode;

  //oost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_snsCode.compare(hold)==0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

//precondition: cannot compare game itself
//postcondition: can compare game to itself
//returnType: bool
void Shirts::operator=(const Shirts& rhs)
{
  m_snsCode=rhs.m_snsCode;
  m_productName=rhs.m_productName;
  m_purchaseRate=rhs.m_purchaseRate;
  m_casePrice=rhs.m_casePrice;
  m_dozenPrice=rhs.m_dozenPrice;
  m_piecePrice=rhs.m_piecePrice;
  m_productCategory=rhs.m_productCategory;
}
