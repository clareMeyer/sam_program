
#ifndef EMBROIDS_H
#define EMBROIDS_H
#include <string>
using namespace std;
class Embroids
{
private:
  std::string m_type;
  double m_firstPrice;
  double m_secondPrice;
  double m_lastPrice;
public:
  Embroids(std::string type, double firstPrice, double secondPrice, double lastPrice);
  Embroids(const Embroids& original);
  double getFirst();
  double getSecond();
  double getLast();
  std::string getType();
  Embroids();
  void operator=(const Embroids& rhs);
  bool operator==(const std::string& type);
  bool operator<(const std::string& type);
  bool operator>(const std::string& type);
  bool operator==(const Embroids& embroids);
  bool operator<(const Embroids& embroids);
  bool operator>(const Embroids& embroids);

  //~Shirts();

};
#endif
