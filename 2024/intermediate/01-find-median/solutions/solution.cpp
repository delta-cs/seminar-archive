#include <iostream>
#include <vector>
#include <algorithm>




void print_median(std::vector<int> &vec){
    if(vec.size()%2 == 0){
        float med = (vec.at((int)(vec.size() / 2)) + vec.at((int)(vec.size() / 2))) / 2;
        std::cout << med;
    }
    else{
        int med = vec.at((int)(vec.size()/2));
        std::cout << med;
    }
}


int main(){
    int K;
    std::cin >> K;

    std::vector<int> numbers;

    for(int i=0; i<K; i++){
        int tmp;
        std::cin >> tmp;
                
        numbers.push_back(tmp);
    }

    std::sort(numbers.begin(), numbers.end());

    print_median(numbers);

    return 0;
}