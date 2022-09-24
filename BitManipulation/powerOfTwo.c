

bool isPowerOfTwo(int n){
    if (n<=0) return false;

    int cnt = 0;
    for (int ii = 0; ii<31; ii++)
    {
        if ( (n>>ii & 1) )
        {
            cnt++;
        }
        if(cnt>1)
            return false;
    }
    return true;
}
