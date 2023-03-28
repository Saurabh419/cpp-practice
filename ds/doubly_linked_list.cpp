#include <bits/stdc++.h>
using namespace std;

template <class T>
struct node {
    T data;
    node *next;
    node *prev;

    node(T data) {
        this->data = data;
        this->next = this->prev = nullptr;
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
