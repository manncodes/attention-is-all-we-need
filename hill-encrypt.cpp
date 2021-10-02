#include<iostream>
#include<vector>
using namespace std;
int main(){
 int x,y,i,j,k,n;
 cout<<"18BCE0420\nEnter the size of key matrix\n";
 cin>>n;
 cout<<"Enter the key matrix\n";
 int a[n][n];
 for(i=0;i<n;i++){
 for(j=0;j<n;j++){
 cin>>a[i][j];
 }
 }
 cout<<"Enter the message to encrypt\n";
 string s;
 cin>>s;
 int temp = (n-s.size()%n)%n;
 for(i=0;i<temp;i++){
 s+='x';
 }
 k=0;
 string ans="";
 while(k<s.size()){
 for(i=0;i<n;i++){
 int sum = 0;
 int temp = k;
 for(j=0;j<n;j++){
 sum += (a[i][j]%26*(s[temp++]-'a')%26)%26;
 sum = sum%26;
 }
 ans+=(sum+'a');
 }
 k+=n;
 }
 cout<<"\nencrypted message\n";
 cout<<ans<<'\n';
 return 0;
}
