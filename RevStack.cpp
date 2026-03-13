#include <iostream>
using namespace std;
void insert(stack<int> &st,int x){
    if(st.size()==0 ){ 
        st.push(x);
        return;
    }
        int a=st.top();
        st.pop();
        insert(st,x);
        st.push(a);
}
    void reverseStack(stack<int> &st) {
        if(st.size()>0){
            int x=st.top();
            st.pop();
            reverseStack(st);
            insert(st,x);

        }
    }
