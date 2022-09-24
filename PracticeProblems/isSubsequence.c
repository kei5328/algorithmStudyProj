

bool isSubsequence(char * s, char * t){

    int s_len = strlen(s);
    int t_len = strlen(t);

    int idx1 = 0;
    int idx2 = 0;
    while (idx1<s_len && idx2<t_len)
    {
        if (s[idx1]==t[idx2])
        {
            idx1++;
            idx2++;
        }
        else
            idx2++;
    }
    return (idx1==s_len);
}
