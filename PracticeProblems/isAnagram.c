

bool isAnagram(char * s, char * t){

    uint16_t s_len = strlen(s);
    uint16_t t_len = strlen(t);
    if (s_len!=t_len) return false; // check the easy case first: lengths are different.
// I could use hash map but since the constraints says "s and t consist of lowercase English letters.", I'll use an array of size 26
    uint16_t letter_cnt[26];
    memset(letter_cnt, 0, sizeof(letter_cnt));

    for (int ii = 0; ii<s_len-1; ii++)
    {
        int idx = (int) ((*(s+ii)) - 'a');
        if (idx<0||idx>=26)
        {
            // do nothing...
        }
        // it's not in the range of lowercase alphabet
        else
        {
            letter_cnt[idx]++;
        }
    }
    // check with t;
    for (int ii = 0; ii<t_len-1; ii++)
    {
        int idx = (int) ((*(t+ii)) - 'a');
        if (idx<0||idx>=26)
        {
            // do nothing...
        }
        // it's not in the range of lowercase alphabet(what should be the output?)
        else if (letter_cnt[idx]>0)
        {
            letter_cnt[idx]--;
        }
        else
        {// alphabet t is not used(or # does not add up) in s.
            return false;
        }
    }

    // check for leftover
    for (int ii = 0; ii<t_len-1; ii++)
    {
        if (letter_cnt[ii]>0) return false;
    }
    // at this point, all the alphabet in s was used in t.
    return true;
}
