#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



string secretMessage;
string wordKey;




int main(int argc, string argv[])
{
    if(argc == 2)
    {
    wordKey = argv[1];
    printf("The wordKey is %s.\n", wordKey);

    for(int i = 0, n = strlen(wordKey); i < n; i++)
    {
        if(!isalpha(wordKey[i]))
        {
            printf("Sorry, but your keyword has to be all letters.\n");
            return 1;
        }
    }
    secretMessage = get_string("What is your secret message?\n");

    for (int i = 0, n = strlen(secretMessage), m = strlen(wordKey); i < n; i++)
    {


        //printf("The current key is %i\n", wordKey[i % m]);
        if(isalpha(secretMessage[i]))
        {
            if(isupper(secretMessage[i]))
            {
                if(isupper(wordKey[i % m]))
                {
                    printf("%c", (((secretMessage[i] + wordKey[i % m] ) - 130) % 26) + 65);
                }
                else if(islower(wordKey[i % m]))
                {
                    printf("%c", (((secretMessage[i] + wordKey[i % m] ) - 162) % 26) + 65);
                }
            }
            else if(islower(secretMessage[i]))
            {
                 if(isupper(wordKey[i % m]))
                {
                    printf("%c", (((secretMessage[i] + wordKey[i % m] ) - 162) % 26) + 97);
                }
                else if(islower(wordKey[i % m]))
                {
                    printf("%c", (((secretMessage[i] + wordKey[i % m] ) - 194) % 26) + 97);
                }
            }
        }
        else
        {
            printf("%c", secretMessage[i]);

        }
    }
    printf("\n");
    return 0;
    }
    else
    {
        printf("Please specify the wordKey of only letters when running the program as a command line argument.\n");
        return 1;
    }
}
