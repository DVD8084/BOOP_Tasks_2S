#ifndef STACKSTD_H
#define STACKSTD_H

#include <stack>
#include "../base/Stack.h"

using std::stack;

/**
 *  @brief  Stack based on std::stack.
 */
template <typename T>
class StackStd : public Stack<T> {
private:
    stack<T> std_stack;
public:
    StackStd();
    explicit StackStd(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "StackStd.tpp"

#endif