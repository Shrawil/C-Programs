#include <stdio.h>
#include <math.h>

// Swapping smallest and largest digits in a number without using arrays or linked list.

int main() {
    int num = 987654321, smallest = 9, biggest = 0;
    int copy = num;
    int length = 0;
    // Finding smallest and biggest digit.
    while(copy != 0) {
        int digit = copy % 10;
        if(digit > biggest) biggest = digit;
        if(digit < smallest) smallest = digit;
        copy /= 10;
        length++;
    }
    copy = num;
    int lPos = length, sPos = length, lPosFound = 0, sPosFound = 0, pos = 0;
    // Finding position of smallest and biggest digit.
    while(copy != 0) {
        int digit = copy % 10;
        
        if(digit == smallest && sPosFound == 0) {
            sPos = pos;
            sPosFound = 1;
        }
        if(digit == biggest && lPosFound == 0) {
            lPos = pos;
            lPosFound = 1;
        }
        copy /= 10;
        pos++;
    }
    copy = num;
    int newNum = 0;
    // Swapping
    for(int i = 0; i < length; i++) {
        printf("i = %d | i <= length = %d | newNum = %d\n", i, i <= length, newNum);
        if(i == sPos) {
            newNum = (pow(10, i) * biggest) + newNum;
            copy /= 10;
        }
        else if(i == lPos) {
            newNum = (pow(10, i) * smallest) + newNum;
            copy /= 10;
        }
        else {
            int digit = copy % 10;
            newNum = (pow(10, i) * digit) + newNum;
            copy /= 10;
        }
    }
    printf("Number = %d of %d digits\nSmallest = %d at %d\nBiggest = %d at %d\nNew number = %d", num, length, smallest, sPos, biggest, lPos, newNum);
    return 0;
}
