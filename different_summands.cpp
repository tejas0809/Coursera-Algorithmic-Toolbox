#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int totalGivenCandies = 0, curCandyGiven = 0;
  while(totalGivenCandies < n)
  {
    if((n -totalGivenCandies) < ++curCandyGiven){
      summands[int(summands.size() - 1)] += (n -totalGivenCandies);
      break;
    }
    summands.push_back(curCandyGiven);
    totalGivenCandies += curCandyGiven;
  }
  
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
