#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int Binomial_Coefficient(int n,int k)
{
    int res=1;
    // Since C(n, k) = C(n, n-k) 
    if(k>n-k)
    k=n-k;
    for(int i=0;i<k;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int32_t main(){
fast
int n,k;
cin>>n>>k;
cout<<"C(n,k) : "<<Binomial_Coefficient(n,k);
return 0;
}
/*Complexity Analysis:

Time Complexity: O(k).
A loop has to be run from 0 to k. So, the time complexity is O(k).
Auxiliary Space: O(1).
As no extra space is required.*/