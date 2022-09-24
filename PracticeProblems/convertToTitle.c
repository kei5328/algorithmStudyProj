
char * convertToTitle(int columnNumber){


// let's find the digits first


    const static int NUM_ALPHABET = 26;
    int temp = columnNumber;
    int digits = 0;

    while (temp>0)
    {
        if (temp%NUM_ALPHABET==0)
        {
            temp = (temp-1)/(NUM_ALPHABET);
        }
        else
        {
            temp/=(NUM_ALPHABET);
        }
        digits++;
    }

     char * column_title= (char*) malloc(sizeof(char)*(digits+1));

     // check for null ptr.
     if (column_title==NULL) return NULL;


     // set last index as end of string.
     column_title[digits] = '\0';

     // start to fill in the alphabets.
     temp = columnNumber-1;
     int curr_num = 0; // indicates how many power of 26s is contained in the columnNumber.
     // get each alphabet
     for (int ii = digits; ii>0; ii--)
     {
        // use pow function to get what the current
        int power = (int)pow(NUM_ALPHABET,(ii-1)); // get the 26^ii for each digit
        int curr_num = (temp/power);

        temp-=(power*curr_num); //subtract for the next digit

        //
        if (ii==1)
            column_title[digits-ii] = (char)((curr_num) + 'A');
        else
            column_title[digits-ii] = (char)((curr_num-1) + 'A');

     }

    return column_title;
}


char * convertToTitle(int columnNumber){
    const static int NUM_ALPHABET = 26;
    int digits = 1; // init as one as there should be at least 1 digit.
    int temp = (columnNumber-1)/NUM_ALPHABET;
    // first, count how many "digits" needed.
    while(temp>0)
    {// how to handle 'A'?
        temp = temp/NUM_ALPHABET;
        digits++;
    }

    // allocate the result.
    char * title = (char *)malloc(sizeof(char)*digits + 1);

    // find each digit number.
    temp = columnNumber-1;
    for (int ii = 0; ii<digits; ii++)
    {
        int curr_value = temp/pow(NUM_ALPHABET,digits-ii-1);
        temp = temp%pow(NUM_ALPHABET,digits-ii-1);
        if (i==digits-1)
        {// last digit(right most). For this, the A means 0(since one has been subtracted to start with 0).
            title[ii] = 'A' + (curr_value);
        }
        else
        {// all but the last digit. For this, the A means 1.
            title[ii] = 'A' + (curr_value-1);
        }


    }

    return column_title;
}

