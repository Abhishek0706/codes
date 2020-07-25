int pow_mod(int a, int n) {
    int result = 1;
    while (n > 0) {
        if (n&1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return result;
}
