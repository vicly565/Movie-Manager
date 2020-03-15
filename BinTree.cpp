// ------------------------------------------------ bintree.cpp -------------------------------------------------------
// Victor Ly & Kenneth Ven CSS343 Section C
// Creation Date: 3/09/2020
// Date of Last Modification: 3/14/2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file contains implementation of the BinTree data structure. The BinTree datastructure is used to
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
#include "bintree.h"

// ------------------------------------BinTree()----------------------------------------------- 
// Description
// BinTree(): Creates a Bintree object by making the root null
// preconditions: none
//
// postconditions: a BinTree object is created
//
// -------------------------------------------------------------------------------------------- 
BinTree::BinTree()
{
	this->root = nullptr;
}

// ------------------------------------~BinTree()----------------------------------------------- 
// Description
// ~HashTable(): Destructor for the BinTree. Frees all memory associated with the BinTree
// preconditions: BinTree is an existing object
//
// postconditions: BinTree is deleted, and memory is deallocated
//
// -------------------------------------------------------------------------------------------- 
BinTree::~BinTree()
{
	//if this tree is not empty, then call the method to make the tree empty
	if (!this->isEmpty()) {
		makeEmpty();
	}
}

// ------------------------------------Functions-----------------------------------------------
// ------------------------------------isEmpty----------------------------------------------- 
// Description
// isEmpty(): Check if the tree is empty
// preconditions: none
//
// postconditions: returns true if the pointer is a null pointer, and false if it isnt
//
// --------------------------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
	//check if root is null
	return root == nullptr;
}

// ------------------------------------retrieve----------------------------------------------- 
// Description
// retrieve(Movie*& target, Movie*& toFind): Finds the target movie in the tree
// preconditions: none
//
// postconditions: returns true if movie was found, and false if it was not found
//
// --------------------------------------------------------------------------------------------
bool BinTree::retrieve(Movie*& target, Movie*& toFind)
{
	if (root == nullptr) {
		//might need to display movie name we're looking for
		//maybe handle this in the borrow/return function of transaction
		//cout << "Error: Movie not found";
		return false;
	}
	
	//start traversing
	Node* curr = root;
	bool found = false;

	//while we haven't found the movie
	while (!found) {
		if (curr != nullptr) {
		}
		if (curr != nullptr && *target == *curr->pMovie) {
			//if we've found our movie
			toFind = curr->pMovie;
			found = true;
			return true;
		}
		else if (curr != nullptr && *target > *curr->pMovie) {
			//go right because what we're looking for is bigger than current
			curr = curr->right;
		}
		else if (curr != nullptr && *target < *curr->pMovie) {
			//go left because what we're looking for is smaller than current
			curr = curr->left;
		}
		else {
			//we hit a nullptr
			//movie wasn't found so break out of the while loop
			found = true;
		}
	}

	//might need to display movie name we're looking for
	//cout << "Error: Movie not found" << endl;
	return false;
}

// ------------------------------------insert----------------------------------------------- 
// Description
// insert(const Movie* inserting): inserts a movie into the tree.
// preconditions: none
//
// postconditions: returns true if movie was inserted and false if it is a duplicate
//
// assumptions: We assume that we don't want to store any duplicate movies
//
// --------------------------------------------------------------------------------------------
bool BinTree::insert(Movie* inserting)
{
	//if root is empty we insert at root
	if (root == nullptr) {
		root = new Node;
		root->pMovie = inserting;
		root->left = nullptr;
		root->right = nullptr;
		return true;
	}
	else {
		//traverse where to insert at
		Node* curr = root;
		//call recursive helper for inserting
		return InsertHelper(curr, inserting);
	}
}

// ------------------------------------makeEmpty()----------------------------------------------- 
// Description
// makeEmpty(): Frees all memory associated with the BinTree by calling a helper function
// preconditions: BinTree is an existing object
//
// postconditions: BinTree is deleted, and memory is deallocated
//
// -------------------------------------------------------------------------------------------- 
void BinTree::makeEmpty()
{
		EmptyHelper(root);
}

// ------------------------------------display()----------------------------------------------- 
// Description
// display(): the BinTree is printed in order by calling a helper function
//
// postconditions: BinTree is printed in order.
//
// -------------------------------------------------------------------------------------------- 
void BinTree::display() const
{
	if (root != nullptr) {
		DisplayHelper(root);
	}
}

