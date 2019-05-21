#ifndef QUEUESTD_H
#define QUEUESTD_H

#include <queue>
#include "../base/Queue.h"

using std::queue;

/**
 *  @brief  Queue based on std::queue.
 */
template <typename T>
class QueueStd  : public Queue<T> {
private:
    queue<T> std_queue;
public:
    QueueStd();
    explicit QueueStd(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "QueueStd.tpp"

#endif