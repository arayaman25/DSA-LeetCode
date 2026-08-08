#include <iostream>
#include <vector>
using namespace std;

//TC: O(n) word 1
//SC: O(m) word 2

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);
        int j = m - 1;
        for(int i = n - 1  ; i >= 0 ; i--){
            if(word1[i] == word2[j]) {
                last[j] = i;
                j--;
                if(j < 0) break;
            }
            
        }

        bool change = false;
        j = 0;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if (j == m) break;

            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if( !change && (j == m-1 || last[j+1] > i)){
                change = true;
                ans.push_back(i);
                j++;
            }
        }

        if(ans.size() == m) return ans;
        return {};

    }
};

/* Trick or rules that helped :
If the current letters match → Take it! Easy win.
If they don't match → You can use your joker card, BUT only if it's safe:
✓ Safe if this is the last letter you need (finish line!)
✓ Safe if you know there are more matching letters ahead (checked using the "last" array)
✗ Not safe if using it now would trap you (no matches left ahead)
If you can't match and can't use the joker → Skip this letter and keep walkin */