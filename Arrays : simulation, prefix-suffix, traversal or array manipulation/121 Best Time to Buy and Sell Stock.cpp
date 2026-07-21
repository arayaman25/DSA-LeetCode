#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include <unordered_map>
using namespace std;
int maxProfitBrute(vector<int>& prices) {
    int n = prices.size();
    if(n == 0) return 0;

    int maxProfit = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int profit = prices[j] - prices[i];
            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
    }
    
    return maxProfit;
}

int maxProfitOptimal(vector<int>& prices) {
    int n = prices.size();
    if(n == 0) return 0;
    int mini = prices[0];
    int maxProfit = 0;
    
    for(int i = 0; i < n; i++){
        int cost=prices[i]-mini;
        maxProfit=max(maxProfit,cost);
        mini=min(mini,prices[i]);    
    }
    
    return maxProfit;
}

int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
