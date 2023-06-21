#include <iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<windows.h>
#include <vector>
using namespace std;
string names[5] = { "Андрей","Сергей","Алексей","Александр","Владимир" };
string surnames[5] = { "Андреев","Сергеев","Алексеев","Александров","Владимиров" };
string patronymics[5] = { "Андреевич","Сергеевич","Алексеевич","Александрович","Владимирович" };
string teles[20] = { "88005553535","89223077612","89028327085","89223076403","89264177054","88005553536","88005553537", "88005553538", "88005553539","88005553530","88005553531","88005553532","88005553533","88005553534","89223077618","89223077617","89223077616","89223077615","89223077611","89223077614" };
string passports[5] = { "23_32_675412","99_11_231525","44_65_654122","12_44_342788","32_32_564123" };
struct Human {
    Human() {
        fio = "NULL";
        tele = "NULL";
        passport = "NULL";
    }
    string fio;
    string tele;
    string passport;

};
struct Node {
    Human data;
    Node* next = nullptr;
};
unsigned int HASH(const string key, int table_size)
{
    double A = 0.61803398875;
    double hash_value = 0;
    for (size_t i = 0; i < key.length(); i++) {
        hash_value = hash_value + (int)key[i] * pow(A, i + 1);
    }
    hash_value = hash_value - floor(hash_value);
    return (unsigned int)(floor(table_size * hash_value));
}
int getnumber() {
    return (rand() % 5);
}
string getfio() {
    return(surnames[getnumber()] + " " + names[getnumber()] + " " + patronymics[getnumber()]);
}
string gettele() {
    return(teles[(rand() % 20)]);
}
string getpassport() {
    return (passports[getnumber()]);
}
Human createhuman() {
    Human tmp;
    tmp.fio = getfio();
    tmp.tele = gettele();
    tmp.passport = getpassport();
    return tmp;
}
void showinfo(const Human tmp) {
    cout << "ФИО:" << tmp.fio << endl;
    cout << "Номер телефона:" << tmp.tele << endl;
    cout << "Паспорт:" << tmp.passport << endl;
}
void printarray(Human* array, int size) {
    for (int i = 0;i < size;i++) {
        showinfo(array[i]);
        cout << endl;
    }
}
void fillarray(Human* array, int count) {
    for (int i = 0;i < count;i++) {
        array[i] = createhuman();
    }
}
struct hashtable {
    Human* array;
    int collisioncount = 0;
    hashtable(int size) {
        array = new Human[size];
    }
    ~hashtable() {
        delete[] array;
    }
    void add(Human temp, int size) {
        int i = HASH(temp.tele, size);
        int j = i;
        if (array[i].fio == "NULL") {
            array[i] = temp;
            return;
        }
        else {
            while (i < size) {
                if (array[i].fio == "NULL") {
                    array[i] = temp;
                    return;
                }
                collisioncount++;
                i++;
            }
            if (i >= size) {
                i = 0;
                collisioncount++;
                while (i < j) {
                    if (array[i].fio == "NULL") {
                        array[i] = temp;
                        return;
                    }
                    collisioncount++;
                    i++;
                }
            }
        }
    }
    void findindex(string temp, int size) {
        int hash = HASH(temp, size);
        int index = hash;
        while (array[index].tele != temp && index < size) {
            index++;
        }
        if (index >= size) {
            index = 0;
            while (array[index].tele != temp && index < hash) {
                index++;
            }
            if (index >= hash) {
                cout << "Человек с номером телефона " << temp << " содержится по индексу " << index << endl;
            }
        }
        else {
            cout << "Человек с номером телефона " << temp << " содержится по индексу " << index << endl;
        }
    }
    void pop(string temp, int size) {
        int index = HASH(temp, size);
        if (array[index].tele == temp) {
            array[index] = Human();
            return;
        }
        else {
            while (index < size) {
                if (array[index].tele == temp) {
                    array[index] = Human();
                    return;
                }
                index++;
            }
            if (index >= size) {
                index = 0;
                while (index < size) {
                    if (array[index].tele == temp) {
                        array[index] = Human();
                        return;
                    }
                    index++;
                }
            }
        }
    }
    void infile(Human* array, int size) {
        ofstream fo("file.txt");
        for (int i = 0;i < size;i++) {
            fo << array[i].fio << endl;
            fo << array[i].tele << endl;
            fo << array[i].passport << endl;
        }
        fo.close();
    }
    void outfile(Human* array, int size) {
        ifstream fi("file.txt");
        for (int i = 0;i < size;i++) {
            getline(fi, array[i].fio);
            getline(fi, array[i].tele);
            getline(fi, array[i].passport);
        }
        fi.close();
    }
};
struct hashtable_chain {
    vector<Node*> array;
    int collisioncount = 0;
    hashtable_chain(int size) {
        array.resize(size);
    }
    ~hashtable_chain() {
        for (auto node : array) {
            while (node != nullptr) {
                Node* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }
    void add(Human temp, int size) {
        int i = HASH(temp.tele, size);
        Node* node = new Node();
        node->data = temp;
        if (array[i] == nullptr) {
            array[i] = node;
        }
        else {
            collisioncount++;
            Node* current = array[i];
            while (current->next != nullptr) {
                current = current->next;
                collisioncount++;
            }
            current->next = node;
        }
    }
    void findindex(string temp, int size) {
        int hash = HASH(temp, size);
        Node* current = array[hash];
        int index = hash;
        while (current != nullptr && current->data.tele != temp) {
            current = current->next;
            index++;
        }
        if (current != nullptr) {
            cout << "Человек с номером телефона " << temp << " содержится по индексу " << index << endl;
        }
        else {
            cout << "Человек с номером телефона " << temp << " не найден" << endl;
        }
    }
    void pop(string temp, int size) {
        int index = HASH(temp, size);
        Node* current = array[index];
        Node* prev = nullptr;
        while (current != nullptr && current->data.tele != temp) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            else {
                array[index] = current->next;
            }
            delete current;
        }
    }
    void infile(vector<Node*>& array, int size) {
        ofstream fo("file.txt");
        for (int i = 0; i < size; i++) {
            Node* current = array[i];
            while (current != nullptr) {
                fo << current->data.fio << endl;
                fo << current->data.tele << endl;
                fo << current->data.passport << endl;
                current = current->next;
            }
        }
        fo.close();
    }
    void outfile(vector<Node*>& array, int size) {
        ifstream fi("file.txt");
        for (int i = 0; i < size; i++) {
            string fio, tele, passport;
            getline(fi, fio);
            getline(fi, tele);
            getline(fi, passport);
            Human temp;
            temp.fio = fio;
            temp.tele = tele;
            temp.passport = passport;
            int index = HASH(tele, size);
            Node* node = new Node();
            node->data = temp;
            if (array[index] == nullptr) {
                array[index] = node;
            }
            else {
                Node* current = array[index];
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = node;
            }
        }
        fi.close();
    }
};
void showhash(hashtable* newhash, int size) {
    for (int i = 0;i < size;i++) {
        showinfo(newhash->array[i]);
        cout << endl;
    }
}
void showhashtable(hashtable_chain* newhash, int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        Node* current = newhash->array[i];
        while (current != nullptr) {
            j++;
            cout << " Номер - " << j << endl;
            cout << "ФИО:" << current->data.fio << endl;
            cout << "Номер телефона:" << current->data.tele << endl;
            cout << "Паспорт:" << current->data.passport << endl;
            current = current->next;
            cout << endl;
        }
    }
}
int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    int size = 0;
    while (size < 10) {
        cout << "Введите число элементов массива:";
        cin >> size;
    }
    cout << endl;
    Human* array = new Human[size];
    hashtable newtable(size);
    hashtable_chain newtable2(size);
    fillarray(array, size);
    printarray(array, size);
    cout << "=======================================================" << endl;
    for (int j = 0;j < size;j++) {
        newtable.add(array[j], size);
        newtable2.add(array[j], size);
    }
    showhash(&newtable, size);
    newtable.findindex("88005553535", size);
    system("pause");
    newtable.pop("88005553535", size);
    cout << "=======================================================" << endl;
    showhash(&newtable, size);
    cout << "Количество коллизий на " << size << " элементов - " << newtable.collisioncount << endl;
    cout << "Это был метод открытой адресации, сейчас будет метод цепочек " << endl;
    system("pause");
    system("cls");
    showhashtable(&newtable2, size);
    newtable2.findindex("88005553535", size);
    system("pause");
    newtable2.pop("88005553535", size);
    cout << "=======================================================" << endl;
    showhashtable(&newtable2, size);
    cout << "Количество коллизий на " << size << " элементов - " << newtable2.collisioncount << endl;
    delete[] array;
}