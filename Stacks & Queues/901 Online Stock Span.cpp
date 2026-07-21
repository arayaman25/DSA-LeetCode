#include<iostream>
using namespace std;
//brute
class StockSpanner {
public:
    vector<int> arr;

    StockSpanner() {
    }
    
    int next(int price) {
        arr.push_back(price);
        int cnt=1;
        for(int i=arr.size()-2;i>=0;i){
            if(arr[i]<=price) cnt++;
            else break;
        }
        return cnt;
    }
};

//--------------------------------------------------

//optimal
class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind=-1;
    StockSpanner() {
        ind=-1;
        while(!st.empty()) st.pop();
    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans=ind - (st.empty()? -1:st.top().second);
        st.push({price,ind});
        return ans;
    }
};

//--------------------------------------------------