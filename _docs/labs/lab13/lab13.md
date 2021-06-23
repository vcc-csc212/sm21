---
title: Stacks
asg: Lab 13
permalink: /lab13/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
This lab will help you solidify your understanding of stacks.

---

#### Background Info {#bgi}

##### Linked List

We'll be using Linked Lists as our base today. We are familiar with the Node & Linked List classes as well as how they behave together from [Lab 11](/sm21/lab11).

Node objects store Data & a reference to the next Node in the list. The Linked List maintains a pointer to the first Node in the list ("head") and contains all of the operations that can be performed on the list. Linked Lists can also contain a "tail" pointer that points to the last element in the list.

<p align="center">
  <img src="/sm21/labs/lab12/linked-list.png" />
</p>


##### Stack

A Stack is a Linked List with an enforced add/remove order: first-in last-out (FILO) aka last-in first-out (LIFO). Elements added to the Stack (pushed) are placed at the fron, and we can only ever remove (pop) from the front.

<p align="center">
  <img src="/sm21/labs/lab13/stack.png" />
</p>


Stacks are particularly useful and popular thanks to their efficiency as inserting and removing take constant time:

|         | Stack | 
| :-----: | :---: | 
| Push    | O(1)  | 
| Pop     | O(1)  | 
|  Peek   | O(1)  | 

<details>
    <summary><strong>We learned last week that linked lists can have constant time insert and delete operations. Given a stacks's LIFO ordering and its constant-time operations, how do we modify a linked list for it to behave as a stack?</strong></summary>

    <ul>
        <li>Since a stack has constant-time pushing (prepending), we need to ensure our linked list uses its head pointer correctly.</li>
        <li>Since a stack can only have insertions happen at the front, we remove insert() and push_back(), leaving only push_front(). We rename push_front() to push().</li>
        <li>Since a stack can only have removals from the front, we modify del() to only remove the head each time it's called (no index parameter required). We rename del() to pop()</li>
        <li>Stacks cannot be searched. We remove contains().</li>
        <li>Stacks can be peeked which means being able to access the value at head without removing it. We add a function called peek() that can do this. peek() does not take in any parameters and it returns a char representing the value at head.</li>
        <li>Given that neither push nor pop access the end of the linked list, we can remove the tail pointer.</li>
    </ul>

</details>

---

#### Your Task {#task}

Modify your implementation from [Lab 11](/sm21/lab11) to become a stack.

1. Make a copy of your Lab 11 files **do not modify the originals**.
2. Rename `linked_list.cpp` to `stack.cpp`. Change your constructor's and class name (from LinkedList to Stack-- don't forget the `LinkedList::` before all the functions too!). Make sure to change the `#include` from `linked_list.h` to `stack.h`
3. Rename `linked_list.h` to `stack.h`. Change your constructor's and class name (from LinkedList to Stack). 
4. Update `node.h` to be friends with `Stack` instead of `LinkedList`
5. Compile your code to make sure 1-4 were done correctly. Update anything you missed.
6. In `stack.h`:
    - **a)** Remove the tail pointer if you have it.
    - **b)** Remove insert() and push_back()
    - **c)** Rename push_front() to push()
    - **d)** Rename del() to pop(). Remove its parameter.
    - **e)** Remove contains()
    - **f)** Add a function called peek()
7. Update `stack.cpp` so it matches `stack.h`. Namely:
    - **a)** Remove the tail pointer if you have one. 
    - **b)** Remove insert() and push_back()
    - **c)** Rename push_front() to push().
    - **d)** Rename del() to pop(). Remove its parameter. Update the function to only remove the first element (the head) each time. Make sure to update the head pointer so it's pointing to the new front of the stack.
    - **e)** Remove contains()
    - **f)** Add a function called peek(). peek() does not take in any parameters and it returns a char representing the value at head. Write the function so it performs the correct action. If the head is nullptr, return `'\0'`.
8. Update `test.cpp` to test all of your three functions and remove any tests that don't apply. Make sure to change the `#include` from `linked_list.h` to `stack.h`

---

#### Requirements {#reqs}  

1. Stack functionality is as expected for all functions:
    - push
    - pop
    - peek
2. Stack has constant time operations for all three functions.

---

#### Handing in {#submit}
To submit your solution to Gradescope, select **all of the following files** and use the *drag and drop* option:
- stack.cpp
- stack.h
- test.cpp
- node.h
- node.cpp

---

#### Grade Breakdown {#grading}
You must successfully meet [requirements](#reqs) **1 through 2** in order to receive credit for this assignment.

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sm21/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---