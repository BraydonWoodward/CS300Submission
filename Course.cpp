/*
    File: Course.cpp
    Author: Braydon Woodward
    Created: December 10th, 2023
    Description: Binary Search tree for ABCU Computer Science course catolog 
*/

#include "Course.h"

#include <sstream>


// CourseNode constructors and destructor

CourseNode::CourseNode() {
    left = nullptr;
    right = nullptr;
}

CourseNode::CourseNode(Course aCourse) : CourseNode() {
    this->course = aCourse;
}

CourseNode::~CourseNode() {
    left = nullptr;
    right = nullptr;
}

// CourseTree constructors and destructor

CourseTree::CourseTree() {
    root = nullptr;
}

CourseTree::~CourseTree() {
    destroyRecursive(root);
    root = nullptr;
}

// Recursive function to destroy CourseTree nodes

void CourseTree::destroyRecursive(CourseNode* node) {
    if (node != nullptr) {
        destroyRecursive(node->left);
        destroyRecursive(node->right);
        delete node;
    }
}


// Traverses CourseTree in-order

void CourseTree::inOrder() {
    this->inOrder(root);
}

// Inserts a course into the CourseTree

void CourseTree::insert(Course course) {
    if (root == nullptr) {
        root = new CourseNode(course);
    }
    else {
        this->addNode(root, course);
    }
}


// Searches for a course in the CourseTree

Course CourseTree::search(std::string courseNumber) {
    CourseNode* current = root;// set current node equal to root

    // keep looping downwards until bottom reached or match found
    while (current != nullptr) {
        if (current->course.courseNumber.compare(courseNumber) == 0) {// if match found, return current bid
            return current->course;
        }
        if (courseNumber.compare(current->course.courseNumber) < 0) {// if bid is smaller than current node then traverse left
            current = current->left;
        }
        else {
            current = current->right;// else it is larger so traverse right
        }
    }

    Course emptyCourse; // Return an empty course if not found
    return emptyCourse;
}

// Adds a course node to the CourseTree
void CourseTree::addNode(CourseNode* node, Course course) {
    if (node->course.courseNumber.compare(course.courseNumber) > 0) {// if node is larger  add to left
        if (node->left == nullptr) {// if left child is null add  to the left
            node->left = new CourseNode(course);
        }
        else { // else there is a node
            this->addNode(node->left, course);  
        }
    }
    else {// add to the right 
        if (node->right == nullptr) {// if left child is null add  to the left
            node->right = new CourseNode(course);
        }
        else {
            this->addNode(node->right, course);// else there is a node
        }
    }
}

// Traverses CourseTree in-order and prints course details

void CourseTree::inOrder(CourseNode* node) {
    if (node != nullptr) {
        inOrder(node->left);
        std::cout << node->course.courseNumber << ": " << node->course.courseTitle << std::endl;
        inOrder(node->right);
    }
 }


void CourseTree::loadDataStructure(const std::string& fileName) {

    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) { // Read file line by line
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> courseTokens;

        while (std::getline(ss, token, ',')) {  // Parse each line into tokens
            courseTokens.push_back(token);
        }

        // Check if there are at least two parameters on each line
        if (courseTokens.size() >= 2) {
            std::string courseNumber = courseTokens[0];
            std::string courseTitle = courseTokens[1];
            Course newCourse = Course(courseNumber, courseTitle);

            // Check for prerequisites and add them to the course node
            for (size_t i = 2; i < courseTokens.size(); ++i) {
                newCourse.addPrerequisite(courseTokens[i]);
            }

            // Add the course node to the CourseTree
            insert(newCourse);

        }
        else {
            std::cerr << "Error: Invalid format for course data" << std::endl;
        }

    }

    file.close(); // close file
}