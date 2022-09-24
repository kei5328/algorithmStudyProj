

int longestPalindrome(char * s){
    // using an array, count how many letters exist
    // after going thru, go thru the array to find a pair exist
    // if a single letter exist, set the single existance to true to add to the end result.
    // end result = num of pairs*2 + singleExist

    int letters[52]; // both upper and lower
    int num_pairs = 0;
    bool has_single = false;

    memset(letters, 0, sizeof(letters)); // set all to 0.

    int s_len = strlen(s);

    for (int ii=0; ii<s_len; ii++)
    {
        int idx = 0;
        if ('A'<=s[ii] && s[ii]<='Z')
            idx = (int)(s[ii]-'A');
        else if ('a'<=s[ii] && s[ii]<='z')
            idx = (int)(s[ii]-'a') + 26;
        else
            continue;
        letters[idx] += 1;
    }


    for (int ii = 0; ii<52; ii++)
    {
        num_pairs+= letters[ii]/2;
        if (!has_single && letters[ii]%2==1)
            has_single = true;
    }

    return (num_pairs*2 + (has_single ? 1:0));
}
