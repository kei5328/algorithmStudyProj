
uint32_t reverseBits(uint32_t n) {

    uint32_t result = 0;

    for (int ii = 0; ii<32; ii++)
    {
        // get current bit
        uint8_t current_bit = (n>>ii) & 1;
        if (current_bit>0)
        {// shift needed
            uint8_t shift_idx = 31-ii;
            uint32_t shift_bit = (uint32_t) 1 << shift_idx;
            result = result | shift_bit;
        }
        //printf("%d\n", ((uint32_t)1<<ii) & n);
    }
    return result;
}


