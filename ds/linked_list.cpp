#include <bits/stdc++.h>

#include <cstdint>
#include <iostream>
using namespace std;

template <class T>
struct ll_doubly_node {
    T data;
    ll_doubly_node *next;
    ll_doubly_node *prev;

    ll_doubly_node(T data) {
        this->data = data;
        this->next = this->prev = nullptr;
    }
};

template <class T>
struct ll_singly_node {
    T data;
    ll_singly_node *next;

    ll_singly_node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
struct SinglyLinkedList {
    ll_singly_node<T> *head;

    SinglyLinkedList() { this->head = nullptr; }

    int size();

    void push_back(T);
    void push_front(T);
    bool insert(T, unsigned int);
    bool pop();
    bool pop_front();
    void print();
};

template <class T>
int SinglyLinkedList<T>::size() {
    if (this->head == nullptr) return 0;

    ll_singly_node<T> *temp = this->head;

    int lenght(0);
    while (temp != nullptr) {
        temp = temp->next;
        lenght++;
    }

    return lenght;
}

template <class T>
void SinglyLinkedList<T>::print() {
    if (this->size() == 0) return;

    ll_singly_node<T> *temp = this->head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

template <class T>
void SinglyLinkedList<T>::push_back(T data) {
    if (this->size() == 0) {
        ll_singly_node<T> *add = new ll_singly_node<T>(data);
        this->head = add;
        return;
    }

    ll_singly_node<T> *temp = this->head;
    while (temp->next != nullptr) temp = temp->next;
    ll_singly_node<T> *add = new ll_singly_node<T>(data);
    temp->next = add;
}

template <class T>
bool SinglyLinkedList<T>::insert(T data, unsigned int index) {
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
    ll_singly_node<T> *current = this->head;
    ll_singly_node<T> *previous = this->head;

    while (current->next != nullptr && i < index) {
        previous = current;
        current = current->next;
        i++;
    }

    ll_singly_node<T> *add = new ll_singly_node<T>(data);
    add->next = current;
    previous->next = add;
    return true;
}

template <class T>
void SinglyLinkedList<T>::push_front(T data) {
    if (this->size() == 0) {
        this->head = new ll_singly_node<T>(data);
        return;
    }

    ll_singly_node<T> *add = new ll_singly_node<T>(data);
    add->next = this->head;
    this->head = add;
    return;
}

template <class T>
bool SinglyLinkedList<T>::pop() {
    if (this->size() == 0) return false;

    ll_singly_node<T> *current = this->head;
    ll_singly_node<T> *previous = this->head;

    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    delete current;
    previous->next = nullptr;
    return true;
}

template <class T>
bool SinglyLinkedList<T>::pop_front() {
    if (this->size() == 0) return false;

    ll_singly_node<T> *current = this->head;
    ll_singly_node<T> *next = current->next;

    delete current;
    this->head = next;
    return true;
}

int main(void) {
    std::cout << "hello, world!" << std::endl;
    SinglyLinkedList<char> kt;
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
    return 0;
}
