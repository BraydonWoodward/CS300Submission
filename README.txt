READ ME : CSCourseTree

 Author: Braydon Woodward
 Created: December 10th, 2023
 Description: Binary Search tree for ABCU Computer Science course catolog 

This is a command line argument program that accepts the name of a file
with comma seperated data. Each entry should appear on its own line and
the data file should be stored in the same directory as the program. 

This program has the functionality to:
1. Load the courses into a Binary Search Tree.(data must be loaded first)
2. Print the courses in Alphanumeric Order.
3. Search for a course by CourseNumber and print the courses infoormation;


EXAMPLE DATA INPUT: CourseNumber,CourseTitle,Prerequisites(1),Prerequisites(2) 

MATH201,Discrete Mathematics
CSCI300,Introduction to Algorithms,CSCI200,MATH201
CSCI350,Operating Systems,CSCI300
CSCI101,Introduction to Programming in C++,CSCI100
CSCI100,Introduction to Computer Science
CSCI301,Advanced Programming in C++,CSCI101

CS300 SUBMISSION ANSWERS
1. What was the problem you were solving in the projects for this course? 
  -The problem for this project was to design a program for a CS Advisor that stores a catalog of
   courses offered and allows them to input courses, print out all courses, and search for a course.

2. How did you approach the problem?
  -Before this project, we worked with multiple data sctructures. I decided on a binary tree because the data set would be easy to 
   print in alphanumerical order, and searching the catalog would be fast and easy. I also considered that the data set would never
   get too large as to cause problems with the binary tree.

3. How did you overcome any roadblocks you encountered while going through the activities or project? 
  -My favorite technique to overcome road bloack is to take a break thinking about other things. I find that the answer to my issues
   comes naturally to me that way. I also used print statements to determine exactly what part of code was buggy.

4. How has your work on this project expanded your approach to designing software and developing programs?
   -This project has taught me the importance of properly formatting stored data, as well as making sure an empty structure is also formatted
    in a predictable way. 

5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
   -In this project I made sure to write functions as simple as possible, creating new functions to call if neccesary. So the functions are simple to read and understand. 
    In the past I would have functions that were more complex than they should have been. 
    

