#include "Set_BST.h"

using namespace std;
bool Set_BST::pripada(int k)
{
	Node *p = root;
	while (p != nullptr && p->broj != k)
	{
		if (p->broj > k)p = p->left;
		else p = p->right;
	}
	if (p == nullptr) return false;
	return true;
}
bool Set_BST::operator += (int k)
{
	Node *tek = root, *pret = nullptr;
	/*if (tek == nullptr) {
		root = new Node (k);
		size++;
		return *this;
	}*/
	while (tek != nullptr && tek->broj != k)
	{
		pret = tek;
		if (k > tek->broj) tek = tek->right;
		else tek = tek->left;
	}

	if (tek == nullptr) {
		if (pret == nullptr) root = new Node(k);
		else {
			if (pret->broj > k) pret->left = new Node(k);
			else pret->right = new Node(k);
		}
		size++;
		return true;
	}
	else return false;
	
}
Set_BST::Node* Set_BST::inorder_next(Stack<Node*>& s) {
	if (EMPTY(s) == true) return nullptr;
	Node *tek = POP(s);
	inorder_fill(tek->right, s);
	return tek;
}
void Set_BST::inorder_fill(Node *tek, Stack<Node*> &s) {
	while (tek != nullptr)
	{
		PUSH(s, tek);
		tek = tek->left;
	}
}
void Set_BST::inorder() {
	Stack<Node*> s;
	Node *next = root;
	if (next == nullptr) cout << "Skup je prazan!\n";
	inorder_fill(next, s);
	while (next != nullptr) {
		next = inorder_next(s);
		if (next != nullptr) cout << next->broj << " ";
	}
}
bool Set_BST::operator -= (int k) {
	Node *tek = root, *par = nullptr;
	if (tek == nullptr) { cout << "Skup je prazan!\n"; return false; }
	while (tek != nullptr && tek->broj != k) {
		par = tek;
		if (k > tek->broj) tek = tek->right;
		else tek = tek->left;
	}
	if (tek == nullptr) { return false; }
	else
	{
		size--;
		if (tek->left == nullptr && tek->right == nullptr) {
			if (par == nullptr)
			{
				delete tek;
				root = tek = nullptr;
			}
			else
			{
				if (par->left == tek) par->left = nullptr;
				else par->right = nullptr;
				delete tek;
				tek = nullptr;
			}
		}
		else if ((tek->left != nullptr && tek->right == nullptr) || (tek->left == nullptr && tek->right != nullptr))
		{
			if (par == nullptr)
			{
				root = ((tek->left != nullptr) ? tek->left : tek->right);
				delete tek;
				tek = nullptr;
			}
			else
			{
				(tek == par->left ? par->left : par->right) = (tek->left != nullptr ? tek->left : tek->right);
				tek->left = tek->right = nullptr;
				delete tek;
				tek = nullptr;

			}
		}
		else
		{
			Node* succ = tek->right, *s = succ->left, *parsucc = nullptr;
			while (s != nullptr) {
				parsucc = succ;
				succ = s;
				s = s->left;
			}
			tek->broj = succ->broj;
			if (parsucc == nullptr)
			{
				tek->right = succ->right;
			}
			else
			{
				parsucc->left = succ->right;
			}

			succ->right = nullptr;
			delete succ;
			succ = parsucc = nullptr;
		}
		return true;
	}
}
void Set_BST::level_order() const {
	Node *next = root;
	Queue<Node*> q;
	if (next == nullptr) cout << "Skup je prazan!\n";
	else
	{
		INSERT(q, next);
		while (EMPTY_Q(q) == false)
		{
			next = DELETE_Q(q);
			cout << next->broj << " ";
			if (next->left != nullptr) INSERT(q, next->left);
			if (next->right != nullptr) INSERT(q, next->right);
		}
	}
}
Set_BST::Set_BST(int * niz, int maxind)  // MOZDA PUKNE ZATO STO SE NE KORISTE POKAZIVACI KAD SE UBACUJE NA RED VEC SAMO CLANOVI!!
{
	struct Elem {
		Node *pok;
		int ind, min, max;
		Elem(Node *p, int indd, int minn, int maxx) : pok(p), ind(indd), min(minn), max(maxx) {};
	};
	Queue<Elem> q;
	size = maxind + 1;
	root = new Node(niz[maxind / 2]);
	Elem next(root, maxind / 2, 0, maxind);
	INSERT(q, next);
	while (EMPTY_Q(q) == false)
	{
		Elem next = DELETE_Q(q);
		if (next.ind != next.max) {
			int right_ind, right_min, right_max;
			right_ind = (next.ind + next.max) / 2;
			if (next.max - next.ind == 1) right_ind++;
			Node *rightson = new Node(niz[right_ind]);
			next.pok->right = rightson;
			right_min = next.ind + 1;
			right_max = next.max;
			if (!((right_ind == right_max) == true  && (right_ind == right_min) == true)) {
				Elem right(rightson, right_ind, right_min, right_max);
				INSERT(q, right);
			}
		}
		if (next.ind != next.min) {
			int left_ind, left_min, left_max;
			left_ind = (next.ind + next.min) / 2;
			//if (next.ind - next.min == 1) left_ind--;
			Node *leftson = new Node(niz[left_ind]);
			next.pok->left = leftson;
			left_min = next.min;
			left_max = next.ind - 1; 
			if (!((left_ind == left_max) == true && (left_ind == left_min)== true)) {
				Elem left(leftson, left_ind, left_min, left_max);
				INSERT(q, left);
			}
		}
	}
}
void Set_BST::premesti(Set_BST & s) {
	root = s.root;
	size = s.size;
	s.root = nullptr;
}
Set_BST Set_BST::operator + (Set_BST & skup) {
	if (this->root == nullptr) return skup;
	if (skup.root == nullptr) return *this;
	Stack <Node*> s1, s2;
	inorder_fill(root, s1);
	inorder_fill(skup.root, s2);
	Node *tek1 = inorder_next(s1);
	Node *tek2 = inorder_next(s2);
	int maxind = -1;
	int *niz = new int [size + skup.size]; //ovim se pokriva najgori slucaj, tj da su svi razliciti elementi
	while (tek1 != nullptr && tek2 != nullptr)
	{
		maxind++;
		if (tek1->broj == tek2->broj)
		{
			niz[maxind] = tek1->broj;
			tek1 = inorder_next(s1);
			tek2 = inorder_next(s2);
		}
		else
		{
			if (tek1->broj > tek2->broj)
			{
				niz[maxind] = tek2->broj;
				tek2 = inorder_next(s2);
			}
			else
			{
				niz[maxind] = tek1->broj;
				tek1 = inorder_next(s1);
			}
		}
	}
	if (tek1 == nullptr && tek2 != nullptr) {
		while (tek2 != nullptr)
		{
			maxind++;
			niz[maxind] = tek2->broj;
			tek2 = inorder_next(s2);
		}
	}
	else
		if (tek2 == nullptr && tek1 != nullptr)
		{
			while (tek1 != nullptr)
			{
				maxind++;
				niz[maxind] = tek1->broj;
				tek1 = inorder_next(s1);
			}
		}
	Set_BST unija(niz, maxind);
	delete niz;
	return unija;
}
void Set_BST::brisi()
{
	Queue<Node*> q;
	Node *next = root;
	if (next != nullptr)
	{
		INSERT(q, next);
		while (EMPTY_Q(q) == false) {
			next = DELETE_Q(q);
			if (next->left != nullptr) INSERT(q, next->left);
			if (next->right != nullptr) INSERT(q, next->right);
			next->left = next->right = nullptr;
			delete next;
		}
		root = nullptr;
	}
}
void Set_BST::kopiraj(const Set_BST & skup) {
	size = skup.size;
	if (skup.root == nullptr) return;
	struct Elem {
		Node *pok;
		bool leftson, rightson;
		Elem(Node *p, bool l = false, bool r = false) : pok(p), leftson(l), rightson(r) {};
	};
	Node *next = skup.root;
	Queue<Node*>lvl_ord;
	Queue<Elem>son, wait;
	INSERT(lvl_ord, next);
	while (EMPTY_Q(lvl_ord) == false)
	{
		next = DELETE_Q(lvl_ord);
		if (next->left != nullptr) INSERT(lvl_ord, next->left);
		if (next->right != nullptr) INSERT(lvl_ord, next->right);
		bool left = false, right = false;
		if (next->left != nullptr) left = true;
		if (next->right != nullptr) right = true;
		Node *novi = new Node(next->broj);
		Elem nod{ novi,left,right };
		INSERT(son, nod);
	}
	Elem nod = DELETE_Q(son);
	root = nod.pok;
	INSERT(wait, nod);
	while (EMPTY_Q(son) == false)
	{
		Elem nod = DELETE_Q(wait);
		if (nod.leftson == true)
		{
			Elem left = DELETE_Q(son);
			nod.pok->left = left.pok;
			INSERT(wait, left);
		}
		if (nod.rightson == true)
		{
			Elem right = DELETE_Q(son);
			nod.pok->right = right.pok;
			INSERT(wait, right);
		}
	}
}
void Set_BST::interval_delete(int min, int max) {
	if (min > max) throw 25;
	if (root == nullptr) return;
	while (min <= max && root != nullptr)
	{
		Node* tek = root, *par = nullptr;
		while (tek != nullptr && tek->broj != min)
		{
			par = tek;
			if (min > tek->broj) tek = tek->right;
			else tek = tek->left;
		}
		delete_element(tek, par);
		min++;
	}
}

