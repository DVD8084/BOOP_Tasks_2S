#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief Abstract queue class.
 */
template<typename T>
class Queue
{

public:
    virtual ~Queue() = default;
    Queue() = default;
    explicit Queue(T data){}
    virtual void fill_random(int size){}
    virtual T peek(){}
    virtual T pop(){}
    virtual void print(){}
    virtual int push(T new_data){}

};
#endif // QUEUE_H
