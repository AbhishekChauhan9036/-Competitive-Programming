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

const int N = 200100;
const int M = 32;

int n;

ll a[N + 1], b[N + 1], c[N + 1], k;

bool compute(){
	for(int i = 0; i < N; i++){
		b[i] = (a[i] % 2 != 0)? 1 : 0;
		a[i+1] += (a[i] - b[i]) / 2;
	}

	b[N] = a[N];
	
	if(b[N] < 0) return false; return true;
}

int main(){ _
	cin >> n >> k;
	n++;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) c[i] = a[i];
	
	if(!compute()){
		for(int i = 0; i <= N; i++){
			c[i] = -c[i];
			a[i] = c[i];
		}
		compute();
	}

	int lst = -1;
	for(int i = 0; i <= N; i++) if(b[i]) lst = i;
	
	int fst = -1;
	for(int i = N; i >= 0; i--) if(b[i]) fst = i;
	
	int cnt = 0;
	for(int i = 0; i <= fst; i++){
		if(lst-i+1 > M) continue;
		
		ll num = 0;
		for(int j = lst; j >= i; j--) num = (num << 1) + b[j];
		
		if(i < n and abs(c[i] - num) <= k){
			if(i == n-1 and num == c[i]) continue;
			cnt++;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
