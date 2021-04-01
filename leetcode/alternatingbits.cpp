//693. Binary Number with Alternating Bits
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n&1;
        n = n>>1;
        while(n){
            if(n&1){
                if(prev==0)
                    prev=1;
                else
                    return false;
            }
            else{
                if(prev==1)
                    prev=0;
                else
                    return false;
            }
            n = n>>1;
        }
        return true;
    }
};