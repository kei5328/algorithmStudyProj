int hammingWeight(uint32_t n) {
    int result = 0; // result.
    for (int ii = 0; ii<32; ii++)
    {
        uint8_t curr_bit = (n>>ii & 1); // shift ii bit and bit and 1.
        if (curr_bit>0) // shift is greater than 1
            result++;
    }
    return result;
}
