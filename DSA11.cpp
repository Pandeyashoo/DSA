class Solution {
public:
    int recur(vector<int>& obstacles,int currlane,int currpos){
        int n=obstacles.size()-1;
        if(currpos==n){
            return 0;
        }
        if(obstacles[currpos+1]!=currlane){
           return recur(obstacles,currlane,currpos+1);
        }
        else{
            int ans=INT_MAX;
            for(int i=1; i<=3; i++){
                if(obstacles[currpos]!=i && currlane!=i ){
                    ans=min(ans,1+recur(obstacles,i,currpos));
                }
            }
            return ans;
        }
        
    }
    int mem(vector<int>& obstacles,int currlane,int currpos,vector<vector<int>>&dp){
        int n=obstacles.size()-1;
        if(currpos==n){
            return 0;
        }
        if(dp[currlane][currpos]!=-1)return dp[currlane][currpos];
        if(obstacles[currpos+1]!=currlane){
           return mem(obstacles,currlane,currpos+1,dp);
        }
        else{
            int ans=INT_MAX;
            for(int i=1; i<=3; i++){
                if(obstacles[currpos]!=i && currlane!=i ){
                    ans=min(ans,1+mem(obstacles,i,currpos,dp));
                }
            }
            dp[currlane][currpos]= ans;
        }
        return dp[currlane][currpos];
    
    }
    int minSideJumps(vector<int>& obstacles) {
       // return recur(obstacles,2,0);
       vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
       return mem(obstacles,2,0,dp);
    }
};