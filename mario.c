#include <stdio.h>
#include <cs50.h>

int get_height();
int height;

int main(void)
{
   height = get_height();


   for(int i=0; i < height; i ++)
   {
       for(int s = i; s < height - 1; s++)
       {
           printf(" ");
       }

       for(int h = 0; h <= i; h++)
       {
           printf("#");
       }

       printf("  ");

       for(int h = 0; h<= i; h++)
       {
           printf("#");
       }

       printf("\n");
   }
}

int get_height()
{
    int i;
    do
    {
        i = get_int("Height: ");
        if (i <= 0 || i > 23)
        {
            printf("The height needs to be between 1 and 23 \n");
        }
    }
    while (i <= 0 || i > 23);
    return i;

}
