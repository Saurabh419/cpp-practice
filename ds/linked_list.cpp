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
    ll_singly_node<T> *root;

    SinglyLinkedList() { this->root = nullptr; }

    int size();

    void push_back(T);
    void push_front(T);
    void insert(T, int);
    bool pop();
    bool pop_front();
    void print();
};

template <class T>
int SinglyLinkedList<T>::size() {
    if (this->root == nullptr) return 0;

    ll_singly_node<T> *temp = this->root;

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

    ll_singly_node<T> *temp = this->root;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

template <class T>
void SinglyLinkedList<T>::push_back(T data) {
    if (this->size() == 0) {
        ll_singly_node<T> *add = new ll_singly_node<T>(data);
        this->root = add;
        return;
    }

    ll_singly_node<T> *temp = this->root;
    while (temp->next != nullptr) temp = temp->next;
    ll_singly_node<T> *add = new ll_singly_node<T>(data);
    temp->next = add;
}

int main(void) {
    std::cout << "hello, world!" << std::endl;
    SinglyLinkedList<char> kt;
    for (int i = 65; i <= 90; i++) kt.push_back(i);
    kt.print();
    std::cout << std::endl;
    return 0;
}
