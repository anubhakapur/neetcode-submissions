class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>pairs;
        for(int i=0;i<n;i++){
            int diff=target-nums[i];
            if(pairs.find(diff)!=pairs.end())return {pairs[diff],i};
            pairs[nums[i]]=i;
        }
        return {};
    }
};
