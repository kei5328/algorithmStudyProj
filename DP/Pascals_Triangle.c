

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows; // return array of arrays have the same length as returnSize

    // generate the result array
    int ** result = (int **)malloc(sizeof(int*)*numRows);
    (*returnColumnSizes) = (int *)malloc(sizeof(int)*numRows); // assign the return column size.

    for (int ii = 0; ii<numRows; ii++)
    {

        *(*returnColumnSizes+ii) = ii+1; // return column sizes is the same as the ii+1;
        *(result+ii) = (int *)malloc(sizeof(int)*(ii+1)); // assign the array to be contained by result.
        for (int jj = 0; jj<=ii; jj++)
        {
            if (jj>0 && jj<ii)
            {// middle columns
                (*(*(result+ii)+jj)) = *(*(result+ii-1)+jj-1) + *(*(result+ii-1)+jj);
            }
            else
            {// both sides of the triangle: 1
                *(*(result+ii)+jj) = 1;
            }
        }
    }
    return result;
}
