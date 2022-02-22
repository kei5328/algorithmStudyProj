/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){

    *returnSize = rowIndex+1;


    int * result =  (int *) malloc(sizeof(int)*(rowIndex+1));

    if (rowIndex==0)
    {
        result[0] = 1;
        return result;
    }
    else if (rowIndex==1)
    {
        result[0]=1;
        result[1]=1;
        return result;
    }
    else
    {// row index more than 1
        int prev_temp[rowIndex+1]; // generate an array.
        int temp[rowIndex+1];
        prev_temp[0] = 1;
        prev_temp[1] = 1;
        for (int ii=2; ii<=rowIndex; ii++)
        {
            temp[0] = 1;
            temp[ii] = 1;
            for (int jj = 1; jj<=ii-1; jj++)
            {
                temp[jj] = prev_temp[jj-1] + prev_temp[jj];
            }
            memcpy(prev_temp, temp, sizeof(temp));
        }
        memcpy(result, temp, sizeof(temp));
    }
    return result;
}
