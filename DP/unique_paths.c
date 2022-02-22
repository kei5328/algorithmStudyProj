
int uniquePaths(int m, int n){

  int dp[m][n];
    int num_path;
    for (int ii=0;ii<m;ii++)
    {
        for (int jj=0;jj<n;jj++)
        {
            dp[ii][jj] = 0;
        }
    }
    num_path=find_num_paths(m, n, (int *) dp, n);
    return num_path;
}

int find_num_paths(int row, int col, int * dp[], int col_len)
{
    if (row==1 || col==1)
    {
        *(dp+row*col_len+col) = 1;
        return 1;
    }

    if ( *(dp+row*col_len+col)>0)
    {
        return  *(dp+row*col_len+col);
    }
    *(dp+row*col_len+col) = find_num_paths(row-1, col, dp, col_len) + find_num_paths(row, col-1, dp, col_len);
    return  *(dp+row*col_len+col);
}
