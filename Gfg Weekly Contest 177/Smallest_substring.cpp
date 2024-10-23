//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string smallestSubstring(string s, int k) {
        // code here
        int i=0,j=0;
        int ans=INT_MAX,sum=0;
        int st=-1,e=-1;
        while(j<s.size()){
            sum+=s[j];
            if(j-i+1 == k){
                if(ans > sum){
                    st=i;
                    e=j;
                    ans=sum;
                }
                sum-=s[i];
                i++;
            }
            j++;
        }
        return s.substr(st,e-st+1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string str;
        cin >> str;

        int k;
        scanf("%d", &k);

        Solution obj;
        string res = obj.smallestSubstring(str, k);

        cout << res << "\n";
    }
}

// } Driver Code Ends