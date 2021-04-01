//Daily Temperatures
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> s;
        vector<int> v;
        
        for(int i=T.size()-1; i>=0; i--){
            if(s.size()==0){
                v.push_back(0);
            }
            else if(s.size()>0 && s.top().first > T[i]){
                v.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first <= T[i]){
                while(s.size()>0 && s.top().first <= T[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(0);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
            s.push({T[i], i});
        }
        reverse(v.begin(), v.end());
        
        for(int i=0; i<T.size(); i++){
            int a = v[i]-i;
            if(a>0){
                v[i]=a;
            }
            else{
                v[i]=0;
            }
        }
        return v;
    }
};