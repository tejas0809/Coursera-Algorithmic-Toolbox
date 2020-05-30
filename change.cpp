#include <iostream>
#define ll long long

int get_change(int m) {
  //write your code here
  ll n = 0;
  ll curVal = m;
  while(curVal>0){
    while(curVal>=10){
      curVal-=10;
      n++;
    }
    while(curVal>=5){
      curVal -= 5;
      n++;
    }

    while(curVal>=1){
      curVal --;
      n++;
    }
  }
  return n;
}

int main() {
  ll m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
