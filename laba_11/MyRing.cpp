#include "Header.h"

template<typename T>
MyRing<T>::MyRing()
{

	this->size = -1;
	this->head = this->head;
	this->tail = this->tail;

}

template<typename T>
MyRing<T>::MyRing(MyRing& obj)
{
	this->head = this->head;
	this->size = -1;
	Node<T>* temp = obj.tail;

	while (temp)						//���������� ���� ��������� ������ ������� � ����� ������
	{
		push_front(temp->data);
		temp = temp->next;
	}

	this->head = temp;					//������ ������ - ��� ��������� ����������� ����
	this->tail = this->head->prev;		//����� ������ - ���������� ����� ������� ������

}

template<typename T>
MyRing<T>::MyRing(T& data)
{
	this->size = -1;
	Node<T> obj(data, this->head, this->tail);
	push_front(obj);
	this->head = this->head;					//������ ������ - ��� ��������� ����������� ����
	this->tail = this->head->prev;		//����� ������ - ���������� ����� ������� ������
}

template<typename T>
MyRing<T>::~MyRing()
{
	clear();
}

template<typename T>
inline void MyRing<T>::push_front(T& data)
{
	if (this->head == this->head && this->size == -1)							//���� ������ ������ (�������� 0 ��������� � ��������� ��� �� ����)
	{
		this->head = new Node<T>(data, this->tail, this->head);
		this->tail = this->head;
		this->head->next = this->head;
		this->head->prev = this->head;
	}
	else
	{
		this->tail->prev = new Node<T>(data, this->tail, this->head);
		this->tail = this->tail->prev;

		this->head->next = this->tail;
	}

	++(this->size);
}



template<typename T>
void MyRing<T>::push_back(T& data)
{

	if (this->head == this->head && this->size == -1) {						//���� ������ ������ (�������� 0 ��������� � ��������� ��� �� ����)
		this->head = new Node<T>(data, this->head, this->tail);
		this->tail = this->head;
		this->head->next = this->head;
		this->head->prev = this->head;
	}
	else {
		this->head->next = new Node<T>(data, this->tail, this->head);
		this->head = this->head->next;

		this->tail->prev = this->head;
	}

	++(this->size);
}

template<typename T>
void MyRing<T>::print()
{
	Node<T>* help = this->tail;
	//Iterator<T> help(this->tail);
	if (help == NULL || this->size == -1) {
		cout << "Your Ring is empty" << endl;
	}
	else {
		for (int i = 0; i < size + 1; i++) {
			cout << help->data << endl;
			help = help->next;
		}
	}
}

template<typename T>
void MyRing<T>::insert(T data, int index)
{

	if (index == 1)
	{
		push_front(data);
	}
	else
	{
		Node<T>* curr = (*this)[index];
		curr->prev = new Node<T>(data, curr, curr->prev);
		curr->prev->prev->next = curr->prev;
	}
	++(this->size);
}

template<typename T>
void MyRing<T>::deleteElement(int index)
{

	Node<T>* delNode = (*this)[index];

	if (delNode == this->head && delNode)											//���� ��� "������" ������
	{
		this->head = this->head->prev;
		delNode->next->prev = delNode->prev;
		delNode->prev->next = delNode->next;
		delNode->next = nullptr;
		delNode->prev = nullptr;
		delete delNode;
	}
	else if (delNode == this->tail && delNode)										//���� ��� "�����" ������
	{
		this->tail = this->tail->next;
		delNode->next->prev = delNode->prev;
		delNode->prev->next = delNode->next;
		delNode->next = nullptr;
		delNode->prev = nullptr;
		delete delNode;
	}
	else if (!(this->head == this->head && this->size == -1) && delNode)		//���� ������ �� ������
	{

		delNode->next->prev = delNode->prev;
		delNode->prev->next = delNode->next;
		delNode->next = nullptr;
		delNode->prev = nullptr;
		delete delNode;
	}

	--(this->size);
}

template<typename T>
Node<T>* MyRing<T>::operator[](const int index)
{
	Node<T>* currNode = this->head;

	if (index >= 0 && index <= this->size) {
		for (int i = 0; i < index; ++i) currNode = currNode->next;
	}
	return currNode;
}


template<typename T>
void MyRing<T>::sortDescending()
{
	Iterator<T> tmp = Begin(), next = Begin();
	++next;
	T chen;

	for (int i = 0; i < this->size; i++) {
		tmp = Begin(); next = Begin(); ++next;
		do {
			if (*tmp > *next)
			{
				chen = *tmp;
				*tmp = *next;
				*next = chen;

				++tmp;
				++next;
			}
			else {
				++tmp;
				++next;
			}
		} while (next != Begin());
	}

}

template<typename T>
void MyRing<T>::sortAscending()
{
	Iterator<T> tmp = Begin(), next = Begin();
	++next;
	T chen;

	for (int i = 0; i < this->size; i++) {
		tmp = Begin(); next = Begin(); ++next;
		do {
			if (*tmp < *next)
			{
				chen = *tmp;
				*tmp = *next;
				*next = chen;

				++tmp;
				++next;
			}
			else {
				++tmp;
				++next;
			}
		} while (next != Begin());
	}

}

template<typename T>
void MyRing<T>::find(MyRing<T>& newRing)
{
	T obj;
	cout << endl << "Enter information to find: ";
	cin >> obj;
	Iterator<T> it = Begin();

	do {
		if (*it == obj)
			newRing.push_back(*it);
		++it;
	} while (it != Begin());


}

template<typename T>
void MyRing<T>::inputRing(int index) {

	T data;
	cin >> data;

	if (index == 0)
		this->push_front(data);
	else if (index == this->size + 1)
		this->push_back(data);
	else
		this->insert(data, index);

}

template<typename T>
void MyRing<T>::clear()
{
	if (this != NULL && this->size != -1) {
		while (this->size) deleteElement(0);
		deleteElement(0);
	}

}
