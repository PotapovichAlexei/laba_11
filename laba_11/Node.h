#pragma once
#include "Header.h"


template<class T>
class Node
{
public:
	Node* next;
	Node* prev;
	T data;
public:
	Node(T data, Node* next, Node* prev);
	void swap(T& data);
	~Node();
};