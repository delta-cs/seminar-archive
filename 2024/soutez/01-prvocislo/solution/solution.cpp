#include <iostream>
#include <cmath>


int main(){

    int n;

    std::cin >> n;

    int n_sqrt = std::ceil(std::sqrt(n));

    bool prime = true;
    for(int i=2; i<=n_sqrt; i++){
        if(n%i == 0 && n != 2){
            prime = false;
            break;
        }
    }

    if(prime) std::cout << "ano\n";
    else std::cout << "ne\n";



    return 0;
}