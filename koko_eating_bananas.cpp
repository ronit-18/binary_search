class Solution {
public:
bool check(int mid,vector<int>& piles, int h){
     int n = piles.size();
     int m = mid;
     long long count = 0;
     for(int i=0;i<n;i++){
       if(m>piles[i]) count++;
       else if(piles[i] % mid == 0)  count += (long long)(piles[i]/mid);
        else  count += (long long)(piles[i]/mid +1);
        }
        if(count>h) return false;
        else return true;
     }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = INT_MIN;
        for(int i  = 0;i<n;i++){
            if(max<piles[i]) max = piles[i];
        }

        int l = 1;
        int high = max;
        int ans  = max;
        while(l<=high){
            int mid = l + (high-l)/2;
            if(check(mid,piles,h)){
                ans  = mid;
                high = mid-1;
            }
            else {
                l = mid +1;
            }
        }
        return ans;
    }
};
