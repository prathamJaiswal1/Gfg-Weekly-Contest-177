//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int validQueries(string s, string pattern, int q, vector<vector<int>> &queries) {
        // code here
        int n=s.size();
        vector<int>fp(26,0);
        for(auto ch:pattern){
            fp[ch-'a']++;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(26,0));
        for(int i=0;i<n;i++){
            dp[i+1][s[i]-'a']++;
            for(int j=0;j<26;j++){
                dp[i+1][j]+=dp[i][j];
            }
        }
        
        int valid=0;
        for(auto it:queries){
            int left=it[0],right=it[1];
            bool flag=true;
            for(int i=0;i<26;i++){
                if(dp[n][i]-(dp[right+1][i]-dp[left][i]) < fp[i]){
                   flag=false;
                   break;
                }
            }
            if(flag)valid++;
        }
        return valid;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string text;
        cin >> text;

        string pattern;
        cin >> pattern;

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        int res = obj.validQueries(text, pattern, q, queries);

        cout << res << endl;
    }
}

// } Driver Code Ends