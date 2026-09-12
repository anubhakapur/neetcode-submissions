class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int leftMaxHeight=i,rightMaxHeight=i;
            for(int j=0;j<i;j++){
                if(heights[j]>=heights[i]){
                    leftMaxHeight=j;
                    break;
                }
            }
            for(int j=n-1;j>i;j--){
                if(heights[j]>=heights[i]){
                    rightMaxHeight=j;
                    break;
                }
            }
            res=max(res,(rightMaxHeight-leftMaxHeight)*heights[i]);
        }
        return res;
    }
};
