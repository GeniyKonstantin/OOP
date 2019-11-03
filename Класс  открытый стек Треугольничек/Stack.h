#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Stack
{
private:
	template <typename T>
	class Node // узел, который содержит адрес след элемента и данные
	{
	public: // т.к. он и так в private секции класса List
		Node* pNext;  // указатель на след элемент
		T data;   //  переменная типа T, хранящая в себе данные
		Node(T data=T(), Node* pNext = nullptr) // конструктор, pNext=nullptr чтобы мы могли передать только данные , например для последнего элемента, который указывает на NULL
		{
			this->data = data;
			this->pNext = pNext;
		}

	};
	int size;   // колличество элементов (Node), чтобы знать сколько элементов всего в списке, и не затрачивать время на перебор всех элементов
	Node <T> *head;  // головной элемент через который мы будем находить все остальные
public:
	Stack();
	~Stack();

	void push_back(T data);
	T pop_back();
	int get_size() const { return size; };
	T& operator[](const int index) const;
	int search(T data) const;
	void print() const;
	void clear();

};

template <typename T>
Stack <T>::Stack()
{
	size = 0;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
void Stack<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node <T>* p;
		p = head;
		while (p->pNext!=nullptr)
		{
			p = p->pNext;
		}
		p->pNext = new Node <T>(data);
	}
	size++;
}

template<typename T>
T Stack<T>::pop_back()
{
	if (size != 0)
	{
		Node <T>* p = head,*temp;
		T data;
		for (int i = 1; i <size-1; i++)
		{
			p = p->pNext;
		}
	
		data = p->pNext->data;
		temp = p->pNext;
		p->pNext = nullptr;
		delete temp;
		temp = nullptr;
		size--;
		return data;
	}
}

template<typename T>
T& Stack<T>::operator[](const int index) const
{
	if (index < size)
	{
		Node <T>* p = head;
		for (int i = 0; i < index; i++)
			p = p->pNext;
		return p->data;
	}
}

template<typename T>
int Stack<T>::search(T data) const
{
	for (int i = 0; i < size; i++)
		if (Stack::operator[](i) == data)
			return i;
}

template<typename T>
inline void Stack<T>::print() const
{
	Node<T>* p=head;
	cout << p->data << "\t";
	while (p->pNext != nullptr)
	{
		p = p->pNext;
		cout << p->data << "\t";
	}
}


template<typename T>
void Stack<T>::clear()
{
	while (size != 0)
	{
		Node<T>* p = head;
		head = head->pNext;
		delete p;
		size--;
	}
	head = nullptr;
}
