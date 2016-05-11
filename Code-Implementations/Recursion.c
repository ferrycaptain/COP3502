#include <stdio.h>
#include <stdlib.h>

int main()
{

    // iterative function call
    int iSumSquares = iterativeSumSquares(1, 10);
    printf("Iterative sum of squares for 1 through 10 = %d\n", iSumSquares);

    int uSumSquares = upRecursvieSumSquares(1, 10);
    printf("Recursive sum of squares going up for 1 through 10 = %d\n", uSumSquares);

    int dSumSquares = downRecursiveSumSquares(1, 10);
    printf("Recursive sum of squares going down for 1 through 10 = %d\n", dSumSquares);

    int sSumSquares = splitRecursiveSumSquares(1, 10);
    printf("Recursive sum of squares split for 1 through 10 = %d\n", sSumSquares);
}

// iterative implementation
// assuming m is less than or equal to n
int iterativeSumSquares(int m, int n)
{
    int i, sum;

    printf("iterativeSumSquares, start value %d, end value %d\n", m, n);

    // initialize sum to zero
    sum = 0;

    // for each value of i (i.e. 1 through 10) the value of sum is increased by the square of the value of i
    // this is the same as going up recursion
    for(i = m; i <= n; ++i)
    {
        printf("------------- Iterative -------------\n");
        printf("iterativeSumSquares iteration %d sum equals %d\n", i, sum);
        printf("adding %d * %d to the sum\n", i, i);
        sum += i * i;
        printf("iterativeSumSquares iteration %d, sum now equals %d\n", i, sum);
    }

    // this is the same as going down recursion
    for(i = n; i >= m; --i)
    {
        printf("------------- Iterative -------------\n");
        printf("iterativeSumSquares iteration %d sum equals %d\n", i, sum);
        printf("adding %d * %d to the sum\n", i, i);
        sum += i * i;
        printf("iterativeSumSquares iteration %d, sum now equals %d\n", i, sum);
    }

    return sum;
}

// recursive implementation
// assuming m is less than or equal to n
int upRecursvieSumSquares(int m, int n)
{
    printf("------------- Going Up Recursive -------------\n");
    if (m < n)
    {
        printf("if leg: m = %d, n = %d\n", m, n);
        return m * m + upRecursvieSumSquares(m + 1, n);   // recursion
        // first time 1 * 1 + 2 * 2 + 3 * 3
    }
    else
    {
        printf("else leg: m = %d, n = %d\n", m, n);
        return m * m;                                    // base case
    }
}

// recursive implementation
// assuming m is less than or equal to n
int downRecursiveSumSquares(int m, int n)
{
    printf("------------- Going Down Recursive -------------\n");
    if (m < n)
    {
        printf("m = %d, n = %d\n", m, n);
        return downRecursiveSumSquares(m, n - 1) + n * n;   // recursion
    }
    else
    {
        printf("m = %d, n = %d\n", m, n);
        return n * n;                                    // base case
    }
}

// recursive implementation
// assuming m is less than or equal to n
int splitRecursiveSumSquares(int m, int n)
{
    printf("------------- Split Recursive -------------\n");

    int middle;

    if (m == n)
    {
        printf("m = %d, n = %d\n", m, n);
        return m * m;                                    // base case
    }
    else
    {
        middle = (m + n)/2;
        printf("m = %d, n = %d\n", m, n);
         return splitRecursiveSumSquares(m, middle) + splitRecursiveSumSquares(middle + 1, n);   // recursion                                // base case
    }
}
