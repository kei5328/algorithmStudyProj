class Solution {
public:

    // idea
        /*
        1. sort the input score vector, keep track of the indicies
        2. go thru the vector with loop, and output "gold medal", etc as the

    */
    vector<string> findRelativeRanks(vector<int>& score) {

        vector<string> result(score.size(), "");
        vector<int> sort_idx(score.size(), -1);

        for (int ii = 0; ii<score.size(); ii++)
        {
            sort_idx[ii] = ii;
        }

        // sort the array
        quicksort(score, sort_idx, 0, score.size()-1);

        for (int ii = 0; ii<sort_idx.size(); ii++)
        {
            if (ii==0)
                result[sort_idx[ii]] = "Gold Medal";
            else if (ii==1)
                result[sort_idx[ii]] = "Silver Medal";
            else if (ii==2)
                result[sort_idx[ii]] = "Bronze Medal";
            else
            {
                result[sort_idx[ii]] = to_string(ii);
            }
        }

        return result;
    }


private:
    void swap(vector<int> & A, int i, int j);
    void quicksort(vector<int> & A, vector<int> & sort_idx, int l, int m);
    int partition(vector<int> & A, vector<int> & sort_idx, int l, int m);
};

void Solution::swap(vector<int> & A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
}

void Solution::quicksort(vector<int> & A, vector<int> & sort_idx, int l, int m)
{
    if (l<m)
    {
        int n = partition(A, sort_idx, l, m);
        quicksort(A, sort_idx, l, n-1);
        quicksort(A, sort_idx, n+1, m);
    }
    return;
}

// sort with descending order(larger in the front. )
int Solution::partition(vector<int> & A, vector<int> & sort_idx, int l, int m)
{
    int ii = l;
    int jj = l-1;

    int pivot_val = A[m];

    for (;ii<m;ii++)
    {
        if (A[ii]>pivot_val)
        {
            jj++;
            swap(A, ii, jj);
            swap(sort_idx, ii, jj);
        }
    }
    jj++;
    swap(A, ii, jj);
    swap(sort_idx, ii, jj);
    return jj;
}
