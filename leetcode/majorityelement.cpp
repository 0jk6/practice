//Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        int res = 0;
        for(auto x:mp){
            if(x.second > nums.size()/2)
                res = x.first;
        }
        return res;
    }
};