//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<long long>ans;  //vector create kiye taki ans wale row ko store kr ke return kr sake
        vector<vector<long long>>row(n);   //vector of vector create kr liye taki har row ko store kr ske
        
        
        
        
        long long m = 1e9+7;   //number (element) ka value bahut jayada ho kr 
        //integer ke range se bahr na ja ske use rokne ke liye module le liye,mention in question   
        
        
        for(long long int i=0; i<n; i++){
            row[i].resize(i+1);   //har row me element ka number alaga alag hai to use initialize kr rahe like first row me ek element 2 row me 2 element 
            
            row[i][0]=1;  //ham jante hai first element 1 hi hoga to use initialize kr liye 
            row[i][i]=1;    ////ham jante hai last element 1 hi hoga to use initialize kr liye 
            
            for(int j=1; j<i; j++){
                row[i][j]= (row[i-1][j-1] + row[i-1][j]) %m;   //same row ke next element ka value calculate kr rahe 
                //value pichle row(i-1) ke previouse column number (j-1) + pichle row ka same col number (j)
                //value out of range na jaye isliye modulo kr de rahe 
            }
            
            if(i==(n-1))   //nth row pe pahunch gye iska hame element return krna hai answer me
            {
                for(auto k:row[i])   //us row ka sara element ko apne ans me store kr le rahe 
                {
                    ans.push_back(k);
                }
            }
        }
        return ans; //ans return kr de rahe
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends