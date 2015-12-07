#include <stdio.h>
// Add Digits...
int addDigits(int num) {
    if(num == 0){
		return 0;
	}
    num = num%9;
	if(num == 0){
		num = 9;
	}
	return num;
}





// Single Number...
int singleNumber(int* nums, int numsSize) {
    int result = 0;
    int i = 0;
    for(i = 0;i < numsSize;i++){
        result ^= nums[i];
    }
    
    return result;
}
int main(int argc, char *argv[]) {
	
}