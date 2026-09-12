class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int n=height.size();
        int l=0,r=n-1;
        int leftMax=height[0];
        int rightMax=height[n-1];
        while(l<r){
            if(leftMax<rightMax){
                l++;
                leftMax=max(leftMax,height[l]);
                res+=(leftMax-height[l]);
            }else{
                r--;
                rightMax=max(rightMax,height[r]);
                res+=(rightMax-height[r]);
            }
        }
        return res;
    }
};
