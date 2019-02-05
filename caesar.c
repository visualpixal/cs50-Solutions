#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//test edit
string secretMessage;
int code;

//another test edit

int main(int argc, string argv[])
{
    if(argc == 2)
    {
    code = atoi(argv[1]);
    printf("The code is %i\n", code);
    secretMessage = get_string("What is your secret message?");

     for (int i = 0, n = strlen(secretMessage); i < n; i++)
    {
        if(isalpha(secretMessage[i]))
        {
            if(isupper(secretMessage[i]))
            {
                printf("%c", (((secretMessage[i] + code) - 65) % 26) + 65);
            }
            if(islower(secretMessage[i]))
            {
                printf("%c", (((secretMessage[i] + code) - 97) % 26) + 97);
            }
        }
        else
        printf("%c", secretMessage[i]);
    }
    printf("\n");
    return 0;
    }
    else
    {
        printf("Please specify the code when running the program as a command line argument.\n");
        return 1;
    }
}
