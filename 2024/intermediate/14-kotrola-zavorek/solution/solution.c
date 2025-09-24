#include <stdio.h>
#include <stdlib.h>



int evaluate(char end){
    char c = getchar();
    while (c != end){
        if(c == EOF) return 0;

        switch(c){
            case '(': if (!evaluate(')')) return 0; break;
            case '[': if (!evaluate(']')) return 0; break;
            case '{': if (!evaluate('}')) return 0; break;

            case ')':
            case ']':
            case '}': return 0; break;
        }

        c = getchar();
    }
    return 1;
}



int main(){
    
    if(evaluate(EOF)) printf("VALID\n");
    else printf("INVALID\n");

    return 0;
}