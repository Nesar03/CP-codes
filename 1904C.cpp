//Author: Md Nesar Ahmad

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxi(v)     *max_element(v.begin(),v.end())
#define mini(v)     *min_element(v.begin(),v.end())
#define rev(v)      reverse(v.begin(), v.end())
#define gcd(a,b)    __gcd(a,b)
#define xnp(v)       for(auto& x:v) cin>>x
#define ceilDiv(x,y)   ((x + y - 1) / y)
#define floorDiv(x,y)  ((x) / (y))
#define vi(n)                vector<int> v(n)
#define vif(v,i,n) for(int i=0; i<n; i++) cin>>v[i];
#define vl(n)                vector<long long> v(n)
#define vb(n)                vector<bool> v(n)
#define vs(n)                vector<string> v(n)
#define vch(n)                vector<char> v(n)
#define vpb(v,x)       v.push_back(x)
#define vpob(v)        v.pop_back()
#define mapi           map<int,int> mpp
#define mapl           map<long,long> mpp
#define mapc           map<char,int> mpp
#define unmap_i        unordered_map<int,int> mpp
#define unmap_l        unordered_map<long,long> mpp
#define unmap_c        unordered_map<char,long> mpp
#define MOD (ll)(1e9+7)



// for sorting -> vector<pair<int,int>> ans;
//  sort(ans.begin(), ans.end(), [](auto &a, auto &b) {
//             if (a.first != b.first) 
//                 return a.first > b.first; // descending gcd
//             return a.second < b.second;  // ascending index
//         });


//just remove some characters from a string
// s.erase(remove(s.begin(), s.end(), x), s.end());

//just to find the firstly appear element index which is greater than any require element
//auto iterator = upper_bound(v.begin(),v.end(),value);


// v.erase(remove_if(v.begin(), v.end(), [](int x){
//     return x % 2 == 0; // remove all even numbers
// }), v.end());

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =



ll power(ll i,ll x){
if(x==0) return 1;
if(x%2==0) return power(i*i,x/2);
return i*power(i*i,(x-1)/2);
}


vector<ll> v(1e6+1);

ll smallestprimefactor(ll n){
  for(int i=0;i<=n;i++) v[i]=i;
  for(int i=2;i*i<=n;i++){
    if(v[i]==i){
      for(int j=i*i;j<=n;j+=i){
        if(v[j]==j){
          v[j]=i;
        }
      }
    }
  }
  return v[n];
}

bool prime(ll n){
  if(n<2) return false;
  if(n<=3) return true;
  if(n%2==0 || n%3==0) return false;
  for(int i=5; i*i<=n; i+=6)
    if(n%i==0 || n%(i+2)==0)
      return false;
  return true;
}

vector<int> primes;

bool primesieve(int n){ // O(nlog(log(n)))
  vector<int> v(n+1);
  v[0]=v[1]=false;
  for(int i=2;i<=n;i++) v[i]=true;
  for(int i=2;i*i<=n;i++){
    if(v[i]){
    for(int j=i*i;j<=n;j+=i) v[j]=false;
    }
  }
  for(int i=2;i<=n;i++){
    if(v[i]) primes.push_back(i);
  }
}

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}

ll lcm(ll a, ll b){
  return (a / gcd(a,b)) * b;
}

ll digit(ll y){
  ll sum=0;
while(y>0){
  sum+=y%10;
  y/=10;
}
return sum;
}


int binaryexpo(int x, int n){
  int res=1;
  while(n){
    if(n%2==1){
      res=(1LL*res*x)%MOD;
    }
    x=(1LL*x*x)%MOD;
    n/=2;
  }
  return res;
}




void solve(){
int n,k; cin>>n>>k;
vector<ll> v(n); vif(v,i,n);
sort(v.begin(),v.end());
if(k>=3){
  cout<<0<<endl;
  return;
}
if(k==1){
  ll mini=*min_element(v.begin(),v.end());
  for(int i=1;i<n;i++){
    mini=min(mini,v[i]-v[i-1]);
  }
  cout<<mini<<endl;
  return;
}
ll ans=v[0];
for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++){
    ll diff=abs(v[j]-v[i]);
    ans=min(ans,diff);
    auto it=lower_bound(v.begin(),v.end(),diff);
    if(it!=v.end()){
      ans=min(ans,abs(*it-diff));
    }
    if(it!=v.begin()){
      --it;
      ans=min(ans,abs(*it-diff));
    }
  }
}
cout<<ans<<endl;
}


int main(){
  smallestprimefactor(1e6);
  int t; cin>>t;
  while(t--){
  solve();
  }
       return 0;
 }