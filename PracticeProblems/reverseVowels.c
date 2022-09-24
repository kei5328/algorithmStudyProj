

void swapChar(char*s, int idx1, int idx2)
{
    char temp = *(s+idx1);
    *(s+idx1) = *(s+idx2);
    *(s+idx2) = temp;
    return;
}


bool isVowel(char c)
{
    return ((c-'a')==0 || (c-'e')==0 || (c-'i')==0 || (c-'o')==0 || (c-'u')==0 || (c-'A')==0 ||(c-'E')==0 || (c-'I')==0 || (c-'O')==0 || (c-'U')==0)
}

char * reverseVowels(char * s){

    int ii = 0;
    int jj = strlen(s)-1;
    while (ii<jj)
    {
        while (!isVowel(*(s+ii)) && ii<strlen(s)-1)
            ii++;
        while (!isVowel(*(s+jj)) && j>=0)
            jj--;
        if (ii<jj)
        {
            swapChar(s, ii, jj);
            ii++;
            jj--;
        }
    }
}
