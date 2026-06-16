class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int &n:nums){
            freq[n]++;
            if(freq[n]==2)return true;
        }
        return false;
    }
};