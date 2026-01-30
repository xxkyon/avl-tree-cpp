# AVL Tree Student Management System (C++)

## Overview

This project is a C++ console application that implements an AVL Tree to manage student records.
Users can insert, remove, search, update, and print students using a menu-based interface.

The goal of this project is to demonstrate practical understanding of:

- Self-balancing binary search trees (AVL Trees)
- Pointers and references
- Recursion
- Tree rotations
- Input validation
- Object-oriented programming in C++

---

## Project Structure

avl-tree-cpp/
|
|-- include/
|   |-- avlTree.h
|   |-- student.h
|   |-- utils.h
|
|-- src/
|   |-- avlTree.cpp
|   |-- student.cpp
|   |-- utils.cpp
|   |-- main.cpp

---

## Student Management

Each student has:
- A unique integer ID
- A name (string)

Duplicate IDs are not allowed.

If the user tries to insert a student with an existing ID, the program:
1. Detects the duplicate
2. Offers the option to update the student’s name
3. Or cancel the operation

This guarantees data integrity while remaining user-friendly.

---

## Input Validation (utils.cpp / utils.h)

The project includes a dedicated utility module to handle safe input.

### Integer Input

- IDs and menu options must be integers
- Invalid input (letters or symbols) is rejected
- The input buffer is cleared properly to avoid infinite loops

### Name Validation

- Names cannot contain numbers
- Names can contain spaces and accented characters
- Extra spaces are normalized:
  - Leading and trailing spaces are removed
  - Multiple consecutive spaces are reduced to one

This behavior is implemented using a custom normalizeSpaces function.

---

## AVL Tree Implementation

### Node Structure

Each node stores:
- A Student object
- A pointer to the left child
- A pointer to the right child
- A balance factor used to keep the tree balanced

### Insertion

- Uses standard BST insertion logic
- Updates balance factors during recursive unwinding
- Automatically rebalances the tree when necessary

### Removal

Deletion handles all three cases:
1. Node with no children
2. Node with one child
3. Node with two children

For nodes with two children:
- The in-order successor is found
- The current node’s data is replaced
- The successor node is removed recursively

The remove function returns a boolean indicating whether the student was found and removed.

---

## Tree Rebalancing and Rotations

The AVL tree maintains balance using the following rotations:

- Right Rotation (LL case)
- Left Rotation (RR case)
- Left-Right Rotation (LR case)
- Right-Left Rotation (RL case)

Balance factors are updated carefully after insertions and removals to preserve the AVL property.

---

## Tree Traversals

The tree supports three traversal methods:

- Pre-order: Root -> Left -> Right
- In-order: Left -> Root -> Right
  (prints students sorted by ID)
- Post-order: Left -> Right -> Root

---

## User Interaction (main.cpp)

- Menu-based interface
- Repeats until the user chooses to exit
- Validates menu options
- Provides clear feedback for all operations:
  - Successful insertion
  - Successful removal
  - Student not found
  - Invalid input

---

## How to Compile and Run

1. Navigate to the project root folder:

cd avl-tree-cpp

2. Compile all source files:

g++ src/*.cpp -Iinclude -o avl

3. Run the program:

Linux / macOS:
./avl

Windows:
avl.exe

---

## Example Usage

***********************************
Type in 0 to stop the algorithm
Type in 1 to insert an element
Type in 2 to remove an element
Type in 3 to search for an element
Type in 4 to print the AVL tree

Choose an option: 1
Insert the student's ID: 101
Insert the student's name: André Schiavone

Choose an option: 4
Type 2 to print it in order

André Schiavone (101)
***********************************

---

## Testing Strategy

The program can be tested directly through the executable by verifying:

- Insertion of multiple students
- Automatic balancing after insertions
- Removal of leaf nodes
- Removal of nodes with one child
- Removal of nodes with two children
- Correct rebalancing after removals
- Searching for existing and non-existing IDs
- Updating student names
- Correct output of all traversal methods
- Input validation for invalid menu options, IDs, and names

---

## Potential Improvements

- Add file I/O to save and load students
- Display balance factors for debugging or learning purposes
- Improve UI with colors or clearer formatting
- Add automated unit tests
- Extend validation rules for names
