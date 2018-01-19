#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include "Shirts.h"
#include "colors.h"
#include "Embroids.h"
#include "BinarySearchTree.h"

class Executive
{
private:
  std::string snsCode;
  std::string productName;
  int purchaseRate;
  double casePrice;
  double dozenPrice;
  double piecePrice;
  std::string productCategory;
  int numberShirts;
  int cases;
  int dozens;
  int pieces;
  std::string distributorChoice;
  std::string fileName;
  std::string embroidery;
  double adding;

  double finalPrice;

  BinarySearchTree<std::string, Shirts>* shirtsTree;
  BinarySearchTree<std::string, Embroids>* embroidsTree;
  BinarySearchTree<std::string, colors>* colorsTree;

public:
  double embroideryCost(int number);
  double colorsCost(int number);
  Executive();
  void Distributor();
  void run();
  ~Executive();

};
#endif
