
int titleToNumber(char * columnTitle){

    int result = 0;
    int len = strlen(columnTitle);

    for (int ii = 0; ii<len; ii++)
    {
        int shift_len = (int) (columnTitle[ii] - 'A')+1;
        result+=pow(26,len-ii-1)*shift_len;

    }
    return result;
}
