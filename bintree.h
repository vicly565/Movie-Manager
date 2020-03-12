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
    
	bool isEmpty() const;
    bool retrieve(const Movie*& target, Movie*& toFind);
    bool insert(Movie* inserting);
    void makeEmpty();
	void display() const;
 
    
private:
	struct Node {
		Movie* pMovie;
		Node* right;
		Node* left;
	};
	Node* root;
    
	bool InsertHelper(Node* curr, Movie* inserting);
	void EmptyHelper(Node*& current);
	void DisplayHelper(Node* curr) const;
};

