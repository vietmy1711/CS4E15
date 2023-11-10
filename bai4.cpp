#include <iostream>
#include <queue>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isSuperPrime(int n)
{
    if (!isPrime(n))
        return false;
    while (n > 0)
    {
        if (!isPrime(n))
            return false;
        n /= 10;
    }
    return true;
}

queue<int> superPrimeNumber(int n)
{
    queue<int> superPrimes;
    for (int i = 2; i <= n; ++i)
    {
        if (isSuperPrime(i))
        {
            superPrimes.push(i);
        }
    }
    return superPrimes;
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    queue<int> superPrimes = superPrimeNumber(n);

    cout << "Danh sach cac so sieu nguyen to tu 1 den " << n << " la:\n";
    while (!superPrimes.empty())
    {
        cout << superPrimes.front() << " ";
        superPrimes.pop();
    }

    return 0;
}
