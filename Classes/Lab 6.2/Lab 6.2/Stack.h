#pragma once
struct node
{
	node* next = nullptr;
	int data = 0;
}
;
class stack
{
public:
	stack();
	stack(int s);
	~stack();
	void push(int);
	void pop();
	void showlast();
	bool empty();
	int getsize();
private:
	int size;
	node* head = nullptr;
};