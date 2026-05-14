#include <iostream>
using namespace std;
//brute
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            int nextGreater = -1;
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    for(int k = j + 1; k < nums2.size(); k++) {
                        if(nums2[k] > nums2[j]) {
                            nextGreater = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};

//optimal- monotonic stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i = nums2.size()-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};