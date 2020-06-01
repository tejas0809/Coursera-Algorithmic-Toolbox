#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string findBetterNumber( string a, string b){
  int aptr = 0, bptr = 0;
  while(aptr < a.size() && bptr < b.size()) {
    if(a[aptr] > b[bptr]){
      return a;
    }
    else if(b[bptr] > a[aptr]) {
      return b;
    }
    else {
      if(aptr == a.size() -1 && bptr == b.size() - 1){
        return a;
      }
      aptr = (aptr+1)%a.size();
      bptr = (bptr+1) % b.size();
    }
  }
}

string largest_number(vector<string> a) {
  std::stringstream ret;
  while(!a.empty()) {
    string maxNumber = "0";
    int maxIdx = -1;
    for(int i = 0; i< a.size(); i++) {
      if(findBetterNumber(maxNumber, a[i]) == a[i]){
        maxNumber = a[i];
        maxIdx = i;
      }
    }
    
    ret << maxNumber;
    // std::cout<<"ret\t"<< a.size() <<" " <<maxNumber   <<" \n";
    a.erase(a.begin()+maxIdx);
  }

  //write your code here
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
