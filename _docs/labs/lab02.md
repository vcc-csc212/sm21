---
title: C++ Crash Course
asg: Lab 2
permalink: /lab02/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
This lab will help you solidify your understanding of programming, debugging, and testing in C++. Through this lab, you will set up your environment and familiarize yourself with some basic terminal commands. **Be sure to read and follow all instructions unless otherwise specified.**  

> Please read all of the background info before jumping down to the task! The background info is intended to provide you with crucial information in as concise a format as possible. **Make sure to take notes and follow the links to additional resources**.

---

#### Background Info {#bgi}
If you have not yet set up your IDE of choice, please do so now. You may refer to [Lab 1](/sm21/lab01) for suggestions and tutorials.

The next section will deal with Unix commands, as Unix is a common environment for C++ development. For those of you in a Windows environment, you can install the [Windows Subsystem for Linux](https://itsfoss.com/install-bash-on-windows/) and gain access to a Unix Shell.

##### Basic Unix Command-Line Exploration

Now that you've set up your environment, we can start to learn some basic UNIX command line. Unix and [Unix-like operating systems](http://www.doc.ic.ac.uk/~wjk/unixintro/Lecture1.html), like Linux, can all use the following commands to interact with [file systems](http://homepages.uc.edu/~thomam/Intro_Unix_Text/File_System.html). Basic tasks like changing directories, creating or modifying files, or removing files all together are just a few examples of things we can do using a Shell terminal.

To really understand what you'll be doing for this section of the lab, having a strong understanding of what a file system is and how we can navigate it will be critically important.

###### Opening a New Terminal

CS50
: If you don't have a terminal already open in your environment, you can create one in the the CS50 IDE by clicking File > New Terminal. Please read [the CS50 documentation](https://cs50.readthedocs.io/ide/online/#working-with-terminals) before moving to the next step.

Mac OS
: Run the 'Terminal' program

Windows
: If you followed the above steps to install the 'Windows Subsystem for Linux' then run the 'Ubuntu' program to open a terminal.

###### Making a file

We can  make empty files on the fly with the `touch <filename>` command. Try the following below: 

```bash
$ touch test.cpp
```

Now, you should see `test.cpp` in your file manager on the left-hand side.

###### Removing files

Before your workspace gets too cluttered, let's remove that test file you just created with the `touch` command. You can do this by typing:

```bash
$ rm test.cpp
```

The test file you just created should be removed if this command ran properly.

Ok, lets create another empty file with the following command:

```bash
$ touch hello.cpp
```

###### Creating a new directory

Making and deleting files is great but we often need to organize them in a sensible way. We usually do this by making **directories**. You can think of directories as folders. They're named locations that can hold other files or directories.

To make a directory type the following terminal command:

```bash
$ mkdir projects
```

Now you should see your `hello.cpp` and `projects` folder in your file manager.

###### Removing a directory

Just like how we created and removed a file, we can do the same with directories. Lets make a test directory named `testd` with the following command:

```bash
$ mkdir testd
```

To delete this directory (only if is empty), we can simply run:

```bash
$ rmdir testd
```

###### Moving files

Lets clean up our workspace by moving that `hello.cpp` file into our projects folder.  The syntax to move one file from one location to another location is `mv <source> <target>`. In this case, it would be:

```bash
$ mv hello.cpp projects
```

Now, our `hello.cpp` file is in our `projects` directory.

###### Print Working Directory

To see where we are, the command `pwd` will print the current directory you are operating in to the command line. Currently, running the command

```bash
$ pwd
```

If you are running on 'Ubuntu', it should print out `/home/ubuntu`, if at any point you changed directory with the following command your output will be different. The output of this line will differ based on your environment.

###### Change Directory

Now that we have made a new directory named `projects` and moved our `hello.cpp` file to it, we need to navigate our terminal to this directory in order to have easy access to our file for editing/compiling/file management. This is accomplished with the `cd` command with syntax as follows, `cd <directory_path>`, meaning we can move more than one file at a time. For now the following command should get you to where you need to be,

```bash
$ cd projects/
```

Now that we have changed directory, we can execute the earlier commands to validate our position within the file system. Executing `pwd` from this file should output `/home/ubuntu/projects` (again, assuming you are running on 'Ubuntu') and executing `ls` should show that there is a file named `hello.cpp` present.

Some useful cd commands:
```bash
#### to change your working directory to its parent directory, i.e. one step back
$ cd ..
#### to change back to your user directory, i.e. "/home/ubuntu" or "~/" in the case of CS50 IDE's file system
$ cd
#### to change back to the file system root directory, i.e. "/" for short
$ cd /
```

> Note that `cd` can accept full paths, so for example `cd ../..` will move your working directory two steps back in the file system, though **don't do this now** as this will put you behind your root directory which is out of the scope of this lab.

###### Displaying File Contents

Another (popular) command-line utility available to us is `cat`, which is short for concatenate. In its simplest form, `cat` can display the contents of a text file; it can also be used to concatenate together many text files.

For example, if we had a text document named `test.txt` with the contents 

```text
I love CSC 212
```

The contents of that file would print out to our terminal by running:

```bash
$ cat test.txt
```

> Spend some time to create a text file with some content in it and use the `cat` command to report those contents to the console.

######  Shell Hints

Before we move on, there are a few things about the shell you should know. The up arrow goes to previous commands. And if you think the computer can guess what you are typing, you can hit TAB to have it completed for you. For example, if `cd pro` is typed in terminal, and the TAB key is hit, the rest of the file name will be filled in. [Learn more on terminal commands](http://mally.stanford.edu/~sr/computing/basic-unix.html).

##### Command-Line Arguments

It is often helpful for us to specify how a program will run by providing arguments during the execution process. For example, normally compiling a program and running may look like this:

```
g++ main.cpp -o prog && ./prog
```

But if we wanted the execution of our program to change based on some variable (number of loops, size of a data structure, etc.) we can provide an argument here like so:

```
g++ main.cpp -o prog && ./prog 5
```

Or even multiple arguments

```
g++ main.cpp -o prog && ./prog 5 3 6 local
```

Our code would look like so:

```c++
int main(int argc, char*argv[]){
    
}
```

Where `argc` stands for the number of arguments passed (including the command to run the program!) and `argv` holds those arguments. Note the type! They will all be treated as char arrays or C-Style strings. 


> C-Strings can be confusing so beow are some reesources to help you familiarize yourself with them. 
- [C++ Strings](https://www.tutorialspoint.com/cplusplus/cpp_strings.htm)
- [How to use Command Line Arguments in C/C++](https://www.youtube.com/watch?v=h2LGTzQXzJU) (16 min)
- [C-Style Strings](https://eecs280staff.github.io/notes/05_Strings_Streams_IO.html#c-style-strings)
- [C-style Strings in C++](https://www.cprogramming.com/tutorial/lesson9.html)

If you need to use the arguments as different types (int, float, etc.), you will need to convert them.  Using the last argument example, this is how we would extract them:

```c++
#include <string> // string, stoi (string to integer)
int main(int argc, char*argv[]){
    int num1 = std::stoi(argv[1]); // extracts the 5
    int num2 = std::stoi(argv[2]); // extracts the 3
    int num3 = std::stoi(argv[3]); // extracts the 6
    std::string str(argv[4]); // converts the C-Style string to a C++ String Object
}
```

For more information regarding command line aerguments, read [Command line arguments in C/C++
](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)

##### Makefiles

We reviewed in the previous section how to compile a C++ program thorugh the terminal:
```
g++ main.cpp -o prog && ./prog
```

Wouldn't it be nice to not have to type that every single time you're trying to compile? There's a way!

A makefile is a file containing the set of instructions required to compile and run your proram. The nice thing about a makefile is that if it is created correctly, all you need to do to compile your code is run the command `make`, no arguments needed. We'll be using a makefile for the next lab, but in the mean time, you should [read up on them](https://makefiletutorial.com)!

##### Good Programming Practices

There are many ways to solve a problem. This too holds true for programming; there are multiple ways to code a solution to a problem. This section will go over a few tried-and-true rules to live by in order to create code that won't get you banished from polite society.

###### Plan before you code!

A common trap students fall into is programming as they solve a problem; this has a tendency to spiral out of control into an unsalvageable mess that ends in a waste of time. Take the time to plan your solution BEFORE you even touch code. What functions, and variables, you'll need, the flow of your program, etc. I **guarantee** that the time spent planning before hand will more than makeup for the time you'd waste backtracking & re-writing code otherwise.

###### K.I.S.S (Keep it Simple, Silly!)

Your code will not be efficient if you do not first solve the underlying problem in a simple manner. Over-complication is common in these early programming courses; don't be afraid to reach out to staff and ask for feedback on your strategy!

###### Naming Conventions

On top of following [C++ programming style guidelines](https://google.github.io/styleguide/cppguide.html), make sure to give your functions & variables **descriptive** names! When you ask the staff for help its *incredibly* unhelpful (and time consuming) to attempt and parse hundreds of lines of code that look like `int a;`

###### Functions

- Follow the "Rule of Three"
  - If you have a piece of code that is replicated (read: copy & pasted, from your own file of course!) more than twice, this task should be a function.
- Any section of code that performs a specific task in your program should be a function. Some examples:
  - Reading from a file
  - Writing to a file
  - Performing calculations on an array

###### Variables

Don't be afraid to create variables to improve code clarity! As mentioned before, name them appropriately!

###### Ninety-ninety rule

This is a fantastic quote that really captures the main pitfalls many of you will fall into:

``` 
"The first 90 percent of the code accounts for the first 90 percent of the development time. The remaining 10 percent of the code accounts for the other 90 percent of the development time."
—Tom Cargill, Bell Labs
```

> To clarify: software has a tendency to take longer than anticipated to finish. **Start your assignments early!**

###### Chasing false efficiency

While Christian (the TA who originally wrote this version of the lab) is a huge proponent of writing efficient code, it is important to realize that not everything needs to be coded in the most efficient manner. Often times code clarity/development speed take a higher priority. As an example: if it takes 5 minutes to code a function that runs once in 0.005 seconds, is it really worth spending an hour to get that same function to run in 0.002 seconds? Probably not. 

> A solid rule of thumb while you're learning is to get something that **works** first, **then** worry about efficiency to improve your skill afterwards.

###### Avoid Hard-coding!

You should **always** use variables to represent values in your code. This makes your code easier to modify later on if needed and it adds clarity to your code.

As an example:

```c++
// Bad
for (int i = 0; i < 5; i++){
    // Do stuff
}
```

```c++
// Good
unsigned int num_rows = 5;
for (int i = 0; i < num_rows; i++){
    // Do stuff
}
```

---

#### Your Task {#task}

1. Create a new Google Document (this will allow me to see your change history), and title it "Lab 2".
2. Sign up on [LeetCode](https://leetcode.com/), a website similar to HackerRank.
3. Read the problem description for [Implement strStr()](https://leetcode.com/problems/implement-strstr/). **Don't start coding yet. Write down your initial thoughts and reactions on the Google Doc**. 
4. In the Google Doc, write up some sample test cases of your own and confirm they are correct with a peer. **Write down (in the Google Doc) the name of your peer and whether any mistakes or misunderstandings were caught in this process.**
5. How do you plan on solving the problem? **Write down your planned approach, in sentences, not code**. 
6. Confirm your plan works for the test cases you came up with (i.e., **walk through your plan step by step** using the inputs from your test cases and check whether the output your planned approach gives is the same as the expected output). If the outputs don't match, repeat 5-6 until it does.
7. Solve the challenge using C++, following what you came up with in step 5. **If it doesn't pass all the test cases, repeat 5-6, adding in the new test case that didn't pass.**
	- Feel free to work locally on your IDE of choice and then copy it into LeetCode. If you do this, make sure you **leave the code they give you as is**.
8. Once you've successfuly solved the challenge, **take a screenshot showing you successfully completed it and paste the screenshot into your Google Doc**
9. Write up (on the Google Doc) a short (3-5 sentences) reflection about this experience.

---

#### Requirements {#reqs}
Your submission will be manually checked to ensure it meets the following specifications:  

1. Google Document history shows all **nine steps were completed, in order**.

---

#### Handing in {#submit}
1. Share the Google Document with my email **uncheck the box next to "Notify people"**
2. Copy the link to your document
3. Submit the link to Gradescope. 

> For reference, my email is vcchavez [at] uri.edu

---

#### Grade Breakdown {#grading}
You must successfully meet [requirement](#reqs) **1** in order to receive credit for this assignment.


> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sm21/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Original assignment by [Dr. Marco Alvarez](https://homepage.cs.uri.edu/~malvarez/) and [Michael Conti](https://web.uri.edu/cs/meet/michael-conti/), modified assignment version by Christian Esteves, used and modified (again) with permission.