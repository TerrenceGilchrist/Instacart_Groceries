# Instacart_Groceries
Insight Coding Challenge for the Data Engineering Program | Instacart Online Grocery Shopping Dataset 2017 | C++

**Table of Contents**
I.    Purpose
II.   Dataset
III.  Output
IV.   Time
V.    Implementation
VI.   My Approach
VII.  What I Learned


**I.    Purpose**

The code distills a dataset of online grocery purchases into a spreadsheet of total orders and first-time orders by respective department.



**II.   Dataset**

The files products.csv and orders.csv are directly from the Instacart Online Grocery Shopping Dataset 2017. Products.csv has 49,689 rows, including the header row. Order_products__prior.csv has 32,434,490 rows, also inclusive of the header row with the names of the columns.



**III.   Output**

As mentioned, the program generates a table, by grocery department, of (a) total orders, (b) first-time orders, and (c) percentage of first-time orders to total orders.



**IV.    Time**

The program runs on my laptop from 57.025 seconds to a few milliseconds over 61 seconds.



**V.     Implementation**

To run this program, some combination of the following items will assist. 
a) *Text Editor* – Emacs, Notepad++, Notepad, and
b) *C++ Compiler* – Apple, Clang, Cygwin, Digital Mars, GCC, Mingw, Intel,
or
c) *Combination of Compiler and Text Editor* – Atom, CLion, Code::Blocks, Microsoft SDK, Netbeans, Visual Studio

The selection is according to individual preference. Even Bjourne Stroustrup does not express, at least publicly, a preference for compiler. See "An Incomplete List of C++ Compilers," http://www.stroustrup.com/compilers.html, by Bjourne Stroustrup. Back in 2006 and 2007, I myself have programmed in a Unix environment with access to supercomputers at the Harvard-MIT Data center, located at the northern Knafel Building of the Institute for Quantitative Social Science. Now with my own laptop, built circa 2009 with two Intel core i5 processors, I prefer to use Notepad++, which can save programs in various compiled and interpreted languages, from C++ to R. I prefer to compile with Code::Blocks, which allows me to simply point and click. Please forgive me.



**VI.     My Approach**

To address the matter of perusing several tens of millions of rows of data, I focused with composing the code to selectively concatenate characters from specific columns then only retain the data for a brief moment while either a function derives information based upon that data or a conditional statement responds to that data, depending upon the column. A map container was created, with product_id as the key and department_id as the only other member. This container facilitated identifying and matching the department_id from the product_id data of the order_products.csv file. A binary search function was written to conduct the matching thereby deriving the aforementioned information based upon the concatenated data.



**VII.     What I Learned**

Each coding experience, from 1989 to the present, has always presented a new lesson or expansion of knowledge. Here are some concepts that helped in completing this coding challenge.

a) *End of File to End of Loop* – To read a file, in the past, I have counted the rows and used a for loop. This time, I create while loop with the condition of ( !File.eof() ). Yet, to ensure the loop finished, I wrote a line to detect the end of file character: File.peek() == char_traits<char>::eof.

b) *Correct Dataset* – Computer programs operate upon what they are given or designed to seek. In my rush to meet the deadline, I used the correct dataset of products.csv but the incorrect dataset of orders.csv. After reviewing the glossary from the Instacart dataset, I downloaded the correct data set: order_products__prior.csv.

c) *Existence of Various String to Integer Conversions* – At first, I had each department_id saved as a string. Yet, the alphabetical sorting of these string of department_ids was not in exact numerical order, e.g. 111999, 112, 112000. I revised my code and ultimately settled upon the legacy atoi function from the C language. C++11 has a string to integer function called stoi. There is also a choice of using stringstream from the cstlib.

d) *Clearing Strings* – At times, my initial internal data and output had large numbers with many significant digits. His was especially true after converting strings to integers. After double checking and using various string to integer conversions, I resolved the matter by adding a line for appending a string variable with the clear function: data.clear().

e) *Filtering Characters* – For anyone who has handed administrative datasets, sometimes clerical errors appear. Without having viewed the entire Instacart order_products__prior.csv data set, it appears that the product_id column has non-numerical values. To address this, I invoked the functions isalpha and isdigit as well as isblank and isspace.

f) *Iterators* –Although I deployed a map container to recreate the products.csv data file, my submitted version of this code project only uses an iterator once and not extensively. Yet, I learned about iterators and how to use. To instantiate, the code involves the following: vector<string, int>::iterator name_of_iterate_variable. Iterators can acquire data by equating to the respective container: name_of_iterate_variable = name_of_vector_container. Then, to access the iterator, which itself is a pointer, arrows and the words first or second are involved: name_of_iterate_variable->first.

g) *Adding to a Map Container* – Emplace is the method that I chose to initially fill the map. Later in the program, I equated the map with its respective key of product_id to the other member of the map, which was department_id.

h) *Reserving Memory for a Map Container* – Get_allocator().allocate() is a way to demarcate sufficient memory space. There is a way to deallocate too.
