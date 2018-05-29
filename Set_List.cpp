#include "Set_List.h"
bool Set_List::pripada(int k)  {
	Elem *tek = prvi;
	if (tek != nullptr)
	if (size > 1000) {
		for (int i = 0; i < (size / 1000);i++)
			if (k > niz[i]->broj) tek = niz[i];
			else break;
	}
	while (tek != nullptr && k > tek->broj) tek = tek->sled;
	if (tek == nullptr) return false;
	if (k == tek->broj) return true;
	return false;
}
bool Set_List :: operator += (int br) {
	bool flag;
	Elem *tek = prvi;
	int ind = 0;
	bool pomeraj = false;
	if (tek != nullptr)
	if (size > 1000) {
		for (int i = 0; i < (size / 1000);i++)
			if (br > niz[i]->broj) tek = niz[i], ind = i, pomeraj = true;
			else break;
	}
	while (tek != nullptr && br > tek->broj)tek = tek->sled;
	if (tek == nullptr) flag = false;
	else
		if (br == tek->broj) flag = true;
		else
			flag = false;
	if (flag == true) return false;
	if (flag == false) {
		Elem *novi = new Elem(br);
		
		if (prvi == nullptr) {
			prvi =posl= novi;

		}
		else
		{
			if (tek != nullptr)
			{
				if (tek != prvi) {
					novi->sled = tek;
					novi->pret = tek->pret;
					(tek->pret)->sled = novi;
					tek->pret = novi;
				}
				else
				{
					novi->sled = tek;
					tek->pret = novi;
					prvi = novi;
				}

			}
			else
			{
				novi->pret = posl;
				posl->sled = novi;
				posl = novi;
			}
		}
		if (pomeraj == true)
		{
			for (int i = ind + 1; niz[i] != nullptr;i++) niz[i] = niz[i]->pret;
		}
		if (pomeraj == false)
		{
			if (size >= 1000)
				for (int i = 0; niz[i] != nullptr; i++) niz[i] = niz[i]->pret;
		}
		size++;

		if (size >= 1000 && size % 1000 == 0) { niz[(size / 1000) - 1] = posl; }
	}
	return true;
}
void Set_List::delete_pt(Elem *tek) {
	
	if (tek == nullptr) return;
	if (size >= 1000)
	{
		Elem *pom = nullptr;
		int ind = 0;
		for (int i = 0; niz[i] != nullptr && tek->broj > niz[i]->broj; i++) pom = niz[i], ind = i;
		if (pom != nullptr)
		{
			for (int i = ind+1; niz[i] != nullptr; i++) niz[i] = niz[i]->sled;
		}
		else
		{
			for (int i = 0; niz[i] != nullptr;i++) niz[i] = niz[i]->sled;
		}

	}
	size--;
	if (tek == prvi) {
		if (tek != posl)
		{
			(tek->sled)->pret = nullptr;
			prvi = tek->sled;
			tek->sled = nullptr;
			delete tek;
		}
		else
		{
			prvi = posl = nullptr;
			delete tek;
		}
	}
	else if (tek == posl)
	{
		tek->pret->sled = nullptr;
		posl = tek->pret;
		tek->pret = nullptr;
		delete tek;
	}
	else
	{
		tek->sled->pret = tek->pret;
		tek->pret->sled = tek->sled;
		tek->sled = tek->pret = nullptr;
		delete tek;
	}
}
bool Set_List::operator -= (int br) {
	bool flag;
	Elem *tek = prvi;
	if (tek == nullptr) {
		cout << "Skup je prazan!\n";
	}
	if (tek != nullptr)
	if (size > 1000) {
		for (int i = 0; i < (size / 1000);i++)
			if (br> niz[i]->broj) tek = niz[i];
			else break;
	}
	while (tek != nullptr && br > tek->broj)tek = tek->sled;
	if (tek == nullptr) flag = false;
	else
		if (br == tek->broj) flag = true;
		else
			flag = false;
	if (flag == true) {
		delete_pt(tek);
	}
	else return false;
	return true;
}
void Set_List::interval_delete(int min, int max) {
	if (min > max) return;
	Elem *tek = prvi;
	if (prvi == nullptr) return;
	if (min > posl->broj || max < prvi->broj) return;
	if (tek != nullptr)
	if (size > 1000) {
		for (int i = 0; i < (size / 1000);i++)
			if (min > niz[i]->broj) tek = niz[i];
			else break;
	}
	while (min <= max)
	{
		if (prvi == nullptr)break;
		if (min > posl->broj || max < prvi->broj) break;
		while (tek != nullptr && min > tek->broj) tek = tek->sled;
		if (tek != nullptr && tek->broj == min)
		{
			Elem *stari = tek;
			tek = tek->sled;
			delete_pt(stari);
		}
		min++;
	}
}
void Set_List::kopiraj(const Set_List & s) {
	Elem *tek = s.prvi;
	size = 0;
	while (tek != nullptr)
	{
		size++;
		Elem *novi = new Elem(tek->broj);
		if (prvi == nullptr) {
			prvi = posl = novi;
		}
		else
		{
			novi->pret = posl;
			posl->sled = novi;
			posl = novi;
		}
		tek = tek->sled;
		if (size >= 1000 && (size) % 1000 == 0) niz[(size / 1000) - 1] = posl;
	}
}
void Set_List::premesti(Set_List &s) {
	size = s.size;
	prvi = s.prvi;
	posl = s.posl;
	s.prvi = s.posl = nullptr;
}
void insert_end(Set_List &s,int k) {
	Set_List::Elem *novi = new Set_List::Elem(k);
	s.size++;
	if (s.prvi == nullptr) {
		s.prvi = s.posl = novi;
	}
	else
	{
		s.posl->sled = novi;
		novi->pret = s.posl;
		s.posl = novi;
	}
	if (s.size >= 1000 && s.size % 1000 == 0)s.niz[(s.size) / 1000 - 1] == s.posl;
}
Set_List Set_List::operator + (const Set_List &s) const {
	Elem *tek1 = prvi, *tek2 = s.prvi;
	Set_List unija;
	while (tek1 != nullptr && tek2 != nullptr)
	{
		if (tek1->broj == tek2->broj)
		{
			insert_end(unija, tek1->broj);
			tek1 = tek1->sled;
			tek2 = tek2->sled;
		}
		else
			if (tek1->broj < tek2->broj)
			{
				insert_end(unija, tek1->broj);
				tek1 = tek1->sled;
			}
			else
			{
				insert_end(unija, tek2->broj);
				tek2 = tek2->sled;
			}
	}
	if (tek2 == nullptr && tek1 != nullptr)
	{
		while (tek1)
		{
			insert_end(unija, tek1->broj);
			tek1 = tek1->sled;
		}
	}
	else 
		if (tek1 == nullptr && tek2 != nullptr)
		{
			while (tek2)
			{
				insert_end(unija, tek2->broj);
				tek2 = tek2->sled;
			}
		}
	return unija;
}







































































