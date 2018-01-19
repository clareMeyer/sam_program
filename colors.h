#ifndef COLORS_H
#define COLORS_H
#include <string>
using namespace std;
class colors
{
private:
  std::string m_type;
  double m_firstPrice;
  double m_secondPrice;
  double m_thirdPrice;
  double m_fourthPrice;
  double m_fifthPrice;

public:
  colors(std::string type, double firstPrice, double secondPrice, double thirdPrice, double fourthPrice,
        double fifthPrice);
  colors(const colors& original);
  double getFirst();
  double getSecond();
  double getThird();
  double getFourth();
  double getFifth();
  std::string getType();

  colors();
  void operator=(const colors& rhs);
  bool operator==(const std::string& type);
  bool operator<(const std::string& type);
  bool operator>(const std::string& type);
  bool operator==(const colors& theColors);
  bool operator<(const colors& theColors);
  bool operator>(const colors& theColors);

  //~Shirts();

};
#endif
