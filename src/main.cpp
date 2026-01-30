#include <iostream>
#include <string>
#include "avlTree.h"
#include "utils.h"

int main(){
    AvlTree studentTree;

    int option, id, printOption;

    std::string name;

    do{ std::cout << "\n\n";
        std::cout << "***********************************\n";
        std::cout << "Type in 0 to stop the algorithm\n";
        std::cout << "Type in 1 to insert an element\n";
        std::cout << "Type in 2 to remove an element\n";
        std::cout << "Type in 3 to search for an element!\n";
        std::cout << "Type in 4 to print the AVL tree!\n";
        std::cout << "\n\n";
        option = readInt("Choose an option: ");
        
        if(option < 0 || option > 4){
            std::cout << "Invalid option. Please choose a number between 0 and 4.\n";
            std::cout << "\n\n";
            continue;
        }

        if(option == 1){
            id = readInt("Insert the student's ID: ");

            Student foundStudent;
            if(studentTree.search(id, foundStudent)){
                std::cout << "\n\n";
                std::cout << "There's already a student with this ID.\n";
                std::cout << "1. Update name\n";
                std::cout << "2. Cancel\n";    
                std::cout << "\n\n";
                int choice = readInt("Choose an option: ");
                if(choice == 1){
                    name = readString("Insert the new name: ");
                    studentTree.updateStudentName(id, name);
                    std::cout << "Student updated successfully.\n";
                }
                continue;
            }
            name = readString("Insert the student's name: ");
            studentTree.insert(Student(id, name));

        } else if (option == 2){
            std::cout << "\n\n";
            id = readInt("Type in the ID of the student you want to remove: ");
            Student student(id, " ");
            
            if(!studentTree.remove(student)){
                std::cout << "\n\n";
                std::cout << "Student not found.\n";
            } else {
                std::cout << "\n\n";
                std::cout << "Student removed successfully\n";
            }
        } else if (option == 3){
            std::cout << "\n\n";
            id = readInt("Type in the ID of the student you want to search: ");

            Student student;
            bool found = studentTree.search(id, student);
            
            if(found){
                std::cout << "\n\n";
                std::cout << "The student has been found!\n";
                std::cout << "Name: " << student.getName() << std::endl;
                std::cout << "ID: " << student.getId() << std::endl;
            } else {
                std::cout << "\n\n";
                std::cout << "This student hasn't been found!\n";
            } 
        } else if (option == 4){
            std::cout << "\n\n";
            std::cout << "Type 1 to print it in pre-order!\n";
            std::cout << "Type 2 to print it in order!\n";
            std::cout << "Type 3 to print it in post-order!\n";
            std::cout << "\n\n";
            printOption = readInt("Your option: ");
            if(printOption == 1){
                studentTree.printPreOrder();
            } else if(printOption == 2){
                studentTree.printInOrder();
            } else if(printOption == 3){
                studentTree.printPostOrder();
            } else{
                std::cout << "\n\n";
                std::cout << "Invalid option. \n";
            }
        }
        std::cout << "\n***********************************\n";
    } while (option != 0);

    return 0;
}