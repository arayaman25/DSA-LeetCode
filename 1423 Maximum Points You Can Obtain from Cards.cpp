#include <iostream>
using namespace std;

//O(n^2)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        long long maxi=0;
        long long sum=0;
        int t=k;
        while(t>=0){
            sum=0;
            for(int i=0;i<t;i++) sum+=cardPoints[i];
            for(int j=0;j<k-t;j++) sum+=cardPoints[n-j-1];
            maxi=max(maxi,sum);
            t--;
        }
        return maxi;
    }
};

//--------------------------------------------------


//O(n)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        long long suml=0;
        long long sumr=0;
        long long maxi=0;
        for(int i=0;i<k;i++) suml+=cardPoints[i];

        maxi=suml;
        
        for(int i=0;i<k;i++){
            suml-=cardPoints[k-i-1];
            sumr+=cardPoints[n-i-1];
            maxi=max(maxi,suml+sumr);
        }
        return maxi;
    }
};

//--------------------------------------------------