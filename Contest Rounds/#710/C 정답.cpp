#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll           long long
#define rep(i,j,n)   for(int i=j;i<n;++i)
#define scn(a)       scanf("%d",&a)
#define scns(a,b)    scanf("%d %d",&a,&b)
#define print(a)     printf("%d\n",a)
#define pb           emplace_back    
#define f            first
#define s            second
#define all(v)       v.begin(),v.end()
#define inf          2e9+7
const int mod = 1e9+7;
const int N = 25;
 
int n, dp[N][N][N][N];
string s1, s2; 
unordered_map<string, int> mp;
 
int rec(int i,int j,int x,int y)
{
    if(i > j) return y-x+1;
    if(x > y) return j-i+1;
 
    string s3 = s1.substr(i, j-i+1), s4 = s2.substr(x, y-x+1);
 
    if(s3 == s4) return 0;
 
    int &ans = dp[i][j][x][y];
 
    if(ans != -1) return ans;
 
    ans = 1 + min({rec(i+1,j,x,y), rec(i,j-1,x,y), rec(i,j,x+1,y), rec(i,j,x,y-1)});
    
    return ans;
}
 
int main()
{
    int test; scn(test);
 
    for(int tt = 1; tt <= test; ++tt)
    {
        cin >> s1 >> s2;
 
        memset(dp, -1, sizeof dp);
        
        print(rec(0, s1.size()-1, 0, s2.size()-1));
    }
 
    return 0;
}