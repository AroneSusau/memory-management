// * * * * * * * * * * * * * * * * 
// 2020 Semester 2 - Assignemnt 2
// Author: Arone Susau
// Course: COSC1114 
// Student#: s3728977
// * * * * * * * * * * * * * * * *

#include "./../headers/file_io.h"

void readFile(char* path, names &names) {
  char base[] ="./data/";
  char ext[] =".txt";
  
  stringstream dest;
  dest << base << path << ext;
  ifstream file(dest.str().c_str());  
  
  string line;
  int count = 0;
  
  while (getline(file, line)) {
    names[count] = new char[MAX_CHAR];
    strcpy(names[count], line.c_str());
    count++;
  }

  file.close();
}

void writeAllocMBFile(char* path, char* type, memory_list &results) {
  char base[] ="./results/";
  char ext[] =".csv";

  std::ofstream file;
  stringstream dest;
  dest << base << path << "/alloc-" << type << ext;
  file.open(dest.str());

  file << "address,size,contents"  << endl;

  for (auto mb : results) {
    file << mb->address << "," << mb->size << "," << (char *) mb->address << endl;
  }

  file.close();
}

void writeFreeMBFile(char* path, char* type, memory_list &results) {
  char base[] ="./results/";
  char ext[] =".csv";

  std::ofstream file;
  stringstream dest;
  dest << base << path << "/free-" << type << ext;
  file.open(dest.str());

  file << "address,size"  << endl;

  for (auto mb : results) {
    file << mb->address << "," << mb->size << endl;
  }

  file.close();
}

void writeHeaderFile(char* path, char* type, int total) {
  char dest[] ="./results/totals.csv";
  std::ofstream file;
  file.open(dest, ios_base::app);
  file << path << "," << type << "," << total << endl;
  file.close();
}

void writeCombinedFile(char* path, char* type, memory_list &freeMBList, memory_list &allocMBList) {
  char base[] ="./results/";

  std::ofstream file;
  stringstream dest;
  dest << base << "combined.csv";
  file.open(dest.str(), ios_base::app);

  for (auto mb : allocMBList) {
    file << path << "," << type << "," << "ALLOC" << "," <<  mb->address << "," << mb->size << "," << (char *) mb->address << endl;
  }

  for (auto mb : freeMBList) {
    file << path << "," << type << "," << "FREE" << "," << mb->address << "," << mb->size << "," << endl;
  }

  file.close();
}
