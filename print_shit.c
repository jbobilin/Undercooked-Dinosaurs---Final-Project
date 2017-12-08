#include <stdio.h>
#include "main_global.h"
void print_shit(void)
{
        int row, col;
         printf("Coordinate Map\n");
                for (row = 0; row < 8; row++)
                {
                        for (col = 0; col < 10; col++)
                        {
                                printf("%d , %d", row,col);
                                printf("\t");
                        }
                        printf("\n");
                }

                printf("Timmy Level\n");
                for (row = 0; row < 8; row++)
                {
                        for (col = 0; col < 10; col++)
                        {
                                printf("%d", timmy_level[row][col]);
                                printf("\t");
                        }
                        printf("\n");
                }

                printf("Display Level\n");
                for (row = 0; row < 8; row++)
                {
                        for (col = 0; col < 10; col++)
                        {
                                printf("%d", display_level[row][col]);
                                printf("\t");
                        }
                        printf("\n");
                }

                printf("Mine Level\n");
                for (row = 0; row < 8; row++)
                {
                        for (col = 0; col < 10; col++)
                        {
                                printf("%d", mine_level[row][col]);
                                printf("\t");
                        }
                        printf("\n");
                }

                printf("Timmy's Location:\t");
                printf("(%d, %d)\n", timmys_location[0], timmys_location[1]);
}
