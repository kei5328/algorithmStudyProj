
bool isPalindrome(char * s){


    /* Idea

    1: find the length of the string,

    2: start from the


    */

    uint32_t len = strlen(s);

    int idx1 = 0;
    int idx2 = len-1; // start from the end
    char cmp1;
    char cmp2;

    while (idx1<idx2)
    {
        while (!((s[idx1]>='0' && s[idx1]<='9') || (s[idx1]>='A' && s[idx1]<='Z') || (s[idx1]>='a' && s[idx1]<='z')))
        {
            idx1++;
        }
        while (!((s[idx2]>='0' && s[idx2]<='9') || (s[idx2]>='A' && s[idx2]<='Z') || (s[idx2]>='a' && s[idx2]<='z')))
        {
            idx2--;

        }
        // need to convert upper case to lower case
        if ((s[idx1]>='a' && s[idx1]<='z'))
        {
            cmp1 = s[idx1] - ('A' - 'a');
        }
        else
        {
            cmp1 = s[idx1];
        }

        if ((s[idx2]>='a' && s[idx2]<='z'))
        {
            cmp2 = s[idx2] - ('A' - 'a');
        }
        else
        {
            cmp2 = s[idx2];
        }

        if (cmp1!=cmp2)
        {
            return false;
        }

        idx1++;
        idx2--;
    }
    return true;
}
