#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int change;
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    int remaining;
    int total;

    // Get change
    do
    {
        change = get_int("Change owed: ");
    }
    while(change < 0);

    quarters = change/25;
    remaining = change - (25 * quarters);

    dimes = remaining/10;
    remaining = remaining - (10 * dimes);

    nickels = remaining/5;
    remaining = remaining - (5 * nickels);

    pennies = remaining/1;
    remaining = remaining - (1 * pennies);

    total = quarters + dimes + nickels + pennies;

    printf("%i\n", total);

}





