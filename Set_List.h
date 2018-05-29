#pragma once
#include "Set.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Set_List : public Set
{
private:
	struct Elem {
		int broj;
		Elem *pret, *sled;
		Elem(int br, Elem *p = nullptr, Elem *s = nullptr) : broj(br), pret(p), sled(s) {};
	};
	Elem *prvi, *posl, *niz[10000] = { nullptr };
private:

	void brisi()  {
		Elem *tek = prvi;
		while (tek) {
			Elem *stari = tek;
			tek = tek->sled;
			stari->sled = nullptr;
			stari->pret = nullptr;
			delete stari;
		}
		//size = 0;
		for (int i = 0; i < 10000; i++)niz[i] = nullptr;
		posl=prvi = nullptr;
	}
	void delete_pt(Elem * tek);             //modifikacija
	void kopiraj(const Set_List& s);        //modifikacija uradjena
	void premesti(Set_List & s);
	friend void insert_end(Set_List& s,int k);  //modifikacija uradjena
public:
	Set_List(const Set_List & s) { kopiraj(s); }
	Set_List(Set_List && s) { premesti(s); }
	void add(int k) override {
		if ((*this += k)== false) cout<<"Broj " <<k <<" se vec nalazi u skupu !\n";
	}
	void delete_number(int k) { if((*this -= k) == false ) cout<<"Broj "<<k<<" se ne nalazi u skupu\n"; }
	Set_List & operator = (const Set_List & s) {
		if (this != &s)
		{
			brisi();
			kopiraj(s);
		}
		return *this;
	}
	Set_List & operator = (Set_List &&s) {
		if (this != &s) {
			brisi();
			premesti(s);
		}
		return *this;
	}
	Set_List() : Set(), prvi(nullptr),posl(nullptr) {};
	~Set_List() { brisi(); }
	bool pripada(int k) override;      //modifikacija uradjena
	bool operator += (int br);
	friend ostream& operator << (ostream &os, const Set_List &s)
	{
		Elem *tek = s.prvi;
		if (tek == nullptr) return os << "Skup je prazan!" << endl;
		while (tek) {
			os << tek->broj << ' ';
			tek = tek->sled;
		}
		return os << endl;
	}
	void invert() {
		Elem *tek = posl;
		while (tek) {
			cout << tek->broj << " ";
			tek = tek->pret;
		}
		cout << endl;
	}
	bool operator -= (int br);  //modifikacija
	void interval_delete(int min, int max) override; //modifikacija
	Set_List operator + (const Set_List & s) const;  //modifikacija uradjena
	void print() {
		if (size >= 1000) {
			for (int i = 0; niz[i] != nullptr; i++) {
				cout << (i + 1) * 1000 << " element je: " << niz[i]->broj << endl;
			}
		}
	}
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

