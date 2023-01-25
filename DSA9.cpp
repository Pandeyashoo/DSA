//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int recur(vector<vector<int>>&mat,int i,int j, int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        if(i>=row || j>=col){
            return 0;
        }
        int right=recur(mat,i,j+1,maxi);
        int down=recur(mat,i+1,j,maxi);
        int diag=recur(mat,i+1,j+1,maxi);
        if(mat[i][j]==1){
            int ans= 1+min(right,min(down,diag));
            maxi=max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    int mem(vector<vector<int>>&mat,int i,int j, int &maxi,vector<vector<int>>&dp){
        int row=mat.size();
        int col=mat[0].size();
        if(i>=row || j>=col){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right=mem(mat,i,j+1,maxi,dp);
        int down=mem(mat,i+1,j,maxi,dp);
        int diag=mem(mat,i+1,j+1,maxi,dp);
        if(mat[i][j]==1){
            dp[i][j]= 1+min(right,min(down,diag));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    int Tab(vector<vector<int>>&mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){
                int right=dp[i][j+1];
                int down=dp[i+1][j];
                int diag=dp[i+1][j+1];
            if(mat[i][j]==1){
            dp[i][j]= 1+min(right,min(down,diag));
            maxi=max(maxi,dp[i][j]);
           }
            else{
              dp[i][j]=0;
          }
        }
        }
        return 0;
        
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
     //  int solve=recur(mat,0,0,maxi);
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // mem(mat,0,0,maxi,dp);
      Tab(mat,maxi);
       return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends