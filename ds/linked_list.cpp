#include <iostream>
using namespace std;

template <class T>
struct node {
    T data;
    node *next;

    node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
struct LinkedList {
    node<T> *head;

    LinkedList() { this->head = nullptr; }

    int size();

    void push_back(T);
    void push_front(T);
    bool insert(T, unsigned int);
    bool pop();
    bool pop_front();
    void print();
};

template <class T>
int LinkedList<T>::size() {
    if (this->head == nullptr) return 0;

    node<T> *temp = this->head;

    int lenght(0);
    while (temp != nullptr) {
        temp = temp->next;
        lenght++;
    }

    return lenght;
}

template <class T>
void LinkedList<T>::print() {
    if (this->size() == 0) return;

    node<T> *temp = this->head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

template <class T>
void LinkedList<T>::push_back(T data) {
    if (this->size() == 0) {
        node<T> *add = new node<T>(data);
        this->head = add;
        return;
    }

    node<T> *temp = this->head;
    while (temp->next != nullptr) temp = temp->next;
    node<T> *add = new node<T>(data);
    temp->next = add;
}

template <class T>
bool LinkedList<T>::insert(T data, unsigned int index) {
    int length = this->size();

    if (index >= length) return false;
    if (index == 0) {
        this->push_front(data);
        return true;
    }

    if (index == length - 1) {
        this->push_back(data);
        return true;
    }

    int i = 0;
    node<T> *current = this->head;
    node<T> *previous = this->head;

    while (current->next != nullptr && i < index) {
        previous = current;
        current = current->next;
        i++;
    }

    node<T> *add = new node<T>(data);
    add->next = current;
    previous->next = add;
    return true;
}

template <class T>
void LinkedList<T>::push_front(T data) {
    if (this->size() == 0) {
        this->head = new node<T>(data);
        return;
    }

    node<T> *add = new node<T>(data);
    add->next = this->head;
    this->head = add;
    return;
}

template <class T>
bool LinkedList<T>::pop() {
    if (this->size() == 0) return false;

    node<T> *current = this->head;
    node<T> *previous = this->head;

    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    delete current;
    previous->next = nullptr;
    return true;
}

template <class T>
bool LinkedList<T>::pop_front() {
    if (this->size() == 0) return false;

    node<T> *current = this->head;
    node<T> *next = current->next;

    delete current;
    this->head = next;
    return true;
}

int main(void) {
    std::cout << "hello, world!" << std::endl;
    LinkedList<char> kt;
    for (int i = 65; i <= 90; i++) kt.push_back(i);
    for (int i = 57; i > 47; i--) kt.push_front(i);
    kt.print();
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) kt.pop();
    for (int i = 0; i < 5; i++) kt.pop_front();
    kt.print();
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) kt.insert('$', 5);
    std::cout << "size of linkedlist(kt) = " << kt.size() << '\n';
    kt.insert('^', 40);
    kt.insert('^', 0);
    kt.insert('^', -1);
    kt.print();
    std::cout << std::endl;

    LinkedList<std::string> kt2;
    kt2.push_back("keshav0");
    kt2.push_back("keshav1");
    kt2.push_back("keshav2");
    kt2.push_back("keshav3");
    kt2.push_back("keshav4");
    kt2.push_back("keshav5");
    kt2.print();
    return 0;
}
