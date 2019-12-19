#define MAX_SIZE 100000

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize)
{
    int profitMap[MAX_SIZE + 1] = {0};

    int i, curProfit;
    for (i = 0; i < profitSize; i++) {
        curProfit = profitMap[difficulty[i]];
        profitMap[difficulty[i]] = profit[i] > curProfit ? profit[i] : curProfit;
    }

    int curMaxProfit = 0;
    for (i = 0; i < MAX_SIZE + 1; i++) {
        curMaxProfit = profitMap[i] > curMaxProfit ? profitMap[i] : curMaxProfit;
        profitMap[i] = curMaxProfit;
    }

    long long maxProfitSum = 0;
    for (i = 0; i < workerSize; i++) {
        maxProfitSum += profitMap[worker[i]];
    }

    return maxProfitSum;
}