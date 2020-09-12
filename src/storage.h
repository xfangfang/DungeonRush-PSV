#ifndef SNAKE_STORAGE_H_
#define SNAKE_STORAGE_H_
#include "types.h"
#include <stdio.h>

#ifdef __vita__
  #define STORAGE_PATH "ux0:data/dungeonrush_storage.dat"
#else
  #define STORAGE_PATH "storage.dat"
#endif
#define STORAGE_RANKLIST_NUM 10

void updateLocalRanklist(Score*);
Score** insertScoreToRanklist(Score*, int*, Score**);
void destroyRanklist(int n, Score** scores);
void writeRanklist(const char*, int, Score**);
Score** readRanklist(const char* path, int* n);
#endif