#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 50100;

int n, m;
vector<int> g[N];
unordered_set<int> s[N];
int vis[N];

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= m; i++){
		int u, v; sd2(u,v);
		g[u].pb(v);
		g[v].pb(u);
		s[u].insert(v);
		s[v].insert(u);
	}

	int ans = 0;

	for(int i = 1; i <= n; i++){
		vis[i] = 1;
		for(int &j : g[i]){
			if(vis[j]) continue;
			for(int &k: g[j]){
				if(k == i) continue;
				if(vis[k]) continue;
				for(int &l : g[k]){
					if(l == j or l == i or vis[l]) continue;
					if(s[l].count(i)) ans++;
				}
			}
		}
	}
	
	ans /= 8;
	
	printf("%d\n", ans);
	
	return 0;
}
