# Doubly Linked List Implementation

This repository contains an implementation of a Doubly Linked List data structure in C++, along with a demonstration of its usage.

## Overview

A Doubly Linked List is a type of linked list in which each node contains a reference to the next and previous nodes, allowing bidirectional traversal. This implementation provides functionalities for insertion, deletion, searching, and manipulation of elements in the list.

## Features

- Efficient insertion and deletion operations
- Bidirectional traversal and manipulation
- Search operations for finding elements
- Memory management for dynamic data storage

## Usage

1. **Clone the Repository:**
   - Open your terminal or command prompt.
   - Clone the repository to your local machine:
     ```
     git clone https://github.com/exampleuser/DoublyLinkedList.git
     ```
   - Navigate to the cloned directory:
     ```
     cd DoublyLinkedList
     ```

2. **Build the Project:**
   - Ensure Make is installed on your system.
   - Run the Makefile to build the project:
     ```
     make
     ```

3. **Run the Program:**
   - Execute the compiled program:
     ```
     ./doublyLinkedList > doublyLinkedListOutput.txt
     ```
   - This command generates the output in a text file named `doublyLinkedListOutput.txt`.

4. **View the Output:**
   - Open `doublyLinkedListOutput.txt` to view the program output.

5. **Clean Up:**
   - To remove compiled files, run:
     ```
     make clean
     ```

## Implementation and Usage Across Different Operating Systems

The implementation and usage of this code may vary slightly depending on your operating system.

- **Windows Users:** No modifications are typically needed. Follow the provided instructions to compile and run the code.

- **Mac or Linux Users:** In the Makefile, you may need to modify the `clean` target to ensure proper deletion of object files and executables. Replace `rm -f *.o doublyLinkedList` with `rm -f *.o doublyLinkedList doublyLinkedList.exe`. Additionally, ensure you have the necessary dependencies installed to compile the code, such as `make` and `g++`. Follow the provided instructions to clone the repository, compile the code, and run the executable.

## Contributing

Contributions are welcome! If you have any suggestions, improvements, or bug fixes, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
