// * * * * * * * * * * * * * * * * 
// 2020 Semester 2 - Assignemnt 2
// Author: Arone Susau
// Course: COSC1114 
// Student#: s3728977
// * * * * * * * * * * * * * * * *

#include "../headers/strategies.h"

void strategies::allocate(names &names, memory_list &allocMBList, memory_list &freeMBList) {
  if (type == FIRST) {
    first_pick(names, allocMBList, freeMBList);
  } else if (type == BEST) {
    best_pick(names, allocMBList, freeMBList);
  } else if (type == WORST) {
    worst_pick(names, allocMBList, freeMBList);
  }
}

void strategies::first_pick(names &names, memory_list &allocMBList, memory_list &freeMBList) {

  for (int i = 0; i < ALLOC_MAX && name_index != max_names; ++i) {
    
    // Find first matching memory_block size from freeMB
    int target = strlen(names[name_index]) + 1;
    auto it = find_if(freeMBList.begin(), freeMBList.end(), 
      [target] (memory_block* m)->bool { 
        return m->size >= target; 
      });

    // If match found, allocate the block otherwise create a new one
    it != freeMBList.end() ?
      allocateBlock(it, names, allocMBList, freeMBList, target) :
      newBlock(names, allocMBList);
  }
}

void strategies::best_pick(names &names, memory_list &allocMBList, memory_list &freeMBList) {
  
  for (int i = 0; i < ALLOC_MAX && name_index != max_names; ++i) {

    int limit = maxSize(freeMBList);
    int target = strlen(names[name_index]) + 1;
    auto match = false;

    // Select a desired size and increment if no match found
    for (int desired = target; desired <= limit && !match; ++desired) {

      // Find best matching memory_block size from freeMB
      auto it = find_if(freeMBList.begin(), freeMBList.end(), 
        [desired] (memory_block* m)->bool { 
          return m->size == desired; 
        });
      
      // If match found, allocate the block otherwise create a new one
      if (it != freeMBList.end()) {
        match = true;
        allocateBlock(it, names, allocMBList, freeMBList, target);
      }
    }

    if (!match) {
      newBlock(names, allocMBList);
    }
  }
}

void strategies::worst_pick(names &names, memory_list &allocMBList, memory_list &freeMBList) {
  for (int i = 0; i < ALLOC_MAX && name_index != max_names; ++i) {

    int limit = maxSize(freeMBList);
    int target = strlen(names[name_index]) + 1;

    // Find worst matching memory_block size from freeMB
    if (limit >= target) {
      
      auto it = find_if(freeMBList.begin(), freeMBList.end(), 
        [limit] (memory_block* m)->bool { 
          return m->size == limit; 
        });

      // If match found, allocate the block otherwise create a new one
      allocateBlock(it, names, allocMBList, freeMBList, target);
    } else {
      newBlock(names, allocMBList);
    }
  }
}

void strategies::newBlock(names &names, memory_list &allocMBList) {
  
  auto size = strlen(names[name_index]) + 1;
  void* address = sbrk(0);
  sbrk(size);
  strcpy((char*) address, names[name_index]);
  memory_block* m = (memory_block*) malloc(sizeof(memory_block));
  m->address = address;
  m->size = size;

  total_memory += size;
  
  allocMBList.push_back(m);
  name_index++;
}

void strategies::allocateBlock(memory_iter it, names &names, memory_list &allocMBList, memory_list &freeMBList, int size) {
  memory_block* mb = *it;
  strcpy((char*) mb->address, names[name_index]);
  
  // Split if memory block greater than name
  if (mb->size > size) {
    splitBlocks(it, freeMBList, size);
  }

  allocMBList.push_back(mb);
  freeMBList.erase(it);
  name_index++;
}

void strategies::splitBlocks(memory_iter it, memory_list &freeMBList, int size) {
  auto mb = *it;
  int remaining = mb->size - size;
  mb->size = size;
  
  memory_block* m = (memory_block*) malloc(sizeof(memory_block));
  m->address = (void*) ((intptr_t) mb->address + mb->size);
  m->size = remaining;
  freeMBList.push_back(m);
}

int strategies::maxSize(memory_list &freeMBList) {
  int max = 0;

  for (auto it = freeMBList.begin(); it != freeMBList.end(); ++it) {
    auto mb = *it;
    max = mb->size > max ? mb->size : max;
  }

  return max;
}