// ------------------------------------displayInStock()----------------------------------------------- 
// Description
// displayInStock(): the BinTree prints out movies that are in stock that match the title of the movie
// passed in
//
// postconditions: Similar titles are printed
//
// -------------------------------------------------------------------------------------------- 
void BinTree::displayInStock(Movie* target) const
{
	if (root != nullptr) {
		InStockHelper(root, target);
	}
}
// ------------------------------------End of functions--------------------------------

// ------------------------------------Helper Functions-----------------------------------------------
// ------------------------------------insertHelper----------------------------------------------- 
// Description
// insertHelper(): Helper method to insert a movie into the tree
// preconditions: insert is called
//
// postconditions: returns true if we are able to insert the movie, and false if we couldnt
//
// assumptions: We return false if we couldn't insert the movie
//
// --------------------------------------------------------------------------------------------
bool BinTree::InsertHelper(Node* curr, Movie* inserting)
{
	//ASSUMPTION: this program does not accept duplicate movies in the system
	if (curr != nullptr) {
		if (*inserting == *curr->pMovie) {
			cout << "ERROR IN INSERTION DUPLICATE MOVIE, ";
			inserting->display();
			return false;
		}
	}


	//if the movie we are inserting is greater than the current movie
	//we need to traverse right
	if (*inserting > *curr->pMovie) {
		if (curr->right == nullptr) {

			//If right is empty we insert here
			Node* insNode = new Node();
			insNode->pMovie = inserting;
			insNode->left = nullptr;
			insNode->right = nullptr;

			curr->right = insNode;
			return true;
		}
		else {
			//otherwise we go right
			return InsertHelper(curr->right, inserting);
		}
	}
	else if (*inserting < *curr->pMovie) {
		if (curr->left == nullptr) {

			//If left is empty we insert here
			Node* insNode = new Node();
			insNode->pMovie = inserting;
			insNode->left = nullptr;
			insNode->right = nullptr;

			curr->left = insNode;
			return true;
		}
		else {
			//otherwise traverse left side
			return InsertHelper(curr->left, inserting);
		}
	}

	//dead statement should not happen, and this will be posted if error in testing
	cout << "ERROR IN INSERTION" << endl;
	return false;
}

// ------------------------------------EmptyHelper----------------------------------------------- 
// Description
// EmptyHelper(*Node current): Helper method to empty out the tree. Deletes nodes in a post order traversal
// preconditions: empty is called
//
// postconditions: memory associated with the tree is deallocated
//
// --------------------------------------------------------------------------------------------
void BinTree::EmptyHelper(Node* current)
{

	if (current != nullptr && current->pMovie != nullptr) {
		//we want to do a post order traversal
		//and delete in post order so that leaves are deleted first
		//in the order of left then right
		//and root is deleted last

		//traversals if the current node has children
		if (current->left != nullptr) {
			EmptyHelper(current->left);
		}
		if (current->right != nullptr) {
			EmptyHelper(current->right);
		}


		//then we delete the node itslef
		delete current->pMovie;
		current->pMovie = nullptr;
		delete current;
		current = nullptr;
	}
}

// ------------------------------------DisplayHelper----------------------------------------------- 
// Description
// DisplayHelper(*Node curr): Helper method to print out the tree. Does an in order traversal
// preconditions: display is called
//
// postconditions: the tree is printed
//
// --------------------------------------------------------------------------------------------
void BinTree::DisplayHelper(Node* curr) const
{
	if (curr != nullptr) {
		//print out in order (left, root, right)
		DisplayHelper(curr->left);
		curr->pMovie->display();
		DisplayHelper(curr->right);
	}
}

// ------------------------------------InStockHelper----------------------------------------------- 
// Description
// InStockHelper(*Node curr, Movie* target): Helper method to print out movies with the same title
//
// postconditions: the movies with the same title are printed
//
// --------------------------------------------------------------------------------------------
void BinTree::InStockHelper(Node* curr, Movie* target) const
{
	if (curr != nullptr) {

		//print out in order (left, root, right)
		InStockHelper(curr->left, target);

		//if the title of the movies are the same
		if (curr->pMovie->getTitle() == target->getTitle()) {
			//and if the stock is more than zero
			if (curr->pMovie->getStock() > 0) {
				//print the movie
				cout << "Consider this alternative: ";
				curr->pMovie->display();
			}
		}

		InStockHelper(curr->right, target);
	}
}
// ------------------------------------End of Helper Functions----------------------------------
