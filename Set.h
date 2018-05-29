#pragma once
#include <iostream>
using namespace std;
class Set
{
protected:
	unsigned size;
	
	
public:
	virtual void add(int k) = 0;
	Set() { size = 0; }
	virtual bool pripada(int k) = 0;
	virtual void delete_number(int k) = 0;
	virtual void interval_delete(int min, int max) = 0;

	/*~Set() {
		brisi();
	}
	Set(const Set &s) {
		kopiraj(s);
	}
	Set(Set &&s) { premesti(s); }
	Set & operator = (const Set &s) {
		if (this != &s) {
			brisi();
			kopiraj(s);
		}
		return *this;
	}
	Set & operator = (Set &&s) {
		if (this != &s) {
			brisi();
			premesti(s);
		}
	}*/

	unsigned getsize() const { return size; }
	virtual ~Set() { size = 0; }
};

