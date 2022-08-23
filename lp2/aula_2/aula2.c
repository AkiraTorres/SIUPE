#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int magic_number() {
  int magic, guess;
  srand(time(0));
  magic = rand();
  printf("Adivinhe o número mágico: ");
  scanf("%d", &guess);

  if (guess == magic) {
    printf("** Certo **\n");
    printf("%d é o número mágico\n", magic);
  } else {
    printf("Errado, ");
    printf(guess > magic ? "muito alto!" : "muito baixo!");
  }

  printf("\nO número era %d.\n", magic);
}

int main() {
  // magic_number();

  return 0;
}