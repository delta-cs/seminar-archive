#include <stdio.h>
#include <math.h>

int main() {
    int stones;
    scanf("%d", &stones);

    int housePrinted = 0;

    int maxRoofEdge = sqrt(stones * 2);
    for (int roofEdge = 3; roofEdge <= maxRoofEdge; ++roofEdge) {
        int roofStones = roofEdge * (roofEdge + 1) / 2;
        int baseStones = stones - roofStones;

        int baseWidth = roofEdge * 2 - 3;
        int baseHeight = baseStones / baseWidth;

        if (baseWidth >= 3 && baseHeight >= 3 && baseStones % baseWidth == 0) {
            if (housePrinted) {
                printf("\n");
            }

            housePrinted = 1;

            for (int i = 0; i < roofEdge; ++i) {
                for (int j = 0; j < roofEdge - i - 1; ++j) {
                    printf(" ");
                }

                for (int j = 0; j < i; ++j) {
                    printf("* ");
                }
                printf("*\n");
            }

            for (int i = 0; i < baseHeight; ++i) {
                printf(" ");
                for (int j = 0; j < baseWidth; ++j) {
                    printf("*");
                }
                printf("\n");
            }
        }
    }

//    if(!housePrinted)
//    {
//        printf("\n");
//    }
}
