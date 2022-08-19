#include <iostream>

using namespace std;

uint32_t Fibonacci(uint32_t n)
{
    if (n <= 1) return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    for (uint32_t n = 0; n < 20; ++n)
    {
        printf("Fibonacci(%d) = %d\n", n, Fibonacci(n));
    }
    return 0;
}
