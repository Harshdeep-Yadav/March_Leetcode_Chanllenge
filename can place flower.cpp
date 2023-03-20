class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int tot=0;
        for(int i=0;i<nums.size()&& tot<n;i++){
            if(nums[i]==0){
                int next=(i==nums.size()-1)?0:nums[i+1];
                int prev=(i==0)?0:nums[i-1];
                if(next==0 && prev==0){
                    nums[i]=1;
                    tot++;
                }
            }
        }
        return tot==n;
    }
};