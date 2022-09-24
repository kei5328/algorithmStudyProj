void swapStr(char * s, int idx1, int idx2)
{
    char temp = *(s+idx1);
    *(s+idx1) = *(s+idx2);
    *(s+idx2) =  temp;
    return;
}


void reverseString(char* s, int sSize){

    for (int ii = 0; ii<sSize/2; ii++)
    {
        int tail_idx = sSize-1-ii;
        swapStr(s, ii, tail_idx);
    }
}

