/*
Jump Game IV
You are given a 0-indexed integer array nums and an integer k.
You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.
You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

https://leetcode.com/problems/jump-game-vi/
*/ 

#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    

    void showpq(priority_queue<pair<int,int>> gq)
    {
        priority_queue<pair<int,int>> g = gq;
        while (!g.empty()) {
            cout << ' ' << g.top().first;
            g.pop();
        }
        cout << '\n';
    }
    

    
    int maxResult(vector<int>& nums, int k) {
        
        int length = nums.size();
            
        int opt_arr[length]; 
        opt_arr[length-1] = nums[length-1];
        priority_queue<pair<int,int>> maxh;
        
        maxh.push({opt_arr[length-1],length-1});
        for(int position=length-2; position>-1; position--){
                    
                    while(maxh.size() > 0 && maxh.top().second > position+k){
                        maxh.pop();
                    }
                    showpq(maxh);
            
                               
                    opt_arr[position] = maxh.top().first + nums[position];
                    maxh.push({opt_arr[position], position});
        }   
      
        return opt_arr[0];
    }
};
