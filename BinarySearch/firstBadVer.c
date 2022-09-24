// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {

    int idx = searchBad(n);
    return idx;
}


int searchBad(int init, int fin)
{
    if (init>fin) return init;

    int result;
    int mid = (init+fin)/2;

    if (isBadVersion(mid))
    {
        result = searchBad(init mid-1);
    }
    else
    {
        result = searchBad(mid+1, fin)
    }
    return result;
}
