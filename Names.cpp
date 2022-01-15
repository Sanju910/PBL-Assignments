#include <bits/stdc++.h>
using namespace std; 

int main() {
    set<string>s;
    string p;
    int n;
    cout<<"\nEnter the number of names to be sorted: ";
    cin>>n;
    while(n--){
        cout<<"\nEnter the name: "<<endl;
        cin>>p;
        s.insert(p);
    }
    
    cout<<"\nNames arranged in alphabetic order:\n\n";
    for(auto i:s){
        cout<<i<<"\n";
    }
    return 0;
}
