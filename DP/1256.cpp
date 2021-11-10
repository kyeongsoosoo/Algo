#include <iostream>
#define INF 1e9+7

using namespace std;

int n, m, k;
typedef long long ll;

ll c[201][201];
ll lim;

inline ll avail(int a, int b){ return c[a+b][b]; }

void f(int i, int j, int cnt, int len){
	if(len <= 0) return;
	if(i == 0){
		cout << 'z';
		f(i, j-1, cnt-avail(i-1, j), len-1);
	}
	else if(j == 0){
		cout << 'a';
		f(i-1, j, cnt, len-1);
	}

	else if(avail(i-1, j) >= cnt){
		cout << 'a';
		f(i-1, j, cnt, len-1);
	}else{
		cout << 'z';
		f(i, j-1, cnt-avail(i-1, j), len-1);
	}
}

int main(){
	cin >> n >> m >> k;

	c[1][0] = c[1][1] = 1;
	for(int i=2; i<=200; i++){
		for(int j=0; j<=i; j++){
			c[i][j] = min((ll)1e9+7, c[i-1][j] + c[i-1][j-1]);
		}
	}

	lim = avail(n, m);
	if(k > lim){
		cout << -1; return 0;
	}

	f(n, m, k, n+m);
}