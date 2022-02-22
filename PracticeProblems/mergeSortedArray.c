void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if (m==0)
    {
        memcpy(nums1, nums2, sizeof(int)*n);
        return;
    }

    int temp[m];
    memcpy(temp, nums1, sizeof(int)*m);

    int idx1 = 0; // index for nums1
    int idx2 = 0; // index for nums2
    int idx = 0;
    for (int idx=0; idx<nums1Size; idx++)
    {
        if (idx1<m && idx2<n)
        {// both arrays has not ended yet. We still need to compare
            if (temp[idx1]<nums2[idx2])
            {// use temp[idx1] value.
                nums1[idx] = temp[idx1];
                idx1++;
            }
            else
            {
                nums1[idx] = nums2[idx2];
                idx2++;
            }
        }
        else if (idx1<m)
        {// we still have the first
            nums1[idx] = temp[idx1];
            idx1++;
        }
        else
        {
            nums1[idx] = nums2[idx2];
            idx2++;
        }
    }
}
