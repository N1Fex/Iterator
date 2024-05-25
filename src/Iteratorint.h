#pragma once

#include "ListNodeint.h"

bool isPowerOfTwo(int num) {
    if (num == 1) return false;
    return !(num & (num)-1);
}

class Iteratorint {
public:
    Iteratorint(ListNodeint* ptr) : m_Ptr(ptr) {};

    bool hasNext() {
        return m_Ptr->next;
    }
    void next() {
        m_Ptr = m_Ptr->next;
    }

    Iteratorint& operator++() {
        
        if (this->hasNext()) next();
        else {
            m_Ptr = nullptr;
            return *this;
        }
        while (m_Ptr!=nullptr && this->hasNext() && !isPowerOfTwo(m_Ptr->val))
            next();

        /*
        if (this->hasNext()) next();
        else m_Ptr = nullptr;
        return *this;
        */
    }
    Iteratorint operator++(int) {
        Iteratorint it = *this;
        ++(*this);
        return it;
    }
    int& operator*() {
        return (m_Ptr->val);
    }

    bool operator==(const Iteratorint& other) const {
        return (m_Ptr == other.m_Ptr);
    }
    bool operator!=(const Iteratorint& other) const {
        return !(m_Ptr == other.m_Ptr);
    }

private:
    ListNodeint* m_Ptr;
};

bool equals(Iteratorint begin1, Iteratorint end1, Iteratorint begin2) {

    for (; begin1 != end1; ++begin1, ++begin2) {
        if (!(*begin1 == *begin2)) return false;
    }

    return true;
}
