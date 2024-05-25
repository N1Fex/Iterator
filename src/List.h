#pragma once

#include "ListNode.h"
#include "Iterator.h"

#define CONTAINER_MAX_SIZE 1'000'000

template <typename T>
class Container {
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    size_t con_size;
    
public:    
    using ValueType = T;
    using NodeType = ListNode<ValueType>;
    using Iterator = ContainerIterator<Container<ValueType>>;
public:
    Container() {
        this->head = nullptr;
        this->tail = nullptr;
        this->con_size = 0;

    }
    ~Container() {
        clear();
    }

    Iterator begin() {
        return Iterator(head);
    }
    Iterator end() {
        return Iterator(nullptr);
    }
    const Iterator cbegin() const{
        return Iterator(head);
    }
    const Iterator cend() const {
        return Iterator(tail);
    }

    ValueType& operator[](size_t index) {
        if (index >= con_size-1) return (tail->val);

        ListNode<ValueType>* cache = this->head;
        for (int i = 1; i <= index; i++) {
            cache = cache->next;
        }
        return (cache->val);
    }

    bool operator==(const Container& other) const{
        return (con_size == other.con_size) && equals(cbegin(), cend(), other.cbegin());
    }
    bool operator!=(const Container& other) const {
        return !(*this == other);
    }

    void swap(Container<T>& other) {
        ListNode<T>* cache_head = other.head;
        ListNode<T>* cache_tail = other.tail;
        size_t size = other.size();

        other.head = this->head;
        other.tail = this->tail;
        other.con_size = this->con_size;

        head = cache_head;
        tail = cache_tail;
        con_size = size;

    }

    size_t max_size() const {
        return CONTAINER_MAX_SIZE;
    }
    size_t size() const {
        return con_size;
    }
    size_t find(T x) {
        if (this->head == nullptr) return -1;
        ListNode<T>* cache = this->head;
        size_t index = 0;
        while (cache->next != nullptr) {
            if (cache->val == x) return index;
            cache = cache->next;
            index++;
        }
        return -1;
    }
    bool empty() const{
        return !con_size;
    }

    void addElement(T x) {
        if (this->head == nullptr) this->head = new ListNode<T>(x);
        else{
            ListNode<T>* cache = this->head;

            while (cache->next != nullptr) {
                cache = cache->next;
            }
            cache->next = new ListNode<T>(x);
            this->tail = cache->next;
        }
        this->con_size++;
    }
    void deleteElement(T el) {
        if (this->head == nullptr) {
            std::cout << "List is empty!\n";
        }
        else if (this->head && this->head->val == el) {
            ListNode<T>* cache = this->head->next;
            delete this->head;
            this->head = cache;
            this->con_size--;
            return;
        }
        else if (this->head) {
            ListNode<T>* left = this->head;
            ListNode<T>* right = this->head->next;

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
            ListNode<T>* cache = this->head;
            while (cache->next != nullptr) {
                std::cout << cache->val.to_string() << " | ";
                cache = cache->next;
            }
            std::cout << cache->val.to_string() << '\n';
        }
    }
    void clear() {
        if (this->head == nullptr) std::cout << "List is empty!\n";
        else {
            ListNode<T>* cache = this->head->next;
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


/* 
template <typename T>
void addElement(ListNode<T>*& head, T x) {
    if (head == nullptr) head = new ListNode<T>(x);
    else {
        ListNode<T>* cache = head;

        while (cache->next != nullptr) {
            cache = cache->next;
        }
        cache->next = new ListNode<T>(x);
    }
}

template <typename T>
void print(ListNode<T>* head) {
    if (head == nullptr) std::cout << "List is empty!\n";
    else {
        ListNode<T>* cache = head;
        while (cache->next != nullptr) {
            std::cout << cache->val << ' ';
            cache = cache->next;
        }
        std::cout << cache->val << '\n';
    }
}

template <typename T>
void deleteElement(ListNode<T>*& head, T el) {
    if (head == nullptr) {
        std::cout << "List is empty!\n";
    }
    else if (head && head->val == el) {
        ListNode<T>* cache = head->next;
        delete head;
        head = cache;
        return;
    }
    else if (head) {
        ListNode<T>* left = head;
        ListNode<T>* right = head->next;

        while (right != nullptr) {
            if (right->val == el) {
                left->next = right->next;
                delete right;
                return;
            }
        }
    }
}

template <typename T>
int find(ListNode<T>* head, T x) {
    if (head == nullptr) return -1;
    ListNode<T>* cache = head;
    int index = 0;
    while (cache->next != nullptr) {
        if (cache->val == x) return index;
        cache = cache->next;
        index++;
    }
    return -1;
}

template <typename T>   
void clear(ListNode<T>*& head) {
    if (head == nullptr) std::cout << "List is empty!\n";
    else {
        ListNode<T>* cache = head->next;
        while (head != nullptr) {
            delete head;
            head = cache;
            cache = cache->next;
        }
        head = nullptr;
    }
}
*/

/* 
ListNode* unite(ListNode* head1, ListNode* head2) {
    ListNode* output = nullptr;
    ListNode* temp = nullptr;
    ListNode* cache1 = head1;
    ListNode* cache2 = head2;
    if (head1 == nullptr && head2 != nullptr) {
        do {
            if (temp == nullptr) {
                output = new ListNode(cache2->val);
                temp = output;
            }
            else {
                temp->next = new ListNode(cache2->val, output);
                temp = temp->next;
            }
            cache2 = cache2->next;
        } while (cache2 != head2);
        return output;
    }
    else if (head1 == nullptr && head2 == nullptr) return nullptr;

    if (head2 == nullptr && head1 != nullptr) {
        do {
            if (temp == nullptr) {
                output = new ListNode(cache1->val);
                temp = output;
            }
            else {
                temp->next = new ListNode(cache1->val, output);
                temp = temp->next;
            }
            cache1 = cache1->next;
        } while (cache1 != head1);
        return output;
    }
    else if (head1 != nullptr && head2 == nullptr) return nullptr;

    bool flag1 = true, flag2 = true;
    do {
        if (cache1->val < cache2->val) {
            if (output == nullptr) {
                output = new ListNode(cache1->val);
                temp = output;
            }
            else temp->next = new ListNode(cache1->val);
            cache1 = cache1->next;
            flag1 = false;
        }
        else {
            if (output == nullptr) {
                output = new ListNode(cache2->val);
                temp = output;
            }
            else temp->next = new ListNode(cache2->val);
            cache2 = cache2->next;
            flag2 = false;
        }
        temp = temp->next;
        temp->next = output;
    } while ((cache1 != head1 || flag1) && (cache2 != head2 || flag2));


    while (cache1 != head1 || flag1) {
        temp->next = new ListNode(cache1->val, output);
        temp = temp->next;
        cache1 = cache1->next;
        flag1 = false;
    }
    while (cache2 != head2 || flag2) {
        temp->next = new ListNode(cache2->val, output);
        temp = temp->next;
        cache2 = cache2->next;
        flag2 = false;
    }

    return output;
}
*/