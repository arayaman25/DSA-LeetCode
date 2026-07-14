#include <iostream>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        int n = val.size();
        double ans=0;
        vector<pair<double, pair<long long, long long>>> rvw(n);// ratio , value , weight
        
        for(int i=0 ; i<n ;i++) {
            double ratio = (double) val[i] / (double) wt[i];
            rvw[i].first=ratio;
            rvw[i].second.first=val[i];
            rvw[i].second.second=wt[i];
        }    
        sort(rvw.begin() , rvw.end());

        for(int i = n-1 ;i >= 0 ; i--) {
            if(rvw[i].second.second <= capacity) {
                ans += rvw[i].second.first;
                capacity -= rvw[i].second.second;
            }
            else {
                ans += (double) rvw[i].first * capacity;
                break;
            }
        }
        return ans;
    }
};