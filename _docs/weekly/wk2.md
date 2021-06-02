---
title: Week 2
permalink: /wk2/
---

> Reminder that you **must complete the pre-reading before each class**.
<br><br>
✔️ [Pre-reading for Tuesday 6/1](#tues)  
✔️ [Pre-reading for Wednesday 6/2](#weds)  
✔️ [Pre-reading for Thursday 6/3](#thurs)

---

#### Pre-Reading for Essential Math Overview {#tues}

> This is a hefty unit designed to review **several pre-algebra and pre-calculus topics**. If you’re comfortable with these concepts, you may skim material as you see fit. **If your math is rough around the edges**, please review the [Math Resources](/sm21/resources#math) available on the resource page **before completing these readings**.

##### Essential Questions
Before attending class, please complete the material below and use the following questions to guide your note-taking:  
<br>
✔️ What are the rules and properties of **exponents**?  
✔️ What are the rules and properties of **logarithms**?  
✔️ What does **logarithmic** growth look like?  
✔️ What does **exponential** growth look like?  
✔️ When are **permutations** useful and how are they calculated?  
✔️ When are **combinations** useful and how are they calculated?  
✔️ When are **summations** useful and how are they calculated?  
✔️ When are **factorials** useful and how are they calculated?

##### Read/Watch/Review
Before attending class, please complete the material below. 
- For a one-stop shop of Exponents and Logarithms, read [Exponentials: Discrete, Real, and Imaginary](https://sites.google.com/site/butwhymath/algebra/eponentials-discrete-real-and-imaginary). Alternatively, read the two separate readings below:
	- Read [Rules of Exponents](https://www.chilimath.com/lessons/intermediate-algebra/rules-of-exponents/) 
	- Read [Logarithms Explained](https://www.chilimath.com/lessons/advanced-algebra/logarithms-explained/)
- Read [Rules or Laws of Logarithms](https://www.chilimath.com/lessons/advanced-algebra/logarithm-rules/)
- Read/Watch [Permutations and Combinations](https://www.mathplanet.com/education/algebra-2/discrete-mathematics-and-probability/permutations-and-combinations)
- Read [Using Summation Notation](https://courses.lumenlearning.com/ivytech-collegealgebra/chapter/using-summation-notation/)
- Read [Summation Notation](https://tutorial.math.lamar.edu/Classes/CalcI/SummationNotation.aspx) (pay close attention to the **formulas**)
- Read/Watch [Simplifying Factorials: The Easy Way](https://medium.com/i-math/simplifying-factorials-the-easy-way-61c221c21b57)

---

#### Pre-Reading for Dynamic Arrays {#weds}

##### Essential Questions
Before attending class, please complete the material below and **use the following questions to guide your note-taking**:  
<br>
✔️ How are dynamic arrays different from (static) arrays?  
✔️ How do dynamic arrays work?  
✔️ How do you know whether you should use a (static) array vs a dynamic array?  

##### Read/Watch/Review
Before attending class, please complete the material below:
- Watch [Dynamic array and Static array](https://www.youtube.com/watch?v=i9mGE6-svxg) (12 min)
	- The code example is in JavaScript but the description applies to C++ as well.
- Read [Array Data Structure](https://www.interviewcake.com/concept/cpp/array?)
- Read [Dynamic Array Data Structure](https://www.interviewcake.com/concept/cpp/dynamic-array)
- Watch [What if you had to invent a dynamic array?](https://www.youtube.com/watch?v=5AllG-i_yto) (14 min)
- Watch [The Simple and Elegant Idea behind Efficient Dynamic Arrays](https://www.youtube.com/watch?v=Ij7NQ-0mIVA) (8 min)

---

#### Pre-Reading for Basic Sorting Algos {#thurs}

##### Essential Questions
Before attending class, please complete the material below and **use the following questions to guide your note-taking**:  
<br>
✔️ What's the difference between stable and unstable sorting and why does it matter?  
✔️ How does bubble sort work?  
✔️ What is the time complexity of bubble sort and why?  
✔️ How does insertion sort work?  
✔️ What is the time complexity of insertion sort and why?  
✔️ How does selection sort work?  
✔️ What is the time complexity of selection sort and why?  

##### Read/Watch/Review
> 
- **Order is important** for the material below-- **especially the videos**. 
	- Lalitha's videos show you how to analyze the algorithms in the way we saw earlier this week-- by explicitly counting primitive operations, whereas Back To Back SWE's videos show you how to do it at a more abstract level, which is **where we're headed for future analyses**. 
- Back To Back SWE's videos are particularly **long** so I recomend you **split them up into chunks**. 
- **Prioritize understanding Big-O (worst-case)**, since that's what we'll be working with most.

Before attending class, please complete the material below:
- Read [Stable Sorting Algorithms](https://www.baeldung.com/cs/stable-sorting-algorithms)
	- Ignore section 3.3 "Radix Sort"
- Watch [Stable Sort vs Unstable Sort Algorithms](https://www.youtube.com/watch?v=akLN-F0HSS4) (4 min)
- Read [Bubble Sort Algorithm](https://www.studytonight.com/data-structures/bubble-sort)
- Watch [Bubble Sort](https://www.youtube.com/watch?v=nmhjrI-aW5o) (1 min)
- Watch [Bubble Sort - Time Complexity](https://www.youtube.com/watch?v=Yffvd3pkTW4) (Lalitha, 11 min)
- Watch [An In-Depth Algorithmic Analysis of Bubble Sort](https://www.youtube.com/watch?v=euPlXW7dnlI) (Back to Back SWE, 29 min)
	- Keep in mind that the *Best Case* analysis assumes using the **optimized** version of Bubble Sort, where if you don't swap for an entire iteration then you stop altogether because the array is sorted.
- Read [Insertion Sort Algorithm](https://www.studytonight.com/data-structures/insertion-sorting)
- Watch [Insertion Sort](https://www.youtube.com/watch?v=OGzPmgsI-pQ) (2 min)
- Watch [Insertion Sort - Time Complexity](https://www.youtube.com/watch?v=p6jppwMbB0k) (Lalitha, 13 min)
- Watch [A Detailed Algorithmic Analysis of Insertion Sort](https://www.youtube.com/watch?v=ufIET8dMnus) (Back to Back SWE, 37 min)
- Read [Selection Sort Algorithm](https://www.studytonight.com/data-structures/selection-sorting)
- Watch [Selection Sort](https://www.youtube.com/watch?v=xWBP4lzkoyM) (2 min)
	- **Note:** For selection sort, you can find either the largest element smallest element-- either approach is fine, as long as you're consistent with the decision in any given implementation.
- Watch [Selection Sort - Time Complexity](https://www.youtube.com/watch?v=PhNlp_q7mQk) (Lalitha, 11 min)
- **Exercise**: After seeing the more abstract time analysis of bubble sort and insertion sort, can you complete a similar analysis of selection sort?

> Additional material if you'd like different explanations of the same concepts:
- Read [The Bubble Sort](https://runestone.academy/runestone/books/published/pythonds/SortSearch/TheBubbleSort.html)
- Watch [Introduction to Bubble Sort](https://www.youtube.com/watch?v=A6m-g0SPzt0) (8 min)
- Read [The Selection Sort](https://runestone.academy/runestone/books/published/pythonds/SortSearch/TheSelectionSort.html)
- Watch [Introduction to Selection Sort](https://www.youtube.com/watch?v=Z3dCjzhjAWA) (11 min)
- Read [The Insertion Sort](https://runestone.academy/runestone/books/published/pythonds/SortSearch/TheInsertionSort.html)
- Watch [Introduction to Insertion Sort](https://www.youtube.com/watch?v=qJsmUw3-QRA) (13 min)