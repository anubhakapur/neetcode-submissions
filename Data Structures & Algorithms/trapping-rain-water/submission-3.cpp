class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int n=height.size();
        int l=0,r=n-1;
        int leftMax=0;
        int rightMax=0;
        while(l<r){
            leftMax=max(leftMax,height[l]);
            rightMax=max(rightMax,height[r]);
            if(leftMax<rightMax){
                res+=(leftMax-height[l]);
                l++;
            }else{
                res+=(rightMax-height[r]);
                r--;
            }
        }
        return res;
    }
};
