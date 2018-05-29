#pragma once
template <class T> class Stack {
private:
	struct Elem {
		T broj;
		Elem *sled;
		Elem(T br, Elem * pok = nullptr) : broj (br) , sled (pok){};
	};
	Elem *top;
public:
	Stack() :top{ nullptr } {};
	friend void PUSH(Stack& s,T br)
	{
		Elem * novi = new Elem(br);
		novi->sled = s.top;
		s.top = novi;
	}
	friend bool EMPTY(Stack &s)
	{
		if (s.top == nullptr) return true;
		return false;
	}
	friend T POP(Stack &s)
	{
		if (EMPTY(s) == true) throw 10;
		Elem *old = s.top;
		s.top = s.top->sled;
		T val = old->broj;
		old->sled = nullptr;
		delete old;
		return val;
	}
	friend T PEEK(Stack &s)
	{
		if (EMPTY(s) == true) throw 10;
		return s.top->broj;
	}
	friend void CLEAR (Stack &s) {
		while (top != nullptr)
		{ 
			Elem *stari = top;
			top = top->sled;
			delete stari;
		}
	}
	~Stack() {
		while (top != nullptr) {
			Elem *stari = top;
			top = top->sled;
			delete stari;
		}
	}
};