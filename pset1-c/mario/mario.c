#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // Prompt the user for the pyramid’s height
    do
    {
        height = get_int("Height: ");
    }
    while(height < 1);


    for (int row = height; row > 0 ; row--)
    {
        // Print spaces
        for (int spaces = row - 1; spaces > 0 ; spaces--)
        {
            printf(" ");
        }

        // Print bricks
        for (int bricks = row - 1; bricks < height; bricks++)
        {
            printf("#");
        }

        printf("\n");
    }
}
