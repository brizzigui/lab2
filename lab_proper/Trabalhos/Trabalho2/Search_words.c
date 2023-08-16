#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct positions
{
    int x_init;
    int y_init;
    int x_end;
    int y_end;
};

char* get_word(int m, int n)
{
    int max_dimension;
    if (m >= n)
    {
        max_dimension = m;
    }

    else
    {
        max_dimension = n;
    }
    
    char* requested_word = (char*) malloc((max_dimension+1) * sizeof(char));
    printf("Insert the word you want to search for: ");
    scanf("%s", requested_word);

    return requested_word;
}

bool find_horizontal_direct(int m, int n, char* requested_word, char** mat, struct positions* placement)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= n-strlen(requested_word); j++)
        {
            int count = 0;
            for (int k = j; k-j < strlen(requested_word); k++)
            {
                if(mat[i][k] == requested_word[k-j])
                {
                    count++;
                    if (count == 1)
                    {
                        placement->x_init = i;
                        placement->y_init = k;
                    }

                    if (count == strlen(requested_word))
                    {
                        placement->x_end = i;
                        placement->y_end = k;
                        return true;
                    }
                    
                }
            }     
        }        
    }

    return false;
}

bool find_horizontal_reverse(int m, int n, char* requested_word, char** mat, struct positions* placement)
{
    strrev(requested_word);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= n-strlen(requested_word); j++)
        {
            int count = 0;
            for (int k = j; k-j < strlen(requested_word); k++)
            {
                if(mat[i][k] == requested_word[k-j])
                {
                    count++;
                    if (count == 1)
                    {
                        placement->x_init = i;
                        placement->y_init = k;
                    }

                    if (count == strlen(requested_word))
                    {
                        placement->x_end = i;
                        placement->y_end = k;
                        return true;
                    }
                }
            }     

            if(count == strlen(requested_word))
            {
                strrev(requested_word);
                return true;
            }
        }
    }
    
    strrev(requested_word);     
    return false;
}

bool find_vertical_direct(int m, int n, char* requested_word, char** mat, struct positions* placement)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= m-strlen(requested_word); i++)
        {
            int count = 0;
            for (int k = i; k-i < strlen(requested_word); k++)
            {
                if(mat[k][j] == requested_word[k-i])
                {
                    count++;
                    if (count == 1)
                    {
                        placement->x_init = k;
                        placement->y_init = j;
                    }

                    if (count == strlen(requested_word))
                    {
                        placement->x_end = k;
                        placement->y_end = j;
                        return true;
                    }
                }
            }     

            if(count == strlen(requested_word))
            {
                return true;
            }
        }        
    }

    return false;
}

bool find_vertical_reverse(int m, int n, char* requested_word, char** mat, struct positions* placement)
{
    strrev(requested_word);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= m-strlen(requested_word); i++)
        {
            int count = 0;
            for (int k = i; k-i < strlen(requested_word); k++)
            {
                if(mat[k][j] == requested_word[k-i])
                {
                    count++;
                    if (count == 1)
                    {
                        placement->x_init = k;
                        placement->y_init = j;
                    }

                    if (count == strlen(requested_word))
                    {
                        placement->x_end = k;
                        placement->y_end = j;
                        return true;
                    }
                }
            }     

            if(count == strlen(requested_word))
            {
                strrev(requested_word);
                return true;
            }
        }        
        
    }
    strrev(requested_word);
    return false;
}

bool find_primary_diagonal_direct(int m, int n, char* requested_word, char** mat, struct positions* placement)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            int count = 0;
            for (int x = i, y = j; x < m && y < n && x-i < strlen(requested_word) && y-j < strlen(requested_word); x++, y++)
            {
                if(mat[x][y] == requested_word[x-i])
                {
                    count++;
                    if (count == 1)
                    {
                        placement->x_init = x;
                        placement->y_init = y;
                    }

                    if (count == strlen(requested_word))
                    {
                        placement->x_end = x;
                        placement->y_end = y;
                        return true;
                    }
                }
            }

            if(count == strlen(requested_word))
            {
                return true;
            }
        }
    }

    return false;    
}

bool find_primary_diagonal_reverse(int m, int n, char* requested_word, char** mat, struct positions* placement)
{
    strrev(requested_word);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            int count = 0;
            for (int x = i, y = j; x < m && y < n && x-i < strlen(requested_word) && y-j < strlen(requested_word); x++, y++)
            {
                if(mat[x][y] == requested_word[x-i])
                {
                    count++;
                    if (count == 1)
                    {
                        placement->x_init = x;
                        placement->y_init = y;
                    }

                    if (count == strlen(requested_word))
                    {
                        placement->x_end = x;
                        placement->y_end = y;
                        return true;
                    }
                }

            }

            if(count == strlen(requested_word))
            {
                strrev(requested_word);
                return true;
            }
        }
    }

    strrev(requested_word);
    return false;
}

