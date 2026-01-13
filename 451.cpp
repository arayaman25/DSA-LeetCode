#include <iostream>
using namespace std;
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Convert to (char, freq) pairs
        vector<pair<char, int>> v;
        for (auto &p : freq) {
            v.push_back({p.first, p.second});
        }

        // Sort by frequency in descending order
        sort(v.begin(), v.end(), [](pair<char, int>& a,pair<char, int>& b) {
            return a.second > b.second;
        });

        // Build result
        string ans = "";
        for (auto &p : v) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};