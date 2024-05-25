#pragma once

/* 
bool is_power_of_two(int num) {
    if (num == 1) return false;
    return !(num & (num)-1);
}
*/
template <typename Con>
class ContainerIterator
{
public:
    //Value of ListNode
    using ValueType = typename Con::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
    //ListNode type
    using NodeType = typename Con::NodeType;
    using NodePointer = NodeType*;
    using NodeReference = NodeType&;

public:
    ContainerIterator(NodePointer ptr) : m_Ptr(ptr) {};

    bool hasNext() {
        return m_Ptr->next;
    }
    void next() {
        m_Ptr = m_Ptr->next;
    }

    ContainerIterator& operator++() {
        /* 
        if (this->hasNext()) next();
        else {
            m_Ptr = nullptr;
            return *this;
        }
        while (m_Ptr!=nullptr && this->hasNext() && !is_power_of_two(m_Ptr->val))
            next();
        */
        if (this->hasNext()) next();
        else m_Ptr = nullptr;
        return *this;
    }
    ContainerIterator operator++(int) {
        ContainerIterator it = *this;
        ++(*this);
        return it;
    }
    ReferenceType operator*() {
            return (m_Ptr->val);
    }

    bool operator==(const ContainerIterator& other) const {
        return (m_Ptr == other.m_Ptr);
    }
    bool operator!=(const ContainerIterator& other) const {
        return !(m_Ptr == other.m_Ptr);
    }

private:
    NodePointer m_Ptr;
};


template <class It1, class It2>
bool equals(It1 begin1, It1 end1, It2 begin2) {

    for (; begin1 != end1; ++begin1, ++begin2) {
        if (!(*begin1 == *begin2)) return false;
    }

    return true;
}

