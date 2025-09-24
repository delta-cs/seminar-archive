#include <iostream>




int possible_values[] = {50,20,10,5,2,1};

int main(){
    int C, V;
    std::cin >> C >> V;

    int total_sum=0;
    for(int i=0; i < V; i++){
        int n;
        std::cin >> n;
        total_sum += n;
    }

    int to_return = total_sum-C;

    if(to_return < 0){
        std::cout << "nelze vydat\n";
        return 0;
    }

    for(int i=0; i<6; i++){
        for(int j=0; j < (int)(to_return/possible_values[i]); j++)
            std::cout << possible_values[i] << '\n';

        to_return %= possible_values[i];
    }


}