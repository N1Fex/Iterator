#pragma once
#include <iostream>

template <typename T>
struct ListNode {
    T val;
    ListNode<T>* next;

    ListNode(T x) : val(x), next(nullptr) {};
    ListNode(T x, ListNode<T>* nextlink) : val(x), next(nextlink) {};
    ~ListNode() {
        //std::cout << "Объект со значением " << this->val << " удалён\n";
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& os, ListNode<T>* a) {
    if (a) return os << a->val;
    else return os << "Wrong pointer!";
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const ListNode<T>& a) {
    return os << a.val;
}
