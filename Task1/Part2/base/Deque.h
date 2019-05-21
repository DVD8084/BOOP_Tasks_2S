#ifndef DEQUE_H
#define DEQUE_H

/**
 * @brief Abstract deque (double-ended queue) class.
 */
template<typename T>
class Deque
{

public:
	virtual ~Deque() = default;
	Deque() = default;
	explicit Deque(T data){}
	virtual void fill_random(int size){}
	virtual T peek_end(){}
	virtual T peek_start(){}
	virtual T pop_end(){}
	virtual T pop_start(){}
	virtual void print(){}
	virtual void print_rev(){}
	virtual int push_end(T new_data){}
	virtual int push_start(T new_data){}

};
#endif // DEQUE_H
