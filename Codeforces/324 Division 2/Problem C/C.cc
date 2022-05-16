#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cassert>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<" "<<__LINE__<<" "
#define tr(x) cerr<<meta<<#x<<" "<<x<<endl;
#define tr2(x,y) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define tr3(x,y,z) cerr<<meta<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr4(w,x,y,z) cerr<<meta<<#w<<" "<<w<<" "<<#x<<" " <<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cerr<<meta<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cerr<<meta<<#u<<" "<<u<<" "<<#v<<" "<<v<<" "<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

using namespace std;

int n, t;
char s1[100100], s2[100100], s3[100100];

int main(){
	sd2(n,t);
	scanf("%s %s", s1, s2);
	
	int dff = 0;
	for(int i = 0; i < n; i++){
		if(s1[i] != s2[i]) dff++;		
	}

	if(dff > 2*t){
		printf("-1"); return 0;
	}
	
	if(dff <= t){
		for(int i = 0; i < n; i++){
			if(s1[i] != s2[i]){
				for(int j = 0; j < 26; j++){
					char c = (char)(j+'a');
					if(c != s1[i] and c != s2[i]){
						s3[i] = c;
						break;
					}
				}
			}
		}
		t -= dff;
		for(int i = 0; i < n; i++){
			if(s1[i] == s2[i]){
				if(t > 0){
					if(s1[i] == 'a') s3[i] = 'b';
					else s3[i] = 'a';
					t--;
				}
				else{
					s3[i] = s1[i];
				}
			}
		}
		s3[n] = '\0';
		printf("%s\n", s3);
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		if(s1[i] == s2[i]){
			if(t < n){
				s3[i] = s1[i];
				t++;
			}
			else{
				if(s1[i] == 'a') s3[i] = 'b';
				else s3[i] = 'a';
			}
		}
	}
	
	int cur = 0;
	for(int i = 0; i < n; i++){
		if(s1[i] != s2[i]){
			if(t < n){
				if(cur == 0){
					s3[i] = s1[i];
					cur ^= 1;
				}
				else{
					s3[i] = s2[i];
					cur ^= 1;
					t++;
				}
			}
			else{
				for(int j = 0; j < 26; j++){
					char c = (char)(j+'a');
					if(c != s1[i] and c != s2[i]){
						s3[i] = c;
						break;
					}
				}
			}
		}
	}
	
	s3[n] = '\0';
	if(t < n){
		printf("-1"); return 0;
	}
	
	printf("%s\n", s3);
	return 0;
}
