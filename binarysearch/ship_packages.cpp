//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    bool canLoad(vector<int> &weights, int D, int mid){
        int count = 1;
        int wt = 0;
        for(int i=0; i<weights.size(); i++){
            //if weights[i] is greater than mid we can't load it
            //so, return false
            if(weights[i] > mid){
                return false;
            }
            //add up weights[i] to wt variable
            wt += weights[i];
            
            //if wt is greater than mid, then we can say that the current day's
            //capacity is over
            if(wt > mid){
                count++; //it is new day, so, we increment the count
                wt = weights[i]; //update the wt variable for the new day
            }
            //if count is greater than D, return false
            if(count > D){
                return false;
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int low = 0;
        int high = 0;
        
        //high should have a value of total sum of weights
        for(int i=0; i<weights.size(); i++)
            high += weights[i];
        
        int ans = INT_MAX;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(canLoad(weights, D, mid)){
                high = mid-1;
                ans = min(mid, ans); //get the minimum value
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};