#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

struct Stack {
    int size = 0;
    Node* head = nullptr;
};

void push(Stack*, int value);
void pop(Stack*);
void last(Stack*);

int main()
{
    setlocale(LC_ALL, "Russian");
    Stack* stack = new Stack;
    int n, value;
    do {
        system("cls");
        cout << "Введите 0 для завершения работы\n";
        cout << "Введите 1 для добавления элемента \n";
        cout << "Введите 2 для удаление элемента\n";
        cout << "Введите 3 для показа верхушки стэка\n";
        cout << "============================================================================\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "  Введите значение элемента "; cin >> value;
            push(stack, value);
            break;
        }
        case 2:
        {
            pop(stack);
            break;
        }
        case 3:
        {
            last(stack);
            cout << " Введите чтобы продолжить ";cin >> value;
            break;
        }
        case 0:
            cout << " Завершение работы ";
            break;
        }
    } while (n != 0);

    delete stack;
}

void push(Stack* stack, int value)
{
    if (stack->head == nullptr)
        stack->head = new Node{ value };
    else
    {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = stack->head;
        stack->head = new_node;
    }
    stack->size++;
}

void pop(Stack* stack)
{
    if (stack->head != nullptr)
    {
        Node* temp = stack->head;
        stack->head = temp->next;
        stack->size--;
        delete temp;
    }
}

void last(Stack* stack)
{
    if (stack->head == nullptr)
        cout << "Стек пуст\n";
    else
        cout << "Элемент верхушки стека - " << stack->head->data << endl;
}