//Hamming Distance
class Solution {
public:
    int hammingDistance(int x, int y) {
        //xor b/w different bits will always be 1
        int res = x^y;
        int c = 0;
        //now count the number of set bits in res
        while(res){
            if(res&1)
                c++;
            res = res >> 1;
        }
        
        return c;
    }
};