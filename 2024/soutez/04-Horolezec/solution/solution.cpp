#include <iostream>
#include <cmath>



float cutoff(int x){
    return (float)((int)(x*100))/100.0;
}


int main(){

    int n;
    std::cin >> n;

    double x,y, angle, max_y;

    for(int i=0; i<n; i++){
        double u, l;
        std::cin >> u >> l;
        angle += l;

        float u_r = angle * (M_PI / 180);

        double d_x = std::cos(u_r)*l;
        double d_y = std::sin(u_r)*l;

        x += d_x;
        y += d_y;

        if(y > max_y) max_y = y;
    }

    std::cout << max_y << '\n' << x;


    return 0;
}