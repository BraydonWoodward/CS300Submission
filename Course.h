/*
    File: Course.h
    Author: Braydon Woodward
    Created: December 10th, 2023
    Description: Binary Search tree header file for ABCU Computer Science course catolog
*/
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Course {
    std::string courseNumber;  // unique identifier
    std::string courseTitle;
    std::vector<std::string> prerequisites;

    // Default constructor
    Course() {
        courseNumber = "";
        courseTitle = "";
    }

    // Parameterized constructor
    Course(std::string number, std::string title) {
        courseNumber = number;
        courseTitle = title;
    }

    // Function to iterate through and print prerequisites
    void printPrerequisites() const {
        for (const auto& prereq : prerequisites) { 
            std::cout << prereq << " ";
        }
        std::cout << std::endl;
    }

    // Function to add prerequisites

    void addPrerequisite (std::string prereq) {
        this->prerequisites.push_back(prereq);
    
    }
};

class CourseNode {
private:
    Course course;
    CourseNode* left;
    CourseNode* right;

public:
    CourseNode();
    CourseNode(Course course);
    ~CourseNode();  

    friend class CourseTree;
};

class CourseTree {
private:
    CourseNode* root;
    void inOrder(CourseNode* node);
    void addNode(CourseNode* node, Course course);
    void destroyRecursive(CourseNode* node);

public:
    CourseTree();
    ~CourseTree();
    void inOrder();
    void insert(Course course);
    Course search(std::string courseNumber);
    void loadDataStructure(const std::string& fileName);
};
#endif


