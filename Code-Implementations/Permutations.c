#include <stdio.h>
#include <stdlib.h>

// Pre-condition: str is a valid C String, and
// k is non-negative and less than
// or equal to the length of str.

// Post-condition: All of the permutations of str
// with the first k characters fixed
// in their original positions are
// printed. Namely, if n is the
// length of str, then (n-k)!
// permutations are printed.

// Mathematical solution to determine the number of ways CAT can be arranged

// Number of permutations of n distinct things taking them all at a time = nPn = n!
// CAT has 3 letters
// 3P3 = 3! = 6

// Number of permutations of n distinct things taking r at a time can be given by
// nPr = n!(n − r)! = n(n − 1)(n − 2)...(n − r + 1) where 0 ≤ r ≤ n
// 3P1 =
// If r > n,  nPr = 0

// Special Case: nP0 = 1



// function prototypes
void ExchangeCharacters(char str[], int i, int j);
void RecursivePermute(char str[], int k);

int main()
{
    char str[] = "CAT";
    RecursivePermute(str, 0);
}

void RecursivePermute(char str[], int k)
{
printf("RecursivePermute called with str = %s, k = %d\n\n", str, k);
    int j;

    // Base-case: All fixed, so print str.
    if (k == strlen(str))
    {
        printf("%s\n", str);
printf("MET BASE CASE! k equaled the string length\n");
    }
    else
    {
        // Try each letter in spot j.
        for (j = k; j < strlen(str); j++)
        {
            // Place next letter in spot k.
printf("before first ExchangeCharacters call, passing k= %d and j = %d\n\n", k, j);
            ExchangeCharacters(str, k, j);
system("pause");
            // Print all with spot k fixed.
            RecursivePermute(str, k + 1);
system("pause");
            // Put the old char back.
printf("before second ExchangeCharacters call, passing j = %d and k = %d\n\n", j, k);
            ExchangeCharacters(str, j, k);
system("pause");
        }
    }
}

void ExchangeCharacters(char str[], int i, int j)
{
printf("swapping str[%d] = %c and str[%d] = %c \n", i, str[i], j, str[j]);
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}
