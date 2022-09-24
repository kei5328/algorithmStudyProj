class NumArray {
public:

    vector<int> num_vec;
    vector<int> cum_sum;

    NumArray(vector<int>& nums) {
        num_vec = nums;

        int sum = num_vec.at(0);
        cum_sum.push_back(sum);
        for (int ii = 1; ii<nums.size(); ii++)
        {
            sum += nums.at(ii);
            cum_sum.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        int res = 0;

        if (left==0)
        {
            res = cum_sum.at(right);
        }
        else
        {
            res = cum_sum.at(right)-cum_sum.at(left-1);
        }
        /*
        for (int ii = left; ii<=right; ii++)
        {
            res+=num_vec.at(ii);
        }
        */

        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
