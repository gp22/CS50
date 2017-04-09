
#include <stdio.h>

int main(void) {

  float change;
  int coins = 0;

  printf("O hai! How much change is owed?\n");
  scanf("%f", &change);

  while (change < 0) {
    printf("O hai! How much change is owed?\n");
    scanf("%f", &change);
  }

  if (change > 0.25) {
    int quarters = (change / 0.25);
    coins = quarters;
    change = change - (quarters * 0.25);
    printf("%i quarters\n", quarters);
  }

  if (change > 0.1) {
    int dimes = (change / 0.10);
    coins = coins + dimes;
    change = change - (dimes * 0.10);
    printf("%i dimes\n", dimes);
  }

  if (change > 0.05) {
    int nickels = (change / 0.05);
    coins = coins + nickels;
    change = change - (nickels * 0.05);
    printf("%i nickels\n", nickels);
  }

  if (change > 0) {
    int pennies = (change * 100);
    change = change - (pennies * 0.01);
    if (change > 0.009) {
      pennies = pennies + 1;
    }
    coins = coins + pennies;
    printf("%i pennies\n", pennies);
  }

  printf("%i total coins\n", coins);
}