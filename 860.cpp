class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int notes5 = 0 , notes10 = 0;
        for(int i=0 ;i < n ; i++){
            if(bills[i] == 5) notes5++;
            else if (bills[i] ==10) {
                if(!notes5) return false;
                notes10++;
                notes5--;
            }
            else {
                if(!notes10) {
                    if(!notes5 || notes5 < 3) return false;
                    else{
                        notes5 -=3;
                        continue;
                    }
                }
                if(!notes5) return false;
                notes10--;
                notes5--;
            }
        }
        return true;
    }
};