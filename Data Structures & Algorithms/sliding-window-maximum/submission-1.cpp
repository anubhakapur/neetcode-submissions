class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        int i=0,j=0,n=nums.size();
        int maxElement=nums[0];
        for(;j<k;j++){
            maxElement=max(maxElement,nums[j]);
        }
        res.push_back(maxElement);
        while(j<n){
            maxElement=max(maxElement,nums[j]);
            if(nums[i]>=maxElement){
                maxElement=nums[i+1];
                for(int x=i+1;x<i+k+1;x++){
                    maxElement=max(maxElement,nums[x]);
                }
            }
            i++;j++;
            res.push_back(maxElement);
        }
        return res;
    }
};
