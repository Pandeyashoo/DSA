class Solution
{
    public:
    int solveMem(int W, int wt[], int val[], int index, vector<vector<int>>&dp){
         if(index==0){
            if(wt[0]<=W)return val[0];
            else return 0;
        }
        if(dp[index][W]!=-1)return dp[index][W];
        int include=0,exclude=0;
        if(wt[index]<=W){
            include=val[index]+solveMem(W-wt[index],wt, val, index-1,dp);
        }
        exclude=solveMem(W,wt,val,index-1,dp);
        dp[index][W]= max(include,exclude);
        return dp[index][W];
        
    }
    int solveRec(int W,int wt[],int val[],int index){
        if(index==0){
            if(wt[0]<=W)return val[0];
            else return 0;
        }
        int include=0,exclude=0;
        if(wt[index]<=W){
            include=val[index]+solveRec(W-wt[index],wt, val, index-1);
        }
        exclude=solveRec(W,wt,val,index-1);
        return max(include,exclude);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       int value=solveMem(W,wt,val,n-1,dp);
       return value;
    }
};