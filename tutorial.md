# B1602.1 Tutorial

## 1 Linear-time sorting

<!-- ! -->
### 1.1 Radix sort

The algorithm can be described informally as follows:

1. Prepare two buckets: $0$ and $1$. Examine the $c_{k-1}$-th bit of all $n$ integers. Move them to the corresponding bucket.
2. If the bucket has only one element, it is at the correct position. Otherwise, recursively repeat the process for the next bit in each bucket until the last bit.

In the worst case, we examine all $k$ bits of $n$ integers, so the time complexity would be $O(kn)$.

As an extension, I attempted the implementation of radix sort. It is clearly not working and I'm unsure how to approach it.

Implementation: [radix_sort.hpp](part-1/radix_sort.hpp)

Output for [radix_sort_driver.cpp](part-1/radix_sort_driver.cpp):

```bash
Before sorting: [1, 19, 2, 9, 12, 18, 4, 8, 5, 6, 17, 10, 11, 14, 16, 15, 7, 3, 13, 20]
After sorting: [16, 8, 4, 20, 12, 2, 18, 10, 6, 14, 1, 17, 9, 5, 13, 3, 19, 11, 7, 15]
```

## 2 Arrays

### 2.1 Complexity of `ArrayInsert`

$O(n)$, because if we were to insert an element at the beginning of the array, we would have to shift all the elements to the right by one position.

### 2.2 Writing `ArrayDelete`

Implementation: [array_delete.hpp](part-1/array_delete.hpp)

Output for [array_delete_driver.cpp](part-1/array_delete_driver.cpp):

```bash
Initially A = [0, 1, 2, 3, 4]
After deleting the element at position 0: A = [1, 2, 3, 4]
After deleting the element at position 0: A = [2, 3, 4]
After deleting the element at position 0: A = [3, 4]
After deleting the element at position 0: A = [4]
After deleting the element at position 0: A = []
```

The worst-case complexity would also be $O(n)$, because if we were to delete an element at the beginning of the array, we would have to shift all the elements to the left by one position.

## 3 Stacks

### 3.1 Enhanced stack class

Implementation: [stack_enhanced.hpp](part-1/stack_enhanced.hpp)

Output for [stack_enhanced_driver.cpp](part-1/stack_enhanced_driver.cpp):

```bash
Stack content: 6 5 4
```

<!-- ! -->
### 3.2 Reverse Polish calculator

I was not able to implement the extension. Please refer to the implementation and driver files for more details.

Implementation: [stack_rpn.hpp](part-1/stack_rpn.hpp)

Output for [stack_rpn_driver.cpp](part-1/stack_rpn_driver.cpp):

```bash
2 2 3 + * = 10
```

## 4 Queues

<!-- ! -->
### 4.1 Enhanced queue class

I was not able to solve this problem. I don't think I fully understand the original [queue.hpp](part-1/queue.hpp) file and how its `_position` works.

Implementation: [queue_enhanced.hpp](part-1/queue_enhanced.hpp)

Output for [queue_enhanced_driver.cpp](part-1/queue_enhanced_driver.cpp):

