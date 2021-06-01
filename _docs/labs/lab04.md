---
title: Intro to Analysis of Algos
asg: Lab 4
permalink: /lab04/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
This lab will introduce you to the concept of analyzing algorithms. 

---

#### Background Info {#bgi}
Rather than writing out a lengthy section for the background information, we have included some essential questions, readings, and videos, to introduce you to the analysis of algos. Please complete all the material below before jumping into the task.

##### Essential Questions
Before completing the task below, please complete the material below and use the following questions to guide your note-taking:  
<br>
✔️ Why is time complexity important?  
✔️ What are common order-of-growth classifications?  
✔️ What are the differences between Big-O, Big-Omega, and Theta?  
✔️ What is the process for analyzing the time complexity of an algorithm?  

##### Read/Watch/Review
Before attending class, please complete the material below:
- Read [Gaddis 9.6: Introduction to Analysis of Algorithms](/sm21/files/Gaddis-Algos.pdf)
- Watch [Analyzing Algorithms](https://www.youtube.com/watch?v=-gN6KCS_D4k) (15 min)
- Watch [Big O Notation](https://www.youtube.com/watch?v=3Yo7Kxa0vOU) (14 min)
- Explore [Common Complexities, Graphed](https://www.desmos.com/calculator/pdft1nieox)
	- When I say explore, I mean zoom in and out, add constants, compare values at small vs large x values, etc.
- Read [Asymptotic Notations](https://www.studytonight.com/data-structures/aysmptotic-notations)
- Watch [Asymptotic Bounding 101: Big O, Big Omega, & Theta](https://www.youtube.com/watch?v=0oDAlMwTrLo) (23 min)

---

#### Your Task {#task}
Complete the four analyses below, using a **Google Doc**. For each, **show and explain your work**. 

1. What’s the Big-O of **myFunc()? Show and explain your work.**
	```
	myFunc(int n) {
	  num = 1;
	  for (int i = n; i > 1; i--) {
	    num *= i;
	  }
	  return num;
	}
	```

2. What’s the Big-O of **getAverage()? Show and explain your work.**
	```
	int getTotal(vector<int> v){
		int total = 0;
		for(int i = 0; i < v.size(); i++){
			total = total + v.at(i);
		}
		return total;
	}
	int getAverage(vector<int> v){
		int total = getTotal(v);
		double average = total/v.size();
		return average;
	}
	```

3. What’s the Big-O of the **algorithm** below? **Show and explain your work.**
> **Note:** You can assume a square matrix of dimensions n x n. <br>
**Hint:** Might be easier to reformat the “for each pixel” part 

	```
	calculate global T:
		for each pixel A[i][j] in A do
		    if A[i][j] < T then
		        B[i][j] = 0
		    else
		        B[i][j] = 255
		    endif
		endfor
	```

4. What’s the Big-O of **myFunc()? Show and explain your work.**
	```
	void myFunc() {
		for (int i = 0; i != 3; i += 2) {
			  cout << "Hi :)" << endl;
		  }
	}
	```

---

#### Requirements {#reqs}
Your submission will be manually checked to ensure it meets the following specifications:  

1. All four analyses show and explain work.
2. At least three of the four given time complexities are correct.

---

#### Handing in {#submit}
> Please **only submit after completing ALL FOUR ANALYSES**.

1. Share the Google Document with my email **uncheck the box next to "Notify people"**
2. Copy the link to your document
3. Submit the link to Gradescope. 

---

#### Grade Breakdown {#grading}
You must successfully meet [requirement](#reqs) **1 through 2** in order to receive credit for this assignment.

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sm21/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---
