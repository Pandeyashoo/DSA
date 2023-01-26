class Solution {
public:
    int recursion(vector<int>&values,int i,int j){
        if(i+1==j)return 0;
        int ans=INT_MAX;
        for(int k=i+1; k<j; k++){
            ans=min(ans,values[i]*values[j]*values[k]+recursion(values,i,k)+recursion(values,k,j));
        }
        return ans;
    }
    int Mem(vector<int>&values,int i,int j,vector<vector<int>>&dp){
         if(i+1==j)return 0;
         int ans=INT_MAX;
         if(dp[i][j]!=-1)return dp[i][j];
         for(int k=i+1; k<j; k++){
            ans=min(ans,values[i]*values[j]*values[k]+Mem(values,i,k,dp)+Mem(values,k,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        //return recursion(values,0,n-1);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return Mem(values,0,n-1,dp);
    }
};