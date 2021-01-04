#pragma once
#include "Header.h"
#include"Node.h"
#include"Iterator.h"

template<typename T>
class MyRing
{

	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	MyRing();
	MyRing(MyRing& obj);
	MyRing(T& data);
	~MyRing();

	void push_front(T& data);					//�������� ������� � ������ ������
	void push_back(T& data);					//�������� ������� � ����� ������
	void insert(T data, int index);				//�������� ������� � ������ �� ���������� �������
	void inputRing(int index);					//������ ������� �� �������
		
	void deleteElement(int index);				//�������� �������� ������ �� ���������� �������					
	void clear();								//�������� ������
	
	void sortAscending();								//���������� ������ �� ������������ 
	void sortDescending();								//���������� ������ �� �������� 
	void find(MyRing<T>& NewMyRing);			//����� �������� ������

	void print();								//����� ������ �� �����
	Node<T>* operator[](const int index);		//������ �� ������� ������

	Node<T>* Begin() { return this->tail; }
	Node<T>* End() { return this->head; }

	int getSize() { return size; }				//���������� ��������� � ������
	Node<T>* getHead() { return this->head; };	//����� ������
	Node<T>* getTail() { return this->tail; };	//������ ������
};

