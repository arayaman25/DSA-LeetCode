#include <iostream>
using namespace std;
 int beauty(string& s){
        vector<int> freq(26,0);
        int maxFreq=0;
        int minFreq=INT_MAX;
        for(int i=0;i<s.size();i++){
            freq[(s[i]-'a')]++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){       
                maxFreq = max(maxFreq, freq[i]);
                minFreq = min(minFreq, freq[i]);
            }            
        }
        return maxFreq-minFreq;
    }
    int Brute_beautySum(string s) {
        int n=s.size();
        int SumBeauty=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string s2=s.substr(i,j-i+1);
                if(s2.size()!=1){
                    int Beauty=beauty(s2);
                    if(Beauty!=0) SumBeauty+=Beauty;
                }
            }
        }
        return SumBeauty;
        
    }

    // -----------------------------------------------------------------------––––––––---–––-––––––------------------------