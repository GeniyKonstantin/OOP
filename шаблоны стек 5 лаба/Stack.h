#pragma once
#include <string>
#include <iostream>
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
	const T& operator[](const int index) const;
	int search(T data) const;
	void print() const;
	void clear();
	void draw();
	void readfile(string s);
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
		Node <T>* p	=new Node<T>;
		p->pNext = head;
		p->data = data;
		Node <T>* temp = head;
		head = p;
		p = temp;
		temp = nullptr;
	}
	size++;
}

template<typename T>
T Stack<T>::pop_back()
{
	if (size != 0)
	{
		Node <T>*temp=head->pNext;
		T data;
		data = head->data;
		delete head;
		head = temp;
		size--;
		return data;
	}
}

template<typename T>
const T& Stack<T>::operator[](const int index) const
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

void Stack <Outline*> ::draw()
{
	head->data->draw();
}
void Stack <Painted*> ::draw()
{
	head->data->draw();
}
void Stack <Nested*> ::draw()
{
	head->data->draw();
}
void Stack <Outline*>  ::readfile(string s)
{
	Outline *a=new Outline;
	a->read_file(s);
	Stack::push_back(a);
}
void Stack <Painted*>  ::readfile(string s)
{
	Painted* a = new Painted;
	a->read_file(s);
	Stack::push_back(a);
}
void Stack <Nested*>  ::readfile(string s)
{
	Nested* a = new Nested;
	a->read_file(s);
	Stack::push_back(a);
}

