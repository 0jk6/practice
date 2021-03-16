#include <iostream>
#include <queue>
#include <vector>

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //store the distance and the index of that point in the input vector in the maxheap
    priority_queue<pair<float, int>> maxheap;
    for(int i=0; i<points.size(); i++){
        float d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        d = sqrt(d);
        maxheap.push({d, i});
        if(maxheap.size()>k)
            maxheap.pop();
    }
    
    vector<vector<int>> v;
    while(maxheap.size()>0){
        v.push_back(points[pq.top().second]);
        maxheap.pop();
    }
    
    return v;
}

int main(){


	return 0;
}