#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
int checkMatrix(int A[3][3])
{
   //Storing sum of first row in val, and comparing it with all the other values
    int val = 0,tempVal = 0;
    //Checking first row
    for (int i = 0; i < 3; i++)
    {
        val = val + A[0][i];
    }

    //Checking 2nd and 3rd row
    for (int i = 1; i < 3; i++)
    {
        tempVal = 0;
        for (int j = 0; j < 3; j++)
        {
            tempVal = tempVal + A[i][j];
        }
        if (tempVal != val)
        {
            return 0;
        }  
    }
    //Checking all columns
    for (int i = 0; i < 3; i++)
    {
        // reset tempVal
        tempVal = 0;
        for (int j = 0; j < 3; j++)
        {
            tempVal = tempVal + A[j][i];
        }
        if (tempVal != val)
        {
            return 0;
        }  
    }

    //Cheking diagonals

    tempVal = 0;
    for (int i = 0; i < 3; i++)
    {
        tempVal = tempVal + A[i][i];
    }
     if (tempVal != val)
    {
        return 0;
    }

    tempVal = A[0][2] + A[1][1] + A[2][0];    
     if (tempVal != val)
    {
        return 0;
    }

    return 1;
}
int main() {
	int A[3][3];
	int row, column;
	int size, option;
	int i, j;
	int magic = 0;
    printf("Lo Shu Magic Square!\n");
    // give user two option for choosing the type of check for magic square
	printf("If you want to check the magic square with user input, choose 1\nIf you want to check with random number, choose 2\n");
    scanf("%d", &option);
    printf("Enter the order of the matrix:\n");
    scanf("%d %d", &row, &column);
    if(option == 1){
        // check for the magic square
        if(row==column) {
            printf("Enter the elements of matrix \n");
            for(i=0; i<row; i++) {
                for(j=0; j<column; j++) {
                    scanf("%d", &A[i][j]);
                }
            }
            
            printf("\n\nMATRIX  is\n");
            for(i=0; i<row; i++) {
                for(j=0; j<column; j++) {
                    printf("%3d\t", A[i][j]);
                }
                printf("\n");
            }
            
            if(checkMatrix(A) == 1)
                printf("\nGiven matrix is a magic square matrix");
            else 
                printf("\nGiven matrix is not a magic square");
        } 
        else {
            printf("\n\nPlease enter the square matrix order(m=n) \n\n");
        }
    }
    // the matrix is randomly created and check how many times creating of square, we have a magic square
    else if(option == 2){
        //TODO
        int count = 0; //Count of squares that are generated
        while (1)
        {        
            count++;
            int used[10] = {0};
            srand(time(0)+count); // Changing seed , so that we get new values each time
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    int n = rand()%9 + 1;
                    while (used[n])
                    {
                        n = rand()%9 + 1;
                    }
                    A[i][j] = n;
                    used[n] = 1;
                }
            }
            //Breaks the loop if a magic square is found
            if(checkMatrix(A) == 1){
                break;
            }
            
        }
        // print the number of created square
        printf("No. of squares generated : %d \n",count);
        // print the matrix
        printf("\n\nMATRIX  is\n");
            for(i=0; i<row; i++) {
                for(j=0; j<column; j++) {
                    printf("%3d\t", A[i][j]);
                }
                printf("\n");
            }

        }
    return 0;
}

