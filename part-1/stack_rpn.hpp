#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>
#include <string>

// WRITE YOUR CODE HERE
template <typename T> void plus(Stack<T> &stack)
{
    T x1 = stack.top();
    stack.pop();
    T x2 = stack.top();
    stack.pop();
    stack.push(x2 + x1);
}

template <typename T> void multiplies(Stack<T> &stack)
{
    T x1 = stack.top();
    stack.pop();
    T x2 = stack.top();
    stack.pop();
    stack.push(x2 * x1);
}

template <typename T> Stack<T> &operator<<(Stack<T> &stack, const T &value)
{
    stack.push(value);
    return stack;
}

// ! Could not get the operator to work. Input should be plus not "plus" (function not a string) but I'm unsure how to do that. 
template <typename T>
Stack<T> &operator<<(Stack<T> &stack, const std::string &op)
{
    if (op == "plus") { plus(stack); }
    if (op == "multiplies") { multiplies(stack); }
    return stack;
}

#endif // __stack_rpn__