#include <stdio.h>
#include <cs50.h>

float change;
int coins = 0;
int quarters = 0;
int dimes = 0;
int nickels = 0;
int pennies = 0;

int main(void)
{
    do
    {
        change = get_float("What is the change?\n");
    }
    while(change <=0);

    int remaining;

    remaining = change % 10;

    printf("Your change is %f\n", change);
    printf("remainder is %i\n", remaining);

    while(change >= .009)
        {
            if (change >=.25)
            {
                change = change - .25;
                quarters++;
                coins++;
            }
            else if (change >= .0910000)
            {
                change = change - .10;
                dimes++;
                coins++;
            }
            else if (change >= .0491000)
            {
                change = change -.05;
                nickels++;
                coins++;
            }
            else if (change >= .0091000)
            {
                printf("%f remaining money.\n", change);
                change = change - .01;
                pennies++;
                coins++;
            }

        }
    printf("%i number of coins.\n", coins);
    printf("%i quarters.\n", quarters);
    printf("%i dimes.\n", dimes);
    printf("%i nickels.\n", nickels);
    printf("%i pennies.\n", pennies);
    printf("%f remaining money.\n", change);

}
