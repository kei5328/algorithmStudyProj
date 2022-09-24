class Solution {
public:
    string addStrings(string num1, string num2) {

        string res;

        int len1 = num1.size();
        int len2 = num2.size();

        int carry = 0;

        int val1 = 0, val2 = 0, digit = 0;

        for (int ii = 0; (ii<len1 || ii<len2); ii++ )
        {
            int idx1 = len1-ii-1; // right most
            int idx2 = len2-ii-1; // right most.

            if (idx1<0)
            {// reached the end of num1;
                val1 = 0;
                val2 = (int)(num2[idx2]-'0');
            }
            else if (idx2<0)
            {// reached the end of num2;
                val1 = (int)(num1[idx1]-'0');
                val2 = 0;
            }
            else
            {// both of them still have number
                val1 = (int)(num1[idx1]-'0');
                val2 = (int)(num2[idx2]-'0');
            }

            // add one value.
            digit = val1 + val2 + carry;
            if (digit>=10)
            {
                digit -=10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            res.insert(0, to_string( digit ));
        }
        if (carry)
            res.insert(0, to_string( carry ));

        return res;
    }
};
