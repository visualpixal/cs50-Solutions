#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string hash;


int main(int argc, string argv[])
{

    if(argc != 2)
    {
        printf("Please enter the hash as a command line argument.\n");
    }

    else
    {
        hash = argv[1];
        //printf("The crypt of %s with the salt of 50 is %s\n", hash, crypt("crush", "50"));
        //run a crypt on a random word, see what the hash is and compare it to the real hash

        char key[5];
        for(int i = 0; i < 58; i++)
        {
            for(int j = 0; j < 58; j++)
            {
                for(int k = 0; k < 58; k++)
                {
                    for(int l = 0; l < 58; l++)
                    {
                        key[0] = 65 + i;
                        key[1] = 65 + j;
                        key[2] = 65 + k;
                        key[3] = 65 + l;

                        if (strcmp(crypt(key, "50"), hash) == 0)
                        {
                            printf("%s\n", key);
                            return 0;
                        }
                    }
                }
            }
        }

        char keyTwo[4];

        for(int j = 0; j < 58; j++)
            {
                for(int k = 0; k < 58; k++)
                {
                    for(int l = 0; l < 58; l++)
                    {

                        keyTwo[0] = 65 + j;
                        keyTwo[1] = 65 + k;
                        keyTwo[2] = 65 + l;

                        if (strcmp(crypt(keyTwo, "50"), hash) == 0)
                        {
                            printf("%s\n", keyTwo);
                            return 0;
                        }
                    }
                }
            }

            char keyThree[4];

            for(int k = 0; k < 58; k++)
                {
                    for(int l = 0; l < 58; l++)
                    {


                        keyThree[0] = 65 + k;
                        keyThree[1] = 65 + l;

                        if (strcmp(crypt(keyThree, "50"), hash) == 0)
                        {
                            printf("%s\n", keyThree);
                            return 0;
                        }
                    }
                }


    }




}
