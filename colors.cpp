#include "colors.h"
#include <string>

colors::colors()
{

}

std::string colors::getType()
{
  return(m_type);
}
double colors::getFirst()
{
  return(m_firstPrice);
}

double colors::getSecond()
{
  return(m_secondPrice);
}

double colors::getThird()
{
  return(m_thirdPrice);
}
double colors::getFourth()
{
  return(m_fourthPrice);
}
double colors::getFifth()
{
  return(m_fifthPrice);
}
colors::colors(std::string type, double firstPrice, double secondPrice, double thirdPrice, double fourthPrice,
              double fifthPrice)
{
  m_type=type;
  m_firstPrice=firstPrice;
  m_secondPrice=secondPrice;
  m_thirdPrice=thirdPrice;
  m_fourthPrice=fourthPrice;
  m_fifthPrice=fifthPrice;
}

colors::colors(const colors& original)
{
  m_type=original.m_type;
  m_firstPrice=original.m_firstPrice;
  m_secondPrice=original.m_secondPrice;
  m_thirdPrice=original.m_thirdPrice;
  m_fourthPrice=original.m_fourthPrice;
  m_fifthPrice=original.m_fifthPrice;
}


bool colors::operator==(const std::string& type)
{
  std::string hold=type;

  //boost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_type.compare(hold)==0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

bool colors::operator>(const std::string& type)
{
  std::string hold=type;

  //boost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_type.compare(hold)>0)
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
bool colors::operator<(const std::string& type)
{
  std::string hold=type;

  //boost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_type.compare(hold)<0)
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
bool colors::operator<(const colors& theColors)
{
  std::string hold=theColors.m_type;

  //boost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_type.compare(hold)<0)
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
bool colors::operator>(const colors& theColors)
{

  std::string hold=theColors.m_type;

  //boost::to_lower(m_name);
  //boost::to_lower(hold );

  if(m_type.compare(hold)>0)
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
bool colors::operator==(const colors& theColors)
{
  std::string hold=theColors.m_type;

  //oost::to_lower(m_name);
  //boost::to_lower(hold);

  if(m_type.compare(hold)==0)
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
void colors::operator=(const colors& rhs)
{
  m_type=rhs.m_type;
  m_firstPrice=rhs.m_firstPrice;
  m_secondPrice=rhs.m_secondPrice;
  m_thirdPrice=rhs.m_thirdPrice;
  m_fourthPrice=rhs.m_fourthPrice;
  m_fifthPrice=rhs.m_fifthPrice;
}
