#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

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


long long fibonacci_sum_squares(long long n){
    long long fn = get_fibonacci_huge_new(n, 10);
    long long fn1 = get_fibonacci_huge_new(n-1, 10);
    // std::cout<<fn <<" "<<fn1;

    return fn%10*(fn%10+fn1%10);
}



int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n)%10;
}
