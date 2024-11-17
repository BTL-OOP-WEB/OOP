#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <initializer_list>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value, Node* nextNode = nullptr);
    };

    Node* head;
    Node* tail;
    size_t listSize;

    Node* getNode(size_t index) const;

public:
    LinkedList();
    LinkedList(std::initializer_list<T> values);
    ~LinkedList();

    size_t size() const;
    bool empty() const;
    void push_back(const T& value);
    void insert(size_t index, const T& value);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    void erase(size_t index);
    void pop_back();
    int find(const T& value) const;
    void clear();
};

#endif // LINKEDLIST_H
