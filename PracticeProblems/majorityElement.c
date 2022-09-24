

int majorityElement(int* nums, int numsSize){


    int sum = 1;
    int candidate = nums[0];
    for (int ii = 1; ii<numsSize; ii++)
    {//
        if (candidate==nums[ii])
        {
            sum+=1;
        }
        else
        {
            sum-=1;
        }

        if (sum<=0)
        {
            candidate = nums[ii];
            sum = 1;
        }
    }
    return candidate;
}
