class Solution {
public:
    int recur(vector<int>& satisfaction,int index,int time){
        int n=satisfaction.size();
        if(index==n)return 0;
        int include=satisfaction[index]*(time+1)+recur(satisfaction,index+1,time+1);
        int exclude=recur(satisfaction,index+1,time);
        return max(include,exclude);
    }
    int Mem(vector<int>& satisfaction,int index,int time,vector<vector<int>>&dp){
        int n=satisfaction.size();
         if(index==n)return 0;
         if(dp[index][time]!=-1)return dp[index][time];
        int include=satisfaction[index]*(time+1)+Mem(satisfaction,index+1,time+1,dp);
        int exclude=Mem(satisfaction,index+1,time,dp);
        dp[index][time]= max(include,exclude);
         return dp[index][time];
    }
    int Tab(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        dp[n][n]=0;
        for(int index=n-1; index>=0; index--){
            for(int time=index; time>=0; time-- ){
                int include=satisfaction[index]*(time+1)+dp[index+1][time+1];
                int exclude=dp[index+1][time];
                dp[index][time]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        //return recur(satisfaction,0,0);
       // int n=satisfaction.size();
       // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       // return Mem(satisfaction,0,0,dp);
       return Tab(satisfaction);
    }
};