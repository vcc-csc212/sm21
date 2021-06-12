---
title: Sets & Maps
asg: Lab 8
permalink: /lab08/
---

> Watch this lab's [video walkthrough](https://youtu.be/UVoLhJuvP2E)

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
This lab will help you solidify your understanding of sets and maps while providing you with an opportunity to practice working with a real dataset.

---

#### Background Info {#bgi}
##### Sets

A set is a collection of distinct objects-- that is, a set cannot contain any duplicates. Sets are beneficial when we need to **store unique items**. There are a myriad of operations that you can perform on a set. Look at the [set reference](https://www.cplusplus.com/reference/set/set/) page to familiarize yourself with the basic operations. Below is a code snippet for a program that creates a set of strings and then inserts three unique strings into the dataset:

```c++
#include <set>
#include <string>

int main() {
    std::set<std::string> animals; // creating a set of strings
    
    myset.insert("cat");
    myset.insert("dog");
    myset.insert("horse");    
}
```

##### Maps

Maps are similar to sets, in that each contains a number of **unique elements** that are in order. The *key* difference between sets and maps is that **sets store elements all by themselves**, whereas **maps store *key-value pairs***. A key-value pair is a pair of two elements where the first element (the key) is used to index (access data from) the map, and the second element (the value) is what is stored/returned. Similar to the set reference page, there exists a [map reference](https://www.cplusplus.com/reference/map/map/) page for you to explore as well.

Below is a code snippet for a program that creates a map of strings and ints and then inserts three unique key-value pairs into the dataset. When inserting into a map, the **keys must be unique**. If you use `emplace` or `insert` with a key that is *already in the map*, the value will **not** be replaced.:

```c++
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> animals;

    animals["dog"] = 7;
    animals.emplace("cat", 4); // This is the same as animals["cat"] = 4
    animals.insert({"fish", 11}); // This is the same as animals["fish"] = 11
    animals["cat"]++;
    animals["dog"] = animals["dog"] + 3;

    std::cout << animals["dog"] << std::endl; // Prints 10
    std::cout << animals["cat"] << std::endl; // Prints 5
    std::cout << animals["fish"] << std::endl; // Prints 11

}
```

##### Using Sets and Maps to Process Data

Sets and maps are used to store data and can be used to answer specific questions about a dataset. For example, let's say I have a CSV (comma-separated values) file that contains one row for each student in the class. Each row contains the following information about the student in that row:
- First name
- Last name
- Expected graduation year
- Major
- ID number 
- State of residence

Now say I'm curious to know:
- Are there any students who live in IL (Illinois)?
- How many students are sophomores (i.e., have an expected graduation year of 2024)?
- How many different majors are represented in the class?
- How many students from each major are in the class?
- How many more CS majors than CE majors are in the class?
- Are there more students who live in RI or who live out of state?

<br>

<details>
    <summary><strong>I can use sets and maps to answer each of the above questions! Can you figure out which data structure (either a set or a map) I would need for each of the questions above?</strong></summary>

<ul>
	<li>To answer: "Are there any students who live in IL (Illinois)?"
	 <ul><li>Since you want to keep track of whether there are any students who live in <strong>a specific state</strong>, you should use a <strong>set</strong>. By storing the names of states of residence in a set (which will only hold unique values), you can then answer the question by checking if IL (Illinois) is in the set.</li></ul></li>
	<li>To answer: "How many students are sophomores (i.e., have an expected graduation year of 2024)?"
	 <ul><li>Since you want to keep track of how many unique students graduate in <strong>a specific year</strong>, you should use a <strong>set</strong>. By storing the ID values of students whose graduation year is 2024, you can then answer the question by calculating the size of the set.</li></ul></li>
	<li>To answer: "How many different majors are represented in the class?"
	 <ul><li>Since you want to keep track of how many <strong>unique majors total</strong> are in the class, you should use a <strong>set</strong>. By storing the names of the majors in a set (which will only hold unique values), you can then answer the question by calculating the size of the set.</li></ul></li>
	<li>To answer: "How many students from each major are in the class?"
	 <ul><li>Since you want to keep track of how many students there are <strong>for each major</strong>, you should use a <strong>map</strong>. By storing the <strong>major as a key</strong> and the <strong>number of students with that major as a value</strong>, you can then answer the question by iterating through the map and printing each key-value pair.</li></ul></li>
	<li>To answer: "How many more CS majors than CE majors are in the class?"
	 <ul><li>Since you want to keep track of how many students there are <strong>in two distinct majors</strong>, you should use a <strong>map</strong>. By storing the <strong>major as a key</strong> and the <strong>number of students with that major as a value</strong>, you can then answer the question by iterating through the map and printing each key-value pair.</li></ul></li>
 	<li>To answer: "Are there more students who live in RI or who live out of state?"
	 <ul><li>Since you want to compare how many students live <strong>in different states</strong>, you should use a <strong>map</strong>. By storing the <strong>state as a key</strong> (or rather, RI and not-RI) and the <strong>number of students who live in that state as a value</strong>, you can then answer the question by indexing the map and comparing the values of RI vs not-RI.</li></ul></li>
</ul>

</details>

<br>

> 
- In general, **sets** can be used to answer questions such as:
	- How many unique values of a specific type?
	- Does a value exist or not?
- Whereas, **maps** can be used to answer questions such as:
	- How many unique values of different types?
	- How does one value compare to another?

##### Reading & Parsing Data Files

In order to be able to process data to answer questions about it, we will need to read the data. However, not all the data in our files will be relevant to our questions (notice how in the questions above we didn't need student names?). Therefore, as we read the data, we will also need to parse it: that is, determine whether it's relevant or not and if it is, put it in the correct location (in our case, store it into either a set or a map).

The steps required for handling an input file are as follows:

1. Create an instance of [ifstream](https://www.cplusplus.com/reference/fstream/ifstream/).
2. Open the file. (Check for failure to open.)
3. Read from the file.
4. Close the file.

> Parsing a file would happen in step #3.

When working with a real-world datasets, most of them are stored as CSVs: comma-separated values. A CSV has "columns" separated by commas and "rows" separated by newline characters. For example, in the class CSV from our example in the previous section, our columns could be in the following format:

``` FirstName,LastName,GradYear,Major,ID,State ```

To handle the commas, we can use an **overloaded** version of ```std::getline()```. If you read the [documentation](http://www.cplusplus.com/reference/string/string/getline/) for the function, you'll see that there is a version of the function that accepts a **delimiter**. By passing an argument for the delimeter, we specify **how** we want the string to be split up. Every call to ```std::getline()``` will read the data up to the next symbol set as the delimiter. You can place this in a loop to parse a delimited string:

```c++
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::string line;
    std::string entry;

    //Step 1: Create an instance of ifstream.
    std::ifstream table;               
    //Step 2: Open the file. 
    table.open("tabledata");  
    //Step 2 (part 2): (Check for failure to open.)
    if(table.fail()){                           
        std::cerr << "Can't open tabledata\n";
        return 1;
    }
    //Step 3: Read from the file. Specifically get a line of data from table, store in 'line'
    while(std::getline(table, line)) {        
        std::stringstream streamline(line);

        // Step 3 (parsing): Loop through each "column" in 'line' and store it into 'entry'
        while(std::getline(streamline, entry, ',')) {  
            std::cout << entry << std::endl;
        }
    }    
    //Step 4: Close the file
    table.close();                                  
}
```

> To see an example of CSV reading in action, check out this [repl.it](https://replit.com/@VictoriaChvez/full-csv-reading) (make sure to click where it says "**Code**") where I number each row and column for each entry of a small CSV.

---

#### Your Task {#task}

> Watch this lab's [video walkthrough](https://youtu.be/UVoLhJuvP2E)

You will be working with a real-world dataset. **Choose one** of the three datasets below and download its CSV. 

> 
- Option 1: [Billionaires Data](https://corgis-edu.github.io/corgis/csv/billionaires/)
- Option 2: [Movies on Netflix, Prime Video, Hulu and Disney+](https://www.kaggle.com/ruchi798/movies-on-netflix-prime-video-hulu-and-disney) (**Note**: You can download the file on the left side under "Data Explorer")
- Option 3: [Broadway Shows](https://corgis-edu.github.io/corgis/csv/broadway/)

1. Read the information about the three datasets above
2. Download **one of the three** datasets above 
3. Identify what the data is and how to read it 
	- What does each column represent?
	- Are there any abbreviations or codes? What do they mean?
4. Look at the questions (below) associated with your dataset and determine: 
	- Do you need a map or a set to answer each question?
	- Which columns from the dataset do you need to answer each question?

	> 
	- Questions for [option 1](https://corgis-edu.github.io/corgis/csv/billionaires/):
		1. What percentage of billionares inherited their wealth?  
			- **Hint:** Calculate how many billionares inherited vs didn't inherit their wealth then divide the total number who inherited their wealth by the total number of billionares  
		2. How many billionares are under 30 years old?
	- Questions for [option 2](https://www.kaggle.com/ruchi798/movies-on-netflix-prime-video-hulu-and-disney):
		1. What percentage of movies have a runtime of 120 minutes or more?  
			- **Hint:** Calculate how many movies have a runtime of 120 minutes or more vs 119 minutes or less then divide the total movies >=120 mins by the total number of movies  
		2. How many movies were produced after 2012?
	- Questions for [option 3](https://corgis-edu.github.io/corgis/csv/broadway/):
		1. What percentage of broadway shows are musicals?  
			- **Hint:** Calculate how many shows were musicals vs not musicals then divide the total number of musicals by the total number of shows  
		2. How many shows made more than $150,000?

5. [Review the code](https://replit.com/@VictoriaChvez/full-csv-reading) used to read and parse a small sample CSV where I number each row and column. Make sure to click where it says "**Code**".
6. Download [lab08.cpp](/sm21/labs/lab08/template-code/lab08.cpp)
7. Implement `readCSV()` keeping only the data necessary to answer your dataset's two questions (from task item 4) and inserting it appropriately into `mySet` or `myMap` 
	- Remember that in general, **sets** can be used to answer questions such as "How many unique values of a specific type?" or "Does a value exist or not?"; whereas, **maps** can be used to answer questions such as: "How many unique values of different types?" or "How does one value compare to another?"
	
	> 
	If you are using the BILLIONAIRES or BROADWAY datasets, **do not convert the numbers** using std::stoi or std::stof (or other numbers). Because the data includes quotes, C++ won't recognize it as numbers. However, you can still **do the comparison using strings**!  
		- BILLIONAIRES: use ```"\"30\""``` when checking age  
		- BROADWAY: use ```"\"150000\""``` when checking gross earnings  
		The \ symbol escapes the quotes so C++ knows the quote symbols are part of the string and since characters are internally represented as numbers on a computer, the comparison will still match up.
8. In `main()`, answer the questions for your respective dataset using the built-in functions for maps and sets 
	- Refer to the [documentation for std::map](https://www.cplusplus.com/reference/map/map/) as needed
	- Refer to the [documentation for std::set](https://www.cplusplus.com/reference/set/set/) as needed
9. Come up with **one question** you could ask about your data that can be answered by using a **set**. Describe how you would determine its answer using a **set**.
10. Come up with **one question** you could ask about your data that can be answered by using a **map**. Describe how you would determine its answer using a **maps**.
11. Record a **3-5 minute video of your screen** as you **explain your process and answers** for task items 7-10.

> Watch this lab's [video walkthrough](https://youtu.be/UVoLhJuvP2E)

---

#### Requirements {#reqs}
Your submission will be manually checked to ensure it meets the following specifications:  

1. Video is 3-5 minutes long and thoroughly explains answers while showing code (from task item 11)
2. One of the three listed datasets was used (from task item 2)
3. Both questions associated with chosen dataset answered correctly via appropriate use of set or map (from task item 4 and 8)
4. Student-chosen question and description of how to determine its answer would make appropriate use of set (from task item 9)
5. Student-chosen question and description of how to determine its answer would make appropriate use of map (from task item 10)

---

#### Handing in {#submit}
> Please **only submit after meeting ALL requirements**.

1. Upload your video to YouTube or Google Drive
	- If uploaded to YouTube, make sure its visibility is set to **unlisted**
	- If uploaded to Google Drive, share the video with my email and **uncheck the box next to "Notify people"**
2. Copy the link to your video
3. Submit the link to Gradescope. 

> For reference, my email is vcchavez [at] uri.edu

---

#### Grade Breakdown {#grading}
You must successfully meet [requirements](#reqs) **1 through 5** in order to receive credit for this assignment.

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sm21/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Original assignment by [Dr. Marco Alvarez](https://homepage.cs.uri.edu/~malvarez/), used and modified with permission.
