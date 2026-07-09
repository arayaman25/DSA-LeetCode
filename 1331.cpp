#include <iostream>
#include <unordered_set>
using namespace std;

//brute
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            int greater=0;
            unordered_set<int> seen;
            for(int j=0 ; j<n ; j++){
                if(j!=i && arr[i] > arr[j] && seen.find(arr[j]) == seen.end() ) {
                    greater++;
                    seen.insert(arr[j]);
                }    
            }
            ans.push_back(greater + 1);
        }
        return ans;      
    }
};

 //optimal
 class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mpp;
        int rank=1;

        for(int i=0 ; i<n ;i++){
            if(mpp.find(temp[i]) == mpp.end()){
                mpp[temp[i]]=rank;
                rank++;
            }
        }

        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            ans.push_back(mpp[arr[i]]);
        }


        return ans;      
    }
};