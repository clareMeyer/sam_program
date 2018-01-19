/*Name: Clare Meyer
 *Class: EECS268
 *professor: Gibbons
 *Lab: Surya Tej Nimmakayala, Fri 9:00AM
 *BinarySearchTree.hpp
 *description:this is the implementation of the BinarySearchTree class
 */
#include "BinarySearchTree.h"
#include "Shirts.h"
#include "PrecondViolatedExcep.h"
#include "DuplicateEntryError.h"
#include "BinaryNode.h"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

//////////////////////
//protected methods//
////////////////////

//precondition: do not know the height of the tree
//postcondition: do know the height of the tree
//returnType: int
//called by the public find height method
template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::findHeightHelper(BinaryNode<ItemType>* treePtr) const
{
  //if the root is null there are 0 levels
  if(treePtr==nullptr)
  {
    return(0);
  }
  else
  {
    //return one for the root and add for every level after that
    return(1+max(findHeightHelper(treePtr->getLeftChildPtr()), findHeightHelper(treePtr->getRightChildPtr())));
  }
}

//precondition: do not know the number of nodes in the tree
//postcondition: do know the number of nodes in the tree
//returnType: int
template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::counter(BinaryNode<ItemType>* treePtr) const
{
  //if the root is null there are no nodes in the tree
  if(treePtr==nullptr)
  {
    return(0);
  }
  else
  {
    //return one for the root and add one to every node that comes after that
    return(1+counter(treePtr->getLeftChildPtr())+counter(treePtr->getRightChildPtr()));
  }
}

//precondition: the tree does not have a deep copy
//postcondition: the tree has a deep copy
//returnType: BinaryNode<ItemType>*
//this is called from the copyconstructor
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::copyTree(BinaryNode<ItemType>* treePtr)
{
  //BinaryNode<ItemType>* treeCopy=nullptr;//create a binary node pointer
  treeCopy=nullptr;

  if(treePtr)//if tree pointer is not null
  {
    treeCopy=new BinaryNode<ItemType>(treePtr->getItem());//start creating deep copy of the
    //tree node by node

    treeCopy->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));//copy left
    treeCopy->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));//copy right
  }
  return(treeCopy);//return the deep copy of the tree
}

//precondition: tree is still allocated on the heap
//postcondidiont: tree and all of its nodes are dealloacted from the heap
//return type: void
//called from the destructor
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
  if(subTreePtr!=nullptr)//while the root is not a nullptr
 {
   //get to the last children in the tree
   if(subTreePtr->getLeftChildPtr()!=nullptr)
   {
     destroyTree(subTreePtr->getLeftChildPtr());
   }
   //subTreePtr->setLeftChildPtr(nullptr);
   if(subTreePtr->getRightChildPtr()!=nullptr)
   {
     destroyTree(subTreePtr->getRightChildPtr());
   }
   //subTreePtr->setRightChildPtr(nullptr);

   //delete that child
   //removeNode(subTreePtr);
   delete subTreePtr;
 }
 else if(subTreePtr==nullptr)
 {
   //once you are back at the root with no children, delete the root
   //delete removeNode(subTreePtr);
   delete subTreePtr;
 }
 //delete temp;
}

//precondition: do not know if the node is currently in the tree or not
//postcondition: know if the desired value is in the tree or not
//return type: bool
//returns true if is in tree, this is used in the public add function to make sure
//there are no dupicates
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::findingNode(BinaryNode<ItemType>* subTreePtr, ItemType key) const
{
  if(subTreePtr==nullptr)//if the root is null return null
  {
    return(false);
  }
  else if(subTreePtr->getItem()==key)//if the node item is equal to the item desired
  {
    return(true);
  }
  else if(subTreePtr->getItem()<key)//if if it is greater than searh the right
  {
    return(findingNode(subTreePtr->getRightChildPtr(), key));
  }
  else if(subTreePtr->getItem()>key)//if it is less than search right
  {
    return(findingNode(subTreePtr->getLeftChildPtr(), key));
  }
  return(false);//return false if it is not found
}

