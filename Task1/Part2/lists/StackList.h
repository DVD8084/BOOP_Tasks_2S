#ifndef STACKLIST_H
#define STACKLIST_H

#include "structural/List.h"
#include "../base/Stack.h"

/**
 *  @brief  Stack based on linked lists.
 */
template <typename T>
class StackList : public List<T>, public Stack<T> {
public:
    StackList();
    explicit StackList(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "StackList.tpp"

#endif