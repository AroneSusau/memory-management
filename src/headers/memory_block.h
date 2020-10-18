// * * * * * * * * * * * * * * * * 
// 2020 Semester 2 - Assignemnt 2
// Author: Arone Susau
// Course: COSC1114 
// Student#: s3728977
// * * * * * * * * * * * * * * * *

#ifndef MEMORY_BLOCK
#define MEMORY_BLOCK

#include <string>

using namespace std;

typedef struct _memory_block {
  int size;
  void* address;
} memory_block;

bool operator< (const memory_block& a, const memory_block& b);
bool operator> (const memory_block& a, const memory_block& b);
bool operator== (const memory_block& a, const memory_block& b);
#endif