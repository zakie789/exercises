int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X)
{
    int satisfied = 0;

    int i;
    for (i = 0; i < customersSize; i++) {
        if (i < X || grumpy[i] == 0) {
            satisfied += customers[i];
        }
    }

    int maxValue = satisfied;

    for (i = 1; i <= customersSize - X; i++) {
        if (grumpy[i - 1] == 1) {
            satisfied -= customers[i - 1];
        }
        if (grumpy[i - 1 + X] == 1) {
            satisfied += customers[i - 1 + X];
        }

        maxValue = maxValue < satisfied ? satisfied : maxValue;
    }

    return maxValue;
}