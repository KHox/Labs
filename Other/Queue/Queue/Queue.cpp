#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

struct Queue {
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
};

void push(Queue* queue, int value);
void pop(Queue* queue);
void showl(Queue* queue);
void showf(Queue* queue);

int main()
{
    setlocale(LC_ALL, "Russian");
    Queue* queue = new Queue;
    int n, value;
    do {
        system("cls");
        cout << "Введите 0 для завершения работы\n";
        cout << "Введите 1 для добавления элемента \n";
        cout << "Введите 2 для удаление элемента\n";
        cout << "Введите 3 для показа первого элемента очереди\n";
        cout << "Введите 4 для показа последнего элемента очереди\n";
        cout << "=================================================\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "  Введите значение элемента "; cin >> value;
            push(queue, value);
            break;
        }
        case 2:
        {
            pop(queue);
            break;
        }
        case 3:
        {
            showf(queue);
            cout << " Введите чтобы продолжить ";cin >> value;
            break;
        }
        case 4:
        {
            showl(queue);
            cout << " Введите чтобы продолжить ";cin >> value;
            break;
        }
        case 0:
            cout << " Завершение работы ";
            break;
        }
    } while (n != 0);

    delete queue;
}

void push(Queue* queue, int value)
{
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;

    if (queue->head == nullptr)
    {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }

    queue->size++;
}

void pop(Queue* queue)
{
    if (queue->head != nullptr)
    {
        Node* temp = queue->head;
        queue->head = temp->next;

        if (queue->head == nullptr)
        {
            queue->tail = nullptr;
        }

        queue->size--;
        delete temp;
    }
}
void showf(Queue* queue)
{
    if (queue->head == nullptr)
    {
        cout << "Очередь пуста\n";
    }
    else
    {
        cout << "Первый элемент очереди - " << queue->head->data << endl;
    }
}
void showl(Queue* queue)
{
    if (queue->head == nullptr)
        cout << "Очередь пуста\n";
    else
        cout << "Последний элемент очереди - " << queue->tail->data << endl;
}