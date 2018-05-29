#pragma once
template <class T> class Queue
{
private:
	struct Elem {
		T info;
		Elem *sled;
		Elem(T inf, Elem *pok = nullptr) : info(inf), sled(pok) {};
	};
	Elem *front, *rear;
public:
	Queue() : front(nullptr), rear(nullptr) {};
	friend bool EMPTY_Q(Queue & q)
	{
		if (q.front == nullptr) return true;
		return false;
	}
	friend void INSERT(Queue & q, T br)
	{
		Elem *novi = new Elem(br);
		if (q.front == nullptr) {
			q.front = q.rear = novi;
		}
		else
		{
			q.rear->sled = novi;
			q.rear = novi;
		}
	}
	friend T DELETE_Q(Queue &q)
	{
		if (EMPTY_Q(q) == true) throw 12;
		else
		{
			Elem *stari = q.front;
			q.front = q.front->sled;
			if (q.front == nullptr) q.rear = nullptr;
			T br = stari->info;
			delete stari;
			return br;
		}
	}
	~Queue()
	{
		while (front != nullptr) {
			Elem *stari = front;
			front = front->sled;
			delete stari;
		}
		front = rear = nullptr;
	}
};























