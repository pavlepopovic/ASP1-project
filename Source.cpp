#include "Set_List.h"
#include <iomanip>
#include <random>
#include "Stack.h"
#include "Set_BST.h"
#include "Queue.h"
#include <iostream>
#include "PerformanceCalculator.h"
void meri(int opseg, double  matL[][6],double matS [][6])
{
	PerformanceCalculator pc;
	Set_List lista, lista1;
	Set_BST stablo, stablo1;
	double tfl = 0, tfs = 0;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution <> dis(INT_MIN, INT_MAX);
	while (lista.getsize() != opseg) {
		int br = dis(gen);
		pc.start();
		lista += br;
		pc.stop();
		tfl += pc.elapsedMillis();
		pc.start();
		stablo += br;
		pc.stop();
		tfs += pc.elapsedMillis();
	}
	while (lista1.getsize() != opseg) {
		int br = dis(gen);
		lista1 += br;
		stablo1 += br;
	}
	switch (opseg) {
	case 200: matL[0][0] += tfl;matS[0][0] += tfs;break;
	case 500: matL[0][1] += tfl; matS[0][1] += tfs;break;
	case 1000: matL[0][2] += tfl;matS[0][2] += tfs;break;
	case 10000: matL[0][3] += tfl;matS[0][3] += tfs;break;
	case 100000: matL[0][4] += tfl;matS[0][4] += tfs;break;
	case 1000000: matL[0][5] += tfl;matS[0][5] += tfs;break;
	}
	double tul = 0, tus = 0;
	Set_List l1 = lista;
	Set_BST s1 = stablo;
	int rn = dis(gen);
	pc.start();
	l1 += rn;
	pc.stop();
	tul += pc.elapsedMillis();
	pc.start();
	s1 += rn;
	pc.stop();
	tus += pc.elapsedMillis();
	switch (opseg) {
	case 200: matL[1][0] += tul;matS[1][0] += tus;break;
	case 500: matL[1][1] += tul; matS[1][1] += tus;break;
	case 1000: matL[1][2] += tul;matS[1][2] += tus;break;
	case 10000: matL[1][3] += tul;matS[1][3] += tus;break;
	case 100000: matL[1][4] += tul;matS[1][4] += tus;break;
	case 1000000: matL[1][5] += tul;matS[1][5] += tus;break;
	}
	Set_List l2 = lista;
	Set_BST s2 = stablo;
	rn = dis(gen);
	tul = 0;
	tus = 0;
	pc.start();
	l2 -= rn;
	pc.stop();
	tul += pc.elapsedMillis();
	pc.start();
	s2 -= rn;
	pc.stop();
	tus += pc.elapsedMillis();
	int k = 2;
	switch (opseg) {
	case 200: matL[k][0] += tul;matS[k][0] += tus;break;
	case 500: matL[k][1] += tul; matS[k][1] += tus;break;
	case 1000: matL[k][2] += tul;matS[k][2] += tus;break;
	case 10000: matL[k][3] += tul;matS[k][3] += tus;break;
	case 100000: matL[k][4] += tul;matS[k][4] += tus;break;
	case 1000000: matL[k][5] += tul;matS[k][5] += tus;break;
	}
	tul = tus = 0;
	rn = dis(gen);
	pc.start();
	lista.pripada(rn);
	pc.stop();
	tul += pc.elapsedMillis();
	pc.start();
	stablo.pripada(rn);
	pc.stop();
	tus += pc.elapsedMillis();
	k = 3;
	switch (opseg) {
	case 200: matL[k][0] += tul;matS[k][0] += tus;break;
	case 500: matL[k][1] += tul; matS[k][1] += tus;break;
	case 1000: matL[k][2] += tul;matS[k][2] += tus;break;
	case 10000: matL[k][3] += tul;matS[k][3] += tus;break;
	case 100000: matL[k][4] += tul;matS[k][4] += tus;break;
	case 1000000: matL[k][5] += tul;matS[k][5] += tus;break;
	}
	tul = tus = 0;
	pc.start();
	lista1 + lista;
	pc.stop();
	tul += pc.elapsedMillis();
	pc.start();
	stablo + stablo1;
	pc.stop();
	tus += pc.elapsedMillis();
	k = 4;
	switch (opseg) {
	case 200: matL[k][0] += tul;matS[k][0] += tus;break;
	case 500: matL[k][1] += tul; matS[k][1] += tus;break;
	case 1000: matL[k][2] += tul;matS[k][2] += tus;break;
	case 10000: matL[k][3] += tul;matS[k][3] += tus;break;
	case 100000: matL[k][4] += tul;matS[k][4] += tus;break;
	case 1000000: matL[k][5] += tul;matS[k][5] += tus;break;
	}
}

