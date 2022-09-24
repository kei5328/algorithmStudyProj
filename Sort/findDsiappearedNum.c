class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector <int> res;

        if (nums.size()==1)
        quicksort(nums);
        // nums sorted

        for

        return res;
    }

    // sort algorithm(quick sort)
private:
    void swap(vector<int>&A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        return;
    }

    void quicksort(vector<int>&A)
    {
        partition(A, 0, A.size()-1);
    }

    void partition(vector<int>&A, int p, int q)
    {
        if (p>=q) return;
        int pivot_val = A[q];
        int i = p-1;
        for (int j = p; j<q; j++)
        {
            if (A[j]<=pivot_val)
            {
                i++;
                swap(A, i, j);
            }
        }
        i++;
        swap(A, i, q);

        partition(A, 0, i-1);
        partition(A, i+1, q);
        return;
    }
};




class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        quicksort(nums, 0, nums.size()-1);
        for (int ii = 0; ii<nums.size(); ii++)
        {
            cout<< nums[ii];
            cout<< ',';
        }
        cout << endl;

        return res;
    }

    // sort algorithm(quick sort)
private:
    void swap(vector<int>&A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        return;
    }

    void quicksort(vector<int>&A, int p, int q)
    {
        if (p>=q) return;
        int r = partition(A, p, q);
        quicksort(A, p, r-1);
        quicksort(A, r+1, q);
        return;
    }

    int partition(vector<int>&A, int p, int q)
    {
        cout<<p<<','<<q<<endl;
        int pivot_val = A[q];
        int i = p-1;
        for (int j = p; j<q; j++)
        {
            if (A[j]<=pivot_val)
            {
                i++;
                swap(A, i, j);
            }
        }
        i++;
        swap(A, i, q);

        return i;
    }
};
