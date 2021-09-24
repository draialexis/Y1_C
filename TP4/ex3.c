#include <stdio.h>

#define C 5

int maxTab2D(int tab[][C],  int l){

  int firstLoop = 1;
  int max;

  for(int i = 0; i < l; ++i){
    for(int j = 0; j < C; ++j){
      if(firstLoop){
        max = tab[i][j];
        firstLoop = 0;
      } else if (max < tab[i][j]){
        max = tab[i][j];
      }
    }
  }
  return max;
}

int main() {
  int tab1[][C] = {
    {3, 8, 65, 45, 12},
    {12, 63, 456, 32, 189},
    {189, 89, 123, 67, 15},
    {45, 489, 234, 16, 34}
  };

int tab2[][C] = {
    {3, 8, 65, 45, 12},
    {12, 63, 456, 32, 189},
    {189, 89, 123, 67, 15},
    {45, 389, 234, 16, 34}
  };

int tab3[][C] = {
    {3, 8, 65, 45, 12},
    {12, 63, 56, 32, 188},
    {189, 89, 123, 67, 15},
    {45, 89, 234, 16, 34}
  };

  printf("max1: %d\n", maxTab2D(tab1, 4)); // should return 489
  printf("max2: %d\n", maxTab2D(tab2, 4)); // should return 456
  printf("max3: %d\n", maxTab2D(tab3, 4)); // should return 234
  return 0;
}
