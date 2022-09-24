
int thirdMax(int* nums, int numsSize){
    long max1=LONG_MIN, max2=LONG_MIN, max3 = LONG_MIN;
    int update_cnt = 0;
    for (int ii = 0; ii<numsSize; ii++)
    {
        if (nums[ii]>max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[ii];
            update_cnt++;
        }
        else if (nums[ii]>max2 && nums[ii]<max1)
        {
            max3 = max2;
            max2 = nums[ii];
            update_cnt++;
        }
        else if (nums[ii]>max3 && nums[ii]<max2)
        {
            max3 = nums[ii];
            update_cnt++;
        }
    }
    if (update_cnt<=2)
        return max1;
    else
        return max3;
}
