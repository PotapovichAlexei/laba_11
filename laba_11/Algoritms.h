#pragma once
#include "Header.h"
template<typename T>
void findCont(MyRing<T>& newRing, Iterator<T> begin, T& obj)
{

	Iterator<T> flag = begin;

	do {
		if (*begin == obj)
			newRing.push_back(*begin);
		++begin;
	} while (begin != flag);
}

template<typename T>
void findObjectCont(MyRing<T>& newRing, MyRing<T>& oldRing)
{
	cout << endl << "Enter information to find: ";
	T obj;
	cin >> obj;
	Iterator<T> begin = oldRing.Begin();
	findCont(newRing, begin, obj);
}

template<typename T>
void sortAscendingCont(Iterator<T> begin, int size)
{
	//Iterator<T> begin = ring.Begin();
	Iterator<T> curr = begin, next = begin;
	++next;
	T chen;

	for (int i = 0; i < size; i++) {
		curr = begin; next = begin; ++next;
		do {
			if (*curr < *next)
			{
				chen = *curr;
				*curr = *next;
				*next = chen;

				++curr;
				++next;
			}
			else {
				++curr;
				++next;
			}
		} while (next != begin);
	}
}

template<typename T>
void sortDescendingCont(Iterator<T> begin, int size)
{
	//Iterator<T> begin = ring.Begin();
	Iterator<T> curr = begin, next = begin;
	++next;
	T chen;

	for (int i = 0; i < size; i++) {
		curr = begin; next = begin; ++next;
		do {
			if (*curr > *next)
			{
				chen = *curr;
				*curr = *next;
				*next = chen;

				++curr;
				++next;
			}
			else {
				++curr;
				++next;
			}
		} while (next != begin);
	}
}

template<typename T>
void printContByIt(Iterator<T> begin)
{
	Iterator<T> flag = begin;
	//Node<T>* help = this->tail;
	//Iterator<T> help(this->tail);
	if (begin == NULL) {
		cout << "Your Ring is empty" << endl;
	}
	else {

		/*for (int i = 0; i < ring.getSize() + 1; i++)*/
		do {
			cout << begin.curr->data ;
			++begin;
		} while (flag != begin);
	}
}