//precondition: node is not inserted in the correct place
//postcondition: node is inserted in the correct place
//returnType: BinaryNode<ItemType>*
//this is called from the public add function
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                    BinaryNode<ItemType>* newNode)
{
  if(subTreePtr==nullptr)//if the root is null return the new node
  {
    return(newNode);
  }
  else if(subTreePtr->getItem()>newNode->getItem())//if the current node is greater than
  //the new node insert it into the left
  {
    temp=insertInorder(subTreePtr->getLeftChildPtr(), newNode);//find the appropriate place for the node
    subTreePtr->setLeftChildPtr(temp);//set the place
  }
  else
  {
    temp=insertInorder(subTreePtr->getRightChildPtr(), newNode);//find the appropriate place for the node
    subTreePtr->setRightChildPtr(temp);//put the node in that place
  }
  return(subTreePtr);//return the parent of the node inserted

}

//precondition: the value is in the node
//postcondition: the value is not in the node any longer
//returnType: BinaryNode<ItemType>*
//this is called from the public remove function
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
                                    KeyType target,
                                    bool& success)
{
  if(subTreePtr==nullptr)
  {
    success=false;
  }
  else if(subTreePtr->getItem()==target)
  {
    //item is in the root of some tree
    subTreePtr=removeNode(subTreePtr);
    success=true;
  }
  else if(subTreePtr->getItem()>target)
  {
    //search the left subtree
    temp=removeValue(subTreePtr->getLeftChildPtr(), target, success);
    subTreePtr->setLeftChildPtr(temp);
  }
  else
  {
    //search right subtree
    temp=removeValue(subTreePtr->getRightChildPtr(), target, success);
    subTreePtr->setRightChildPtr(temp);
  }
  return(subTreePtr);
}

//precondition: the node is still in the tree
//postcondition: the node is no longer in the tree
//returnType: BinaryNode<ItemType>*
//protected removeValue method
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
  //BinaryNode<ItemType>* connectionNode;
  if(nodePtr->isLeaf()==true)
  {
    //delete nodePtr->getItem();
    delete nodePtr;
    return(nullptr);
  }
  else if(nodePtr->getLeftChildPtr()==nullptr||nodePtr->getRightChildPtr()==nullptr)
  {
    if(nodePtr->getLeftChildPtr()!=nullptr)
    {
      //has a left child
      temp=nodePtr->getLeftChildPtr();
    }
    else
    {
      //has right child
      temp=nodePtr->getRightChildPtr();
    }
    return(temp);
  }
  else if(nodePtr->getLeftChildPtr()!=nullptr&&nodePtr->getRightChildPtr()!=nullptr)
  {
    //has two children
    ItemType newNodeValue;
    temp= removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);

    nodePtr->setRightChildPtr(temp);
    nodePtr->setItem(newNodeValue);
    return(nodePtr);
  }
  return(nodePtr);
}

//precondition: the leftmostnode is still in the tree
//postcondition: the leftmostNode is no longer in the tree
//returnType: BinaryNode<ItemType>*
//called from the protected removeNode method
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
                                         ItemType& inorderSuccessor)
{
  if(subTreePtr->getLeftChildPtr()==nullptr)
  {
    //if the next left child is null ponter
    inorderSuccessor=subTreePtr->getItem();
    subTreePtr=removeNode(subTreePtr);
    return subTreePtr;
  }
  else
  {
    //get the leftmost node and put the value that should be removed there and then
    //remove that node
    temp=removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
    subTreePtr->setLeftChildPtr(temp);
    return(subTreePtr);
  }
}

//precondition: the node is not found
//postcondition: the node is found or error is thrown if node does not exist
//returnType: BinaryNode<ItemType>*
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::findNode(BinaryNode<ItemType>* treePtr, KeyType key) const
{
  //if the root is null pointer no need to look in rest of tree
  if(treePtr==nullptr)
  {
    return(treePtr);
  }
  //if it is equal to what you are looking for return that
  else if(treePtr->getItem()==key)
  {
    return(treePtr);
  }
  //if it is less than what you are looking for search right
  else if(treePtr->getItem()<key)
  {
    return(findNode(treePtr->getRightChildPtr(), key));
  }
  //if it is greater tahn what you are looking for search left
  else if(treePtr->getItem()>key)
  {
    return(findNode(treePtr->getLeftChildPtr(), key));
  }
  else
  {
    return(nullptr);
  }
}

