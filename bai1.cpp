#include <iostream>

using namespace std;

unsigned long tongUoc(unsigned long n)
{
    long s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            s += i;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        unsigned long number; // 1 -> 10^9
        cin >> number;
        cout << tongUoc(number) << endl;
    }

    return 0;
}
