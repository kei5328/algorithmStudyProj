/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */


int pickNumBinSearch(int p, int q)
{
    if (p>q) return -1;
    int mid = p/2 + q/2 + (p%2==1 && q%2==1)? 1:0;
    int result = guess(mid);
    if (result==0)
        return mid;
    else if (result>0)
        return pickNumBinSearch(mid+1, q);
    else
        return pickNumBinSearch(p, mid-1);
    return -1;
}

int guessNumber(int n){
    return pickNumBinSearch(0, n);
}
