#include <stdio.h>
#include <stdlib.h>

//TP4ex2

int main(int argc, char* argv[]) {
  int somme = 0;
  for(int i = 1; i < argc; ++i){
    somme = somme + atoi(argv[i]);
  }
  printf("somme: %d\n", somme);
  return 0;
}

