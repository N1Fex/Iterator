#pragma once

#include <iostream>

struct ListNodeint {
    int val;
    ListNodeint* next;

    ListNodeint(int x) : val(x), next(nullptr) {};
    ListNodeint(int x, ListNodeint* nextlink) : val(x), next(nextlink) {};
    ~ListNodeint() {
        //std::cout << "Объект со значением " << this->val << " удалён\n";
    }

};

std::ostream& operator<<(std::ostream& os, ListNodeint* a) {
    if (a) return os << a->val;
    else return os << "Wrong pointer!";
}

std::ostream& operator<<(std::ostream& os, const ListNodeint& a) {
    return os << a.val;
}
