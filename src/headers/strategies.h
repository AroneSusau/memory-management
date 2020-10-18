// * * * * * * * * * * * * * * * * 
// 2020 Semester 2 - Assignemnt 2
// Author: Arone Susau
// Course: COSC1114 
// Student#: s3728977
// * * * * * * * * * * * * * * * *

#ifndef STRATEGIES
#define STRATEGIES

#include <string>
#include <list>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <cstring>
#include <algorithm>

#include "memory_block.h"
#include "types.h"

#define FIRST "FIRST"
#define BEST "BEST"
#define WORST "WORST"

#define ALLOC_MAX 1000

class strategies {

  public:
    string type = "";
    int name_index = 0;
    int total_memory = 0;
    int max_names = 0;

    // Determines the allocation strategy specified and executes it
    //
    // names &names                     - List of names
    // memory_list &allocMBList - List of currently allocated memory blocks
    // memory_list &freeMBList  - List of currently deallocated memory blocks
    void allocate(names &names, memory_list &allocMBList, memory_list &freeMBList);

    // Executes the First Pick allocation strategy
    //
    // names &names             - List of names
    // memory_list &allocMBList - List of currently allocated memory blocks
    // memory_list &freeMBList  - List of currently deallocated memory blocks
    void first_pick(names &names, memory_list &allocMBList, memory_list &freeMBList);

    // Executes the Best Pick allocation strategy
    //
    // names &names             - List of names
    // memory_list &allocMBList - List of currently allocated memory blocks
    // memory_list &freeMBList  - List of currently deallocated memory blocks
    void best_pick(names &names, memory_list &allocMBList, memory_list &freeMBList);

    // Executes the Worst Pick allocation strategy
    //
    // names &names             - List of names
    // memory_list &allocMBList - List of currently allocated memory blocks
    // memory_list &freeMBList  - List of currently deallocated memory blocks
    void worst_pick(names &names, memory_list &allocMBList, memory_list &freeMBList);

    // Creates a new memory block
    //
    // names &names             - List of names
    // memory_list &allocMBList - List of currently allocated memory blocks
    void newBlock(names &names, memory_list &allocMBList);

    // Allocates a memory block with a specified size
    //
    // memory_iter it           - Iterator of position of memory block
    // names &names             - List of names
    // memory_list &allocMBList - List of currently allocated memory blocks
    // memory_list &freeMBList  - List of currently deallocated memory blocks
    // size                     - Size of memory block to be allocated
    void allocateBlock(memory_iter it, names &names, memory_list &allocMBList, memory_list &freeMBList, int size);

    // Splits two memory blocks
    //
    // names &names             - List of names
    // memory_iter it           - Iterator of position of memory block
    // memory_list &freeMBList  - List of currently deallocated memory blocks
    void splitBlocks(memory_iter it, memory_list &freeMBList, int size);

    // Finds the largest sized deallocated memory block
    //
    // memory_list &freeMBList  - List of currently deallocated memory blocks
    int maxSize(memory_list &freeMBList);

};

#endif