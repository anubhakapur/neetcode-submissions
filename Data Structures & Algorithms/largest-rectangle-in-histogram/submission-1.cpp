class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            int start=i;
            while(!st.empty() && heights[i]<st.top().second){
                int startIndex=st.top().first;
                int height=st.top().second;
                st.pop();
                int width=i-startIndex;
                maxArea=max(maxArea,height*width);
                start=startIndex;
            }
            st.push({start,heights[i]});
        }
        while(!st.empty()){
                int startIndex=st.top().first;
                int height=st.top().second;
                int width=n-startIndex;
                maxArea=max(maxArea,height*width);
                st.pop();
            }
        return maxArea;
    }
};
