#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

// int compute_min_refills(int dist, int tank, vector<int> & stops) {
//     // write your code here
//     stops.push_back(dist);
//     int curDistance = 0, stopIdx = 0, numStops = 0;
//     std::cout<<"stops size"<<(stops.size())<<" \n";
    
//     for(stopIdx = -1; stopIdx < int(stops.size()-1);){
//         while(stopIdx < int(stops.size())-1 && stops[stopIdx++]- curDistance <= tank){}
//         stopIdx--;
//         // if(stopIdx == -1)
//         //     return -1;
//         curDistance = stops[stopIdx];
//         numStops++;
//     }

//     if(stopIdx == stops.size()-1){
//         return numStops;
//     }
//     if(stopIdx == -1){
//         cout<<numStops<<"asas"<<std::endl;
//     }
//     // else{
//     //     return -1;
//     // }
//     std::cout<<"test"<<stopIdx<<std::endl;
//     return -1;
// }
int compute_min_refills(int dist, int tank, vector<int> & stops){
    stops.push_back(dist);
    int stopIdx = -1;
    int curDist = 0, numStops = 0;
    while(stopIdx< int(stops.size()) -1 ){
        while( (stopIdx< int(stops.size()) -1 ) && stops[stopIdx+1] - curDist <= tank ){
            stopIdx+=1;
        }
        if(stops[stopIdx] - curDist == 0){
            return -1;
        }
        if(stopIdx < int(stops.size())-1){
            numStops++;
            curDist = stops[stopIdx];
        }
    }
    return numStops;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
