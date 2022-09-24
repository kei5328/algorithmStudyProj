class Solution {
public:
    string toHex(int num) {

        if (num==0) return "0";
        uint32_t n = (uint32_t) num;
        string res = "";

        while (n!=0)
        {
            int temp = n&15;
            // to insert a character, need to have repetition argument.
            res = getHex(temp)+res; // insert  ot hte front
            n = n>>4;
        }

        return res;
    }
    char getHex(int num)
    {
        if (num<0 || num>15)
            return ' ';

        if (num<=9)
            return (char)('0'+num);
        else
            return (char) ('a'+ num-10);

    }
};