```bash
Enqueued front 0 1 2
Dequeued front 0 2 1
Enqueued back 0 1 2
Dequeued back 2 2 1
queue_enhanced_driver: /home/jihwanshin24/B16/B1602.1_tutorial/part-1/queue_enhanced.hpp:33: void Dequeue<float>::enqueue_front(const T &) [T = float]: Assertion `this->_size < this->_storage.size()' failed.
Aborted (core dumped)
```

<!-- * _position was explained during the tutorial and corrections have been made to the implementation. -->

## 5 Lists

### 5.1 Deleting elements from a list

I solve this by moving the unique pointer of `node->next` to `node->next->next`. Because they are unique pointers, the old pointer should be released safely.

The worst-case complexity would be $O(1)$. This is the benefit of using linked lists; insertion and deletion of elements are quicker than arrays.

Implementation: [list_enhanced.hpp](part-1/list_enhanced.hpp)

Output for [list_enhanced_driver.cpp](part-1/list_enhanced_driver.cpp):

```bash
[0]
[0, 1]
[0, 1, 2]
[0, 1, 2, 3]
[0, 1, 2, 3, 4]
[0, 1, 2, 3, 4, 5]
[0, 1, 2, 3, 4, 5, 6]
[0, 1, 2, 3, 4, 5, 6, 7]
[0, 1, 2, 3, 4, 5, 6, 7, 8]
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
[1, 2, 3, 4, 5, 6, 7, 8, 9]
[2, 3, 4, 5, 6, 7, 8, 9]
[3, 4, 5, 6, 7, 8, 9]
[4, 5, 6, 7, 8, 9]
[5, 6, 7, 8, 9]
[6, 7, 8, 9]
[7, 8, 9]
[8, 9]
[9]
[]
```

## 6 Binary trees

<!-- ! -->
### 6.1 Enhanced `BinaryTree` class

I added a new unique pointer `_parent` to the `BinaryTreeEnhanced`. When we make the binary tree, we set the `_parent` of the left and right nodes to the parent itself.

The driver results show that the tree is successfully made and the parents are found, but at the end it returns a segmentation fault. I am unsure why this occurs.

Implementation: [binary_tree_enhanced.hpp](part-2/binary_tree_enhanced.hpp)

Output for [binary_tree_enhanced_driver.cpp](part-2/binary_tree_enhanced_driver.cpp):

```bash
Tree:
1 -------v     
2 -v     3 -v  
4  5 -v  6  7  
      8        
The parent of 4 is 2
The parent of 2 is 1
The parent of 5 is 2
The parent of 8 is 5
Node 1 has no parent
The parent of 6 is 3
The parent of 3 is 1
The parent of 7 is 3
Segmentation fault (core dumped)
```

### 6.2 Minimum and maximum element in a binary search tree

I use a recursive method to continuously look for left nodes to find the minimum and right nodes to find the maximum, exploiting the characteristic of a binary search tree.

Implementation: [binary_search_tree_enhanced.hpp](part-2/binary_search_tree_enhanced.hpp)

Output for [binary_search_tree_enhanced_driver.cpp](part-2/binary_search_tree_enhanced_driver.cpp):

```bash
Tree:12 ---v           
5 -v  18 -----v   
2  9  15 -v   19  
      13  17      

