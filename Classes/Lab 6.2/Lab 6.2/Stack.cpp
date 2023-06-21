#include "stack.h"
#include <iostream>
using namespace std;
stack::stack()
{
	size = 0;
	head = nullptr;
}
stack::stack(int s)
{
	for (int i = 0; i < s; i++) {
		push(0);
	}
	size = s;
}
stack::~stack()
{
	node* temp = head;
	while (temp != nullptr) {
		head = temp->next;
		delete temp;
		temp = head;
	}
}
void stack::push(int  data)
{
	node* new_node = new node;
	new_node->data = data;
	new_node->next = head;
	head = new_node;
	size++;
}
void stack::pop()
{
	node* temp = head;
	head = temp->next;
	size--;
	delete temp;
}
void stack::showlast()
{
	if (head == nullptr)
		cout << "Стек пуст\n";
	else
		cout << "Элемент верхушки стека - " << head->data << endl;
}
bool stack::empty()
{
	return size == 0;
}
int stack::getsize()
{
	return size;
}