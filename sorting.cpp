#include <iostream>
#include <vector>
#include <cstdlib>
#define ll long long
using std::vector;
using std::swap;

vector<int> partition3(vector<ll>&a, int l, int r){
  ll x = a[l];
  // std::cout<<"----------------------\n"<<l<<" "<<r<<" "<<x<<"\n";
  int d1  = l, d2 = l;
  for(int i = l+1; i<=r; i++ ){
    if(a[i] < x){
      d1++;
      d2++;
      if(a[d1] ==x){
        swap(a[i], a[d1]);
        swap(a[i],a[d2]);
      }
      else{
        swap(a[i],a[d1]);
      }
    }
    else if(a[i] ==x){
      d2++;
      swap(a[i], a[d2]);
    }
  }
  swap(a[l], a[d1]);
  // std::cout<<d1<<" "<<d2<<std::endl;
   
  // for(int o: a)
  //   std::cout<<o<<" ";
  // std::cout<<"\n"<<l<<" "<<d1<<" "<<d2<<" "<<r<<"\n";

  vector<int> d;
  d.push_back(d1);
  d.push_back(d2);
  return d;

}


int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);


 

}

void randomized_quick_sort(vector<ll> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1]+1, r);

}

int main() {
  int n;
  std::cin >> n;
  vector<ll> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  // vector<int> ans = partition3(a, 0, a.size()-1);
  // std::cout<<ans[0]<<" "<<ans[1]<<"\n";
  // for(int i: a){
  //   std::cout<<i<<" ";
  // }

  
}
