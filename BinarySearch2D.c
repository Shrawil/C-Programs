#include <stdio.h>

int main() {
    int arr[4][4] = {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16};
    int r = 4, c = 4;
    int found = 0;
    int target = 4;

    int left = 0, right = (r * c) - 1, mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;  // Good: avoids overflow
        int row = mid / c;
        int col = mid % c;
        int val = arr[row][col];
        
        if (val == target) {
            found = 1;
            break;
        }
        else if (val < target) {
            left = mid + 1;
        }
        else {  // val > target
            right = mid - 1;
        }
    }
    
    if (found) {
        printf("Element %d found at flat index %d (row=%d, col=%d)!\n", 
               target, mid, mid/c, mid%c);
    } else {
        printf("Element %d could not be found!\n", target);
    }

    return 0;
}