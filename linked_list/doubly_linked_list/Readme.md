### Doubly Linked List

A doubly linked list is a data structure that consists of a sequence of nodes. 
- Each node stores a `refernce to previous`, `value` and a `reference to the next node` in the sequence. 
- The first node in the sequence is called the `head`, and the last node is called the `tail`.
- The head node's reference to the previous node is `null` or `none`. 
- The tail node's reference to the next node is `null` or `None`, indicating the end of the list.

Here's an example of what a singly linked list might look like:

```
prev|head|link -> prev|value1|link -> prev|value2|link -> prev|value3|link -> ... -> prev|valuen|Null
```

In this example, `value1` through `valuen` represent the values stored in each node, and `head` represents the reference to the first node in the list.

To traverse a doubly linked list, you start at the head and follow the references to the next nodes until you reach the end of the list.

doubly linked lists are commonly used in computer science and programming because they allow for efficient insertion and deletion of nodes, as well as traversal of the list in one direction.