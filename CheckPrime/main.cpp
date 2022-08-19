#include <iostream>

using namespace std;

bool IsPrime(uint64_t n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    for (uint64_t i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << IsPrime(111111111111111) << std::endl;
    return 0;
}
