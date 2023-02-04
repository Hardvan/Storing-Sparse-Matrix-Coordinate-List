/*
? Problem Statement:
    * Implementation of Sparse Matrix Storage using Coordinate List in C

? Sparse Matrix:
    * A matrix in which most of the elements are zero.

? Advantage of Sparse Matrix over Simple Matrix:
    ? Storage:
        * There are lesser non-zero elements than zeros,
        * Thus lesser memory can be used to store only those elements.
    ? Computation Time:
        * Computing time can be saved by
        * designing a data structure traversing only non-zero elements.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to store coordinates & value of non-zero elements
struct coordinate
{
    int x;
    int y;
    int val;
};

// Structure to store sparse matrix
struct sparse
{
    int row;
    int col;
    int no_terms;
    struct coordinate *terms;
};

int main()
{
    int i, j;                   // Loop variables
    struct sparse sparseMatrix; // Sparse matrix

    // ? 1) Get the dimensions of the sparse matrix
    printf("Enter the dimensions of the sparse matrix: ");
    scanf("%d %d", &sparseMatrix.row, &sparseMatrix.col);

    // ? 2) Get the number of non-zero elements
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &sparseMatrix.no_terms);

    // ? 3) Dynamically allocate memory for the sparse matrix
    sparseMatrix.terms = (struct coordinate *)malloc(sparseMatrix.no_terms *
                                                     sizeof(struct coordinate));

    // ? 4) Check if memory allocation was successful
    if (sparseMatrix.terms == NULL)
    {
        printf("Error: Failed to allocate memory for matrix\n");
        exit(0);
    }

    // ? 5) Get the non-zero elements
    printf("Enter the non-zero elements (x, y, val):\n");
    for (i = 0; i < sparseMatrix.no_terms; i++)
    {
        // x, y, val
        scanf("%d %d %d",
              &sparseMatrix.terms[i].x,
              &sparseMatrix.terms[i].y,
              &sparseMatrix.terms[i].val);
    }

    // ? 6) Print the sparse matrix
    printf("\nThe sparse matrix:\n");
    for (i = 0; i < sparseMatrix.row; i++) // Loop through the rows
    {
        for (j = 0; j < sparseMatrix.col; j++) // Loop through the columns
        {
            int x = i,
                y = j,
                val = 0;

            for (int k = 0; k < sparseMatrix.no_terms; k++) // Loop through the non-zero elements
            {
                // If the current element is the one we are looking for
                // kth term matches the current element
                if (sparseMatrix.terms[k].x == x &&
                    sparseMatrix.terms[k].y == y)
                {
                    val = sparseMatrix.terms[k].val;
                    break;
                }
            }

            printf("%d ", val);
        }

        printf("\n");
    }
    printf("\n");

    // ? 7) Display no. of non-zero & zero elements
    int non_zero = sparseMatrix.no_terms;
    int zero = sparseMatrix.row * sparseMatrix.col - sparseMatrix.no_terms;

    printf("No. of non-zero elements: %d\n", non_zero);
    printf("No. of zero elements: %d\n", zero);

    free(sparseMatrix.terms); // Free the allocated memory

    return 0;
}

/*
? Sample I/O:

    Enter the dimensions of the sparse matrix : 3 3
    Enter the number of non-zero elements : 3
    Enter the non-zero elements :
    0 0 1
    1 1 2
    2 2 3
    The sparse matrix:
    1 0 0
    0 2 0
    0 0 3

*/
