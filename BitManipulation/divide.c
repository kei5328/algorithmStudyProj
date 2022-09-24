

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.
Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
*/


// Dealing with the large number:
// Since dividend and divisor are within -2^31 and 2^31-1, only cases where the quotient will become larger or equal to these numbers are divisor is 1 or -1.

// Case when divisor is 1
// the dividend stays the same: the number will not be

// Case when divisor is -1
// if the dividend is -2^31, the quotient becomes 2^31 and will exceed 2^31-1: need a special handling
// if the dividend is 2^31-1, the quotient becomes -2^31+1. This is within the range and okay.

int divide(int dividend, int divisor){
    // use while loop and subtract until the temp number is below divisor.

    int quotient = 0;

    int temp_val = dividend;

    if (divisor==1)
    {// we can directly return the dividend.
        quotient = dividend;
    }
    else if (divisor==-1)
    {// unless the dividend is -2^31, return the negative of dividend
        quotient = (dividend == INT_MIN) ? (INT_MAX) : -dividend;
    }
    else if (dividend==0)
    {
        quotient = 0;
    }
    else
    {

        uint64_t abs_divisor = 0;
        uint64_t abs_dividend =0 ;

        if (dividend>0)
        {
            abs_dividend = (dividend);
        }
        else if (dividend==INT_MIN)
        {//
            printf("\nhere\n");
            abs_dividend = ((uint64_t)INT_MAX)+1;
        }
        else
        {
            abs_dividend = (-dividend);
        }

        for (int ii = 0; ii<32; ii++)
        {
            printf("%d", (abs_dividend>>ii & 1));
        }


        if (divisor>0)
        {//
            printf("divisor>0", NULL);
            abs_divisor =(divisor);
        }
        else if (divisor==INT_MIN)
        {
            abs_divisor = ((uint64_t)INT_MAX)+1;
        }
        else
        {
            abs_divisor = (uint64_t)(-divisor);
        }

        quotient = 0;
        bool isPositive = ((divisor<0) == (dividend<0));


        uint32_t temp = 0;

        uint8_t cnt = 0;
        for (int ii = 31; ii>=0; ii--)
        {
            temp = temp<<1;


            if ((abs_dividend>>ii & 1) > 0)
            {
                temp+=1;
            }

            if (temp>=abs_divisor)
            {// put 1 as result, and subtract divisor from temp

                quotient = (quotient | 1<<ii);
                temp -= abs_divisor;
            }
            else
            { // put 0 as a result

            }
        }

        if (!isPositive) quotient = (-quotient);
        cnt++;
    }
    return quotient;
}
