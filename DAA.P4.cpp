#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Factorial
int iterativeFactorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact = fact * i;
    return fact;
}

// Recursive Factorial
int recursiveFactorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Iterative
    auto start1 = high_resolution_clock::now();
    int fact1 = iterativeFactorial(n);
    auto end1 = high_resolution_clock::now();

    // Recursive
    auto start2 = high_resolution_clock::now();
    int fact2 = recursiveFactorial(n);
    auto end2 = high_resolution_clock::now();

    cout << "\nIterative Factorial = " << fact1 << endl;
    cout << "Time = "
         << duration_cast<nanoseconds>(end1 - start1).count()
         << " ns" << endl;

    cout << "\nRecursive Factorial = " << fact2 << endl;
    cout << "Time = "
         << duration_cast<nanoseconds>(end2 - start2).count()
         << " ns" << endl;

    return 0;
}