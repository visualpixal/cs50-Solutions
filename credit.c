#include <stdio.h>
#include <cs50.h>


long long creditCardNumber;
int numberLength;
//function to count the length of a long long
int countNumberLength();
int firstSum;
int secondSum;
int finalSum;


int main(void)
{
    //gets number and makes sure it isn't negative
     do
    {
        creditCardNumber = get_long_long("Credit Card Number Please:\n");
    }
    while(creditCardNumber <=0);

    //counts the number of digits
    numberLength = countNumberLength(creditCardNumber);

    //if number of digits is wrong, asks for the number again until it is within the correct range
    while(numberLength > 16 || numberLength < 13)
    {

        creditCardNumber = get_long_long("Credit Card Number is not a standard length. Please re-enter:\n");
        //recounts the length of the number
        numberLength = countNumberLength(creditCardNumber);
    }

    //creates and assigns values of card number to an array of the length of the card number
    int cardNumber[numberLength];
    for(int i = numberLength - 1; i >= 0; i--)
    {
        cardNumber[i] = creditCardNumber % 10;
        creditCardNumber = creditCardNumber/10;
    }

    printf("First set of numbers\n");
    //multiplies every other digit of the number by 2 and then adds all the sums DIGITS
    for(int i = 1; i <= numberLength - 1; i = i + 2)
    {
        printf("%i\n", cardNumber[i]);
        if((cardNumber[i] * 2) > 9)
        {
            firstSum = firstSum + 1 + ((cardNumber[i] * 2) % 10);
        }
        else
        firstSum = firstSum + cardNumber[i] * 2;
    }

    printf("firstSum: %i\n", firstSum);

    printf("Second set of numbers\n");
    //adds the first digit and every other digit after that for the second sum
    for(int i = 0; i <= numberLength - 1; i = i + 2)
    {
        printf("%i\n", cardNumber[i]);

        secondSum = secondSum + cardNumber[i];
    }

    //adds both of the sums together
    finalSum = firstSum + secondSum;

    //checks to see if the card is valid and what company it is from
    if(finalSum % 10 == 0)
    printf("Your Credit Card Number has the score %i and is %i numbers long and is a ", finalSum, numberLength);
    else
    printf("Your Credit Card Number has the score %i and is %i numbers long and is invalid\n", finalSum, numberLength);
    if(cardNumber[0] == 3 && cardNumber[1] == 4)
    printf("Visa\n");
    if(cardNumber[0] == 3 && cardNumber[1] == 7)
    printf("Visa\n");
}


//function to count the number of digits in a long long
int countNumberLength(long long n)
{
    if(n < 10) return 1;
    return 1 + countNumberLength(n / 10);
}
