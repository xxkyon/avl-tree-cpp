#include <iostream>
#include <cstddef> //nullptr
#include "avlTree.h"

//construtor
AvlTree::AvlTree() : root(nullptr) {}

AvlTree::~AvlTree(){ //destrutor
    removeTree(root);
    root = nullptr;
}

void AvlTree::removeTree(Node* currentNode){
    if(currentNode != nullptr){
        removeTree(currentNode->leftChild);
        removeTree(currentNode->rightChild);
        delete currentNode;
    }
}

Node* AvlTree::getRoot() const{
    return root;
}
bool AvlTree::isEmpty() const{
    return(root == nullptr);
}
void AvlTree::insert(const Student& student){
    bool heightIncreased = false;
    recursiveInsert(root, student, heightIncreased);
}

void AvlTree::recursiveInsert(Node*& currentNode, const Student& student, bool& heightIncreased){
    if(currentNode == nullptr){
        currentNode = new Node(student);
        heightIncreased = true;
        return;
    }

    if(student.getId() < currentNode->student.getId()){
        recursiveInsert(currentNode->leftChild, student, heightIncreased);
        if(heightIncreased) currentNode->balanceFactor--;
    } else if(student.getId() > currentNode->student.getId()){
        recursiveInsert(currentNode->rightChild, student, heightIncreased);
        if(heightIncreased) currentNode->balanceFactor++;
    } else{
        heightIncreased = false;
        return;
    }

    rebalance(currentNode);

    if(heightIncreased && currentNode->balanceFactor == 0){
        heightIncreased = false;
    }
}

bool AvlTree::remove(const Student& student){
    bool heightDecreased = false;
    bool removed = false;

    removeRecursive(student, root, heightDecreased, removed);
    return removed;
}

Node* AvlTree::getInOrderSuccessor(Node* node){
    Node* current = node;
    while(current->leftChild != nullptr){
        current = current->leftChild;
    }
    return current;
}


void AvlTree::removeRecursive(const Student& student, Node*& currentNode, bool& heightDecreased, bool& removed){

    if(currentNode == nullptr){
        heightDecreased = false;
        return;
    }

    if(student.getId() < currentNode->student.getId()){
        removeRecursive(student, currentNode->leftChild, heightDecreased, removed);
        if(heightDecreased){
            currentNode->balanceFactor+=1;
        }
    } else if (student.getId() > currentNode->student.getId()){
        removeRecursive(student, currentNode->rightChild, heightDecreased, removed);
        if(heightDecreased){
            currentNode->balanceFactor-=1;
        }
    } else {
        removed = true;
        removeNode(currentNode, heightDecreased);
    }

    if(currentNode != nullptr){
        rebalance(currentNode);
        if(heightDecreased && currentNode->balanceFactor != 0){
            heightDecreased = false;
        }
    }
}

void AvlTree::removeNode(Node*& currentNode, bool& heightDecreased){
    Node* temp = currentNode;
    if(currentNode->leftChild == nullptr){
        currentNode = currentNode->rightChild;
        delete temp;
        heightDecreased = true;
    } else if(currentNode->rightChild == nullptr){
        currentNode = currentNode->leftChild;
        delete temp;
        heightDecreased = true;
    } else{
        Node* successor = getInOrderSuccessor(currentNode->rightChild);
        Student successorStudent = successor->student;
        currentNode->student = successorStudent;

        bool removed = false;
        removeRecursive(successorStudent, currentNode->rightChild, heightDecreased, removed);
        if(heightDecreased){
            currentNode->balanceFactor-=1;
        } 
    }
}

bool AvlTree::search(int id, Student& result){
    Node* current = root;

    while(current != nullptr){
        if(id < current->student.getId()){
            current = current->leftChild;
        } else if(id > current->student.getId()){
            current = current->rightChild;
        } else{
            result = current->student;
            return true;
        }
    }
    return false;
}


bool AvlTree::updateStudentName(int id, const std::string& newName){
    Node* current = root;

    while(current != nullptr){
        if(id < current->student.getId()){
            current = current->leftChild;
        } else if(id > current->student.getId()){
            current = current->rightChild;
        } else {
            current->student.setName(newName);
            return true;
        }
    }
    return false;
}


