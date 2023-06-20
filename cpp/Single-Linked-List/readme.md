# Linked List (C++)

![C++](https://img.shields.io/badge/C%2B%2B-C%2B%2B17-green)

[![License: MIT](https://img.shields.io/badge/License-MIT-red.svg)](https://opensource.org/licenses/MIT)

![Version](https://img.shields.io/badge/Version-v1.0-navy)


This repository contains a simple and efficient implementation of a Linked List data structure in C++. The Linked List is a fundamental data structure used to store a collection of elements where each element points to the next element in the sequence.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Methods](#methods)
- [Contributing](#contributing)
- [License](#license)

## Features

- Insertion of elements at the end of the list.
- Deletion of specific elements from the list.
- Finding the length of the list.
- Dropping the first or last element of the list.
- Inserting an element at the beginning of the list.
- Printing the elements of the list.
- Reverse the elements of the list.
- Coming Soon 🐱‍🏍
## Installation

1. Clone the repository: 

2. ```git clone``` https://github.com/mohamedo7x/Data-Structure.git

3. ```cd``` linked-list-cpp

4. ```g++ -o main main.cpp```


## Usage

```cpp
#include <iostream>

int main()
{
    LinkedList list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);
   
    list.print();
    return 0;
}
```
 
## Methods
``` cpp 

      // Insert an element at the beginning of the list
    list.InsertFront(120);

    // Remove a specific element from the list
    list.drop(5);

    // Remove the last element from the list
    list.dropBack();

    // Remove the first element from the list
    list.dropFront();

    // Get the length of the list
    list.length();

    // Print the elements of the list
    list.print();

     // reverse the elements of the list
    list.reverse();

```
## Contributing
Thank you for considering contributing to this project! Contributions are highly appreciated and welcomed. To ensure smooth collaboration.
## License
This project is licensed under the [MIT License](https://opensource.org/license/mit/). See the LICENSE file for details.

___

