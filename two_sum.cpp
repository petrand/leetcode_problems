/* 
Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

https://leetcode.com/problems/two-sum/
*/

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        
        vector<int> indexes = {0, 0};
        for(int i=0; i<nums.size(); i++){
            int complement = target-nums[i];
            if(umap.find(complement)==umap.end()){
                umap[nums[i]] = i;   
            }else{
                int j = umap.at(complement);
                indexes[0] = i;
                indexes[1] = j;
                return indexes;
            }
        }
        return indexes;
    }
};
