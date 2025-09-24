#include <stdio.h>

typedef long long ll;

void inverse_collatz(int *count, ll x, int i){
    if(i <= 0){
        *count += 1;
        fprintf(stderr, "DBG: %lld\n", x);
        return;
    }

    ll prev_even = x*2;
    ll prev_odd = (x-1)/3;

    if(prev_even %2 == 0 && prev_even != 1 ){
        inverse_collatz(count, prev_even, i-1);
    } 

    if((x-1)%3 == 0 && prev_odd%2 != 0 && prev_odd != 1){
        inverse_collatz(count, prev_odd, i-1);
    }
}




int main(){

    ll x;
    int j;
    scanf("%lld %d", &x, &j);

    int count = 0;
    inverse_collatz(&count, x, j);

    printf("%d\n", count);

    return 0;
}