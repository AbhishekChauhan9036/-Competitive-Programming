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

const int N = 100100;

int p[N], rnk[N];
ll sz[N];

ll cur;

void create(int x){
	p[x] = x, rnk[x] = 0, sz[x] = 1;
	return;
}

int find(int x){
	if(x != p[x]) return p[x] = find(p[x]);
	return x;
}

void merge(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return;
	if(rnk[px] > rnk[py]){
		p[py] = px;
		cur += sz[px] * sz[py];
		sz[px] += sz[py];
	}
	else{
		p[px] = py;
		cur += sz[px] * sz[py];
		sz[py] += sz[px];
	}
	if(rnk[px] == rnk[py]) rnk[py] = rnk[py] + 1;
	return;
}


int n, q;

vector<pair<int, pii> > w;
vector<pair<int, pii> > qr;

ll res[3*N];

set<int> comp;
map<int, int> f;

int main(){
	sd2(n,q);
	for(int i = 1; i <= n; i++){
		create(i);
	}
	
	int u, v, wt;
	for(int i = 1; i < n; i++){
		sd3(u,v,wt);
		w.pb(mp(wt, mp(u,v)));
		
		comp.insert(wt);
	}
	
	sort(w.begin(), w.end());
	
	for(int i = 1; i <= q; i++){
		sd2(u,v);
		qr.pb(mp(i, mp(u,v)));
		comp.insert(u);
		comp.insert(v);
	}
	
	int cntt = 0;
	foreach(it, comp){
		f[*it] = ++cntt;
	}

	for(int i = 0; i < w.size(); i++){
		w[i].fi = f[w[i].fi];
	}
	
	for(int i = 0; i < q; i++){
		qr[i].se.fi = f[qr[i].se.fi];
		qr[i].se.se = f[qr[i].se.se];
	}
	
	for(int i = 0; i < w.size(); i++){
		int wt = w[i].fi;
		cur = 0;
		while(i <  w.size() and w[i].fi == wt){
			merge(w[i].se.fi, w[i].se.se);
			i++;
		}
		i--;
		
		res[wt] = cur;
	}
	
	for(int i = 2; i < 3*N; i++){
		res[i] += res[i-1];
	}
	
	for(int i = 0; i < q; i++){
		printf("%lld\n", res[qr[i].se.se] - res[qr[i].se.fi-1]);
	}
	
	return 0;
}
