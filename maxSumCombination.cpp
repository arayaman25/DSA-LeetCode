#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
        int n=nums1.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        priority_queue<pair<int , pair<int,int>>> pq;
        set<pair<int,int>> s;
        vector<int> ans;

        pq.push( {nums1.back() + nums2.back() , {n-1 , n-1}} );
        s.insert({n-1 , n-1});

        while(k--){
            auto p=pq.top();
            int sum = p.first;
            int i = p.second.first;
            int j = p.second.second;
            ans.push_back(sum);
            pq.pop();

            if ( i>0 && s.find( {i-1,j} )== s.end() ) {
                pq.push( { nums1[i-1] + nums2[j] , {i-1 ,j } } );
                s.insert({i-1 ,j });
            }

            if ( j>0 && s.find( {i,j-1} )== s.end() ) {
                pq.push( { nums1[i] + nums2[j-1] , {i ,j-1 } } );
                s.insert({i ,j-1 });
            }

        }
        return ans;
  }
};