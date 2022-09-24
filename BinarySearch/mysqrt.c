int mySqrt(int x){
// idea: use simple binary search
    return sqrtByBinarySearch(x, 0, x);
}


int sqrtByBinarySearch(int x, int start, int fin)
{

    int result = -1;
    if (start>=fin)
    {
        if (start*start>x)
            return start-1;
        else
            return start;
    }
    int mid_num = (start+fin)/2;
    if (mid_num>0 && INT_MAX/mid_num <= mid_num)
    {
        result=sqrtByBinarySearch(x, start, mid_num-1);
    }
    else
    {
        int mid_square = mid_num*mid_num;
        if (mid_square==x) return mid_num;
        else if (mid_square<x)
        {// mid square is smaller: increase the start and try again.
            result=sqrtByBinarySearch(x, mid_num+1, fin);
        }
        else
        {// mid square is larger than x,
            result=sqrtByBinarySearch(x, start, mid_num-1);
        }
    }
    return result;
}



// search thru indicies
// finds the number num and returns indices in
int binarySearch(int num, int * arr, int m, int n)
{
    int result = -1;
    if (m>n) return result; // the search should end after the last condition(m==n) does not match with the searched number.

    int mid = (m+n)/2;
    if ( *(arr+mid) == num) return mid;
    else if (*(arr+mid)>num)
    {// num is smaller than middle number; num should be on the smaller index than mid; use mid-1 as n and do it again.
        result=binarySearch(num, arr, m, mid-1);
    }
    else
    {// num is greater than middle number: num should be on the larger index than mid; use mid+1 as m and do it again.
        result=binarySearch(num, arr, m+1, n);
    }
    return result;
}
