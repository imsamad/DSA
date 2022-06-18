#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int product(int n) {
    int prod=1;
    while(n) {
        prod*= (n % 10);
        n/=10;
    }
    return prod;
}

int findNumber(int l, int r) {
    string a=to_string(l);

    string b=to_string(r);
 
    int ans=r;
    for(int i=0; i< b.size(); i++) {
        if(b[i] == '0' ) continue;

        string curr=b;

        curr[i]=((curr[i]-'0')-1)+'0';

        for(int j=i+1; j < curr.size(); j++) curr[j]='9';

        int num =0;
        for(auto c:curr) 
            num=num*10+(c-'0');

        if(num>=1 && product(ans) < product(num))
            ans = num;
    }

    return ans;
}

int main()  {
    int l=4,r=9;
    cout<<findNumber(l,r)<<endl;
    l=51,r=62;
    // cout<<findNumber(l,r)<<endl;

     return 0;
}