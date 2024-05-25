#pragma once

#include "Iteratorint.h"

#define LIST_MAX_SIZE 1'000'000

class Listint {
private:
    ListNodeint* head;
    ListNodeint* tail;
    size_t con_size;

public:
    Listint() {
        this->head = nullptr;
        this->tail = nullptr;
        this->con_size = 0;

    }
    ~Listint() {
        clear();
    }

    Iteratorint begin() {
        return Iteratorint(head);
    }
    Iteratorint end() {
        return Iteratorint(nullptr);
    }
    const Iteratorint cbegin() const {
        return Iteratorint(head);
    }
    const Iteratorint cend() const {
        return Iteratorint(tail);
    }

    int& operator[](size_t index) {
        if (index >= con_size - 1) return (tail->val);

        ListNodeint* cache = this->head;
        for (int i = 1; i <= index; i++) {
            cache = cache->next;
        }
        return (cache->val);
    }

    bool operator==(const Listint& other) const {
        return (con_size == other.con_size) && equals(cbegin(), cend(), other.cbegin());
    }
    bool operator!=(const Listint& other) const {
        return !(*this == other);
    }

    void swap(Listint& other) {
        ListNodeint* cache_head = other.head;
        ListNodeint* cache_tail = other.tail;
        size_t size = other.size();

        other.head = this->head;
        other.tail = this->tail;
        other.con_size = this->con_size;

        head = cache_head;
        tail = cache_tail;
        con_size = size;

    }

    size_t max_size() const {
        return LIST_MAX_SIZE;
    }
    size_t size() const {
        return con_size;
    }
    size_t find(int x) {
        if (this->head == nullptr) return -1;
        ListNodeint* cache = this->head;
        size_t index = 0;
        while (cache->next != nullptr) {
            if (cache->val == x) return index;
            cache = cache->next;
            index++;
        }
        return -1;
    }
    bool empty() const {
        return !con_size;
    }

    void addElement(int x) {
        if (this->head == nullptr) this->head = new ListNodeint(x);
        else {
            ListNodeint* cache = this->head;

            while (cache->next != nullptr) {
                cache = cache->next;
            }
            cache->next = new ListNodeint(x);
            this->tail = cache->next;
        }
        this->con_size++;
    }
    void deleteElement(int el) {
        if (this->head == nullptr) {
            std::cout << "List is empty!\n";
        }
        else if (this->head && this->head->val == el) {
            ListNodeint* cache = this->head->next;
            delete this->head;
            this->head = cache;
            this->con_size--;
            return;
        }
        else if (this->head) {
            ListNodeint* left = this->head;
            ListNodeint* right = this->head->next;

            while (right != nullptr) {
                if (right->val == el) {
                    left->next = right->next;
                    if (tail == right) tail = left;
                    delete right;
                    con_size--;
                    return;
                }
            }
        }
    }

    void print() {
        if (this->head == nullptr) std::cout << "List is empty!\n";
        else {
            ListNodeint* cache = this->head;
            while (cache->next != nullptr) {
                std::cout << cache->val << " | ";
                cache = cache->next;
            }
            std::cout << cache->val << '\n';
        }
    }
    void clear() {
        if (this->head == nullptr) std::cout << "List is empty!\n";
        else {
            ListNodeint* cache = this->head->next;
            while (this->head != nullptr) {
                delete this->head;
                this->head = cache;
                if (cache) cache = cache->next;
            }
            this->head = nullptr;
            this->con_size = 0;
        }
    }

};