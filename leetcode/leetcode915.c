#define MAX_SIZE 30000

int partitionDisjoint(int* A, int ASize)
{
    int leftMax[MAX_SIZE];
    int rightMin[MAX_SIZE];
    int maxValue = A[0];
    int minValue = A[ASize - 1];

    int i;
    for (i = 0; i < ASize; i++) {
        maxValue = maxValue < A[i] ? A[i] : maxValue;
        leftMax[i] = maxValue;

        minValue = minValue > A[ASize - 1 - i] ? A[ASize - 1 - i] : minValue;
        rightMin[ASize - 1 - i] = minValue;
    }

    for (i = 0; i < ASize - 1; i++) {
        if (leftMax[i] <= rightMin[i + 1]) {
            break;
        }
    }

    return (i + 1);
}