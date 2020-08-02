#pragma once
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
};

template <class T> class Node
{
private:
	T data;
	Node *pNext;
public:
	T & GetData() { return data; }
	T& SetData(const T& d);
};

// return type: T&, type parameter <T>
template <class T> T& Node<T>::SetData(const T& d)
{
	return data = d;
}