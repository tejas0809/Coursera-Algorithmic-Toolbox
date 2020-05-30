#include <iostream>
#include <vector>
#include<iomanip>
#define ll long long 
using std::vector;

int selectItem(vector<int> &weights, vector<int> &values){
  int maxIdx = -1;
  double maxVal = -1.0;
  for(int i = 0; i<weights.size(); i++){
    if(weights[i]>0 && double(values[i])/double(weights[i]) > maxVal ) {
      maxIdx = i;
      maxVal = double(values[i])/double(weights[i]);
    }
  }
  return maxIdx;
}


double get_optimal_value(int capacity, vector<int> &weights, vector<int> &values) {
  double value = 0.0;
  ll remCapacity = capacity;
  ll sel_idx = -1;

  for(int i = 0; i < weights.size(); i++){ 
    if(remCapacity == 0)
      return value;
    sel_idx = selectItem(weights, values);
    ll amount = (remCapacity < weights[sel_idx])? remCapacity : weights[sel_idx];
    // one should be casted explicitly to double to get correct answer for integer division resulting in double
    value += amount*double(values[sel_idx])/(double)weights[sel_idx];
    weights[sel_idx] -= amount;    
    remCapacity -= amount;
  }
  return value;
}

int main() {
  int  n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  // std::cout.precision(10);
  std::cout << std::fixed;
  std::cout << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
