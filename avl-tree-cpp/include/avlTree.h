#ifndef AVLTREE_H
#define AVLTREE_H

#include <cstddef>
#include "student.h"

struct Node{
    Student student;
    Node* leftChild;
    Node* rightChild;
    int balanceFactor;

    Node(const Student& a) : student(a), leftChild(nullptr), rightChild(nullptr), balanceFactor(0) {} 

};

class AvlTree{
    private:
        Node* root;
        void removeTree(Node* currentNode);

        void printPreOrder(Node* currentNode) const;
        void printInOrder(Node* currentNode) const;
        void printPostOrder(Node* currentNode) const;

    public: 
        AvlTree();
        ~AvlTree();
        
        Node* getRoot() const;
        bool isEmpty() const;

        void insert(const Student& student);
        void remove(const Student& student);
        void removeRecursive(const Student& student, Node*& currentNode, bool& heightDecreased);
        void removeNode(Node*& currentNode, bool& heightDecreased);
        void getInOrderSuccessor(Student& nextStudent, Node* temp);
        void search(Student& student, bool& found);

        void printPreOrder() const;
        void printInOrder() const;
        void printPostOrder() const;

        void rightRotation(Node*& tree);
        void leftRotation(Node*& tree);
        void leftRightRotation(Node*& tree);
        void rightLeftRotation(Node*& tree);
        void rebalance(Node*& tree);
        void recursiveInsert(Node*& currentNode, const Student& student, bool& heightIncreased);
};

#endif