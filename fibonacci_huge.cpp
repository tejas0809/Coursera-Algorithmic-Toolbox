#include <iostream>
#include<vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous%m + current%m);
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
    // std::cout<<"pos:"<<pos<<" ";
    // std::cout<<"ans:"<<(get_fibonacci_huge_naive(pos, m))<<"\n";
    return get_fibonacci_huge_naive(pos, m);


 
}


// long long get_fib_huge(long long n, long long m){

//     std::vector<long long>fib(n+1, -1);
//     fib[0] = 0;
//     fib[1] = 1;
//     fib[2] = 1;
//     // std::vector<long long>fibmodm(n+1);
//     // fibmodm = fib;
//     long long pos = 3;
//     while(true){
//         fib[pos] = ((fib[pos-2]%m) + (fib[pos-1]%m) )%m;
//         if((int)fib[pos] == 1 && (int)fib[pos-1] ==0){
//             break;
//         }
//         pos++;
//     }

//     long long patternsize = pos-1;
    
//     std::cout<<"patternsize"<<patternsize<<std::endl; 

//     int pos1 = n %patternsize;
//     // std::cout<<"ans"<<fibmodm[pos1]<<std::endl;
//     return fib[pos1];
// }


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_new(n, m) << '\n';
    // for ( int i = 2; i<100; i++){
    //     std::cout<<"m = "<<i<<" "<<get_fibonacci_huge_new(n,i)<<std::endl;        
    // }
}
