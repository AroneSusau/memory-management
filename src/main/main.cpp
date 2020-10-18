// * * * * * * * * * * * * * * * * 
// 2020 Semester 2 - Assignemnt 2
// Author: Arone Susau
// Course: COSC1114 
// Student#: s3728977
// * * * * * * * * * * * * * * * *

#include "./../headers/main.h"

static strategies strat;

int main(int argc, char** argv) {

  char* path = argv[1];
  strat.type = argv[2];
  strat.max_names = stoi(argv[3]);

  names names = new char*[strat.max_names];
  memory_list allocMBList, freeMBList;

  readFile(path, names);
  run(names, allocMBList, freeMBList);
  writeAllocMBFile(path, argv[2], allocMBList);
  writeFreeMBFile(path, argv[2], freeMBList);
  writeHeaderFile(path, argv[2], strat.total_memory);
  writeCombinedFile(path, argv[2], freeMBList, allocMBList);

  for (auto mb: allocMBList) {
    free(mb);
  }

  for (auto mb: freeMBList) {
    free(mb);
  }

	return PROGRAM_SUCCESS;
}

void run(names &names, memory_list &allocMBList, memory_list &freeMBList) {

  while (strat.name_index != strat.max_names) {
    strat.allocate(names, allocMBList, freeMBList);
    removeRandomBlocks(allocMBList, freeMBList);
    freeMBList.sort();
    joinContiguousBlocks(freeMBList);
  }
}

void removeRandomBlocks(memory_list &allocMBList, memory_list &freeMBList) {
  for (auto i = 0; i < RANDOM_MAX; ++i) {
    int index = rand() % allocMBList.size();
    memory_iter it = allocMBList.begin();
    advance(it, index);
    freeMBList.push_back(*it);
    allocMBList.erase(it);
  }
}

void joinContiguousBlocks(memory_list &freeMBList) {  
  for (auto it = freeMBList.begin(); it != freeMBList.end(); ++it) {
    memory_block* current = *it;

    auto result = find_if(freeMBList.begin(), freeMBList.end(), [current](memory_block* mb)->bool {
      return current != mb && current == mb;
    });

    if (result != freeMBList.end()) {
      current->size += (*result)->size;
      freeMBList.erase(result);
    }
  }
}
