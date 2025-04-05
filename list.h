#pragma once
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

template<typename T>
class List
{
public:
	List();
	~List();
	void push_back(T data);
	void push_front(T data);
	int GetSize() { return size; }
	T back();
	bool empty() { return size == 0; }
	void pop_front();
	void clear();
	void pop_back();
	void insert(T data, int index);
	T& operator[](const int index);

private:
	template<typename T>
	class Node
	{
	public:
		T data;
		Node* next;
		Node* prev;
		Node(T data = T(), Node* next = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};

	int size;
	Node<T>* head;
	Node<T>* taill;


};
template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
	taill = nullptr;
}



template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (head == nullptr)
	{
		head = taill = newNode;
	}
	else
	{
		taill->next = newNode;
		newNode->prev = taill;
		taill = newNode;
	}
	size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	Node<T>* new newNode<T>(data, head);
	if (head == nullptr)
	{
		head = taill = newNode;
	}
	else
	{
		head->prev = newNode;
		head = newNode;
	}
	size++;
}

template<typename T>
T List<T>::back()
{
	if (taill != nullptr)
	{
		return taill->data;
	}
	throw std::out_of_range("Список пустой!");

}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* Delet_front = head;
	head = head->next;
	if (head != nullptr)
	{
		head->prev = nullptr;
	}
	else
	{
		taill = nullptr;
	}
	delete Delet_front;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::pop_back()
{
	Node<T>* tmp = taill;
	taill = taill->prev;
	if (taill != nullptr)
	{
		taill->next = nullptr;
	}
	else
	{
		head = nullptr;
	}
	delete tmp;
	size--;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	int count = 0;
	if (index == 0)
	{
		push_front(data);
		return;
	}
	else if (index == size)
	{
		push_back(data);
		return;
	}
	else if (index >= size / 2)
	{
		Node<T>* tmp = taill;
		for (int i = size - 1; i >= index + 1; i--)
		{
			tmp = tmp->prev;
		}
		Node<T>* newNode(data, tmp->next, tmp->prev);
		tmp->prev->next = newNode;
		tmp->prev = newNode;
		size++;
	}
	else if (index < size / 2)
	{
		Node<T>* tmp = head;
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}
		Node<T>* newNode(data, tmp->next, tmp->prev);
		tmp->next->prev = newNode;
		tmp->next = newNode;
		size++;

	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	if (index >= size || index < 0)
	{
		throw index;
	}

	int count = 0;
	Node<T>* current = head;
	while (current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}
		current = current->next;
		count++;
	}
}

template<typename T>
List<T>::~List()
{
	clear();
}