////////////////////////////////////////
// Recursive traversal helper methods://
////////////////////////////////////////

//precondition: the tree has not been travered in the preorder Way
//postcondtion: the tree has been traversaled
//returnType: void
//traverses the tree by printing first then traversing then traversing
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr!=nullptr)
  {
    Shirts s1=treePtr->getItem();
    //visit the node looking at
    visit(s1);

    //traverse left
    preorder(visit, treePtr->getLeftChildPtr());
    //traverse right
    preorder(visit, treePtr->getRightChildPtr());
  }
  else if(treePtr==nullptr)
  {
    return;
  }
}

//precondition: the tree has not been travered in the inorder Way
//postcondtion: the tree has been traversed
//returnType: void
//traverses the tree by traversing then printing then traversing again
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr!=nullptr)
  {
    Shirts s1=treePtr->getItem();

    //traverse left
    inorder(visit, treePtr->getLeftChildPtr());

    //visit node at
    visit(s1);

    //traverse right
    inorder(visit, treePtr->getRightChildPtr());
  }
  else if(treePtr==nullptr)
  {
    return;
  }
}

//precondition: the tree has not been travered in the postorder Way
//postcondtion: the tree has been travered
//returnType: void
//traverses the tree by traversing both sides and then printing last
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr!=nullptr)
  {
    Shirts s1=treePtr->getItem();

    //traverse left
    postorder(visit, treePtr->getLeftChildPtr());
    //traverse right
    postorder(visit, treePtr->getRightChildPtr());
    //visit current node
    visit(s1);
  }
  else if(treePtr==nullptr)
  {
    return;
  }
}

////////////////////////////////////////
// Constructor and Destructor Section.//
////////////////////////////////////////

//precondition: binary search tree object has not been made, member variables not declared
//postcondition: binary search tree object has been made, member variables declared
//returnType: none
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
  //set root to nullptr if tree is empty
  rootPtr=nullptr;
  temp=nullptr;
  temp2=nullptr;
  treeCopy=nullptr;
}

//precondition: binary search tree with root not created yet
//postcondition: binary search tree is created with a root already exisiting
//returnType: none
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const ItemType& rootItem)
{
  //set root pointer to first node in the tree
  rootPtr=new BinaryNode<ItemType>(rootItem);
}

//this is the copy constructor
//precondition: the tree passed in has not been copied
//postcondition: the tree passed in has been copied
//returnType: none
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& tree)
{
  //make a deep copy of the bst that was passed in by value
  rootPtr=copyTree(tree.rootPtr);
}

//precondition: parts of the tree may still be allocated on the heap
//postcondidtion: anything left in the tree has been deallocated and destroyed
//returnType: none
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
  //destroy what nodes are left are left in the tree so that there are
  //no memory leaks

  //delete temp;
  //delete temp2;
  //delete rootPtr;
  //delete treeCopy;
  destroyTree(rootPtr);
}


 /////////////////////
 // Public Methods //
 ///////////////////

//precondition: do not know if tree is empty or not
//postcondition: do now if the tree is empty or nodeToDeletePtr
//returnType: none
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty() const
{
  //if the root is null the tree is empty
  if(rootPtr==nullptr)
  {
    return(true);
  }
  //otherwise the tree is not empty
  return(false);
}

//precondition: do not know the height of the tree
//postcondition: know the height of the tree
//returnType: int
template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeight() const
{
  //if the root is nullptr the tree is empty the height is zero
  if(rootPtr==nullptr)
  {
    return(0);
  }
  else
  {
    //call this helper method to add up the levels of the tree
    return(findHeightHelper(rootPtr));
  }
}

//precondition: do not know the number of nodes in the tree
//postcondition: know the number of nodes in the tree
//returnType: int
template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodes() const
{
  //call the helper method to add up the number of nodes in the tree
  return(counter(rootPtr));
}

