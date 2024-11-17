#include "../declare/LinkedList.h"

template <typename T>
LinkedList<T>::Node::Node(const T& value, Node* nextNode)
    : data(value), next(nextNode) {}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> values) : LinkedList() {
    for (const auto& value : values) {
        push_back(value);
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
size_t LinkedList<T>::size() const {
    return listSize;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return listSize == 0;
}

template <typename T>
void LinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++listSize;
}

template <typename T>
void LinkedList<T>::insert(size_t index, const T& value) {
    if (index > listSize) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        head = new Node(value, head);
        if (listSize == 0) {
            tail = head;
        }
    } else {
        Node* prev = getNode(index - 1);
        prev->next = new Node(value, prev->next);
        if (prev == tail) {
            tail = prev->next;
        }
    }
    ++listSize;
}

template <typename T>
T& LinkedList<T>::operator[](size_t index) {
    return getNode(index)->data;
}

template <typename T>
const T& LinkedList<T>::operator[](size_t index) const {
    return getNode(index)->data;
}

template <typename T>
void LinkedList<T>::erase(size_t index) {
    if (index >= listSize) {
        throw std::out_of_range("Index out of range");
    }

    Node* toDelete;
    if (index == 0) {
        toDelete = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node* prev = getNode(index - 1);
        toDelete = prev->next;
        prev->next = toDelete->next;
        if (toDelete == tail) {
            tail = prev;
        }
    }
    delete toDelete;
    --listSize;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    erase(listSize - 1);
}

template <typename T>
int LinkedList<T>::find(const T& value) const {
    Node* current = head;
    for (size_t i = 0; i < listSize; ++i) {
        if (current->data == value) {
            return i;
        }
        current = current->next;
    }
    return -1;
}

template <typename T>
void LinkedList<T>::clear() {
    while (!empty()) {
        pop_back();
    }
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getNode(size_t index) const {
    if (index >= listSize) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}
