

void moveZeroes(int* nums, int numsSize){
    int idx1 = 0;
    int idx2 = 1;
    while (idx2<numsSize)
    {
        if (nums[idx1]!=0)
        {
            idx1++;
            idx2++;
        }
        else
        {// idx1 has 0
            if (nums[idx2]!=0)
            {
                // swap the value of idx1(zero) and idx2(non-zero)
                int temp = nums[idx1];
                nums[idx1] = nums[idx2];
                nums[idx2] = temp;

                idx1++;
                idx2++;
            }
            else
            {// both idx1 and idx2 have 0. Continue increase idx2 until finding non-zero or reaching end/
                idx2++;
            }
        }

    }
    return;
}
