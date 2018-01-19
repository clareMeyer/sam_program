
#ifndef SHIRTS_H
#define SHIRTS_H
#include <string>
using namespace std;
class Shirts
{
private:
  std::string m_snsCode;
  std::string m_productName;
  int m_purchaseRate;
  double m_casePrice;
  double m_dozenPrice;
  double m_piecePrice;
  std::string m_productCategory;
public:
  Shirts(std::string snsCode, std::string productName, int purchaseRate, double casePrice, double dozenPrice
                  , double piecePrice, std::string productCategory);
  Shirts(const Shirts& original);
  Shirts();
  void operator=(const Shirts& rhs);
  bool operator==(const std::string& ShirtCode);
  bool operator<(const std::string& ShirtCode);
  bool operator>(const std::string& ShirtCode);
  bool operator==(const Shirts& shirts);
  bool operator<(const Shirts& shirts);
  bool operator>(const Shirts& shirts);
  std::string getProductName();
  double getCasePrice();
  double getDozenPrice();
  double getPiecePrice();
  int getPurchaseRate();

  //~Shirts();

};
#endif
