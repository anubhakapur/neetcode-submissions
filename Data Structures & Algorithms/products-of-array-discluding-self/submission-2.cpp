class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        vector<int>prefixProd(n,1),suffixProd(n,1);
        int prod=nums[0];
        for(int i=1;i<n;i++){
            prefixProd[i]=prod;
            prod=prod*nums[i];
        }
        prod=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixProd[i]=prod;
            prod=prod*nums[i];
        }
        for(int i=0;i<n;i++){
            res[i]=prefixProd[i]*suffixProd[i];
        }
        return res;
    }
};
