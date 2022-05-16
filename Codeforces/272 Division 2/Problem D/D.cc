#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, k;

vector<pair<pair<int, int>, pair<int, int> > > res;

int main(){
	sd2(n,k);
	for(int i = 0; i < n; i++){
		res.pb(mp(mp((i*6 + 1)*k, (i*6 + 2)*k), mp((i*6 + 3)*k, (i*6 + 5)*k)));
	}
	
	cout << ((n-1)*6 + 5)*k << endl;
	foreach(it, res){
		printf("%d %d %d %d\n", it->fi.fi, it->fi.se, it->se.fi, it->se.se);
	}
	return 0;
}
