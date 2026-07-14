#include<iostream>
using namespace std;
//brute
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp; // ele , freq
        for(int i=0 ;i<n ; i++) {
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> freq;

        for(auto &x:mpp){
            freq.push_back({x.first , x.second});
        }

        sort(freq.begin(), freq.end(), [](const auto &a, const auto &b) {
            return a.second < b.second;
        });

        vector<int> ans;
        for(int i = freq.size() - 1; i >= (int)freq.size() - k; i--){
            ans.push_back(freq[i].first);
        }    

        return ans;

    }
};

//heap
class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0 ;i<n ; i++) {
            mpp[nums[i]]++;
        }

        priority_queue<P , vector<P> , greater<P> > minHeap;
        for(auto &x:mpp){
            int val= x.first;
            int freq = x.second;

            minHeap.push({freq , val});
            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }    

        return ans;

    }
};

//bucket Sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0 ;i<n ; i++) {
            mpp[nums[i]]++;
        }

        vector<vector<int>> bucket(n+1); //index -> freq , value -> elements with ith freq
        for( auto &it : mpp){
            int ele = it.first;
            int freq = it.second;
            
            bucket[freq].push_back(ele);
        }

        vector<int> ans;
        for(int i=n ; i>=0 ; i--) {
            if(bucket[i].size() == 0) continue;

            while( bucket[i].size() > 0 && k > 0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;

    }
};