---
title: Basic Sorting Algos
asg: Lab 6
permalink: /lab06/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
This lab will help you solidify your understanding of the implementation and analysis of basic sorting algos.

---

#### Background Info {#bgi}

##### Stable vs Unstable Sorting

| Stable      | Unstable |
| ----------- | ----------- |
| Preserves original order relative order of elements | Doesn’t preserve original order relative order of elements |
| Necessary when equal elements are not truly equal | Okay to use if equal elements are truly equal or if working with no repeats |

<center>
	<img alt="image showing example of stable vs unstable sorting using colored and numbered balls" src="https://www.baeldung.com/wp-content/uploads/2019/08/Stable-vs-Unstable-1.png"/>
</center>

<details>
    <summary><strong>I have two students with the same first and last name. I want to sort my roster  by <em>name and GPA</em>, and I need to make sure the grades don't accidentally get switched. Should I use stable or unstable sorting? (after giving it some thought, click to reveal answer)</strong></summary>

Since I need to make sure the grades don't accidentally get switched, I need to make sure that when I sort my roster, the names stay in the <strong>correct relative order</strong>. This means I should use <strong> a stable sorting algo </strong>.

</details>

<br>

<details>
    <summary><strong>I have two students with the same first and last name. I want to sort my roster  by <em>ID</em>, and I need to make sure the grades don't accidentally get switched. Should I use stable or unstable sorting? (after giving it some thought, click to reveal answer)</strong></summary>

Since ID numbers are <strong>unique</strong>, I can use <strong> an unstable sorting algo </strong>.

</details>

<br>

<details>
    <summary><strong>A cashier is sorting the bills in their register. Should they use stable or unstable sorting? (after giving it some thought, click to reveal answer)</strong></summary>

Since a $10 bill is the same as any other $10 dollar bill, <strong>relative order doesn’t matter</strong>. This means the cashier can use <strong> an unstable sorting algo </strong>.

</details>

<br>


##### Bubble Sort
###### Algorithm (assuming ascending order)
```
For every element in the list:
	Compare the current element in the list with the element immediately to its right
		If the current element is greater than the element immediately to its right, swap the two elements
After the above is performed once, the largest element in the list will be in the correct place. 
	Since we have n elements, we have to do the algorithm above n times
```

<center>
	<img alt="An example of bubble sort. Starting from the beginning of the list, compare every adjacent pair, swap their position if they are not in the right order (the latter one is smaller than the former one). After each iteration, one less element (the last one) is needed to be compared until there are no more elements left to be compared." src="https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif"/>
</center>

###### Big-O
In the pre-readings you saw the Counting-version analysis and the High-level analysis. Below is an Intuitive analysis: 
```
Worst case is list in reverse order
Every element is out of order so I need to bubble each element all the way to the end, comparing it to every other element along the way. This means that for every element in an array of size n, I’m doing n work (n-1 comparisons), so this is n^2 work
```

##### Insertion Sort
###### Algorithm (assuming ascending order)
```
Start at the front of the list
Compare the current element to the element immediately to its left 
	If the current element is smaller than the element immediately to its left, compare the current element to all the other elements to the left
		- Do this until the current element is not smaller than the element its being compared to
		- Shift all greater values 1 space to the right
		- Insert the current element at the gap left from shifting

```

<center>
	<img alt="A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list. With each iteration one element (red) is removed from the 'not yet checked for order' input data and inserted in-place into the sorted list." src="https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif"/>
</center>

###### Big-O
In the pre-readings you saw the Counting-version analysis and the High-level analysis. Below is an Intuitive analysis: 
```
Worst case is list in reverse order
Every element will be smaller than the all the ones to its left so for every element, I’m going to have to compare it to every other element. This means that for every element in an array of size n I’m doing n work (n-1 comparisons), so this is n^2 work

```

##### Selection Sort
###### Algorithm (assuming ascending order)
```
1. Set the current sorted_pos to 0
2. Find the smallest element in the rest of list
3. Swap the smallest element in the list with the element at sorted_pos
4. Increment sorted_pos by 1
5. Repeat 2-4 until list is sorted (until sorted_pos is n-1)

```

<center>
	<img alt="Selection sort animation. Red is current min. Yellow is sorted list. Blue is current item." src="https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif"/>
</center>

###### Big-O
In the pre-readings you saw the Counting-version analysis. Below is a High-level analysis and an Intuitive analysis.

**High-Level Analysis**
Outer loop goes from 0 to n-1 and Inner loop will start at sorted_pos+1 and loop n-1 times
<center>
	<img alt="image of summations for doing big-o analysis for selection sort" src="/sm21/labs/lab06/selection-sort-summations.png"/>
</center>

**Intuitive Analysis**

```
Worst case is list in reverse order
Smallest element is at last position so for every element in the list I have to visit every other remaining element in the list. This means that for every element in an array of size n I’m doing n work (n-1 swaps), so this is n^2 work
```

---

#### Your Task {#task}

1. Explore (and bookmark for later) [Sorting animations of various sorting algorithms](https://www.toptal.com/developers/sorting-algorithms)
2. Download the files below (it's easiest if you right click and then choose download or save)

    [sorting-lab.h](/sm21/labs/lab06/template-code/sorting-lab.h)
    : Contains the **declaration** of the sorting lab you'll be implementing. **Do not** alter any of the given private variables, public function signatures or implementations. **Curious about ifndef vs pragma once?** [Read about their differences]-- the TLDR version is that while they are used for the same purpose, they work in different ways. ifndef ignores duplicates by checking that you have not defined something before *anywhere*, pragma once ignores duplicates by checking that you have not included the *same file*.

    [sorting-lab.cpp](/sm21/labs/lab06/template-code/sorting-lab.cpp)
    : Contains the **definition** of the sorting lab you'll be implementing. Some functions have already been implemented for you-- **do not change them**. 

    [test.cpp](/sm21/labs/lab06/template-code/test.cpp)
    : Contains some tests that should pass as soon as you debug the code. **You should add your own test cases to this file**.

    [doctest.h](/sm21/labs/lab06/template-code/doctest.h)
    : The library we'll be using for our own automated tester. There's a ton of code in here so don't worry too much about understanding everything it does-- just know the library is extremely powerful and we'll only be scratching the surface of everything it can do. **Do not edit this file**.

    [makefile](/sm21/labs/lab06/template-code/makefile)
    : File used to compile and run your program with the test suite. 
3. Read the code comments closely-- **code is supposed to follow the algorithm as written in the background info above**
4. Find (and fix) the **TWO bugs**
    - **Note/Hint:** There is **one in selectionSort()** and **one in insertionSort()**
    - **Hint:** You should NOT be adding any code to fix the bug-- you should only be making a single small edit to a single line for each bug.
5. Identify the step the error was in the algorithm, **as written on the slides**
6. Write down how to fix it and how you knew (I recommend you type it so you can copy/paste into Gradescope)

---

#### Requirements {#reqs}
Your submission will be manually checked to ensure it meets the following specifications:  

1. Correct identification of step in selection sort algorithm bug is in
2. Correct identification of how to fix bug in selection sort
3. Correct identification of step in insertion sort algorithm bug is in
4. Correct identification of how to fix bug in insertion sort

---

#### Handing in {#submit}
Submit your answers to the questions on the **Lab 6: Basic Sorting Algos** assignmetn on Gradescope.

---

#### Grade Breakdown {#grading}
You must successfully meet [requirement](#reqs) **1 through 4** in order to receive credit for this assignment.

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sm21/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---