/*
    
    T.C-O(n)
    S.C-O(1)
    
*/

class Solution {  
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long cnt=0;
        int minst=0,maxst=0; // ye index ko store karega 
        int start=0;
        
        bool minf=false,maxf=false; // agar mil jayega to true kar do warna false to h hi
        
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            if(n<minK ||n>maxK){ // yha pe naahi mila ha bhi tak
                minf=false;
                maxf=false;
                start=i+1;
            }
                
            if(n==minK){
                minf=true;// mil gya
                minst=i; // new index asgine kar diya
            }
            if(n==maxK){
                maxf=true;
                maxst=i;
            }
         if(minf && maxf){
                cnt+=(min(minst,maxst)-start+1);
            }   
        }
        return cnt;
    }
};