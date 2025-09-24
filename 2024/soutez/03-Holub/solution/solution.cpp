#include <iostream>

int main(){
    int d, c, v, n, s;
    float p;

    std::cin >> d >> c >> v >> p >> n >> s;

    float p_gb = p/1024.0; // mb/s to gb/s

    int pigeon_max_n = c / s; // maximum files

    float flight_time = (float)d / (float)v;

    float pigeon_transfer_speed = (float)(pigeon_max_n*s) / flight_time;

    bool pigeon_faster = false;
    if(pigeon_transfer_speed > p_gb){ // pigeon faster
        n -= pigeon_max_n;
        pigeon_faster = true;
    }

    float total_land_time = n*s / p_gb; // total size / landline transfer speed

    if(pigeon_faster && flight_time > total_land_time){ // flight takes longer
        std::cout << (int)flight_time << '\n';
    }
    else{ // pigeon not deployed or landline takes longer
        std::cout << (int)total_land_time << '\n';
    }
}