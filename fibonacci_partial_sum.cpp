#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous%m + current%m)%m;
    }

    return current % m;
}


long long get_fibonacci_huge_new(long long n, long long m) {
    if (n <= 1)
        return n;
    int pat_len = 0;
    long long previous = 0;
    long long current  = 1;
    long long i =0;
    for (i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;

        if(previous == 0 and current ==1){
            pat_len = i+1;
            break;
        }
    }    
    if(pat_len==0){
        return get_fibonacci_huge_naive(n, m);
    }
    long long pos = n % (i+1);
    return get_fibonacci_huge_naive(pos, m); 
}


long long fibonacci_sum(long long n){
    if(n <= 1)
        return n;
    return (get_fibonacci_huge_new(n+2, 10)+9)%10;
}


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


long long get_fibonacci_partial_sum(long long from, long long to) {
    return (get_fibonacci_huge_new(to+2, 10) - get_fibonacci_huge_new(from+1, 10) +10)%10;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
