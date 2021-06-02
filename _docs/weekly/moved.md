#### Part 7.  Debugging {#debugging}

The hardest part of programming is figuring out where you went wrong. There are a few techniques we can use to narrow in on our mistakes:

1. Rubber-duck debugging
   - Often we just need to methodically work through the code. Unfortunately, we tend to make assumptions while reviewing code that we wrote. In an effort to prevent glossing over key portions, the goal of this type of debugging is to explain the code to someone as if they had never seen it before. Since it can be difficult to find someone to speak to every time you get stuck (hint: a lot) it is helpful to substitute in a rubber duck. Yes, the generic kind you find in/around bath tubs. Here is a bit more reading on the subject (I recommend giving this a quick read!) https://www.thoughtfulcode.com/rubber-duck-debugging-psychology/
2. Print Statements
   - Sometimes we just need to output everything our program is doing to track down the issue. This is *very* primitive, and does not scale well. But in an isolated environment is a quick and dirty way to discover where a calculation is going wrong. Bonus tip: Read input from the keyboard to "pause" your program and step through it slowly!
3. Use a real debugger
   - This is the proper way to perform technique #2. Set breakpoints accordingly, compile your code, run it through a debugger, and use the tools given to you to explore the values in all of the variables, check scope, trace the program control, etc. This process will differ based on the IDE you are using, lookup tutorials and reach out to staff for help.

------------------------

FOR POINTERS: 

- Read [Stack and Heap Memory](https://courses.engr.illinois.edu/cs225/fa2020/resources/stack-heap/)
- Watch [Stack Versus Heap](https://www.youtube.com/watch?v=IX3fDYz0WyM) (3 min)

##### In Class
In today's class we'll be doing going over some of the properties you learned about in the readings, relating them to our next topic of *analysis of algorithms*, and practicing getting comfortable with all the math symbols and jargon we'll be seeing the rest of the semester.

--------------

##### In Class
In today's class we'll be analyzing and comparing the time complexity of simple algorithms. We'll also talk briefly about why we can't just manually time algorithms, and why asymptotic analysis is important.

---

#### Pre-Reading for Basic Sorting Algos (Implementation), Thursday 2/4 {#thurs}

##### In Class
In today's class we'll be debugging implementations of basic sorting algorithms.
