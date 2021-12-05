#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e4 + 10;
int n;
int q[N], dep[N];
void quick_sort(int l, int r, int now_dep) {
	if (l == r) {
		dep[l] = now_dep++;
		return ;
	}
	if (l > r) {
		return ;
	}
	int tmp_max = -1, index = -1;
	for (int i = l; i <= r; i++)
		if (q[i] > tmp_max) {
			tmp_max = q[i];
			index = i;
		}
	dep[index] = now_dep++;
	quick_sort(l, index - 1, now_dep);
	quick_sort(index + 1, r, now_dep);
}
int main() {
	scanf("%d", &n);
	memset(q,0,sizeof(q));
	memset(dep,0,sizeof(dep));
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	quick_sort(0, n - 1, 0);
	for (int i = 0; i < n; i++){
		if(i==0) printf("%d",dep[i]);
		else printf(" %d", dep[i]);		
	}
	return 0;
}
