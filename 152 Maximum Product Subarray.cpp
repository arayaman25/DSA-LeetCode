 #include<iostream>
 using namespace std;
int maxProduct(vector<int>& nums) {
            int n=nums.size();
            int MaxProd=nums[0];
            for(int i=0;i<n;i++){
                int prod=1;
                for(int j=i;j<n;j++){
                    prod*=nums[j];
                    MaxProd=max(MaxProd,prod);
                    if(prod==0) break;
                }
                
            }
            return MaxProd;
    }

int maxProduct2(vector<int>& nums) {
            int n=nums.size();
            int MaxProd=nums[0];
            int pre=1;
            int suf=1;
            for(int i=0;i<n;i++){
                if(pre==0) pre=1;
                if(suf==0) suf=1;
                pre*=nums[i];
                suf*=nums[n-1-i];
                MaxProd=max(MaxProd,max(pre,suf));
                
            }
            return MaxProd;
    }

int main(){
    return 0;
}    