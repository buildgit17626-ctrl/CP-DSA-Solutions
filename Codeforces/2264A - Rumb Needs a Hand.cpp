// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];

        vector<int>sorted=a;
        vector<int>p;

        sort(sorted.begin(),sorted.end());

        for(int i=0;i<n;i++)
        {
            if(a[i]!=(i+1))
            {
                p.push_back(a[i]);
            }
        }

        int r=p.size()-1;

        for(int i=0;i<n;i++)
        {
            if(a[i]!=(i+1))
            {
                a[i]=p[r--];
            }
        }
        
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=(i+1))
            {
                flag=false;
                break;
            }
        }

        if(flag)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}