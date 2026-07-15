#include <iostream>
using namespace std;

// TC : O(n) + O(nlogn) + O(n) + O(nlogn) = O(nlogn)
// SC : O(n)
class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        int n=s.size();
        vector<int> ans;
        vector<vector<int>> esi; //end , st ,ind

        for (int i = 0; i < n; i++) { /// O(n) 
            esi.push_back({f[i], s[i], i});
        }
        sort(esi.begin(), esi.end(), [](vector<int> &a, vector<int> &b) {//O(nlogn)
            if (a[0] == b[0])
                return a[2] < b[2];   // smaller meeting number first
            return a[0] < b[0];       // smaller finish time first
        });
        
        ans.push_back(esi[0][2] +1);
        int k=0;
        for(int i=1 ; i<n ; i++){ // O(n) 
            if (esi[i][1] > esi[k][0]) {
                ans.push_back(esi[i][2] + 1);
                k=i;
            }
        }
        sort(ans.begin(), ans.end()); //O(nlogn) wort case
        return ans;

    }
};