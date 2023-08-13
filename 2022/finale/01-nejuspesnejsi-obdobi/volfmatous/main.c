#include <stdio.h>

int main() {
    int m;
    scanf(" %d", &m);

    int maxProfitSequence = 0;
    int currentProfitSequence = 0;
    int lastProfit;

    if (m > 0)
    {
        scanf(" %d", &lastProfit);
    }

    for (int i = 1; i < m; ++i) {
        int profit;
        scanf(" %d", &profit);

        if (profit > lastProfit) {
            currentProfitSequence++;

            if (currentProfitSequence > maxProfitSequence) {
                maxProfitSequence = currentProfitSequence;
            }
        }
        else {
            currentProfitSequence = 0;
        }

        lastProfit = profit;
    }

    printf("%d\n", maxProfitSequence);
}