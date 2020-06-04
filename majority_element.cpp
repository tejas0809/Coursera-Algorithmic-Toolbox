#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using std::vector;
ll merge_fun(vector<ll> &a, ll b, ll c, ll left, ll right ){
  if(b==c)
    return b;
  ll bcnt =0, ccnt=0;
  for(ll i = left; i<right;i++){
    if(a[i]==b)
      bcnt++;
    if(a[i]==c)
      ccnt++;
  }

  if(ccnt == bcnt)
    return -1;
  int maxfreq = std::max(ccnt, bcnt);
  if(maxfreq>(right-left)/2){
    if(maxfreq == ccnt)
      return c;
    else
      return b;
  }
  return -1;
}


ll get_majority_element(vector<ll> &a, ll left, ll right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  ll mid = left + (right - left)/2;

  ll b = get_majority_element(a, left, mid);
  ll c = get_majority_element(a, mid, right);
  // std::cout<<left<<" "<<mid<<" "<<right<<" "<<merge_fun(a , b, c, left, right)<<"\n";  
  return merge_fun(a , b, c, left, right);  
}

int main() {
  ll n;
  std::cin >> n;
  vector<ll> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // std::cout << (get_majority_element(a, 0, a.size())) << '\n';
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