bool find_secondary_diagonal_direct(int m, int n, char* requested_word, char** mat, struct positions* placement)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            int count = 0;
            for (int x = i, y = j; x < m && y >= 0 && x-i < strlen(requested_word) && j-y < strlen(requested_word); x++, y--)
            {
                if(mat[x][y] == requested_word[x-i])
                {
                    count++;
                    if (count == 1)
                    {
                        placement->x_init = x;
                        placement->y_init = y;
                    }

                    if (count == strlen(requested_word))
                    {
                        placement->x_end = x;
                        placement->y_end = y;
                        return true;
                    }
                }
            }

            if(count == strlen(requested_word))
            {
                return true;
            }
        }
    }

    return false;  
}

bool find_secondary_diagonal_reverse(int m, int n, char* requested_word, char** mat, struct positions* placement)
{
    strrev(requested_word);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            int count = 0;
            for (int x = i, y = j; x < m && y >= 0 && x-i < strlen(requested_word) && j-y < strlen(requested_word); x++, y--)
            {
                if(mat[x][y] == requested_word[x-i])
                {
                    count++;
                    if (count == 1)
                    {
                        placement->x_init = x;
                        placement->y_init = y;
                    }

                    if (count == strlen(requested_word))
                    {
                        placement->x_end = x;
                        placement->y_end = y;
                        return true;
                    }
                }
            }

            if(count == strlen(requested_word))
            {
                strrev(requested_word);
                return true;
            }
        }
    }

    strrev(requested_word);
    return false;  
}


char find_word(int m, int n, char* requested_word, char** mat)
{
    char *found_word;
    struct positions placement;

    printf("\n");

    if(find_horizontal_direct(m, n, requested_word, mat, &placement))
    {
        printf("Found in Direct Horizontal\n");
        printf("Word starts at (%d, %d) and ends at (%d, %d)\n", placement.x_init+1, placement.y_init+1, placement.x_end+1, placement.y_end+1);
    }

    else if(find_horizontal_reverse(m, n, requested_word, mat, &placement))
    {
        printf("Found in Reversed Horizontal\n");
        printf("Word starts at (%d, %d) and ends at (%d, %d)\n", placement.x_init+1, placement.y_init+1, placement.x_end+1, placement.y_end+1);
    }

    else if(find_vertical_direct(m, n, requested_word, mat, &placement))
    {
        printf("Found in Direct Vertical\n");
        printf("Word starts at (%d, %d) and ends at (%d, %d)\n", placement.x_init+1, placement.y_init+1, placement.x_end+1, placement.y_end+1);
    }

    else if(find_vertical_reverse(m, n, requested_word, mat, &placement))
    {
        printf("Found in Reversed Vertical\n");
        printf("Word starts at (%d, %d) and ends at (%d, %d)\n", placement.x_init+1, placement.y_init+1, placement.x_end+1, placement.y_end+1);
    }

    else if(find_primary_diagonal_direct(m, n, requested_word, mat, &placement))
    {
        printf("Found in Primary Direct Diagonal\n");
        printf("Word starts at (%d, %d) and ends at (%d, %d)\n", placement.x_init+1, placement.y_init+1, placement.x_end+1, placement.y_end+1);
    }

    else if(find_primary_diagonal_reverse(m, n, requested_word, mat, &placement))
    {
        printf("Found in Primary Reverse Diagonal\n");
        printf("Word starts at (%d, %d) and ends at (%d, %d)\n", placement.x_init+1, placement.y_init+1, placement.x_end+1, placement.y_end+1);
    }

    else if(find_secondary_diagonal_direct(m, n, requested_word, mat, &placement))
    {
        printf("Found in Secondary Direct Diagonal\n");
        printf("Word starts at (%d, %d) and ends at (%d, %d)\n", placement.x_init+1, placement.y_init+1, placement.x_end+1, placement.y_end+1);
    }

    else if(find_secondary_diagonal_reverse(m, n, requested_word, mat, &placement))
    {
        printf("Found in Secondary Reverse Diagonal\n");
        printf("Word starts at (%d, %d) and ends at (%d, %d)\n", placement.x_init+1, placement.y_init+1, placement.x_end+1, placement.y_end+1);
    }

    else
    {
        printf("I'm so sorry, comrade! :( \n");
        printf("I couldn't find the word you're looking for...\n");
        printf("Please, don't rat out my wrongdoing to the chairman!\n");
    }

}
