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

We'll be using Linked Lists as our base today. We are familiar with the Node & LinkedList classes as well as how they behave together from [Lab 4](/sm21/lab04).

Node objects store Data & a reference to the next Node in the list. The LinkedList maintains a pointer to the first Node in the list ("head") and contains all of the operations that can be performed on the list. LinkedLists can also contain a "tail" pointer that points to the last element in the list.

<p align="center">
  <img src="/sm21/labs/lab14/images/linked-list.png" />
</p>


##### Queue

As a refresher, a Queue is a Linked List with an enforced add/remove order: first-in first-out (FIFO). Elements added to the Queue (enqueued) are placed at the back, and we can only ever remove (dequeue) from the front.

<p align="center">
  <img src="/sm21/labs/lab14/images/queue.png" />
</p>


##### Priority Queue

As you may suspect, a priority queue's roots lies in the Queue data structure, which we have previously seen as a special Linked List.

<p align="center">
  <img src="/sm21/labs/lab14/images/priority-queue.jpg" />
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
    <summary>Queues and Priority Queues (P-Queues) are very similar, but Enqueue jumps from a constant time operation to a linear time operation. Yikes! <strong>Can you explain why this might be the case?</strong></summary>

    To insert elements into a P-Queue, we must iterate over the queue until we find the proper location. Worst cast would be adding an element with the lowest priority, so we would need to traverse the entire list.

</details>

But fret not, there is a better way to implement a Priority Queue and we'll learn about that soon!

> Task and reqs to be released soon.