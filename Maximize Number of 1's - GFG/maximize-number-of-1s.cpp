//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int maxOne = 0;   //to store ans means maximum consecutive one
        int flip =0;     //track number of flip we have done
        int i=0;
        int j=0;       //to track previous zero where we done flip to unflip that when required
        
        while(i<n){
            if(arr[i] ==0){
                flip++;
            }
            
            while(flip >m){
                //unflip previous zero because we cant go further
                if(arr[j]==0){
                    flip--;
                }
                j++;
            }
            
            maxOne = max(maxOne,i-j+1);
            i++;
            
            
        }
        
        return maxOne;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends