#include <iostream>
#include <string>
#include "avlTree.h"

int main(){
    AvlTree studentTree;

    int option, id, printOption;

    std::string name;

    bool found = false;

    do{
        std::cout << "Type in 0 to stop the algorithm\n";
        std::cout << "Type in 1 to insert an element\n";
        std::cout << "Type in 2 to remove an element\n";
        std::cout << "Type in 3 to search for an element!\n";
        std::cout << "Type in 4 to print the AVL tree!\n";

        std::cin >> option;

        if(option == 1){
            std::cout << "Insert the student's name:\n";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Insert the student's ID:\n";
            std::cin >> id;
            Student student(id, name);
            studentTree.insert(student);
        } else if (option == 2){
            std::cout << "Type in the ID of the student you want to remove:\n";
            std::cin >> id;
            Student student(id, " ");
            studentTree.remove(student);
        } else if (option == 3){
            std::cout << "Type in the ID of the student you want to search!\n";
            std::cin >> id;
            Student student(id, " ");
            studentTree.search(student, found);
            if(found){
                std::cout << "The student has been found!\n";
                std::cout << "Name: " << student.getName() << std::endl;
                std::cout << "ID: " << student.getId() << std::endl;
            } else {
                std::cout << "This student hasn't been found!\n";
            } 
        } else if (option == 4){
            std::cout << "Type 1 to print it in pre-order!\n";
            std::cout << "Type 2 to print it in order!\n";
            std::cout << "Type 3 to print it in post-order!\n";
            std::cin >> printOption;
            if(printOption == 1){
                studentTree.printPreOrder();
            } else if(printOption == 2){
                studentTree.printInOrder();
            } else if(printOption == 3){
                studentTree.printPostOrder();
            }
        }
        
    } while (option != 0);

    return 0;
}