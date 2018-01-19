//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */

#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class ItemType>
class BinaryNode
{
private:
   ItemType              item;           // Data portion
   BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
   BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

public:
  //precondition: member variables are not defined
  //postCondition: member variables are defined
  //returnType: none
   BinaryNode(const ItemType& anItem);

   BinaryNode();

   //precondition: member variables are not defined
   //postCondition: member variables are defined
   //returnType: none
   //different becuase used if have values for left and right children
   BinaryNode(const ItemType& anItem,
              BinaryNode<ItemType>* leftPtr,
              BinaryNode<ItemType>* rightPtr);

  //precondition: the binary node member varibales have not been deallocated from the heap
  //postcondition: the binary node member variables are no longer on the heap
  //returnType: none
  ~BinaryNode();

  //precondition: node may or may not have a value
  //postCondition: node has a new value
  //returnType: void
  void setItem(const ItemType& anItem);

  //precondition: do not know value of node
  //postcondition: know value of know
  //returnType: ItemType
  ItemType getItem() const;

  //precondition: do not know if node is a leaf on the tree
  //postcondition: know if the node is a leaf on the tree (leaf is node has no children)
  //return type: bool
  bool isLeaf() const;

  //precondition: do not know the left child pointer
  //postcondition: know the left child pointer
  //returnType: BinaryNode<ItemType>*
  BinaryNode<ItemType>* getLeftChildPtr() const;

  //precondition: do not know the right child pointer
  //postcondition: know the right child pointer
  //returnType: BinaryNode<ItemType>*
  BinaryNode<ItemType>* getRightChildPtr() const;

  //precondition: the left child pointer may or may not hold a value
  //postCondition: the left child pointer holds a new value
  //return type: void
  void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);

  //precondition: the right child pointer may or may not hold a value
  //postCondition: the right child pointer holds a new value
  //return type: void
  void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
}; // end BinaryNode

#include "BinaryNode.hpp"

#endif
