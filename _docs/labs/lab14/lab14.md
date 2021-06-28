---
title: Priority Queues
asg: Lab 14
permalink: /lab14/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
This lab will help you solidify your understanding of priority queues.

---

#### Background Info {#bgi}

Priority Queues are a special form of queue that allow for "cutting in line". This is beneficial when you want to want to enforce a FIFO ordering schema while also allowing more important entries to have priority. 

##### Linked List

We'll be using Linked Lists as our base today. We are familiar with the Node & LinkedList classes as well as how they behave together from [Lab 11](/sm21/lab11).

Node objects store Data & a reference to the next Node in the list. The LinkedList maintains a pointer to the first Node in the list ("head") and contains all of the operations that can be performed on the list. LinkedLists can also contain a "tail" pointer that points to the last element in the list.

<p align="center">
  <img src="/sm21/labs/lab14/linked-list.png" />
</p>


##### Queue

As a refresher, a Queue is a Linked List with an enforced add/remove order: first-in first-out (FIFO). Elements added to the Queue (enqueued) are placed at the back, and we can only ever remove (dequeue) from the front.

<p align="center">
  <img src="/sm21/labs/lab14/queue.png" />
</p>


##### Priority Queue

As you may suspect, a priority queue's roots lies in the Queue data structure, which we have previously seen as a special Linked List.

<p align="center">
  <img src="/sm21/labs/lab14/priority-queue.jpg" />
</p>


As a reminder, the Queue data structure is a Linked List with a FIFO ordering schema. Elements leave in the same order they entered.

The Priority Queue has the same properties as the Queue in addition to the following:

- Every element has an associated priority
- Elements with a high priority are dequeued before an element with a lower priority
- Any elements with matching priorities are dequeued in the order they arrived 

Lets compare the performance of a Queue with a Priority Queue:

|         | Queue | Enqueue |
| :-----: | :---: | :-----: |
| Enqueue | O(1)  |  O(n)   |
| Dequeue | O(1)  |  O(1)   |
|  Peek   | O(1)  |  O(1)   |

<details>
    <summary>Queues and Priority Queues (P-Queues) are very similar, but Enqueue jumps from a constant time operation to a linear time operation. Yikes! <strong>Can you explain why this might be the case?</strong> (after giving it some thought, click to reveal answer)</summary>

    To insert elements into a P-Queue, we must iterate over the queue until we find the proper location. Worst cast would be adding an element with the lowest priority, so we would need to traverse the entire list.

</details>

<br>

But fret not, there is a better way to implement a Priority Queue and we'll learn about that soon! But first, let's talk about using queues:

<details>
    <summary><strong>How do we modify a queue for it to behave as a priority queue?</strong></summary>

    The only difference between a p-queue and a queue is in the ordering of elements: p-queues have a priority associated with each element, which determines its position in the p-queue.

    <ul>
        <li>Since elements have a priority associated with them, we need to modify our Node class so that they have a priority. </li>
        <li>Since an element's priority determines its position, we need to modify enqueue() so it accounts for priority upon inserting a node into the p-queue</li>
        <li>Since all elements now have a priority associated with them, we also want to modify to_string so we can get the full information of our p-queue when printing it. </li>
    </ul>

</details>

---

#### Your Task {#task}

Modify your implementation from [Lab 12](/sm21/lab12) to become a priority queue.

1. Make a copy of your Lab 12 files **do not modify the originals**.
2. Rename `queue.cpp` to `p_queue.cpp`. Change your constructor's and class name (from Queue to P_Queue-- don't forget the `Queue::` before all the functions too!). Make sure to change the `#include` from `queue.h` to `p_queue.h`
3. Rename `queue.h` to `p_queue.h`. Change your constructor's and class name (from Queue to P_Queue). 
4. Update `node.h` to be friends with `P_Queue` instead of `Queue`
5. Compile your code to make sure 1-4 were done correctly. Update anything you missed.
6. In `node.h`:
  - **a)** Add `priority` as a member variable of the class. `priority` should be an integer.
  - **b)** Add a priority parameter to the two constructors that take in `data` (if you kept original ordering then the second and third constructors). Make sure it's the **second parameter**.
7. Update `node.cpp` so it matches `node.h`. Namely:
  - **a)** Add a priority parameter to the two constructors that take in `data` (if you kept original ordering then the second and third constructors).
  - **b)** Set the `priority` of the node in each of the three constructors. For the constructor that doesn't take a priority in, you can set it to `1`.
8. In `p_queue.h`:
    - **a)** Add a priority parameter to enqueue() 
9. Update `p_queue.cpp` so it matches `p_queue.h`. Namely:
    - **a)** Add a priority parameter to enqueue(). Update the function so it inserts the `data` at the correct position based on its `priority`. Priorities of smaller numbers should go first. If two elements have the same priority, then their order in the p-queue should be based on insertion (i.e., if I enqueue `a` and `b` both with priority `3`, then `a` should appear before `b` since that's the order they were enqueued in).
    - **b)** Update to_string() to the following code:
    ```c++
    std::string P_Queue::to_string(){
        std::string str = "";

        Node* temp = this->head;

        while(temp != nullptr){
            str += "(";
            str += temp->data;
            str += ",";
            str += std::to_string(temp->priority);
            str += ") ";
            temp = temp->next;
        }

        return str;
    }
    ```
10. Update `test.cpp` to test all of your three functions and remove any tests that don't apply. Make sure to change the `#include` from `queue.h` to `p_queue.h`

---

#### Requirements {#reqs}  

1. P_Queue functionality is as expected for all functions:
    - enqueue
    - dequeue
    - peek
    - to_string

---

#### Handing in {#submit}
To submit your solution to Gradescope, select **all of the following files** and use the *drag and drop* option:
- p_queue.cpp
- p_queue.h
- test.cpp
- node.h
- node.cpp

---

#### Grade Breakdown {#grading}
You must successfully meet [requirement](#reqs) **1** in order to receive credit for this assignment.

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sm21/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Original assignment by Christian Esteves, used and modified with permission.
