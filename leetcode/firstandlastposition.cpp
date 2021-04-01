//34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        vector<int> v;
        
        int res = -1;
        
        //find the first occurence
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(target == nums[mid]){
                end = mid-1;
                res = mid;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        v.push_back(res);
        
        //find the last occurence
        start = 0;
        end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(target == nums[mid]){
                start = mid+1;
                res = mid;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        v.push_back(res);
        
        return v;
    }
};