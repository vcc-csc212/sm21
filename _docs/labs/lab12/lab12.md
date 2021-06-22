---
title: Queues
asg: Lab 12
permalink: /lab12/
---

> Because you'll be modifying this lab for your Lab 14 on Thursday, this lab has a **hard final deadline** of **Wednesday 6/23 @ 8pm**. Do not be alarmed, this lab requires several small and a couple medium-sized modifications to your **completed code from Lab 11**.

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
This lab will help you solidify your understanding of queues.

---

#### Background Info {#bgi}

##### Linked List

We'll be using Linked Lists as our base today. We are familiar with the Node & Linked List classes as well as how they behave together from [Lab 11](/sm21/lab11).

Node objects store Data & a reference to the next Node in the list. The Linked List maintains a pointer to the first Node in the list ("head") and contains all of the operations that can be performed on the list. Linked Lists can also contain a "tail" pointer that points to the last element in the list.

<p align="center">
  <img src="/sm21/labs/lab12/linked-list.png" />
</p>


##### Queue

A Queue is a Linked List with an enforced add/remove order: first-in first-out (FIFO). Elements added to the Queue (enqueued) are placed at the back, and we can only ever remove (dequeue) from the front.

<p align="center">
  <img src="/sm21/labs/lab12/queue.png" />
</p>


Queues are particularly useful and popular thanks to their efficiency as inserting and removing take constant time:

|         | Queue | 
| :-----: | :---: | 
| Enqueue | O(1)  | 
| Dequeue | O(1)  | 
|  Peek   | O(1)  | 

<details>
    <summary><strong>We learned last week that linked lists can have constant time insert and delete operations. Given a queue's FIFO ordering and its constant-time operations, how do we modify a linked list for it to behave as a queue?</strong></summary>

    <ul>
        <li>Since a queue has constant-time enqueuing (appending), we need to ensure our linked list uses a tail pointer correctly.</li>
        <li>Since a queue can only have insertions happen at the end, we remove insert() and push_front(), leaving only push_back(). We rename push_back() to enqueue().</li>
        <li>Since a queue can only have removals from the front, we modify del() to only remove the head each time it's called (no index parameter required). We rename del() to dequeue()</li>
        <li>Queues cannot be searched. We remove contains().</li>
        <li>Queues can be peeked which means being able to access the value at head without removing it. We add a function called peek() that can do this. peek() does not take in any parameters and it returns a char representing the value at head.</li>
    </ul>

</details>

---

#### Your Task {#task}

> Because you'll be modifying this lab for your Lab 14 on Thursday, this lab has a **hard final deadline** of **Wednesday 6/23 @ 8pm**. Do not be alarmed, this lab requires several small and a couple medium-sized modifications to your **completed code from Lab 11**.

Modify your implementation from [Lab 11](/sm21/lab11) to become a queue.

1. Make a copy of your Lab 11 files **do not modify the originals**.
2. Rename `linked_list.cpp` to `queue.cpp`. Change your constructor's and class name (from LinkedList to Queue-- don't forget the `LinkedList::` before all the functions too!). Make sure to change the `#include` from `linked_list.h` to `queue.h`
3. Rename `linked_list.h` to `queue.h`. Change your constructor's and class name (from LinkedList to Queue). 
4. Update `node.h` to be friends with `Queue` instead of `LinkedList`
5. Compile your code to make sure 1-4 were done correctly. Update anything you missed.
6. In `queue.h`:
    - **a)** Add a tail pointer if you don't already have one.
    - **b)** Remove insert() and push_front()
    - **c)** Rename push_back() to enqueue()
    - **d)** Rename del() to dequeue(). Remove its parameter.
    - **e)** Remove contains()
    - **f)** Add a function called peek()
7. Update `queue.cpp` so it matches `queue.h`. Namely:
    - **a)** Add a tail pointer if you don't already have one. That is, add it to your constructor like you did head. 
    - **b)** Remove insert() and push_front()
    - **c)** Rename push_back() to enqueue(). Update the function to always update the tail pointer as expected.
    - **d)** Rename del() to dequeue(). Remove its parameter. Update the function to only remove the first element (the head) each time. Make sure to update the head pointer so it's pointing to the new front of the queue.
    - **e)** Remove contains()
    - **f)** Add a function called peek(). peek() does not take in any parameters and it returns a char representing the value at head. Write the function so it performs the correct action. If the head is nullptr, return `'\0'`.
8. Update `test.cpp` to test all of your three functions and remove any tests that don't apply. Make sure to change the `#include` from `linked_list.h` to `queue.h`

---

#### Requirements {#reqs}  

1. Queue functionality is as expected for all functions:
    - enqueue
    - dequeue
    - peek
2. Queue has constant time operations for all three functions.

> Because you'll be modifying this lab for your Lab 14 on Thursday, this lab has a **hard final deadline** of **Wednesday 6/23 @ 8pm**. Do not be alarmed, this lab requires several small and a couple medium-sized modifications to your **completed code from Lab 11**.

---

#### Handing in {#submit}
To submit your solution to Gradescope, select **all of the following files** and use the *drag and drop* option:
- queue.cpp
- queue.h
- test.cpp
- node.h
- node.cpp

> Because you'll be modifying this lab for your Lab 14 on Thursday, this lab has a **hard final deadline** of **Wednesday 6/23 @ 8pm**. Do not be alarmed, this lab requires several small and a couple medium-sized modifications to your **completed code from Lab 11**.

---

#### Grade Breakdown {#grading}
You must successfully meet [requirements](#reqs) **1 through 2** in order to receive credit for this assignment.

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sm21/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Original assignment by Christian Esteves, used and modified with permission.
