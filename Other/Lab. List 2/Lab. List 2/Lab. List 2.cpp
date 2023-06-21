#include <iostream>
#include "windows.h"
using namespace std;
struct Node {
	int data;
	Node* next;
	Node* prev;
};
struct List {
	Node* head;
	Node* tail;
	int count;
};

void show_list(List& list);
void push_front(List& list, int value);
int pop_front(List& list);
void push_back(List& list, int value);
int pop_back(List& list);
int add_after(List& list, int value, int number);
void removeelement(List& list, int number);
int add_several(List& list, int number, int k);
void clear_list(List& list);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List list;
	list.head = NULL;
	list.tail = NULL;
	list.count = 0;
	int n, value, number, k, flag;
	do {
		system("cls");
		cout << "Введите 0 для завершения работы\n";
		cout << "Введите 1 для показа списка\n";
		cout << "Введите 2 для добавления элемента в начало списка\n";
		cout << "Введите 3 для добавления элемента в конец списка\n";
		cout << "Введите 4 для удаления элемента в начале списка\n";
		cout << "Введите 5 для удаления элемента в конце списка\n";
		cout << "Введите 6 для добавления элемента после элемента с заданным номером\n";
		cout << "Введите 7 для удаления элемента с заданным номером\n";
		cout << "Введите 8 для добавление k элементов после элемента с заданным номером\n";
		cout << "Введите 9 для удаления k элементов после элемента с заданным номером\n";
		cout << "Введите 10 для удаления данных из списка\n";
		cout << "============================================================================\n";
		cin >> n;
		switch (n)
		{
		case 1:
		{
			show_list(list);
			cout << "Введите что бы продолжить\n"; cin >> value;
			break;
		}
		case 2:
		{
			cout << " Введите значение элемента, для вставки в начало "; cin >> value;
			push_front(list, value);
			break;
		}
		case 3:
		{
			cout << " Введите значение элемента, для вставки в конец "; cin >> value;
			push_back(list, value);
			break;
		}
		case 4:
		{
			cout << " Удаление в начале списка \n";
			flag = pop_front(list);
			if (flag == -1) cout << "  Список пуст\n";
			else cout << " Элемент в начале списка со значением - " << flag << " был  удален \n";
			break;
		}
		case 5:
		{
			cout << " Удаление в конце списка \n";
			flag = pop_back(list);
			if (flag == -1) cout << "  Список пуст\n";
			else cout << " Элемент в конце списка со значением - " << flag << " был  удален \n";
			break;
		}

		case 6:
		{
			cout << " Введите номер элемента, после которого нужно вставить элемент  ";  cin >> number;
			cout << " Введите значение элемента для вставки "; cin >> value;
			flag = add_after(list, value, number - 1);
			if (flag == -1) cout << " Что-то введено неверно :( ";
			break;
		}

		case 7:
		{
			cout << " Введите номер элемента, который нужно удалить ";cin >> number;
			removeelement(list, number);
			break;
		}

		case 8:
		{
			cout << " Введите номер элемента, после которого нужно вставить элементы  ";  cin >> number;
			cout << "Введите количество элементов для вставки "; cin >> k;
			flag = add_several(list, number - 1, k);
			if (flag == -1) cout << "  Что-то введено неверно :(\n";
			break;
		}
		case 9:
		{
			cout << "Введите количество элементов для удаления "; cin >> k;
			cout << " Введите номер элемента,после которого нужно удалить ";cin >> number;
			for (int i = 0;i < k;i++)
			{
				removeelement(list, number);
			}
			break;
		}
		case 10:
		{
			clear_list(list);
			cout << "Данные удалены ";
			break;
		}
		case 0:
			cout << " Завершение работы ";
			break;
		}
	} while (n != 0);
}
void show_list(List& list) {
	Node* temp = list.head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void push_front(List& list, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = list.head;
	newNode->prev = nullptr;
	if (list.head != nullptr) {
		list.head->prev = newNode;
	}
	list.head = newNode;
	if (list.tail == nullptr) {
		list.tail = newNode;
	}
	++list.count;
}

int pop_front(List& list) {
	if (list.head == nullptr) {
		return -1;
	}

	int result = list.head->data;
	Node* temp = list.head;
	list.head = list.head->next;
	if (list.head != nullptr) {
		list.head->prev = nullptr;
	}
	else {
		list.tail = nullptr;
	}
	delete temp;

	return result;
}

void push_back(List& list, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = list.tail;
	if (list.tail != nullptr)
	{
		list.tail->next = newNode;
	}
	list.tail = newNode;
	if (list.head == nullptr) {
		list.head = newNode;
	}
	list.count++;
}

int pop_back(List& list) {
	if (list.head == nullptr) {
		return -1;
	}
	Node* temp = list.tail;
	int result = temp->data;
	if (list.head == list.tail) {
		list.head = nullptr;
		list.tail = nullptr;
	}
	else {
		list.tail = temp->prev;
		list.tail->next = nullptr;
	}
	delete temp;
	list.count--;
	return result;
}

int add_after(List& list, int value, int number) {
	if (list.head == nullptr || number >= list.count) {
		return -1;
	}
	Node* current = list.head;
	for (int i = 1; i <= number && current != nullptr; i++) {
		current = current->next;
	}
	if (current == nullptr) {
		return -1;
	}
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = current->next;
	current->next = newNode;
	newNode->prev = current;
	if (newNode->next != nullptr) {
		newNode->next->prev = newNode;
	}
	else {
		list.tail = newNode;
	}
	list.count++;
	return 0;
}

void removeelement(List& list, int number) {
	if (number < 1 || number > list.count) {
		return;
	}

	if (number == 1) {
		Node* temp = list.head;

		list.head = list.head->next;

		delete temp;

		list.count--;

		return;
	}
	if (number == list.count)
	{
		Node* temp = list.tail;
		list.tail = list.tail->prev;
		list.tail->next = nullptr;
		delete temp;
		list.count--;
		return;
	}
	Node* temp = list.head;

	for (int i = 1; i < number - 1; i++) {
		temp = temp->next;
	}

	Node* delNode = temp->next;
	temp->next = delNode->next;
	temp = delNode->next;
	temp->prev = delNode->prev;
	delete delNode;

	list.count--;
}

int add_several(List& list, int number, int k) {
	if (list.head == nullptr || number >= list.count || k <= 0) {
		return -1;
	}
	Node* current = list.head;
	for (int i = 1; i <= number && current != nullptr; i++) {
		current = current->next;
	}
	if (current == nullptr) {
		return -1;
	}
	for (int i = 0; i < k; i++) {
		int value;
		cout << "Введите значение для вставки элемента\n";  cin >> value;
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = current->next;
		current->next = newNode;
		newNode->prev = current;
		if (newNode->next != nullptr) {
			newNode->next->prev = newNode;
		}
		else {
			list.tail = newNode;
		}
		list.count++;
		current = newNode;
	}
	return 0;
}

void clear_list(List& list) {
	Node* temp = list.head;

	while (temp != nullptr) {
		Node* delNode = temp;

		temp = temp->next;

		delete delNode;
	}
	list.head = nullptr;
	list.tail = nullptr;
	list.count = 0;
}