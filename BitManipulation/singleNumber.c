


int singleNumber(int* nums, int numsSize){

// idea: use xor to identify the single one(or odd one).

int xor_num=0;

for (int ii = 0; ii<numsSize; ii++)
{
    xor_num ^= nums[ii];
}

return xor_num;
}
