
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {

    // For Fast Run the Code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {

        int n;
        cin>>n;

        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int j=0;

        for(int i=0;i<n;i++){
            if(a[i]<a[j]){
                j=i;
            }
        }

        bool f=true;
        for(int i=j+1;i<n;i++){
            if(a[i]<a[i-1]){
                f=false;
                break;
            }
        }

        if(f){
            cout<<j<<endl;
        }
        else{
            cout<<-1<<endl;
        }


    }
    
    return 0;
}
