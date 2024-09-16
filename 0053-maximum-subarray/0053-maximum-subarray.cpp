class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0;
        int maxsum=0;
        //kadane's Algoritm
        for(int i=0;i<nums.size();i++){
            cursum=cursum+nums[i];
            if(cursum>maxsum || i==0){
               maxsum=cursum; 
            }
            if(cursum<0){
                cursum=0;
            }
        }
        
        return maxsum;
        
    }
};