// * * * * * * * * * * * * * * * * 
// 2020 Semester 2 - Assignemnt 2
// Author: Arone Susau
// Course: COSC1114 
// Student#: s3728977
// * * * * * * * * * * * * * * * *

#ifndef FILE_IO
#define FILE_IO

#include <unistd.h>
#include <cstdlib>
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>

#include "memory_block.h"
#include "types.h"

using namespace std;

// Reads in contents of a file line by line, 
// and assigns is value into the provided array.
//
// char* path   - Path to file
// names &names - List to store names
void readFile(char* path, names &names);

// Writes contents of AllocMBList to file.
//
// char* path           - Path to file
// char* type           - Allocator type
// memory_list &results - List of stored memory_blocks
void writeAllocMBFile(char* path, char* type, memory_list &results);

// Writes contents of freeMBList to file.
//
// char* path           - Path to file
// char* type           - Allocator type
// memory_list &results - List of stored memory_blocks
void writeFreeMBFile(char* path, char* type, memory_list &results);

// Writes total memory usage information to file.
//
// char* path - Path to file
// char* type - Allocator type
// int total  - Total memory usage
void writeHeaderFile(char* path, char* type, int total);

// Writes total memory usage information to file.
//
// char* path               - Path to file
// char* type               - Allocator type
// memory_list &freeMBList  - List of free memory_blocks
// memory_list &allocMBList - List of allocated memory_blocks
void writeCombinedFile(char* path, char* type, memory_list &freeMBList, memory_list &allocMBList);

#endif