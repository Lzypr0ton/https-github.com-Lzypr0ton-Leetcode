class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;
        for(auto x:allowed){
            mp[x]=1;
        }
        int ans=0;
        for(auto y:words){
            int key=1;
            for(auto c:y){
                if(mp[c]==0){
                    key=0;
                    break;
                }
            }
            if(key==1)
                ans++;
                
           
        }
         return ans;
    }
};