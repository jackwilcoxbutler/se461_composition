// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// jwilcox
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <exception>

/**
 * @class Queue
 *
 * Basic Queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
    /// Type definition of the type.
    typedef T type;

    /// Default constructor.
    Queue (void);

    /// Copy constructor.
    Queue (const Queue & q);

    /// Destructor.
    ~Queue (void);

    /**
    * Assignment operator
    *
    * @param[in]      rhs           Right-hand side of operator
    * @return         Reference to self
    */
    const Queue & operator = (const Queue & rhs);

    /**
    * Adds the element to the end of the list
    *
    * @param[in]      element       Element to add to the list
    */
    void enqueue (T element);

    /**
    * Removes the element at the front of the list. If there are not elements in the queue, this
    * method throws empty_exception, similar to the stack.
    *
    * @exception      empty_exception    The stack is empty.
    * @return           The element at front of the queue
    */
    T dequeue (void);

    /**
    * Test if the queue is empty. If the queue is empty, then this method returns true.
    * Otherwise, this method returns false.
    *
    * @retval         true          The stack is empty
    * @retval         false         The stack is not empty
    */
    bool is_empty (void) const;

    /**
    * Number of element on the Queue.
    *
    * @return         Size of the queue.
    */
    size_t size (void) const;

    /// Remove all elements from the queue.
    void clear (void);

    T head (void) const;

    T tail (void) const;

    private:
		// Dr. R: We also need to maintain the head_ and tail_ of the Queue.
		// Dr. R: See the Stack class for comments on the following two items.
        Array<T> array_;
        T head_;
        T tail_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif   // !defined _QUEUE_H_