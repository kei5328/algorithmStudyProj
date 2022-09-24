class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int h = 0; h<12; h++)
        {
            for (int m = 0; m<60; m++)
            {
                if (count_bit(h) + count_bit(m)==turnedOn)
                {
                    string res_str = to_string(h) + ":" + ( (m<10) ? "0": "") + to_string(m);
                    result.push_back(res_str);
                }
            }
        }

        return result;
    }


    int count_bit(int num)
    {
        int cnt = 0;
        while (num>0)
        {
            cnt += (num%2==1?1:0);
            num = num>>1;
        }
        return cnt;
    }
};
