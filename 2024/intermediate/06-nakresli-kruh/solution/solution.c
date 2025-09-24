#include <stdio.h>
#include <math.h>

int main(){
    int w;  int h;
    int center_x;  int center_y;
    int r;

    scanf("%d %d %d %d %d", &w, &h, &center_x, &center_y, &r); // read the numbers

    for(int current_y=0; current_y<h; current_y++){ // iterate trough rows
        for(int current_x=0; current_x<w; current_x++){ // iterate trough columns in each row
            // find distance between current character position and circle center using pythagorian therum
            int delta_x = current_x - center_x;
            int delta_y = current_y - center_y;
            float distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
            if(distance <= r){ // check if current character is inside or outside circle
                printf("#"); // is inside -> print circle
            }
            else{
                printf("."); // is outside -> print paper
            }
        }
        printf("\n"); // print newline after each row
    }
    
    
    return 0;
}