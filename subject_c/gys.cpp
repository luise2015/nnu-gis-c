int get_gcd(int m, int n)
{
    int r;
    while (m % n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return n;
}

int get_lcm(int m, int n)
{
    return m * n / get_gcd(m, n);
}