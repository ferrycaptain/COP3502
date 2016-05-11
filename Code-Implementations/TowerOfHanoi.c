/*
 * C program for Tower of Hanoi using Recursion
 */
#include <stdio.h>

void towers(int, char, char, char);

int main()
{
    int num;

    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    // call the function the first time
    towers(num, 'A', 'B', 'C');
    return 0;
}

// use recursion to move the disks from the fromPeg to the toPeg
void towers(int num, char frompeg, char topeg, char auxpeg)
{
printf("towers call with %d disks, %c frompeg, %c topeg, %c auxpeg\n",
       num, frompeg, topeg, auxpeg);
//system("pause");
    // base case
    if (num == 1)
    {
        // when num equals one move from peg A to peg B
        printf("\n Move disk 1 from peg %c to peg %c\n", frompeg, topeg);
//system("pause");
        // this is our base case that stops the recursion
        // returns program control to the calling function at line 35
        return;
    }

    printf("\n before line 42\n");
    // subtract from our num, if num == 3 then pass
    //         2,     A,       C,      B
    // subtract from our num, if num == 2 then pass
    //         1,     A,       B,      C
    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\n Move disk %d from peg %c to peg %c\n", num, frompeg, topeg);
//system("pause");
    printf("\n before line 46\n");
    towers(num - 1, auxpeg, topeg, frompeg);
}
