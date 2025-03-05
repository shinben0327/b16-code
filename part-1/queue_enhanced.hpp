#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        // WRITE YOUR CODE HERE
        return this->_storage[this->_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        // WRITE YOUR CODE HERE
        return this->_storage[this->_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        // WRITE YOUR CODE HERE
        assert(this->_size < this->_storage.size());
        this->_size++;
        this->_storage[this->_head()] = value;

        // * We can increase the size and add the new element to the head.
        // * But it throws an error? Check assert.
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        // WRITE YOUR CODE HERE
        assert(this->_size >= 1);
        this->_size--;
        if (this->_position + 1 == this->_storage.size()) {
            this->_position = 0;
        } else {
            this->_position++;
        }

        // * We don't have to erase any of the storage. Just fix _size and
        // _position.
    }

    // Remove all elements from the queue
    void clear()
    {
        // WRITE YOUR CODE HERE
        this->_size = 0;

        // * We don't actually have to clear _storage because when _size is 0 it
        // would ignore the elements and overwrite them.
        // * We don't need to reset _position either, because we can start the
        // queue from anywhere in the vector and it would not matter.
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        // WRITE YOUR CODE HERE
        if (this->_position + 1 == this->_storage.size()) { return 0; }
        return this->_position + 1;

        // * This is wrong. Refer to solution.
    }
};

#endif // __queue_enhanced__