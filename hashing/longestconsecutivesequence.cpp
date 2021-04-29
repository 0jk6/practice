class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        
        for(int i=0; i<nums.size(); i++){
            //check if previous element of nums[i] is present in hash map
            //if yes, then nums[i] can't be the start of the sequence
            int prev = nums[i]-1;
            if(mp.find(prev) != mp.end()){
                mp[nums[i]] = false; //prev element is in hashmap, so cur element is false
            }
            else{
                mp[nums[i]] = true; //prev element not in hashmap, so cur element is true
            }
            
            //if nums[i] is start of the sequence then nums[i] + 1 can't be the start
            int next = nums[i]+1;
            if(mp.find(next) != mp.end()){
                mp[next] = false;
            }
        }
        
        int ans = INT_MIN;
        
        for(auto it:mp){
            //if the key value pair has true, then it is the starting sequence
            //from this starting sequence, count the number of consecutive elments
            //and store the max value for all the consecutive sequences
            if(it.second == true){
                int startseq = it.first;
                int count = 0;
                
                while(true){
                    //break if startseq+count is not found in hash map
                    if(mp.find(startseq+count) == mp.end())
                        break;
                    //else increment counter
                    count++;
                }
                
                //store the max value in the ans variable
                ans = max(count, ans);
            }
        }
        return ans;
    }
};