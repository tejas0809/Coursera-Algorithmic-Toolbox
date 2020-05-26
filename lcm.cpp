#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_euclidean(long long a, long long b) {
  if(b==0)
    return a;
  
  gcd_euclidean(b, a%b);
}

long long lcm_trick(long long a , long long b){
  return a*b/gcd_euclidean(a,b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_trick(a, b) << std::endl;
  return 0;
}
