#include "Embroids.h"
#include <string>

Embroids::Embroids()
{

}

std::string Embroids::getType()
{
  return(m_type);
}
double Embroids::getFirst()
{
  return(m_firstPrice);
}

double Embroids::getSecond()
{
  return(m_secondPrice);
}

double Embroids::getLast()
{
  return(m_lastPrice);
}

Embroids::Embroids(std::string type, double firstPrice, double secondPrice, double lastPrice)
{
  m_type=type;
  m_firstPrice=firstPrice;
  m_secondPrice=secondPrice;
  m_lastPrice=lastPrice;
}

Embroids::Embroids(const Embroids& original)
{
  m_type=original.m_type;
  m_firstPrice=original.m_firstPrice;
  m_secondPrice=original.m_secondPrice;
  m_lastPrice=original.m_lastPrice;
}


bool Embroids::operator==(const std::string& type)
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

bool Embroids::operator>(const std::string& type)
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
bool Embroids::operator<(const std::string& type)
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
bool Embroids::operator<(const Embroids& embroids)
{
  std::string hold=embroids.m_type;

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
bool Embroids::operator>(const Embroids& embroids)
{

  std::string hold=embroids.m_type;

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
bool Embroids::operator==(const Embroids& embroids)
{
  std::string hold=embroids.m_type;

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
void Embroids::operator=(const Embroids& rhs)
{
  m_type=rhs.m_type;
  m_firstPrice=rhs.m_firstPrice;
  m_secondPrice=rhs.m_secondPrice;
  m_lastPrice=rhs.m_lastPrice;
}
