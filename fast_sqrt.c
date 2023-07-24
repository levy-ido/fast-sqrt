float fast_sqrt(float x) {
    // Extract x bits.
    unsigned int x_bits = *((unsigned int*)&x);
    // Approximate sqrt(x) bits.
    unsigned int sqrtx_bits = (x_bits + (127 << 23)) >> 1;
    // Convert the result back to a float.
    float sqrtx = *((float*)(&sqrtx_bits));
    // 3 iterations of Newton's method to get a better approximation.
    sqrtx = (sqrtx + x / sqrtx) / 2;
    sqrtx = (sqrtx + x / sqrtx) / 2;
    sqrtx = (sqrtx + x / sqrtx) / 2;
    return sqrtx;
}