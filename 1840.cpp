#include <iostream>
using namespace std;


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());

        int len=restrictions.size();
        int res=0;
        //left to right correction
        for(int i=1 ; i<len ; i++){
            int diffDist=restrictions[i][0]-restrictions[i-1][0];
            restrictions[i][1]=min(restrictions[i][1], restrictions[i-1][1] + diffDist);
        }

        //right to left correction
        for(int i=len-2 ; i>=0 ; i--){
            int diffDist=restrictions[i+1][0]-restrictions[i][0];
            restrictions[i][1]=min(restrictions[i][1], restrictions[i+1][1] + diffDist);
        }


        for(int i=1 ; i<len ; i++){
            int leftPos=restrictions[i-1][0];
            int leftHt=restrictions[i-1][1];
            
            int currPos=restrictions[i][0];
            int currHt=restrictions[i][1];

            int d=currPos-leftPos;
            int htDiff=abs(currHt-leftHt);

            int peak=max(leftHt,currHt) + (d-htDiff)/2;
            res=max(res, peak);
        }
        return res;
    }
};

//--------------------------------------------------