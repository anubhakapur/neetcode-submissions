class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int b=0;b<32;b++){
            int mask=1<<b;
            int x=0,y=0;
            for(int &num:nums){
                if(num & mask)x++;
            }
            for(int i=1;i<n;i++){
                if(i & mask)y++;
            }
            if(x>y)res=res|mask;
        }
        return res;
    }
};