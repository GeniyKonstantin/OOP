/*#include "Stack.h"
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
		head->pNext = new Node<T>(data);
	}
	else
	{
		Node <T>* p;
		p = head;
		for (int i = 0; i < size; i++)
			p = p->pNext;
		p->pNext = new Node <T>(data);
	}
	size++;
}

template<typename T>
T Stack<T>::pop_back()
{
	if (size != 0)
	{
		Node <T>* p=head;
		T data;
		for (int i = 0; i < size; i++)
			p = p->pNext;
		data = p->data;
		delete p;
		p = nullptr;
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
		Stack <T> p;
		for (int i = 0; i < size; i++)
			if (p[i] == data)
				return i;
}


template<typename T>
void Stack<T>::clear()
{
	while(size!=0)
	{
		Node<T>* p = head;
		head = head->pNext;
		delete p;
		size--;
	}
	head = nullptr;
}
*/