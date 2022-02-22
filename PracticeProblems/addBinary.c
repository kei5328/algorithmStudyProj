char * addBinary(char * a, char * b){
uint16_t len_a=strlen(a);// strlen returns the size of string, not the size of an char array(it would NOT count the last \0);
uint16_t len_b=strlen(b);
char a_val, b_val, out_char;
uint8_t carry_over = 0;
uint16_t max_len;
if (len_a>len_b)
    max_len = len_a;
else
    max_len = len_b;
char * out_char_arr = (char *) malloc(sizeof(char)*(max_len+1));

for (uint16_t i = 0; i<max_len; i++)
{
    if (i<len_a)
        a_val = a[len_a-i-1]; //a[len_a]='\0' so a[len_a-1] is the lowerst digit.
    else
        a_val = '0';

    if (i<len_b)
        b_val = b[len_b-i-1];
    else
        b_val = '0';

    //printf("a_val=%c,b_val=%c\n", a_val, b_val);
    if (a_val == '1' && b_val == '1')
    {// both of them are ones
        if (carry_over) // previously we have carry over.
            out_char = '1';
        else
            out_char = '0';
        // regardless of previous carry over, we will have carry over in the next digit.
        carry_over = 1;
    }
    else if (a_val == '1' || b_val == '1')
    {// one of them is one and the other is 0.
        if (carry_over)
        {
            out_char = '0';
            carry_over = 1;
        }
        else
        {
            out_char = '1';
            carry_over = 0;
        }
    }
    else
    {// both of them are zeros
        if (carry_over)
            out_char = '1';
        else
            out_char = '0';
        carry_over = 0;
    }
    out_char_arr[max_len-i-1] = out_char;
}

out_char_arr[max_len] = '\0';
if (carry_over)
{// the last digit has carry over, so we need to increase the
    char temp[max_len+2];
    temp[0] = '1';
    for (int i = 1; i<max_len+2; i++)
    {
        temp[i] = out_char_arr[i-1];
    }
    free(out_char_arr);
    out_char_arr = (char *) malloc(sizeof(char)*(max_len+2));
    memcpy(out_char_arr, temp, max_len+2);
}

    return out_char_arr;
}
