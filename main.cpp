/*
    File: main.cpp
    Author: Braydon Woodward
    Created: December 10th, 2023
    Description: Main program for the ABCU Computer Science course catolog binary Search tree
*/
#include "course.h"     // Include the header file that contains Course-related functions
#include <iostream>  
#include <sstream>



int main(int argc, char* argv[]) {
    // Ensure the program name and csvFile name are given
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name>" << std::endl;
        return 1;
    }

    std::string fileName(argv[1]);// Retrieve the fileName from command-line arguments
    CourseTree* courseTree = new CourseTree(); // Create an instance of the CourseTree
    std::string courseNumber; // Declare courseNumber for user input
    Course foundCourse; 

    int choice = 0;
    while (choice != 4) {
        // Display menu options to the user
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Load Data Structure (BST)" << std::endl;
        std::cout << "2. Print Course List (BST)" << std::endl;
        std::cout << "3. Print Course (BST)" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Take user input for menu choice

        try {
            switch (choice) {
            case 1:
               courseTree->loadDataStructure(fileName); // Load data into the BST
                std::cout << "Data loaded successfully." << std::endl;
                
                break;
            case 2:
                courseTree->inOrder(); // Print course list in alphanumeric order
                break;
            case 3:
                std::cout << "Enter course number: ";
                std::cin >> courseNumber; // Take user input for course number
                foundCourse = courseTree->search(courseNumber); // Search for course
                if (foundCourse.courseNumber != "") {// Print found course
                    std::cout << "Found course: " << foundCourse.courseNumber << ": " 
                              << foundCourse.courseTitle << " | " << "Prerequisites: ";
                    foundCourse.printPrerequisites();
                    std::cout << std::endl;
                }
                else {
                    std::cout << "Course not found!" << std::endl;
                }
                break;
            case 4:
                std::cout << "Exiting the program..." << std::endl;
                break;
            default:
                throw std::invalid_argument("Invalid choice. Please select a valid option."); // Throw an exception for invalid choice
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl; // Display error message for caught exceptions
        }
        catch (...) {
            std::cerr << "An unknown error occurred." << std::endl; // Display a generic error message for unknown exceptions
        }

        std::cin.clear(); // Clear the input stream state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any remaining characters in the input buffer
    }

    return 0;
}