void Set_BST::delete_element(Node *tek, Node *par) {
	if (tek == nullptr) return;
	else
	{
		size--;
		if (tek->left == nullptr && tek->right == nullptr) {
			if (par == nullptr)
			{
				delete tek;
				root = tek = nullptr;
			}
			else
			{
				if (par->left == tek) par->left = nullptr;
				else par->right = nullptr;
				delete tek;
				tek = nullptr;
			}
		}
		else if ((tek->left != nullptr && tek->right == nullptr) || (tek->left == nullptr && tek->right != nullptr))
		{
			if (par == nullptr)
			{
				root = ((tek->left != nullptr) ? tek->left : tek->right);
				delete tek;
				tek = nullptr;
			}
			else
			{
				(tek == par->left ? par->left : par->right) = (tek->left != nullptr ? tek->left : tek->right);
				tek->left = tek->right = nullptr;
				delete tek;
				tek = nullptr;

			}
		}
		else
		{
			Node* succ = tek->right, *s = succ->left, *parsucc = nullptr;
			while (s != nullptr) {
				parsucc = succ;
				succ = s;
				s = s->left;
			}
			tek->broj = succ->broj;
			if (parsucc == nullptr)
			{
				tek->right = succ->right;
			}
			else
			{
				parsucc->left = succ->right;
			}

			succ->right = nullptr;
			delete succ;
			succ = parsucc = nullptr;
		}
	}
}



























