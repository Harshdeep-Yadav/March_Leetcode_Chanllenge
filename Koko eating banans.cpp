/*
        T.C-O(nlogm)
        S.C-O(1)
*/

class Solution {
public:
    bool canEat(vector<int>piles,int k,int h){ // k->mid
        int totTime=0;
        for(auto it : piles){
            int div=it/k;
            totTime+=div;
            if(it%k!=0){
                totTime++;
            }
        }
        return totTime<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=INT_MAX; // 100000000
        while(l<=r){
            int mid=l+(r-l)/2; // this is our k value;
            if(canEat(piles,mid,h))
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};