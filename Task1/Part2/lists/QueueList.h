#ifndef QUEUELIST_H
#define QUEUELIST_H

#include "structural/List.h"
#include "../base/Queue.h"

/**
 *  @brief  Queue based on linked lists.
 */
template <typename T>
class QueueList : public List<T>, public Queue<T> {
private:
    Node<T>* end;
public:
    QueueList();
    explicit QueueList(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "QueueList.tpp"

#endif