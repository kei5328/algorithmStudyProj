/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
	// when a number is doubled, all bits are shifted to the left by one
	// so, it's either the same or adding 1 for the half value.
	// corner cases
	/*
	1: n<0;
	*/
	if (n<0)
	{
		(*returnSize) = 0;
		return NULL;
	}

	int * val_cnt = (int*)malloc(sizeof(int)*(n+1));
	for (int ii = 0; ii<=n; ii++)
	{//
		if (ii==0)
			val_cnt[0] = 0;
		else if (ii==1)
			val_cnt[1] = 1;
		else
		{
			val_cnt[ii] = (ii%2)==0 ? val_cnt[ii/2] : val_cnt[ii/2]+1;
		}
	}
	(*returnSize) = (n+1);
	return val_cnt;
}
