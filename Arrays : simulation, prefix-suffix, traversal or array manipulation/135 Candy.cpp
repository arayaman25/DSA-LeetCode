#include <iostream>
using namespace std;


//TC : O(n) SC:O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> can(n,1);
        int count = 0;
        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                can[i] = can[i-1] + 1;
            }
        }

        int sum = can[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                can[i] = max(can[i], can[i+1] + 1);
            }
            sum+=can[i];
        }

        
        return sum;
    }
};

//TC : O(n) SC:O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1 ;
        int sum = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }

            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]) {
                peak++;
                sum += peak;
                i++;
            }

            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]) {
                sum += down;
                down++;
                i++;
            }

            if(down > peak) sum += down - peak;

        }
        return sum;
        
    }
};