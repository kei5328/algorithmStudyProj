

char findTheDifference(char * s, char * t){
    /*int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (int ii = 0; s[ii]!='\0'; ii++)
    {
        int idx = (int)(s[ii]-'a');
        cnt[idx]++;
    }
    for (int ii = 0; t[ii]!='\0'; ii++)
    {
        int idx = (int)(t[ii]-'a');
        if (cnt[idx]<=0)
            return t[ii];
        cnt[idx]--;
    }
    return ' ';
    */

    int sum = 0;
    for (int ii=0; t[ii]!='\0'; ii++)
    {
        sum+= (int)t[ii];
    }

    for (int ii=0; s[ii]!='\0'; ii++)
    {
        sum-=s[ii];
    }
    return (char)sum;
}
