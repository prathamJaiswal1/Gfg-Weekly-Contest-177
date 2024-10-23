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
    bool fun(int mid,string &s,string &pat,vector<vector<int>>&que){
         int n=s.size();
         vector<int>d(n+1,0);
         for(int i=0;i<mid;i++){
             int left=que[i][0],right=que[i][1];
             d[left]++;
             d[right+1]--;
         }
         for(int i=1;i<=n;i++){
             d[i]+=d[i-1];
         }
         
         vector<int>f(26,0);
         for(int i=0;i<n;i++){
             if(d[i]==0){
                 f[s[i]-'a']++;
             }
         }
         
         bool valid=true;
         for(auto ch:pat){
             f[ch-'a']--;
             if(f[ch-'a'] < 0) {
                 valid=false;break;
             }
         }
         return valid;
         
    }
    int validQueries(string s, string pat, int q, vector<vector<int>> &queries) {
        // code here
        int low=0,high=q;
        while(low <= high){
            int mid=(low+high)>>1;
            if(fun(mid,s,pat,queries)){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return max(high,0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string text;
        getline(cin, text);

        string pattern;
        getline(cin, pattern);

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