// ------------------------------------------------ bintree.h -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This header file contains information on the BinTree data structure. The BinTree datastructure is used to
// hold and sort movies so that they can be retrieved easily.
// -------------------------------------------------------------------------------------------------------------------- 
// 
// Specifications: Each BinTree contains a node structure which contains a left child and a right child. The left
// child is always less than the node, and the right child is always greater than teh child.
// 
// The BinTree has these PUBLIC FUNCTIONS:
//							bool isEmpty() const; 	//checks if the tree is empty
//							bool retrieve(const Movie*& target, Movie*& toFind); //get the movie in the tree
//							bool insert(Movie* inserting); //inserts a movie into the tree
//							void makeEmpty(); //makes the tree empty
//							void display() const; //prints the tree out
//								
//
// The HashTable has these PRIVATE HELPER FUNCTIONS:
//							bool InsertHelper(Node* curr, Movie* inserting); //helper for inserting a movie
//							void EmptyHelper(Node* current); //helper for making the bintree empty
//							void DisplayHelper(Node* curr) const; //helper for displaying the bintree
//
// Assumptions: This data structure assumes that no duplicate movies will be held. Additionally this data structure assumes
// that only the same movie types will be held within the tree
// 
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include "movie.h"
#include "classic.h"
#include <iostream>

using namespace std;

class BinTree
{
    
public:
    BinTree(); 
    ~BinTree();
    
	//checks if the tree is empty
	bool isEmpty() const;
	//get the movie int eh tree
    bool retrieve(Movie*& target, Movie*& toFind);
	//inserts a movie into the tree
    bool insert(Movie* inserting);
	//makes the tree empty
    void makeEmpty();
	//prints the tree out
	void display() const;

	void displayInStock(Movie* target) const;
 
    
private:
	struct Node {
		Movie* pMovie;
		Node* right;
		Node* left;
	};
	Node* root;
    
	//helper methods
	bool InsertHelper(Node* curr, Movie* inserting);
	void EmptyHelper(Node* current);
	void DisplayHelper(Node* curr) const;
	void InStockHelper(Node* curr, Movie* target) const;
};

