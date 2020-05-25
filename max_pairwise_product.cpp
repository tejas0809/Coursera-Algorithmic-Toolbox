#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}


long long MaxPairwiseProduct1(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    long long max1 = (numbers[0] > numbers[1])?numbers[0]:numbers[1];
    long long max2 = (max1 == numbers[0])?numbers[1]: numbers[0];
    
    // assert(max1 >= max2);
    for(int i=2; i<n;i++){
        if(numbers[i] > max1){
            max2 = max1;
            max1 = numbers[i];
        }
        else if (numbers[i]>max2)
        {
            max2 = numbers[i];
        }
    }

    max_product = max1*max2;

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct1(numbers) << "\n";
    return 0;
}
