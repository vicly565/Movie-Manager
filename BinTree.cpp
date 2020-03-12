#include "bintree.h"

BinTree::BinTree()
{
	this->root = nullptr;
}

BinTree::~BinTree()
{
	makeEmpty();
}

bool BinTree::isEmpty() const
{
	//check if root is null
	return root == nullptr;
}

bool BinTree::retrieve(const Movie*& target, Movie*& toFind)
{
	if (root == nullptr) {
		//might need to display movie name we're looking for
		cout << "Error: Movie not found" << endl;
		return false;
	}
	
	//start traversing
	Node* curr = root;
	bool found = false;

	//while we haven't found the movie
	while (!found) {
		if (curr != nullptr && *target == *curr->pMovie) {
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
	cout << "Error: Movie not found" << endl;
	return false;
}

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
		return InsertHelper(curr, inserting);
	}
}

void BinTree::makeEmpty()
{
		EmptyHelper(root);
}

void BinTree::display() const
{
	if (root != nullptr) {
		DisplayHelper(root);
	}
}

bool BinTree::InsertHelper(Node* curr, Movie* inserting)
{
	//ASSUMPTION: this program does not accept duplicate movies in the system
	if (curr != nullptr) {
		if (*inserting == *curr->pMovie) {
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

void BinTree::EmptyHelper(Node*& current)
{
	if (current != nullptr) {

		//we want to do a post order traversal
		//and delete in post order so that leaves are deleted first
		//and root is deleted last
		EmptyHelper(current->left);
		EmptyHelper(current->right);


		//then we delete the node itslef
		delete current;
		current = nullptr;
	}
}

void BinTree::DisplayHelper(Node* curr) const
{
	if (curr != nullptr) {
		//print out in order (left, root, right)
		DisplayHelper(curr->left);
		curr->pMovie->display();
		DisplayHelper(curr->right);
	}
}
