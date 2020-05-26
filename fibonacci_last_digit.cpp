#include <iostream>
#include<vector>
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

long long get_fibonacci_last_digit(int n) {

    std::vector<long long> fib(n+1,0);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n+1; ++i) {
        fib[i] = ((fib[i-1]) + (fib[i-2]))%10;
    }

    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    
    long long c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    
    }
    
