#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	for(int i=0; i<numsSize-1; ++i)
		for(int j=i+1; j<numsSize; ++j)
			if(nums[i]+nums[j] == target){
				int* p = (int*)malloc(sizeof(int)*2);
				*returnSize=2;
				p[0]=i;
				p[1]=j;
				return p;
			}
    return NULL;
}

void main(){
	int size;

	int t1[]={2,7,11,15};
	int* r = twoSum(t1, 4, 9, &size);
	if(r != NULL){
		printf("[%d, %d]\n", r[0], r[1]);
		free(r);
	}

	int t2[]={3,2,4};
	r = twoSum(t2, 3, 6, &size);
	if(r != NULL){
		printf("[%d, %d]\n", r[0], r[1]);
		free(r);
	}

	int t3[]={3,3};
	r = twoSum(t3, 2, 6, &size);
	if(r != NULL){
		printf("[%d, %d]\n", r[0], r[1]);
		free(r);
	}

	int t4[]={2, 5, 5, 11};
	r = twoSum(t4, 4, 10, &size);
	if(r != NULL){
		printf("[%d, %d]\n", r[0], r[1]);
		free(r);
	}
}
