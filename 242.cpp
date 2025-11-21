#include <iostream>
using namespace std;
bool String(string s,string t)
{
    if(s.length()!=t.length())
    {
        return false;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

int main() 
{
    string s,k;
    cin>>s;
    cin>>k;
    bool ns=String(s,k);
    cout<<ns;


    return 0;
}
