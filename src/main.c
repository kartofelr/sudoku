#include "fun.h"
#include <stdio.h>

void printgrid(void) {
  // this assumes that the sudoko is 81 numbers
  int nb_lines = 9;
  int nb_columns = 9;
  int box_size = 3;
  // int grid_size = nb_columns * nb_lines;

  // let's open the sudoku.txt file on read mode
  char *emptySudoku = "/home/henry/dev/include/sudoku.txt";
  FILE *fp = fopen(emptySudoku, "r");

  // the following line simply checks that the file actually was found and
  // opened
  if (fp == NULL) {
    printf("Error: could not open file %s\n", emptySudoku);
  }

  char ch;       // will hold the number values as they are being read
  int line, col; // loop indices for line and column placement

  for (line = 0; line < nb_lines; line++) {
    if (line % box_size == 0) {
      // the next part is the line between box groups
      printf(" +-------+-------+-------+\n");
    }
    for (col = 0; col < nb_columns; col++) {
      /*here we grab the next number and if it is null replace it with a "."
      for readability */
      if ((ch = fgetc(fp)) == 0) {
        ch = '.';
      }
      // this check looks if the number is right of a line
      if (col % box_size == 0) {
        printf(" | %c", ch);
      } else {
        printf(" %c", ch);
      }
    }
    printf(" |\n");
  }
  printf(" +-------+-------+-------+\n");
}

int main() {
  printgrid();
  return 0;
}