#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0 ) return false;
        
        int n=hand.size();
        
        map<int ,int> mp; //element , freq
        for( int i=0 ;i <n ;i++) mp[hand[i]]++;

        while(!mp.empty()){
            int curr = mp.begin()->first;

            for(int i=0 ; i < groupSize ; i++){
                if(mp[curr + i] == 0) return false;

                mp[curr+i]--;
                if(mp[curr+i] == 0 ) mp.erase(curr + i);

            }

        }
        return true;
    }    

};