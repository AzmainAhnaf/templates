// stress test to following problem
// link: https://codeforces.com/contest/2228/problem/C2

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//definition section//////
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define pf push_front
#define pill(x,y) memset(x,y,sizeof(x));
#define X first
#define Y second
#define IN insert
#define endl '\n'
#define UB(a,x) upper_bound(a.begin(),a.end(),x)
#define GT(x) greater<x>()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define PQ priority_queue
#define Graph vector<vector<ll>>
//#define fix(p) cout << fixed << setprecision(p)
using namespace std;
using ll = long long;
using ld = long double;
///////constants///////
const ll mod = 1e9+7;
const ll MOD = 998244353;
const ll INF = 1e18;
const ll nax = 1e9;
const ll mxi = 2000005;
const ll mxt = 1e4+4;
ll dx[4] = {1,0,0,-1};//d l r u
ll dy[4] = {0,-1,1,0};
/////pbds/////
template<class T>
using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; //multiset-less_equal
/////Global Vars///
//////functions////
void solve(ll tt){
  string a;ll n;cin >> a >> n;
  ll na = a.size();
  ll d[n+3]={};for(ll i =1; i<=n; i++){cin >> d[i];}
  //bigger 
  ll f=0ll;
  string p;
  for(ll i =0; i<na; i++){
    if(f){p+=(d[1ll]+'0');continue;}
    auto it = lower_bound(d+1ll,d+n+1ll, (a[i]-'0'));
    if(it==(d+n+1ll)){
      for(ll j = i-1ll;j>=0;j--){
        auto itc = upper_bound(d+1ll,d+n+1ll,(a[j]-'0'));
        if(itc==(d+n+1ll)){p="";break;}
        p[j] = (*itc)+'0';
        f = 1ll;
        break;
      }
      if(f==0ll){p="";break;}
      p+= (d[1]+'0');
      continue;
    }
    if(*it==(a[i]-'0')){
      p+=((*it)+'0');
      continue;
    }
    f =1ll;p+=((*it)+'0');
  }
  if(p.empty()) p ="0";
  ll ans = abs(stoll(p)-stoll(a));
  string q;
  if(d[1]==0){
    if(n>=2ll){
      q+=(d[2ll]+'0');for(ll i =0; i<na; i++) q+='0';
    }else q = (d[1ll]+'0');
  }
  else for(ll i =0; i<na+1; i++) q+=(d[1ll]+'0');
  if(p.empty()) p =d[1]+'0';
  if(q.empty()) q =d[1]+'0';


  ans = min(abs(stoll(q)-stoll(a)),ans);
  //small
  f=0ll;
  p ="";
  for(ll i =0; i<na; i++){
    if(f){p+=(d[n]+'0');continue;}
    auto it = lower_bound(d+1ll,d+n+1ll, (a[i]-'0'));
    if(*it==(a[i]-'0')){
      p+=((*it)+'0');
      continue;
    }
    it--;
    if(it==(d)){
      for(ll j = i-1ll;j>=0;j--){
        auto itc = lower_bound(d+1ll,d+n+1ll,(a[j]-'0'));
        itc--;
        if(itc==(d)){p="";break;}
        p[j] = (*itc)+'0';
        f = 1ll;
        break;
      }
      if(f==0ll){p="";break;}
    }
    f =1ll;p+=((*it)+'0');
  }
  q="";for(ll i =0; i<na-1ll; i++) q+=(d[n]+'0');
  if(p.empty()) p =d[1]+'0';
  if(q.empty()) q =d[1]+'0';
  ans = min(abs(stoll(p)-stoll(a)),ans);
  ans = min(abs(stoll(q)-stoll(a)),ans);
  cout << ans;





}
////////////////////////////////////////////////
int main(){                                   //
    fast();                                   //
    //fix(7);
    //sieve();                                //
    //init();                                 //
    //freopen("input.txt","r", stdin);        //
    //freopen("output.txt", "w", stdout);     //
    //ll tt = 1;                              //
////////////////////////////////////////////////
    ll T;
    T = 1;
    ll tt=0;
    cin >> T;
    while(T--){
        //cout << "Case " << ++tt << ": ";;
        solve(++tt);
        cout << endl;
    }
}
