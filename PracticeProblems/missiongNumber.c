

int missingNumber(int* nums, int numsSize){
    // no overflow guaranteeed due to the limitation of the numsSize
    uint32_t exp_sum = (numsSize)*(numsSize+1);
    uint32_t real_sum = 0;
    for (int ii = 0; ii<numsSize; ii++)
    {
        real_sum+=nums[ii];
    }

    return exp_sum-real_sum;
}
