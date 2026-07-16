#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    int n=intervals.size();
    for(int i=0;i<n;i++){
        int lowerBound=intervals[i][0];
        int upperBound=intervals[i][1];
        if(!ans.empty() && upperBound<=ans.back()[1]) continue;
        for(int j=i+1;j<n;j++){
            if(intervals[j][0]<= upperBound){
                upperBound=max(upperBound,intervals[j][1]);
            }
            else break;
        }
        ans.push_back({lowerBound,upperBound});
 
       
    } return ans;
}

vector<vector<int>> merge(vector<vector<int>>& intervals){
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    int n=intervals.size();
    for(int i=0;i<n;i++){
        int lowerBound=intervals[i][0];
        int upperBound=intervals[i][1];
       if(ans.empty() || lowerBound>ans.back()[1]){
        ans.push_back(intervals[i]);
       }
       else{
        ans.back()[1]=max(ans.back()[1],upperBound);
       }
 
       
    } return ans;
}

int main(){
    return 0;
}