using namespace std;
int main(void)
{
double matL[5][6]{ 0 }, matS[5][6]{ 0 };
/*for (int i = 0; i < 3; i++)
{
	meri(200, matL,matS);
}
for (int i = 0; i < 3; i++)
{
	meri(500, matL, matS);
}
for (int i = 0; i < 3; i++)
{
	meri(1000, matL, matS);
}
for (int i = 0; i < 3; i++)
{
	meri(10000, matL, matS);
}
for (int i = 0; i < 3; i++)
{
	meri(100000, matL, matS);
}
for (int i = 0; i < 3; i++)
{
	meri(1000000, matL, matS);
}*/
cout << "Nacin implementacije: lista" << endl;
cout << "Velicina skupa:    " << setw(25) << 200 << setw(15) << 500 << setw(15) << 1000 << setw(15) << 10000 << setw(15) << 100000 << setw(15) << 1000000 << endl;
for (int i = 0; i < 5; i++)
{
	switch (i)
	{
	case 0: cout << "Formiranje skupa: ";break;
	case 1: cout << "Umetanje u skup:  ";break;
	case 2: cout << "Brisanje          ";break;
	case 3: cout << "Pretraga:         ";break;
	case 4: cout << "Unija             ";break;
	}
	cout << setw(25);
	for (int j = 0; j < 6; j++)
	{
		cout << matL[i][j] / 3 << setw(15);
	}
	cout << endl;
}
cout << endl << endl << endl;
cout << "Nacin implementacije: stablo" << endl;
cout << "Velicina skupa:    " << setw(25) << 200 << setw(15) << 500 << setw(15) << 1000 << setw(15) << 10000 << setw(15) << 100000 << setw(15) << 1000000 << endl;
for (int i = 0; i < 5; i++)
{
	switch (i)
	{
	case 0: cout << "Formiranje skupa: ";break;
	case 1: cout << "Umetanje u skup:  ";break;
	case 2: cout << "Brisanje          ";break;
	case 3: cout << "Pretraga:         ";break;
	case 4: cout << "Unija             ";break;
	}
	cout << setw(25);
	for (int j = 0; j < 6; j++)
	{
		cout << matS[i][j] / 3 << setw(15);
	}
	cout << endl;
}
Set_BST stablo1, stablo2, unijast;
Set_List lista1, lista2, unija;
int min, max, n, niz[100], k, op;
bool kraj1 = true, kraj2 = true, kraj3 = true, kraj4 = true, odbrana = true;
while (odbrana) {
	int i;
	cout << "Pritisnite 1 za ulancanu reprezentaciju skupa\n" << "Pritisnite 2 za reprezentaciju skupa u vidu binarnog stabla pretrazivanja\n" << "Pritisnite 3 za kraj rada\n";
	cin >> i;
	switch (i) {
	case 1:
	{   cout << "Skup 1 - lista\n";
	lista1.~Set_List(); lista2.~Set_List();
	kraj1 = kraj2 = true;
	cout << "Pritisnite 1 za citanje skupa sa glavnog ulaza\n" << "Pritisnite 2 za citanje skupa iz datoteke\n";
	do
	{
		cin >> i;
		if (i != 1 && i != 2) cout << "Ponovite izbor\n";
	} while (i != 1 && i != 2);
	if (i == 1) {
		cout << "Unesite broj elemenata koji zelite da unesete\n";
		do
		{
			cin >> n;
			if (n < 0) cout << "Ponovo unesite broj elemenata\n";
		} while (n < 0);
		for (k = 0; k < n; k++) {
			cout << "Unesite sledeci element: "; cin >> niz[k];
		}
		for (k = 0; k < n; k++) lista1.add(niz[k]);
	}
	else {
		lista1.Read_File();
	}
	while (kraj1) {
		cout << "Skup1 - lista\n";
		cout << "1. Dodavanje elementa u skup\n2. Brisanje elementa iz skupa\n3. Brisanje u opsegu\n4. Ispis skupa\n5. Pretraga u skupu\n6. Broj elemenata skupa\n7. Zavrsetak rada sa prvim skupom\n";
		cout << "Koju operaciju zelite? ";
		cin >> op;
		switch (op) {
		case 1: {cout << "Unesite broj koji zelite da dodate: "; cin >> k; lista1.add(k); break;}
		case 2: {cout << "Unesite broj koji zelite da izbrisete iz skupa: "; cin >> k; lista1.delete_number(k); break;}
		case 3: {cout << "Unesite granice intervala:\n" << "Min= "; cin >> min; cout << "Max= "; cin >> max; lista1.interval_delete(min, max);break;}
		case 4: {cout << "Skup 1 izgleda ovako: " << lista1;break;}
		case 5: {cout << "Unesite broj koji biste da trazite u skupu: "; cin >> k; cout << "Broj " << k << " se "; if (lista1.pripada(k) == false) cout << "ne "; cout << "nalazi u skupu\n";break;}
		case 6: {cout << "Broj elemenata skupa 1 je: " << lista1.getsize() << endl;break;}
		case 7: kraj1 = false;break;
		default: cout << "Ponovite izbor!\n";break;
		}
	}
	cout << "Skup 2 - lista\n";
	cout << "Pritisnite 1 za citanje skupa sa glavnog ulaza\n" << "Pritisnite 2 za citanje skupa iz datoteke\n";
	do
	{
		cin >> i;
		if (i != 1 && i != 2) cout << "Ponovite izbor\n";
	} while (i != 1 && i != 2);
	if (i == 1) {
		cout << "Unesite broj elemenata koji zelite da unesete\n";
		do
		{
			cin >> n;
			if (n < 0) cout << "Ponovo unesite broj elemenata\n";
		} while (n < 0);
		for (k = 0; k < n; k++) {
			cout << "Unesite sledeci element: "; cin >> niz[k];
		}
		for (k = 0; k < n; k++) lista2.add(niz[k]);
	}
	else {
		lista2.Read_File();
	}
	while (kraj2) {
		cout << "Skup 2 - lista\n";
		cout << "1. Dodavanje elementa u skup\n2. Brisanje elementa iz skupa\n3. Brisanje u opsegu\n4. Ispis skupa\n5. Pretraga u skupu\n6. Broj elemenata skupa\n7. Unija skupa 1 i skupa 2\n8. Zavrsetak rada sa drugim skupom\n";
		cout << "Koju operaciju zelite? ";
		cin >> op;
		switch (op) {
		case 1: {cout << "Unesite broj koji zelite da dodate: "; cin >> k; lista2.add(k); break;}
		case 2: {cout << "Unesite broj koji zelite da izbrisete iz skupa: "; cin >> k; lista2.delete_number(k); break;}
		case 3: {cout << "Unesite granice intervala:\n" << "Min= "; cin >> min; cout << "Max= "; cin >> max; lista2.interval_delete(min, max);break;}
		case 4: {cout << "Skup 2 izgleda ovako: " << lista2;break;}
		case 5: {cout << "Unesite broj koji biste da trazite u skupu: "; cin >> k; cout << "Broj " << k << " se "; if (lista2.pripada(k) == false) cout << "ne "; cout << "nalazi u skupu\n";break;}
		case 6: {cout << "Broj elemenata skupa 2 je: " << lista2.getsize() << endl;break;}
		case 7: {unija = lista1 + lista2; cout << "Skup 1 izgleda ovako: " << lista1 << "Skup 2 izgleda ovako: " << lista2 << "Njihova unija izgleda ovako: " << unija; cout << "Unija ima ovoliko elemenata: " << unija.getsize() << endl;break;}
		case 8: kraj2 = false;break;
		default: cout << "Ponovite izbor!\n";break;
		}
	}
	} break;
	case 2:
	{   cout << "Skup 1 - stablo\n";
	stablo1.~Set_BST(); stablo2.~Set_BST(); kraj3 = kraj4 = true;
	cout << "Pritisnite 1 za citanje skupa sa glavnog ulaza\n" << "Pritisnite 2 za citanje skupa iz datoteke\n";
	do
	{
		cin >> i;
		if (i != 1 && i != 2) cout << "Ponovite izbor\n";
	} while (i != 1 && i != 2);
	if (i == 1) {
		cout << "Unesite broj elemenata koji zelite da unesete\n";
		do
		{
			cin >> n;
			if (n < 0) cout << "Ponovo unesite broj elemenata\n";
		} while (n < 0);
		for (k = 0; k < n; k++) {
			cout << "Unesite sledeci element: "; cin >> niz[k];
		}
		for (k = 0; k < n; k++) stablo1.add(niz[k]);
	}
	else {
		stablo1.Read_File();
	}
	while (kraj3) {
		cout << "Skup 1 - stablo\n";
		cout << "1. Dodavanje elementa u skup\n2. Brisanje elementa iz skupa\n3. Brisanje u opsegu\n4. Ispis skupa\n5. Pretraga u skupu\n6. Broj elemenata skupa\n7. Zavrsetak rada sa prvim skupom\n";
		cout << "Koju operaciju zelite? ";
		cin >> op;
		switch (op) {
		case 1: {cout << "Unesite broj koji zelite da dodate: "; cin >> k; stablo1.add(k); break;}
		case 2: {cout << "Unesite broj koji zelite da izbrisete iz skupa: "; cin >> k; stablo1.delete_number(k); break;}
		case 3: {cout << "Unesite granice intervala:\n" << "Min= "; cin >> min; cout << "Max= "; cin >> max; stablo1.interval_delete(min, max);break;}
		case 4: {cout << "Inorder poredak skupa daje: " << stablo1 << endl << "Levelorder obilazak skupa daje: ";stablo1.level_order();cout << endl;break;}
		case 5: {cout << "Unesite broj koji biste da trazite u skupu: "; cin >> k; cout << "Broj " << k << " se "; if (stablo1.pripada(k) == false) cout << "ne "; cout << "nalazi u skupu\n";break;}
		case 6: {cout << "Broj elemenata skupa 1 je: " << stablo1.getsize() << endl;break;}
		case 7: kraj3 = false;break;
		default: cout << "Ponovite izbor!\n";break;
		}
	}
	cout << "Skup 2 - stablo \n";
	cout << "Pritisnite 1 za citanje skupa sa glavnog ulaza\n" << "Pritisnite 2 za citanje skupa iz datoteke\n";
	do
	{
		cin >> i;
		if (i != 1 && i != 2) cout << "Ponovite izbor\n";
	} while (i != 1 && i != 2);
	if (i == 1) {
		cout << "Unesite broj elemenata koji zelite da unesete\n";
		do
		{
			cin >> n;
			if (n < 0) cout << "Ponovo unesite broj elemenata\n";
		} while (n < 0);
		for (k = 0; k < n; k++) {
			cout << "Unesite sledeci element: "; cin >> niz[k];
		}
		for (k = 0; k < n; k++) stablo2.add(niz[k]);
	}
	else {
		stablo2.Read_File();
	}
	while (kraj4) {
		cout << "Skup 2 - stablo\n";
		cout << "1. Dodavanje elementa u skup\n2. Brisanje elementa iz skupa\n3. Brisanje u opsegu\n4. Ispis skupa\n5. Pretraga u skupu\n6. Broj elemenata skupa\n7. Unija skupa 1 i skupa 2\n8. Zavrsetak rada sa drugim skupom\n";
		cout << "Koju operaciju zelite? ";
		cin >> op;
		switch (op) {
		case 1: {cout << "Unesite broj koji zelite da dodate: "; cin >> k; stablo2.add(k); break;}
		case 2: {cout << "Unesite broj koji zelite da izbrisete iz skupa: "; cin >> k; stablo2.delete_number(k); break;}
		case 3: {cout << "Unesite granice intervala:\n" << "Min= "; cin >> min; cout << "Max= "; cin >> max; stablo2.interval_delete(min, max);break;}
		case 4: {cout << "Inorder poredak skupa daje: " << stablo2 << endl << "Levelorder obilazak skupa daje: ";stablo2.level_order();cout << endl;break;}
		case 5: {cout << "Unesite broj koji biste da trazite u skupu: "; cin >> k; cout << "Broj " << k << " se "; if (stablo2.pripada(k) == false) cout << "ne "; cout << "nalazi u skupu\n";break;}
		case 6: {cout << "Broj elemenata skupa 2 je: " << stablo2.getsize() << endl;break;}
		case 7: {unijast = stablo1 + stablo2; cout << "Inorder obilazak skupa 1: " << stablo1 << endl << "Inorder obilazak skupa 2: " << stablo2 << endl << "Inorder obilazak unije: " << unijast << endl << "Levelorder obilazak unije: ";unijast.level_order(); cout<<"Unija ima ovoliko elemenata: "<<unijast.getsize() << endl; break;}
		case 8: kraj4 = false;break;
		default: cout << "Ponovite izbor!\n";break;
		}
	}
	} break;
	case 3: odbrana = false; break;
	default: cout << "Ponovite izbor!\n";break;
	}
}
system("pause");
	return 0;
}