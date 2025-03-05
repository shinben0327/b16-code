#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <cassert>
#include <memory>
#include <vector>

// A class representing a binary tree
template <typename V> struct BinaryTreeEnhanced {
    V _value;
    std::unique_ptr<BinaryTreeEnhanced<V>> _left;
    std::unique_ptr<BinaryTreeEnhanced<V>> _right;

    // WRITE YOUR CODE HERE
    std::unique_ptr<BinaryTreeEnhanced<V>> _parent;

    friend V &value(BinaryTreeEnhanced *t) { return t->_value; }
    friend const V &value(const BinaryTreeEnhanced *t) { return t->_value; }
    friend BinaryTreeEnhanced *left(const BinaryTreeEnhanced *t)
    {
        return t->_left.get();
    }
    friend BinaryTreeEnhanced *right(const BinaryTreeEnhanced *t)
    {
        return t->_right.get();
    }
    friend BinaryTreeEnhanced *parent(const BinaryTreeEnhanced *t)
    {
        // WRITE YOUR CODE HERE
        return t->_parent.get();
    }
};

// A helper function to build an enhanced binary tree
template <typename V>
std::unique_ptr<BinaryTreeEnhanced<V>>
make_binary_tree_enhanced(const V &value,
                          std::unique_ptr<BinaryTreeEnhanced<V>> l,
                          std::unique_ptr<BinaryTreeEnhanced<V>> r)
{
    // WRITE YOUR CODE HERE
    auto parent = std::unique_ptr<BinaryTreeEnhanced<V>>(
        new BinaryTreeEnhanced<V>{value, std::move(l), std::move(r)}
    );

    if (parent->_left) {
        parent->_left->_parent.reset(parent.get());
    }
    if (parent->_right) {
        parent->_right->_parent.reset(parent.get());
    }

    return parent;
}

#endif // __binary_tree_enhanced__