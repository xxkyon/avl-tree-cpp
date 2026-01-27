#### **AVL Tree in C++**



**This project implements an AVL Tree in C++ to manage student records using a self-balancing binary search tree.**



Each node stores a **Student object** identified by an **ID** and **name**.

The tree automatically maintains balance through rotations after insertions and removals.



This project was developed as a learning exercise focused on:

\- Data structures

\- Memory management

\- Recursion

\- Tree balancing algorithms



--------------------------------------------------



###### **Features**



\- Insert students into the AVL Tree

\- Remove students by ID

\- Search for a student by ID

\- Tree traversals:

&nbsp; - Pre-order

&nbsp; - In-order

&nbsp; - Post-order

\- Automatic rebalancing using:

&nbsp; - Single rotations (LL, RR)

&nbsp; - Double rotations (LR, RL)



--------------------------------------------------



###### **Concepts Applied**



\- Binary Search Trees (BST)

\- AVL balancing factor

\- Recursive insertion and removal

\- Pointer manipulation

\- In-order successor strategy for node removal

\- Separation of concerns using .h and .cpp files



--------------------------------------------------



###### **Project Structure**



avl-tree-cpp/

├── README.md

├── include/

│     ├── avlTree.h

│     └── student.h

└── src/

&nbsp;     ├── student.cpp

&nbsp;     ├── avlTree.cpp

&nbsp;     └── main.cpp



--------------------------------------------------



###### **Classes Overview**



**Student**



Represents a student with:

\- id (unique identifier)

\- name



Used as the data payload stored inside each tree node.



--------------------------------------------------



**Node**



Represents a node in the AVL Tree.



Each node contains:

\- A Student

\- Left and right child pointers

\- A balance factor used for AVL rebalancing



--------------------------------------------------



**AvlTree**



Implements the AVL Tree logic:

\- Recursive insertion and removal

\- Balance factor updates

\- Rotations to maintain height balance

\- Tree traversal methods



--------------------------------------------------



###### **How to Compile and Run**



Using g++:



g++ -Iinclude src/student.cpp src/avlTree.cpp src/main.cpp -o avlTree



--------------------------------------------------



###### **Example Usage**



The program runs in a terminal menu with the following options:



\- Insert a student

\- Remove a student

\- Search by ID

\- Print the tree using different traversal orders



--------------------------------------------------



###### **Notes**



\- The project prioritizes clarity and learning over optimization.

\- No STL containers such as map or set were used to reinforce understanding of tree structures.

\- This project reflects hands-on experience with lower-level C++ concepts such as pointers and manual memory management.



--------------------------------------------------



###### **Future Improvements**



\- Add support for duplicate IDs

\- Implement iterative versions of operations

\- Improve input validation

\- Add unit tests



--------------------------------------------------



###### **Author**



Developed as a study project to deepen understanding of data structures and C++ fundamentals.



