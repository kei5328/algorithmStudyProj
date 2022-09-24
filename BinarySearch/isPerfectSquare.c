
bool checkSquareByBinarySearch(int p, int q, int target)
{

    if (p>q) return false;
    int mid = 0;
    if (p>INT_MAX-q)
        mid = p/2+q/2 + ((p%2==1 && q%2==1)? 1 : 0) ;
    else
        mid = (p+q)/2

    if (mid*mid==target)
        return true;
    else if (mid*mid>target)
        return checkSquareByBinarySearch(p, mid-1);
    else
        return checkSquareByBinarySearch(mid+1, q);

    return false;
}

bool isPerfectSquare(int num){

    return checkSquareByBinarySearch(0, num/2);
}

