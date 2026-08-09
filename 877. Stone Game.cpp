#include <iostream>
using namespace std;
//TLE
class Solution {
public:
int solve(vector<int>& piles, int i, int j) {
        if(i > j) return 0;
        
        
        int leftMove = piles[i] + min(solve(piles, i + 2, j), solve(piles, i + 1, j - 1));
        int rightMove = piles[j] + min(solve(piles, i , j - 2), solve(piles, i + 1, j - 1));
        
        return max(leftMove, rightMove);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        for(int x : piles) sum += x;

        int alex = solve(piles, 0, n-1);
        return alex > sum / 2;

    }
};

//optimal
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};