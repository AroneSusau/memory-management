// * * * * * * * * * * * * * * * * 
// 2020 Semester 2 - Assignemnt 2
// Author: Arone Susau
// Course: COSC1114 
// Student#: s3728977
// * * * * * * * * * * * * * * * *

#include "../headers/memory_block.h"

bool operator< (const memory_block& a, const memory_block& b) {
    return (intptr_t) a.address < (intptr_t) b.address;
}

bool operator> (const memory_block& a, const memory_block& b) {
    return (intptr_t) a.address > (intptr_t) b.address;
} 

bool operator== (const memory_block& a, const memory_block& b) {
    return (intptr_t) a.address + a.size == (intptr_t) b.address;
} 