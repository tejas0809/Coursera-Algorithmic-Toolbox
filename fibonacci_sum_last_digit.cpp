#include <iostream>


// long long find_fib(long long n){
//     if(n <= 1)
//         return n;
//     long long prev = 0;
//     long long curr = 0;
//     long long tmp_prev;
//     for( long long i = 0; i < n-1; i++ ){
//         tmp_prev = prev;
//         prev = curr;
//         curr = tmp_prev + curr;
//     }
//     return curr;
// }

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
    return (get_fibonacci_huge_new(n+2, 10)-1+10);
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n)%10;
}
