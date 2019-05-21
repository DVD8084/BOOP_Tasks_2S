#ifndef STACKARRAY_H
#define STACKARRAY_H

#ifndef MAX_ARRAY_SIZE
#define MAX_ARRAY_SIZE 100
#endif

#include "../base/Stack.h"

/**
 *  @brief  Stack based on arrays.
 */
template <typename T>
class StackArray : public Stack<T> {
private:
    T stack[MAX_ARRAY_SIZE];
    int stack_size = 0;
public:
    StackArray();
    explicit StackArray(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "StackArray.tpp"

#endif