The smallest element is 2
The largest element is 19
```

### 6.3 Traversing the nodes of a BST by non-decreasing value

1. Find the left-most node by continuously taking the left node from the root.
2. Traverse up one node to its parent node.
3. If it does not have a right node proceed to its parent node.
4. Otherwise, establish a subtree with its right node as the root.
5. Recursively perform steps 1-4 on the subtree.

This algorithm has not been tested for its correctness. Discuss during tutorial whether it is valid.

## 7 Heaps

### 7.1 Building a heap

The following is the algorithm for `PriorityEnqueue` taken from lecture notes:

**PriorityEnqueue**($ Q, x $):

1. Let $ i \leftarrow Q.\text{size} $
2. Set $ Q.A_i \leftarrow x $
3. Interpret $ (Q.A_0, \dots, Q.A_i) $ as a complete binary tree $ T $ and let $ S $ be the subtree rooted at $ A_i $.
4. Call `SiftUp(S)`.
5. Set $ Q.\text{size} \leftarrow i + 1 $.

`BuildHeapAlt` is essentially the same algorithm as `PriorityEnqueue`.

The time complexity of `SiftUp` and `SiftDown` depend on the height of the tree which is proportional to $\log (n)$ where $n = |A|$. So the complexity of `BuildHeap` will be $O(\frac{n}{2} \log (n))$ and `BuildHeapAlt` will be $O(n \log (n))$. At large $n$, we can consider them to be the same order of complexity.

### 7.2 Building a heap vs sorting

An array can be sorted using the `HeapSort` algorithm which is essentially an alternative implementation of `BuildHeap`.

**HeapSort**($ A $):

**Precondition:** An array $ A $.

**Postcondition:** The array $ A $ has the same elements as before, but permuted in non-decreasing order.

1. Call **BuildHeap**($ A $)
2. For $ i = |A| - 1, \dots, 1 $:
   2.1. Swap elements $ A_0 $ and $ A_i $.
   2.2. Interpret the subarray $ (A_0, \dots, A_{i-1}) $ as a complete binary tree $ T $.
   2.3. Call **SiftDown**($ T $).

### 7.3 Updating the priority of a queued element

We can remove and re-insert an element then call `SiftUp` or `SiftDown` to update its priority.

## 8 Hashing

### 8.1 Worst case complexity for multiple chaining

Each chain can correspond to a slot in the table where there are $m$ such slots. Then each slot will be a list of $\frac{n}{m}$ elements on average.

The worst case complexity would be when the element for retrieval is at the end of the linked list, which would mean $O(\frac{n}{m})$.

<!-- * We need to prove using the inequality with K (the universe). Time complexity is also wrong. If all n elements are from one chain, the worst-case complexity would be $O(n)$. -->

### 8.2 Other usages of hash functions

We can create a hash function that makes a hash based on the contents of the file so that it can be a distinct signature. If the contents of the file are changed, so would the hash.

If we want it to be fully distinct, we would design $m$ to be the number of pixels on the image (or the number of pixels times the number of frames on the video). Realistically, we can probably choose a smaller value since that would grow too large, and it would still be very unlikely that two files in comparison would have the same hash.

### 8.3 Division method for large keys

Make use of the properties of modular arithmetic:

$$
h(c) = \left( \sum_{i=0}^{q-1} c_{q-1-i} \cdot 256^i \right) \mod m \\
     = \left( \sum_{i=0}^{q-1} ( c_{q-1-i} \cdot 256^i ) \mod m \right) \mod m \\
     = \left( \sum_{i=0}^{q-1} ( (c_{q-1-i} \mod m) \cdot (256^i \mod m) ) \mod m \right) \mod m \\
     = \left( \sum_{i=0}^{q-1} ( (c_{q-1-i} \mod m) \cdot (((256 \mod m) \cdot i) \mod m) ) \mod m \right) \mod m
$$

And now implement this the final expression as a function:

```cpp
uint32_t hash(const std::string& str, const uint32_t m)
{
    uint32_t hash_value = 0;

    for (int i = 0; i < str.size(); i++) 
    {
        hash_value += ((str[i] % m) * (((256 % m) * i) % m)) % m;
    }

    return hash_value % m;
}
```

<!-- * This is not what the solution does and it is likely wrong. The solution uses bit-shift until the key becomes an integer, then uses the modulus so that it can work properly. -->

<!-- * There is a mistake in expanding the 256^i. It should not be *i, it should be ^i instead. -->

<!-- ! -->
### 8.4 Permutation invariance of the division method

If $m = 255$: $(256 \mod m)$ would be $1$. This could be a reason why the hash is invariant to the permutation of the characters in the string, but I am not completely sure.

<!-- * Apparently 256^i mod 255 = (256 mod 255)^i = 1. -->

This is not desirable because we want to distinguish strings even if they are permutations of one another.

## 9 Graphs

<!-- * Look more into the explanation of all the shortest path algorithms to understand how they work. -->

<!-- ! -->
### 9.1 Shortest paths using the adjacency list representation

I wrote a new `relax` function and used the same BF algorithm as the example for a adjacency list. I could not implement the Dijkstra algorithm.

I am unsure whether the result is correct.

Implementation: [shortest_paths_sparse.cpp](part-4/shortest_paths_sparse.cpp)

Output for [shortest_paths_sparse_driver.cpp](part-4/shortest_paths_sparse_driver.cpp):

```bash
digraph G {
    0 -> 1 [label= 4];
    0 -> 7 [label= 8];
    1 -> 7 [label= 11];
    2 -> 5 [label= 4];
    2 -> 8 [label= 2];
    3 -> 4 [label= 9];
    3 -> 5 [label= 14];
    4 -> 5 [label= 10];
    5 -> 6 [label= 2];
    6 -> 3 [label= 3];
    6 -> 7 [label= 1];
    6 -> 8 [label= 6];
    7 -> 8 [label= 7];
}

