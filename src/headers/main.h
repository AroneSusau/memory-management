// * * * * * * * * * * * * * * * * 
// 2020 Semester 2 - Assignemnt 2
// Author: Arone Susau
// Course: COSC1114 
// Student#: s3728977
// * * * * * * * * * * * * * * * *

#ifndef MAIN_PROGRAM
#define MAIN_PROGRAM

#include "./types.h"
#include "./strategies.h"
#include "./memory_block.h"
#include "./file_io.h"

#define PROGRAM_SUCCESS 0
#define RANDOM_MAX 500

// Executes the allocation algorithm
//
// names &names                     - List of names
// memory_list &allocMBList - List of currently allocated memory blocks
// memory_list &freeMBList  - List of currently deallocated memory blocks
void run(names &names, memory_list &allocMBList, memory_list &freeMBList);

// Randomly deallocates a number of memory blocks.
//
// memory_list &allocMBList - List of currently allocated memory blocks
// memory_list &freeMBList  - List of currently deallocated memory blocks
void removeRandomBlocks(memory_list &allocMBList, memory_list &freeMBList);

// Searches for and joins memory blocks with contiguous starting
// and ending positions.
//
// memory_list &freeMBList  - List of currently deallocated memory blocks
void joinContiguousBlocks(memory_list &freeMBList);

#endif