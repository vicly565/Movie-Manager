#pragma once
#include "movie.h"
#include <iostream>

using namespace std;

class BinTree
{
	    friend ostream & operator<<(ostream &, const BinTree& b);
    
public:
    BinTree(); 
    ~BinTree();
    
	bool isEmpty() const;
    bool retrieve(const Movie*& target, Movie*& toFind);
    bool insert(Movie* inserting);
    void makeEmpty();
 
    
private:
	struct Node {
		Movie* pMovie;
		Node* right;
		Node* left;
	};
	Node* root;
    
	bool InsertHelper(Node* curr, Movie* inserting);
	void EmptyHelper(Node*& current);
};

