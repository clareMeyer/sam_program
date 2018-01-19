//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Modified by J. R. Miller to make it be a two-parameter template

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"
#include "DuplicateEntryError.h"
#include "BinaryNode.h"
#include "BinaryTreeInterface.h"

template<typename KeyType, typename ItemType>
class BinarySearchTree
{
private:
   BinaryNode<ItemType>* rootPtr;
   BinaryNode<ItemType>* temp;
   BinaryNode<ItemType>* temp2;
   BinaryNode<ItemType>* treeCopy;


protected:
   // Protected Utility Methods Section:

     /////////////////////////////////////////////////////
    // Recursive helper methods for the public methods.//
   /////////////////////////////////////////////////////
   //------------------------------------------------------------

   //precondition: do not know the number of nodes in the tree
   //postcondition: do know the number of nodes in the tree
   //returnType: int
   int counter(BinaryNode<ItemType>* treePtr) const;

   //precondition: do not know the height of the tree
   //postcondition: do know the height of the tree
   //returnType: int
   //called by the public find height method
   int findHeightHelper(BinaryNode<ItemType>* treePtr) const;

   //precondition: the tree does not have a deep copy
   //postcondition: the tree has a deep copy
   //returnType: BinaryNode<ItemType>*
   //this is called from the copyconstructor
   BinaryNode<ItemType>*  copyTree(BinaryNode<ItemType>* treePtr);

   //precondition: tree is still allocated on the heap
   //postcondidiont: tree and all of its nodes are dealloacted from the heap
   //return type: void
   //called from the destructor
   void destroyTree(BinaryNode<ItemType>* subTreePtr);

   //precondition: do not know if the node is currently in the tree or not
   //postcondition: know if the desired value is in the tree or not
   //return type: bool
   //returns true if is in tree, this is used in the public add function to make sure
   //there are no dupicates
   bool findingNode(BinaryNode<ItemType>* treePtr, ItemType key) const;

    //------------------------------------------------------------
   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.

   //precondition: node is not inserted in the correct place
   //postcondition: node is inserted in the correct place
   //returnType: BinaryNode<ItemType>*
   //this is called from the public add function
   BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
                                       BinaryNode<ItemType>* newNode);

   // Removes the given target value from the tree while maintaining a
   // binary search tree.

   //precondition: the value is in the node
   //postcondition: the value is not in the node any longer
   //returnType: BinaryNode<ItemType>*
   //this is called from the public remove function
   BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
                                     KeyType target,
                                     bool& success);

   // Removes a given node from a tree while maintaining a
   // binary search tree.
   //this is called from both the protected removeLeftmostNode and the

   //precondition: the node is still in the tree
   //postcondition: the node is no longer in the tree
   //returnType: BinaryNode<ItemType>*
   //protected removeValue method
   BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);

   // Removes the leftmost node in the left subtree of the node
   // pointed to by nodePtr.
   // Sets inorderSuccessor to the value in this node.
   // Returns a pointer to the revised subtree.

   //precondition: the leftmostnode is still in the tree
   //postcondition: the leftmostNode is no longer in the tree
   //returnType: BinaryNode<ItemType>*
   //called from the protected removeNode method
   BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
                                            ItemType& inorderSuccessor);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.

   //precondition: the node is not found
   //postcondition: the node is found or error is thrown if node does not exist
   //returnType: BinaryNode<ItemType>*
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
		KeyType key) const;


     ////////////////////////////////////////
    // Recursive traversal helper methods://
   ////////////////////////////////////////

   //precondition: the tree has not been travered in the preorder Way
   //postcondtion: the tree has been traversaled
   //returnType: void
   //traverses the tree by printing first then traversing then traversing
   void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

   //precondition: the tree has not been travered in the inorder Way
   //postcondtion: the tree has been traversed
   //returnType: void
   //traverses the tree by traversing then printing then traversing again
   void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

   //precondition: the tree has not been travered in the postorder Way
   //postcondtion: the tree has been travered
   //returnType: void
   //traverses the tree by traversing both sides and then printing last
   void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

public:
   //------------------------------------------------------------
     ////////////////////////////////////////
    // Constructor and Destructor Section.//
   ////////////////////////////////////////
   //------------------------------------------------------------

   //precondition: binary search tree object has not been made, member variables not declared
   //postcondition: binary search tree object has been made, member variables declared
   //returnType: none
   BinarySearchTree();

   //precondition: binary search tree with root not created yet
   //postcondition: binary search tree is created with a root already exisiting
   //returnType: none
   BinarySearchTree(const ItemType& rootItem);

   //this is the copy constructor
   //precondition: the tree passed in has not been copied
   //postcondition: the tree passed in has been copied
   //returnType: none
   BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& tree);

   //precondition: parts of the tree may still be allocated on the heap
   //postcondidtion: anything left in the tree has been deallocated and destroyed
   //returnType: none
   virtual ~BinarySearchTree();

   //------------------------------------------------------------
     /////////////////////
    // Public Methods //
    ///////////////////
   //------------------------------------------------------------

   //precondition: do not know if tree is empty or not
   //postcondition: do now if the tree is empty or nodeToDeletePtr
   //returnType: none
   bool isEmpty() const;

   //precondition: do not know the height of the tree
   //postcondition: know the height of the tree
   //returnType: int
   int getHeight() const;

   //precondition: do not know the number of nodes in the tree
   //postcondition: know the number of nodes in the tree
   //returnType: int
   int getNumberOfNodes() const;

   //precondition: do not know what data is in the root
   //postcondition: know what data is in the root
   //returnType: ItemType
   ItemType getRootData() const throw(PrecondViolatedExcep);

   //precondition: the root data has not been set
   //postcondition: the root data has been set
   //returnType: void
   void setRootData(const ItemType& newData) const throw(PrecondViolatedExcep);

   //precondition: do not know what contains
   //postcondition: know what contains
   //returnType: bool
   bool contains(const KeyType& anEntry) const;

   //precondition: the new node has not been added to the tree
   //postcondition: the new node has been added to the tree
   //returnType: bool
   bool add(const ItemType& newEntry);

   //precondition: the node is in the tree
   //postcondition: the node is no longer in the tree, has been deallocated
   //returnType: bool
   bool remove(const KeyType& anEntry);

   //precondition:do not have the game contained in the node
   //postcondition: do have the entry that was returned
   //returnType: ItemType
   ItemType getEntry(const KeyType& anEntry) const throw(NotFoundException);

   //precondition: the tree has not been cleared
   //postcondition: the tree has been cleared
   //returnType: void
   void clear();

   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------

   //precondition: the tree has not been traversed
   //postcondition: the tree has been traversed
   //returnType: void
   void preorderTraverse(void visit(ItemType&)) const;

   //precondition: the tree has not been traversed
   //postcondition: the tree has been traversed
   //returnType: void
   void inorderTraverse(void visit(ItemType&)) const;

   //precondition: the tree has not been traversed
   //postcondition: the tree has been traversed
   //returnType: void
   void postorderTraverse(void visit(ItemType&)) const;

   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   //precondition: BinarySearchTree and BinarySearchTree are set equal to each other
   //postconditin: they are compared by their root pointers
   //returnType: BinarySearchTree<KeyType, ItemType> by reference
   BinarySearchTree<KeyType, ItemType>& operator=(const BinarySearchTree<KeyType, ItemType>& rightHandSide);
}; // end BinarySearchTree

#include "BinarySearchTree.hpp"

#endif
