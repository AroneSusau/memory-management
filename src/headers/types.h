// * * * * * * * * * * * * * * * * 
// 2020 Semester 2 - Assignemnt 2
// Author: Arone Susau
// Course: COSC1114 
// Student#: s3728977
// * * * * * * * * * * * * * * * *

#ifndef TYPES
#define TYPES 

#include <list>

#include "memory_block.h"

#define MAX_CHAR 50
#define MAX_NAMES 4945

using names = char**;
using memory_list = list<memory_block*>;
using memory_iter = list<memory_block*>::iterator;

#endif