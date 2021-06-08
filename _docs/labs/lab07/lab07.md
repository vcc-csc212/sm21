---
title: Binary Search
asg: Lab 7
permalink: /lab07/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
This lab will help you solidify your understanding of the binary search algorithm.

---

#### Background Info {#bgi}
Imagine trying to find a book at the library-- you get to the aisle you think the book is in and then go down the aisle looking at each book's title to see if it's the one you're looking for. This is an example of a linear search-- you visit each item once to check whether it's what you're looking for or not. 

<br>

<details>
    <summary><strong>What is the worst case scenario of the search in the above context?</strong></summary>

If the book is the last one in the aisle or if it's not in that aisle at all, you'll have visited <strong>every book</strong>. 

</details>

<br>

<details>
    <summary><strong>What is the Big-O of the worst case scenario?</strong></summary>

If you have to visit <strong>every book</strong> and there are <em>n</em> books, the search will have an upper bound of <strong>O(n)</strong>. 

</details>

<br>

Binary search is an algorithm for efficiently finding any given item in a **sorted** list/array/vector. Using the binary search algorithm allows you to determine in which half of the list to look for the item, rather than having you look through the entire list.

<center>
	<p>Binary search animation when item IS present:</p>
	<img alt="binary search animation when item IS present" src="/sm21/labs/lab07/bs-present.gif"/> 
	<br>
	<p>Binary search animation when item IS NOT present:</p>
	<img alt="binary search animation when item IS NOT present" src="/sm21/labs/lab07/bs-not-present.gif" />
</center>

<br>
Going back to our library scenario above, in this case, you know the alphabetical order of the aisle you're looking for the book in. Say, the aisle contains books starting with "Aardvarks" through "Antelopes" and you're looking for "Alligators". You know the books are listed in alphabetical order by their title (and for simplicity's sake there's only one book with each letter) so after singing the ABCs, you think to yourself: "The middle letter of *a* (from 'a**a**rdvark") and *n* (from 'a**n**telope') is '*g*'. Since I'm looking for *l* (from 'a**l**ligator'), which is after *g*, I should look in the second half of the aisle." You repeat the process now with between *h* (the first letter after *g*, which we've already eliminated) and *n* (from 'a**n**telope', where our aisle ends). This time you again cut your search in half because *j* (the midpoint between *h* and *n*) is before *l* (from 'a**l**ligator', the book you're looking for) so you go down to the second half of the half you were looking for the book in (i.e., the last quarter of the aisle). The midpoint between *k* (letter after *j* which has been eliminated) and *n* is *l*, which is the letter you're looking for, so you're done!

<br>

<details>
    <summary><strong>In the scenario above, how many books did you have to look at to find the book you were looking for?</strong></summary>

Each time wee calculated the midpoint we looked at a book to see if it was what we wanted. We did this a total of <strong>three times</strong> once when we found <em>g</em> then again when we found <em>j</em> and once more when we found <em>l</em>. 

</details>

<br>

<details>
    <summary><strong>Recall that in the scenario above, there was only one book with each of the letters a-n for a total of 14 books. Once again, the worst case scenario for trying to find our book is if it's not in our aisle at all (if we were looking for 'axolotl', for example). In the worst case, how many searches would you have needed to perform?</strong></summary>

Each time we calculated the midpoint we looked at a book to see if it was what we wanted. We would then do:
<ul>
	<li>a - n, midpoint: g</li>
	<li>j - n, midpoint: l</li>
	<li>m - n, midpoint: m (we usually round down)</li>
	<li>n - n, midpoint: n (need to make sure we got through to the end)</li>
</ul>

After 4 books we realize our book isn't in this aisle, but hey, at least 4 books is better than 14!

</details>

<br>

<details>
    <summary><strong>What is the Big-O of the worst case scenario?</strong></summary>

I recommend you walk through these on your own (at least up to 26 or 50 books) to confirm:
<ul>
	<li>1 book: 1 search</li>
	<li>4 books: 3 searches</li>
	<li>14 books: 4 searches</li>
	<li>26 books: 5 searches</li>
	<li>50 books: 6 searches</li>
	<li>1,000,000 books: 20 searches</li>
</ul>

If we <a href="https://www.desmos.com/calculator/tvuvftonhe">graph these points</a> we get something that looks familiar:
<center><img src="/sm21/labs/lab07/book-points.png" alt="plotted points form list abocee with books on the x-axis and searches on the y-axis"></center>

What does that graph's behaviour look like? If you thought <strong>logarithmic</strong>, then awesome job! If you didn't think so, now would be a good time to brush up on some pre-algebra and pre-calculus topics using the <a href="/sm21/resources#math">math resources</a> posted on the site!

Binary seach's time complexity is <strong>O(log n)</strong>. To see Lalitha (from previous analysis videos) walk you through a more formal and mathematical analysis, watch her <a href="https://www.youtube.com/watch?v=TomQQb2kJvc">Binary Search - Time Complexity video</a> (15 min).

</details>

<br>

---

#### Your Task {#task}
Now that we have a better understanding of binary search **and its time complexity** let's put it into code.

1. Download the files below (it's easiest if you right click and then choose download or save)

    [binary_search.h](/sm21/labs/lab07/template-code/binary_search.h)
    : Contains the **declaration** of the lab you'll be implementing. **Do not** alter any of the given function signatures. **Curious about the static keyword?** [Read about it](https://www.geeksforgeeks.org/static-keyword-cpp/).

    [binary_search.cpp](/sm21/labs/lab07/template-code/binary_search.cpp)
    : Contains the **definition** of the lab you'll be implementing.

    [test.cpp](/sm21/labs/lab07/template-code/test.cpp)
    : Contains some tests that should pass as soon as you finish your implementation. **You should add your own test cases to this file**.

    [doctest.h](/sm21/labs/lab07/template-code/doctest.h)
    : The library we'll be using for our own automated tester. There's a ton of code in here so don't worry too much about understanding everything it does-- just know the library is extremely powerful and we'll only be scratching the surface of everything it can do. **Do not edit this file**.

2. Once you have downloaded all the files, inspect them. Ask questions if you have them.
3. Create your own makefile to compile and run your program. Refer to [Lab 3](/sm21/lab03) as needed.
4. Implement the binary search algorithm iteratively or recursively (up to you).
5. Add you own test cases.
6. Run, compile, and test your program by running `make` in your terminal, while in the directory all these files are located in.

---

#### Requirements {#reqs}
Your submission will be **tested and graded by an autograder**, for this reason it cannot be stressed enough that your program must **exactly** follow the assignment specifications:  

1. Binary Search algortihm works as expected.

---

#### Handing in {#submit}
To submit your solution to Gradescope, select **all of the following files** and use the *drag and drop* option:
- BinarySearch.h
- BinarySearch.cpp
- makefile
- test.cpp

---

#### Grade Breakdown {#grading}
You must successfully meet [requirement](#reqs) **1** in order to receive credit for this assignment.

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sm21/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---