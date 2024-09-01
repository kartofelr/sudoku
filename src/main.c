#include "fun.h"
#include <stdio.h>

void printgrid(void) {
  // this assumes that the gridstring is 81 numbers
  char *emptySudoku = "/home/henry/dev/include/sudoku.txt";
  FILE *fp = fopen(emptySudoku, "r");

  if (fp == NULL) {
    printf("Error: could not open file %s\n", emptySudoku);
  }
  char ch;
  int i, j;
  for (i = 0; i < 11; i++) {
    if (i % 4 != 3) {
      for (j = 0; j < 17; j++) {
        if (j % 2 == 0) {
          ch = fgetc(fp);
          if (ch == '0') {
            printf(".");
          } else {
            putchar(ch);
          }
        } else if (j % 6 == 5) {
          printf("|");
        } else {
          printf(" ");
        }
      }
    } else {
      for (j = 0; j < 17; j++) {
        if (j % 6 == 5) {
          printf("+");
        } else {
          printf("-");
        }
      }
    }
    printf("\n");
  }
}

int main() {
  printgrid();
  return 0;
}