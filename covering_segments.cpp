#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <utility>


using namespace std;

vector<int> optimal_points(vector< pair<int, int> > &segments) {
  vector<int> points;
  int curPoint = -1;
  sort(segments.begin(), segments.end());
  for( int i = 0; i < (int)segments.size(); i++){
    curPoint = segments[i].first;
    
    while(i< (int) segments.size() && segments[i+1].second <= curPoint){
      i++;
    }
    points.push_back(curPoint);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector < pair<int, int> > segments(n);
  for(size_t i = 0; i< segments.size(); ++i){
    std::cin >> segments[i].second >> segments[i].first;
  }

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