void AvlTree::printPreOrder() const{
    printPreOrder(root);
}

void AvlTree::printInOrder() const{
    printInOrder(root);
}

void AvlTree::printPostOrder() const{
    printPostOrder(root);
}

void AvlTree::printPreOrder(Node* currentNode) const{
    if(currentNode != nullptr){
        std::cout << currentNode->student.getName() << " (" << currentNode->student.getId() << ")\n";
        
        printPreOrder(currentNode->leftChild);
        printPreOrder(currentNode->rightChild);
    }
}
void AvlTree::printInOrder(Node* currentNode) const{
    if(currentNode != nullptr){
        printInOrder(currentNode->leftChild);

        std::cout << currentNode->student.getName() << " (" << currentNode->student.getId() << ")\n";

        printInOrder(currentNode->rightChild);
    }
}
void AvlTree::printPostOrder(Node* currentNode) const{
    if(currentNode != nullptr){
        printPostOrder(currentNode->leftChild);
        printPostOrder(currentNode->rightChild);

        std::cout << currentNode->student.getName() << " (" << currentNode->student.getId() << ")\n";
    }
}

//Novos metodos:

void AvlTree::rightRotation(Node*& parent){
    Node* newParent = parent->leftChild;
    parent->leftChild = newParent->rightChild;
    newParent->rightChild = parent;
    parent = newParent;
}

void AvlTree::leftRotation(Node*& parent){
    Node* newParent = parent->rightChild;
    parent->rightChild = newParent->leftChild;
    newParent->leftChild = parent;
    parent = newParent;
}

void AvlTree::leftRightRotation(Node*& parent){
    Node* child = parent->leftChild;
    leftRotation(child);
    parent->leftChild = child;
    rightRotation(parent);
}

void AvlTree::rightLeftRotation(Node*& parent){
    Node* child = parent->rightChild;
    rightRotation(child);
    parent->rightChild = child;
    leftRotation(parent);
}

void AvlTree::rebalance(Node*& parent){
    Node* child;
    Node* grandchild;

    if(parent->balanceFactor == -2){
        child = parent->leftChild;
        if(child == nullptr) return;

        if(child->balanceFactor == -1){
            parent->balanceFactor = 0;
            child->balanceFactor = 0;
            rightRotation(parent);
        } else if (child->balanceFactor == 0){
            parent->balanceFactor = -1;
            child->balanceFactor = 1;
            rightRotation(parent);
        } else if (child->balanceFactor == 1){
            grandchild = child->rightChild;
            if(grandchild == nullptr) return;
            
            if(grandchild->balanceFactor == -1){
                parent->balanceFactor = 1;
                child->balanceFactor = 0;
            } else if (grandchild->balanceFactor == 0){
                parent->balanceFactor = 0;
                child->balanceFactor = 0;
            } else if (grandchild->balanceFactor == 1){
                parent->balanceFactor = 0;
                child->balanceFactor = -1;
            }
            grandchild->balanceFactor = 0;
            leftRightRotation(parent);
        }
    } else if(parent->balanceFactor == 2){
        child = parent->rightChild;
        if(child == nullptr) return;

        if(child->balanceFactor == 1){
            parent->balanceFactor = 0;
            child->balanceFactor = 0;
            leftRotation(parent);
        } else if (child->balanceFactor == 0){
            parent->balanceFactor = 1;
            child->balanceFactor = -1;
            leftRotation(parent);
        } else if (child->balanceFactor == -1){
            grandchild = child->leftChild;
            if(grandchild == nullptr) return;

            if(grandchild->balanceFactor == -1){
                parent->balanceFactor = 0;
                child->balanceFactor = 1;
            } else if (grandchild->balanceFactor == 0){
                parent->balanceFactor = 0;
                child->balanceFactor = 0;
            } else if (grandchild->balanceFactor == 1){
                parent->balanceFactor = -1;
                child->balanceFactor = 0;
            }
            grandchild->balanceFactor = 0;
            rightLeftRotation(parent);
        }
    }
}