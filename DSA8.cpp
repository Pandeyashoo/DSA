class Solution {
public:
    int recur(vector<int>&days, vector<int>&costs, int i){
        if(i>=days.size())return 0;
        int option1=costs[0]+recur(days,costs,i+1);
        int k=i;
        for(; k<days.size(); k++){
            if(days[k]>=days[i]+7)break;
        }
        int option2=costs[1]+recur(days,costs,k);
        for(; k<days.size(); k++){
            if(days[k]>=days[i]+30)break;
        }
       // k=i;
        int option3=costs[2]+recur(days,costs,k);
        return min(option1,min(option2,option3));
    }
    int Mem(vector<int>&days, vector<int>&costs, int i,vector<int>&dp){
        if(i>=days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int option1=costs[0]+Mem(days,costs,i+1,dp);
        int k=i;
        for(; k<days.size(); k++){
            if(days[k]>=days[i]+7)break;
        }
        int option2=costs[1]+Mem(days,costs,k,dp);
        for(; k<days.size(); k++){
            if(days[k]>=days[i]+30)break;
        }
       // k=i;
        int option3=costs[2]+Mem(days,costs,k,dp);
        int ans= min(option1,min(option2,option3));
        dp[i]=ans;
        return dp[i];
    }
    int Tab(vector<int>&days,vector<int>&costs){
        int n=days.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1; i>=0; i--){
              int option1=costs[0]+dp[i+1];
        int k=i;
        for(; k<days.size(); k++){
            if(days[k]>=days[i]+7)break;
        }
        int option2=costs[1]+dp[k];
        for(; k<days.size(); k++){
            if(days[k]>=days[i]+30)break;
        }
       // k=i;
        int option3=costs[2]+dp[k];
         dp[i]= min(option1,min(option2,option3));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
       // vector<int>dp(n,-1);
       // return Mem(days,costs, 0,dp);
       return Tab(days,costs);
    }
};