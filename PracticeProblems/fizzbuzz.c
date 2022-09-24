

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int countDigits(int num)
{
    int result = 0;

    while(num>0)
    {
        num = num/10;
        result++;
    }
    return result;
}

char ** fizzBuzz(int n, int* returnSize){

    char ** result = (char**)malloc(sizeof(char*)*n);
    *returnSize = n;
    char* str = NULL;
    for (int ii = 1; ii<=n; ii++)
    {
        if (ii%3==0 && ii%5==0)
        {
            str = (char*)malloc(sizeof(char)*(8+1));
            str = "FizzBuzz";        }
        else if (ii%5==0)
        {
            str = (char*)malloc(sizeof(char)*(4+1));
            str = "Buzz";
        }
        else if (ii%3==0)
        {
            str = (char*)malloc(sizeof(char)*(4+1));
            str = "Fizz";
        }
        else
        {
            int digit = countDigits(ii);
            str = (char*)malloc(sizeof(char)*(digit+1));
            sprintf(str, "%d", ii);

        }
        result[ii-1] = str;
    }

    return result;
}
