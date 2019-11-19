#pragma once
template <class T>
class TQueue {
	T* mas;
	int MaxSize, Head, Tail, Count;
public:
	TQueue(int _MaxSize = 10) {
		MaxSize = _MaxSize;
		mas = new T[MaxSize];
		Count = 0;
		Head = 0;
		Tail = -1;
	}

	TQueue<T>& operator=(const TQueue<T>& q)//исправить
	{
		if (this != &q) {
			if (MaxSize != q.MaxSize) {
				delete[] mas;
				MaxSize = q.MaxSize;
				mas = new T[MaxSize];
			}
			Count = q.Count;
			Head = q.Head;
			Tail = q.Tail;
			for (int i = 0; i < MaxSize; i++)
				mas[i] = q.mas[i];
		}
		return *this
	}

	TQueue(const TQueue& q)//исправить
	{
		MaxSize = q.MaxSize;
		mas = new T[MaxSize];
		Count = q.Count;
		Head = q.Head;
		Tail = q.Tail;
		for (int i = 0; i < MaxSize; i++)
			mas[i] = q.mas[i];
	}

	bool Empty() {
		if (count == 0) return true;
		else return false;
	}

	bool Full() {
		if (count == MaxSize) return true;
		else return false;
	}

	void Push(T el) {
		if (Full()) throw 1;
		if (Tail != MaxSize - 1) Tail++;
		else Tail = 0;
		mas[Tail] = el;
		count++;
	}

	T Pop() {
		int OldHead = Head;
		if (Empty()) throw - 1;
		if (Head != MaxSize - 1) Head++;
		else Head = 0;
		count--;
		return mas[OldHead];
	}

	T front() const {
		return mas[Head];
	}

	T back() const {
		return mas[Tail];
	}
};