Bellman-Ford from source 2
[(inf,-1), (inf,-1), (0,-1), (9,6), (18,3), (4,2), (6,5), (7,6), (2,2)]
```

<!-- * Try not to have the separate relax function for sparse graphs. -->
<!-- * has_negative_cycle does not actually check negative cycles. Check solutions for more information. -->
<!-- * Dijkstra's implementation uses Priority Queue in the solution. Investigate why. -->

<!-- ! -->
### 9.2 Decoding shortest paths

The solution needs debugging, as it is in reverse order and does not include the final node.

Implementation: [shortest_paths_decode.hpp](part-4/shortest_paths_decode.hpp)

Output for [shortest_paths_fw_decode_driver.cpp](part-4/shortest_paths_fw_decode_driver.cpp):

```bash
digraph G {
    0 -> 1 [label= 4];
    0 -> 7 [label= 8];
    1 -> 7 [label= 11];
    2 -> 5 [label= 4];
    2 -> 8 [label= 2];
    3 -> 4 [label= 9];
    3 -> 5 [label= 14];
    4 -> 5 [label= 10];
    5 -> 6 [label= 2];
    6 -> 3 [label= 3];
    6 -> 7 [label= 1];
    6 -> 8 [label= 6];
    7 -> 8 [label= 7];
}

Floyd-Warshall ASPS
[(0,-1), (4,0), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (8,0), (15,7)]
[(inf,-1), (0,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (11,1), (18,7)]
[(inf,-1), (inf,-1), (0,-1), (9,6), (18,3), (4,2), (6,5), (7,6), (2,2)]
[(inf,-1), (inf,-1), (inf,-1), (0,-1), (9,3), (14,3), (16,5), (17,6), (22,6)]
[(inf,-1), (inf,-1), (inf,-1), (15,6), (0,-1), (10,4), (12,5), (13,6), (18,6)]
[(inf,-1), (inf,-1), (inf,-1), (5,6), (14,3), (0,-1), (2,5), (3,6), (8,6)]
[(inf,-1), (inf,-1), (inf,-1), (3,6), (12,3), (17,3), (0,-1), (1,6), (6,6)]
[(inf,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (0,-1), (7,7)]
[(inf,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (inf,-1), (0,-1)]

Shortest path 0 ~~> 1 (weight 4): [0]
Shortest path 0 ~~> 7 (weight 8): [0]
Shortest path 0 ~~> 8 (weight 15): [7, 0]
Shortest path 1 ~~> 7 (weight 11): [1]
Shortest path 1 ~~> 8 (weight 18): [7, 1]
Shortest path 2 ~~> 3 (weight 9): [6, 5, 2]
Shortest path 2 ~~> 4 (weight 18): [3, 6, 5, 2]
Shortest path 2 ~~> 5 (weight 4): [2]
Shortest path 2 ~~> 6 (weight 6): [5, 2]
Shortest path 2 ~~> 7 (weight 7): [6, 5, 2]
Shortest path 2 ~~> 8 (weight 2): [2]
Shortest path 3 ~~> 4 (weight 9): [3]
Shortest path 3 ~~> 5 (weight 14): [3]
Shortest path 3 ~~> 6 (weight 16): [5, 3]
Shortest path 3 ~~> 7 (weight 17): [6, 5, 3]
Shortest path 3 ~~> 8 (weight 22): [6, 5, 3]
Shortest path 4 ~~> 3 (weight 15): [6, 5, 4]
Shortest path 4 ~~> 5 (weight 10): [4]
Shortest path 4 ~~> 6 (weight 12): [5, 4]
Shortest path 4 ~~> 7 (weight 13): [6, 5, 4]
Shortest path 4 ~~> 8 (weight 18): [6, 5, 4]
Shortest path 5 ~~> 3 (weight 5): [6, 5]
Shortest path 5 ~~> 4 (weight 14): [3, 6, 5]
Shortest path 5 ~~> 6 (weight 2): [5]
Shortest path 5 ~~> 7 (weight 3): [6, 5]
Shortest path 5 ~~> 8 (weight 8): [6, 5]
Shortest path 6 ~~> 3 (weight 3): [6]
Shortest path 6 ~~> 4 (weight 12): [3, 6]
Shortest path 6 ~~> 5 (weight 17): [3, 6]
Shortest path 6 ~~> 7 (weight 1): [6]
Shortest path 6 ~~> 8 (weight 6): [6]
Shortest path 7 ~~> 8 (weight 7): [7]
```

## 10 Further examples (optional)

### 10.1 Inserting movable objects in an array

### 10.2 Stacks with move semantics

### 10.3 List iterators
