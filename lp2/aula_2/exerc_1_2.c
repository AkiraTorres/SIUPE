#include <stdio.h>

int main() {
  int i, moneys[6] = {50, 20, 10, 5, 1}, cents[6] = {50, 25, 10, 5, 1};
  double value;
  int notes = (int)value;
  int coins = (int)((value - notes) * 100) + 1;

  scanf("%lf", &value);

  printf("Valor lido: %.2lf %i %i\n", value, notes, coins);
  printf("Cédulas:\n");

  for (i = 0; i < 5; i++) {
    printf("%i de R$ %i.00\n", (notes / moneys[i]), moneys[i]);
    notes = notes % moneys[i];
  }

  printf("\nMoedas:\n");

  for (i = 0; i < 5; i++) {
    float coinPrint = ((float)cents[i]) / 100;
    printf("%i de R$ %.2f\n", (coins / cents[i]), coinPrint);
    coins = coins % cents[i];
  }

  return 0;
}