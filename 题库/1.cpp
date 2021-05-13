#include <stdio.h>
#include <stdlib.h>

#include <map>
#include <vector>
using namespace std;

/*
 * 第一个版本，for(){ for(){} } for的时间复杂度是O(n)， 嵌套后就是O(n*n)
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum1(int* nums, int numsSize, int target, int* returnSize){
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

/*
 *    for()//O(n)
 *       for()//O(n)
 *    优化第二个O(n)，使用hash搜索O(1)
 */
//有问题，会重复
int* twoSum2(int* nums, int numsSize, int target, int* returnSize){
    map<int, int> cache;
    for(int i=0; i<numsSize; ++i){
        cache.insert(make_pair(nums[i], i));
    }
    
	for(int i=0; i<numsSize-1; ++i){
            cache.erase(nums[i]);
			if(cache.find(target - nums[i]) != cache.end()){
				int* p = (int*)malloc(sizeof(int)*2);
				*returnSize=2;
				p[0]=i;
				p[1]=cache.find(target-nums[i])->second;
				return p;
			}
    }
    return NULL;
}

//nums是一个集合A，map是一个集合B，拿集合A元素找集合B,没有就移到集合B
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    map<int, int> cache;
    
	for(int i=0; i<numsSize; ++i){
			if(cache.find(target - nums[i]) != cache.end()){
				int* p = (int*)malloc(sizeof(int)*2);
				*returnSize=2;
				p[0]=i;
				p[1]=cache.find(target-nums[i])->second;
				return p;
			}
			
			cache.insert(make_pair(nums[i], i));
    }
    return NULL;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> cache;
        
        for(int i=0; i<nums.size(); ++i){
                if(cache.find(target - nums[i]) != cache.end()){
                    result.push_back(i);
                    result.push_back(cache.find(target-nums[i])->second);
                    return result;
                }
                
                cache.insert(make_pair(nums[i], i));
        }
        return result;
    }
};

int main(){
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

	return 0;
}
