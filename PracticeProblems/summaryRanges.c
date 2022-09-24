/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int numDigits(int x)
{
    int result;
    if (x<0)
        result = 2;
    else
        result = 1;

    while (x/10!=0)
    {
        x=x/10;
        result++;
    }

    return result;
}

char * generateRangeStr(int init_val, int fin_val)
{
    char * range = NULL;
    if (init_val==fin_val)
    {// same value : so the range should be "init_val"
        int digits = numDigits(init_val);
        range = (char*)malloc(sizeof(char)*(digits+1)); // add 1 for \0;
        if (range==NULL) return NULL;
        snprintf(range, digits+1, "%d", init_val);
        range[digits] = '\0';
    }
    else // different value : so the range should be "init_val->fin_val"
    {
        int digit1 = numDigits(init_val);
        int digit2 = numDigits(fin_val);
        range = (char*)malloc(sizeof(char)*(digit1+digit2+2+1));// add 2 for -> and add 1 for \0;
        if (range==NULL) return NULL;
        snprintf(range, digit1+digit2+2+1, "%d->%d", init_val,fin_val);
        range[digit1+digit2+2] = '\0';
    }
    return range;
}
char ** summaryRanges(int* nums, int numsSize, int* returnSize){

    if (numsSize<=0)
    {
        *returnSize = 0;
        return NULL;
    }
    else if (numsSize==1)
    {
        char ** result = (char**)malloc(sizeof(char*));
        *(result) = generateRangeStr(nums[0], nums[0]);
        *returnSize = 1;
        return result;
    }
    // first count
    int init_val = nums[0];
    int prev_val = nums[0];
    int range_cnt = 0;
    int fin_val;
    for (int ii = 1; ii<numsSize; ii++)
    {
        // check for the overflow needed.
        // (nums[ii]-prev_val>INT_MAX) or (nums[ii]-prev_val<INT_MIN)
        int update = false;
        if (prev_val>0 && nums[ii]<INT_MIN+prev_val)
            update = true;
        else if (prev_val<0 && nums[ii]>INT_MAX+prev_val)
        {
            update = true;
        }
        else if (nums[ii]-prev_val>1)
            update = true;
        if (update)
        {
            fin_val = prev_val;
            // generate range.
            init_val = nums[ii];
            range_cnt++;
        }
        prev_val = nums[ii];
    }
    range_cnt++;

    // generate accordingly.
    char ** result = (char**)malloc(sizeof(char*)*range_cnt);
    if (result==NULL) return NULL;
    init_val = nums[0];
    prev_val = nums[0];
    range_cnt = 0;
    for (int ii = 1; ii<numsSize; ii++)
    {
        int update = false;
        if (prev_val>0 && nums[ii]<INT_MIN+prev_val)
            update = true;                 // overflow
        else if (prev_val<0 && nums[ii]>INT_MAX+prev_val)
            update = true;//overflow
        else if (nums[ii]-prev_val>1)
            update = true;
        if (update)
        {
            fin_val = prev_val;
            *(result+range_cnt) = generateRangeStr(init_val, fin_val);
            init_val = nums[ii];
            range_cnt++;
        }
        prev_val = nums[ii];
    }
    fin_val = prev_val;
    *(result+range_cnt) = generateRangeStr(init_val, fin_val);
    range_cnt++;
    *returnSize = range_cnt;
    return result;
}
