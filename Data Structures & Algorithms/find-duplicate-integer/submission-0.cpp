class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int &num:nums){
            int idxOfNum=abs(num)-1;
            if(nums[idxOfNum]<0)return abs(num);
            nums[idxOfNum]*=-1;
        }
        return -1;
    }
};