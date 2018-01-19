/*Name: Clare Meyer
 *Class: EECS268
 *professor: Gibbons
 *Lab: Surya Tej Nimmakayala, Fri 9:00AM
 *BinaryNode.hpp
 *description:this is the implementation of the BinaryNode class
 */

#include "BinaryNode.h"

template<class ItemType>
BinaryNode<ItemType>::BinaryNode()
{

}

//precondition: member variables are not defined
//postCondition: member variables are defined
//returnType: none
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)//constructor
{
  //member variables
  item=anItem;
  leftChildPtr=nullptr;
  rightChildPtr=nullptr;
}

//precondition: member variables are not defined
//postCondition: member variables are defined
//returnType: none
//different becuase used if have values for left and right children
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
           BinaryNode<ItemType>* leftPtr,
           BinaryNode<ItemType>* rightPtr)//constructor
{
  //member variables
  item=anItem;
  leftChildPtr=leftPtr;
  rightChildPtr=rightPtr;
}

//precondition: node may or may not have a value
//postCondition: node has a new value
//returnType: void
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
  //set value passed in to memeber variable value
  item=anItem;
}

//precondition: do not know value of node
//postcondition: know value of know
//returnType: ItemType
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
  return(item);
}

//precondition: do not know if node is a leaf on the tree
//postcondition: know if the node is a leaf on the tree (leaf is node has no children)
//return type: bool
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
  //if the node has no left child and no right child, it is a leaf so return true
  if(leftChildPtr==nullptr&&rightChildPtr==nullptr)
  {
    return(true);
  }
  //otherwise you return false because it is not a leaf
  else
  {
    return(false);
  }
}

//precondition: do not know the left child pointer
//postcondition: know the left child pointer
//returnType: BinaryNode<ItemType>*
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
  return(leftChildPtr);
}

//precondition: do not know the right child pointer
//postcondition: know the right child pointer
//returnType: BinaryNode<ItemType>*
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
  return(rightChildPtr);
}

//precondition: the left child pointer may or may not hold a value
//postCondition: the left child pointer holds a new value
//return type: void
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
  leftChildPtr=leftPtr;
}

//precondition: the right child pointer may or may not hold a value
//postCondition: the right child pointer holds a new value
//return type: void
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
  rightChildPtr=rightPtr;
}

//precondition: the binary node member varibales have not been deallocated from the heap
//postcondition: the binary node member variables are no longer on the heap
//returnType: none
template<class ItemType>
BinaryNode<ItemType>::~BinaryNode()
{
  //delete leftChildPtr;
  //delete rightChildPtr;
}
