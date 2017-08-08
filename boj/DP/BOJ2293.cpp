//BOJ
//ID : 2293 / DP
//2017/07/27
//�� 1/2/1�� 1/1/2�� ���� ����� ���� ����� �ϱ� ������
//������ ���� for������ ���� ����.
#include <cstdio>
int n,dp[10001],money[101];
int main() {
	int k;
	scanf("%d%d", &n,&k);
	for (int i = 0; i < n; i++)
		scanf("%d", &money[i]);

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++)
			if(j-money[i]>=0)
				dp[j] += dp[j - money[i]];
	}
	printf("%d", dp[k]);
}

