#ifndef STACK_H
#define STACK_H

/**
 * @brief Abstract stack class.
 */
template<typename T>
class Stack
{

public:
    virtual ~Stack() = default;
    Stack() = default;
    explicit Stack(T data){}
    virtual void fill_random(int size){}
    virtual T peek(){}
    virtual T pop(){}
    virtual void print(){}
    virtual int push(T new_data){}

};
#endif // STACK_H
