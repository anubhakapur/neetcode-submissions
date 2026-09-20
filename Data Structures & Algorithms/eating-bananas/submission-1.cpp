class Solution {
public:
    int hoursNeeded(vector<int>& piles, int h,int bananaPerHour){
        int hours=0;
        for(int &pile:piles){
            double hoursReq=(double)pile/bananaPerHour;
            hours+=ceil(hoursReq);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(hoursNeeded(piles,h,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;

        }
        return ans;
    }
};
