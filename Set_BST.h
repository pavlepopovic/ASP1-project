#pragma once
#include "Set.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Set_BST: public Set
{
private:
	struct Node {
		int broj;
		Node *left, *right;
		Node(int br, Node*l = nullptr, Node*r = nullptr) : broj(br), left(l), right(r) {};
	};
	Node *root;
	Node *inorder_next( Stack<Node*>& s);
	void inorder_fill(Node *tek, Stack<Node*>&s);
	void inorder();
	Set_BST(int *const niz ,int maxind);
	void premesti(Set_BST & s);
	void brisi();
	void kopiraj(const Set_BST &s);
	void delete_element(Node *tek, Node *par);
	
public:
	Set_BST() : Set(), root(nullptr) {};
	Set_BST(Set_BST &&s) { premesti(s); cout << endl; }
	bool operator -= (int k);
	bool pripada(int k) override;
	bool operator += (int k);
	void delete_number(int k) override { if((*this -= k)==false) cout<<"Broj "<<k<<" se ne nalazi u skupu!\n"; }
	friend ostream& operator << (ostream & os, Set_BST & skup) {
		skup.inorder();
		return os;
	}
	void add(int k) override {
		if ((*this += k) == false) cout << "Broj " << k << " se vec nalazi u skupu!\n";
	}
	void level_order() const;
	Set_BST operator + (Set_BST & skup);
	~Set_BST() { brisi(); }
	Set_BST(const Set_BST &skup) : Set_BST () { kopiraj(skup); }
	Set_BST & operator = (const Set_BST & skup) {
		if (this != &skup) {
			brisi();
			kopiraj(skup);
		}
		return *this;
	}
	Set_BST & operator = (Set_BST && skup) {
		if (this != &skup) {
			brisi();
			premesti(skup);
		}
		return *this;
	}
	void interval_delete(int min, int max) override;
	void Read_File() {
		ifstream dat;
		string filename;
	         do {
				cout << "Unesite ime datoteke: ";
				cin >> filename;
				dat.open(filename);
				if (dat.is_open() == false) { cout << "Neuspesno otvaranje datoteke!" << endl; }
			} while (dat.is_open() == false);
			while ((dat.eof()) == false)
			{
				int k;
				dat >> k;
				*this += k;
			}
			dat.close();
	}
	
};

