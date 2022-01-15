#include <bits/stdc++.h> 
using namespace std;
void findRepeat(int* a, int n){
//Declare the map
unordered_map<int,int> hash;
for(int i=0;i<n;i++){
 hash[a[i]]++;
}
for(auto it=hash.begin();it!=hash.end();it++)
if(it->second>1)
 cout<<it->first<<"\t\t"<<it->second<<endl;
} 
int main()
{
int n,*a;
cout<<"\nArray length: ";
cin>>n;
a = new int[n];
cout<<"\n\nArray elements..\n\n";
for(int i=0;i<n;i++){
 cin>>a[i];

}
cout<<"\n\n";
//function to print repeating elements with their frequencies
cout<<"\nRepeated numbers with frequencies: "<<endl;
findRepeat(a,n); 
return 0;
}
