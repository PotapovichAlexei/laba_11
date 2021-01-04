#include "Header.h"


template<typename T>
inline Iterator<T>::Iterator(Node<T>* curr)
{
	this->curr = curr;
}

template<typename T>
void Iterator<T>::operator++()
{
	this->curr = this->curr->next;
}

template<typename T>
void Iterator<T>::operator--()
{
	this->curr = this->curr->prev;
}

template<typename T>
void Iterator<T>::operator=(T Data)
{
	this->Data = Data;
}

template<typename T>
void Iterator<T>::operator=(Node<T>* tmp)
{
	this->curr = tmp;
}

template<typename T>
T& Iterator<T>::operator*(void)
{
	return this->curr->data;
}

template<typename T>
bool Iterator<T>::operator==(Node<T>* tmp)
{
	if (this->curr == tmp)
		return true;
	else
		return false;
}

template<typename T>
bool Iterator<T>::operator!=(Node<T>* tmp)
{
	if (this->curr != tmp)
		return true;
	else
		return false;
}

template<typename T>
bool Iterator<T>::operator!=(Iterator<T> tmp)
{
	if (this->curr != tmp.curr)
		return true;
	else
		return false;
}

template<typename T>
void Iterator<T>::operator+=(const int& tmp)
{
	for (int i = 0; i < tmp; ++i)
		++(*this);
}