//precondition: do not know what data is in the root
//postcondition: know what data is in the root
//returnType: ItemType
template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<KeyType, ItemType>::getRootData() const throw(PrecondViolatedExcep)
{
  //if the root is null the tree is empty there is no data to give
  if(rootPtr==nullptr)
  {
    throw PrecondViolatedExcep("there is no data in this root");
  }
  //if the root is not empty return the data in the root
  return(rootPtr->getItem());
}

//precondition: the root data has not been set
//postcondition: the root data has been set
//returnType: void
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::setRootData(const ItemType& newData) const throw(PrecondViolatedExcep)
{
  if(rootPtr==nullptr)
  {
    //throw an exception if trying to set data to a node that does not exist
    throw PrecondViolatedExcep("A node has to exist before you can set its data");
  }
  rootPtr->setItem(newData);
}

//precondition: do not know what contains
//postcondition: know what contains
//returnType: bool
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::contains(const KeyType& anEntry) const
{
  //if the node contains keyType that you are looking for return true
  if(findNode(rootPtr, anEntry)==nullptr)
  {
    return(false);
  }
  else if(findNode(rootPtr, anEntry)->getItem()==anEntry)
  {
    return(true);
  }
    //otherwise return false
    return(false);
}

//precondition: the new node has not been added to the tree
//postcondition: the new node has been added to the tree
//returnType: bool
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::add(const ItemType& newEntry)
{
  temp=new BinaryNode<ItemType>(newEntry);
  //if you find that a node holding the entry already exists, throw error
  if(findingNode(rootPtr, newEntry)==true)
  {
    delete temp;
    throw DuplicateEntryError();
  }
  else if(rootPtr==nullptr)
  {
    rootPtr=insertInorder(rootPtr, temp);
    return(true);
  }

  //if it is not already in the tree insert it into the tree
  rootPtr=insertInorder(rootPtr, temp);
  //return true because value was added
  //delete temp;
  return(true);
}

//precondition: the node is in the tree
//postcondition: the node is no longer in the tree, has been deallocated
//returnType: bool
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(const KeyType& anEntry)
{
  //starting false
  bool isSuccessful=false;
  //remove the value
  if(contains(anEntry)==false)
  {
    throw NotFoundException("This node is not in the tree, cannot be removed");
  }
  else
  {
    rootPtr=removeValue(rootPtr, anEntry, isSuccessful);
  }
  //return if the remove was sucessful
  return(isSuccessful);
}

//precondition:do not know if the entry is in the tree
//postcondition: know if the entry is in the tree
//returnType: ItemType
template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<KeyType, ItemType>::getEntry(const KeyType& anEntry) const throw(NotFoundException)
{
  //if the entry is in the tree return that entry
  if(findNode(rootPtr, anEntry)==nullptr)
  {
    throw NotFoundException("the entry was not found");
  }
  return(findNode(rootPtr, anEntry)->getItem());
  //otherwise throw an error because this entry is not in the tree

}

//precondition: the tree has not been cleared
//postcondition: the tree has been cleared
//returnType: void
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clear()
{
  //did not use this one in the tree, not sure what it wanted me to clear
  //was told no points would be taken off if method not used was not defined
}

//////////////////////
//public traversals//
////////////////////

//precondition: the tree has not been traversed
//postcondition: the tree has been traversed
//returnType: void
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  preorder(visit, rootPtr);
}

//precondition: the tree has not been traversed
//postcondition: the tree has been traversed
//returnType: void
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  inorder(visit, rootPtr);
}

//precondition: the tree has not been traversed
//postcondition: the tree has been traversed
//returnType: void
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------

//precondition: BinarySearchTree and BinarySearchTree are set equal to each other
//postconditin: they are compared by their root pointers
//returnType: BinarySearchTree<KeyType, ItemType> by reference
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::operator=(const BinarySearchTree<KeyType, ItemType>& rightHandSide)
{
  rootPtr=rightHandSide.rootPtr;
}
