---
title: Hash Tables, Chaining, & Open-Addressing
asg: Lab 9
permalink: /lab09/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
The goal of this lab is to provide background on **Hash Tables, Chaining, & Open-Addressing**. 

---

#### Background Info {#bgi}

##### Hash Tables

Hash Tables are a Data Structure that maps keys to values via a Hash Function.

The core concept is to have an array of size *n* with efficient storage/retrieval time.

Let's take a brief look at how these work. Using an example w/ a table size of 5, we have the following:

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     |       |
| 2     |       |
| 3     |       |
| 4     |       |

But how do we store values? We need a Hash Function! 

A Hash Function is (surprise) a function that generates some Hash out of the value to be stored. This is an entire field of research, so we'll keep it simple for now. Let's use the following function:

<center>f(x) = x % n </center>

Let's use it to store the following values: 1, 14, 13, 16

1 % 5 = 1

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     |       |
| 4     |       |

14 % 5 = 4

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     |       |
| 4     | 14    |

13 % 5 = 3

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     | 13    |
| 4     | 14    |

16 % 5 = 1

| Index | Value                  |
| ----- | ---------------------- |
| 0     |                        |
| 1     | 1 <-- already a value! |
| 2     |                        |
| 3     | 13                     |
| 4     | 14                     |

We've found an issue with our new Data Structure! This is known as a Hash Collision. Let's look at methods to combat this.

#### Open Addressing

Open Addressing is a method of collision resolution in hash tables. This method uses **probing** in order to find an open spot in the array to place a value that has encountered a collision. Let's look at a few:

##### Linear Probing

For this method, we simply keep checking the next spot to see if it is available. Let's use the example collision from above and see where we end up:

| Index | Value                  |
| ----- | ---------------------- |
| 0     |                        |
| 1     | 1 <-- already a value! |
| 2     | 16                     |
| 3     | 13                     |
| 4     | 14                     |

Since the very next spot was open, 16 gets placed at index 2.

##### Double Hashing

Another open addressing method is to use double hashing. In this strategy, a second hash function is utilized to re-hash a value that has collisions. Let's view that example from above again using this new definition:

<center>f(x, i) = [(x % n) + (i * f'(x))] % n</center>

<center>f'(x) = x+3</center>

f(16, 0) = [(16 % n) + (0 * 19)] % n = 1

f(16, 1) = [(16 % n) + (1 * 19)] % n = [(1) + 19] % n = 0

| Index | Value |
| ----- | ----- |
| 0     | 16    |
| 1     | 1     |
| 2     |       |
| 3     | 13    |
| 4     | 14    |

A slightly different result than Linear Probing. There are many different strategies for implementing these functions, such as quadratic probing. Let's look at another method entirely.

#### Chaining

In Chaining, instead of an array of keys, we have an array of lists that hold keys. This means probing strategies are not needed, and we just need to push a new value onto the list. For efficiency's sake, we typically push onto the front of the list to maintain O(1) time. Thus, our example values from earlier create the following table: 

| Index | Value   |
| ----- | ------- |
| 0     |         |
| 1     | 16 -> 1 |
| 2     |         |
| 3     | 13      |
| 4     | 14      |



#### Your Task {#task}

- Hashtables are incredibly common because they’re so efficient
- However, I value your wellbeing and want to give you some breathing space so you can catch up as needed
- In lieu of a lab for today:
	- Read the STL’s description of [unordered_map](https://www.cplusplus.com/reference/unordered_map/unordered_map/)
	- Read the STL’s description of [unordered_mutimap](https://www.cplusplus.com/reference/unordered_map/unordered_multimap/)
	- Ask questions if you have them
	- Work on on labs 1-8
- Once you’re caught up with Labs 1-8, I strongly recommend you come back to the links below and explore some hashtables challenges for practice:
	- [Design HashMap on LeetCode](https://leetcode.com/problems/design-hashmap/)
	- [Dictionaries and Hashmaps on HackerRank](https://www.hackerrank.com/interview/interview-preparation-kit/dictionaries-hashmaps/challenges)
	- [Collatz Conjecture from Notre Dame](https://www3.nd.edu/~pbui/teaching/cse.30872.fa17/challenge05.html)
	- [Hashing on InterviewBit](https://www.interviewbit.com/courses/programming/topics/hashing/)


---

#### Requirements {#reqs}
Your goal for this lab is to complete the following tasks **in order**:

1. Get caught up with Labs 1-8
2. Once you’re caught up with Labs 1-8, explore some hashtables challenges for practice
	- [Design HashMap on LeetCode](https://leetcode.com/problems/design-hashmap/)
	- [Dictionaries and Hashmaps on HackerRank](https://www.hackerrank.com/interview/interview-preparation-kit/dictionaries-hashmaps/challenges)
	- [Collatz Conjecture from Notre Dame](https://www3.nd.edu/~pbui/teaching/cse.30872.fa17/challenge05.html)
	- [Hashing on InterviewBit](https://www.interviewbit.com/courses/programming/topics/hashing/)

---

#### Handing in {#submit}
Hand in each of Labs 1-8 as described in its respective handout. Hashtable challenges are optional but strongly recommended.

---

#### Grade Breakdown {#grading}
Hand in each of Labs 1-8 as described in its respective handout. Hashtable challenges are optional but strongly recommended.

---

Original descriptions and examples by Christian Esteves, used and modified with permission.