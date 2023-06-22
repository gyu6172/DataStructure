#include <stdio.h>
#define MAX(a,b) a>b?a:b
int main() {
	int n;
	scanf("%d",&n);

	//Ʈ�� ǥ���ϴ� 2���� �迭
	//tree[5][3] = 1
	//tree[5][9] = 1 �̸� 5������� �ڽ��� 3���� 9��
	int tree[300][300]={{0}};

	//��� ��ȣ�� ����� �迭
	int arr[300];

	//��� ��ȣ�� ���� ū ��ȣ
	int maxn=0;
	for (int i = 0; i < n; i++) {
		//�Է¹���
		int p,c1,c2;	//�θ���(p), �ڽĳ��1(c1), �ڽĳ��2(c2)
		scanf("%d %d %d",&p,&c1,&c2);

		arr[i] = p;
		tree[p][c1] = 1;
		tree[p][c2] = 1;

		//maxn ������Ʈ
		maxn = MAX(maxn, p);
		maxn = MAX(maxn, c1);
		maxn = MAX(maxn, c2);
	}

	//���� ����� ��. ������ �����ϸ鼭 �ڼ��� 3�� �̻��̸� rst�� �� ����� ��ȣ�� ���� ����.
	int rst = 0;

	for (int i = 0; i < n; i++) {
		//arr[i]�� ����� �ڽĳ�尡 ����� ���� cnt
		int cnt = 0;

		//arr[i]�� ����� �ڽ��� �� ã��
		for (int j = 0; j < n; j++) {
			if (tree[arr[i]][arr[j]] == 1) {
				//ã���� cnt 1����
				cnt++;
				for (int k = 0; k < n; k++) {
					//arr[j]�� ����� �ڽ��� �� ã��
					if (tree[arr[j]][arr[k]] == 1) {
						//ã���� cnt 1����
						cnt++;
						//arr[k]�� ����� �ڽ��� �� ã��
						for (int l = 0; l < n; l++) {
							if (tree[arr[k]][arr[l]] == 1) {
								//ã���� cnt 1 ����
								cnt++;
							}
						}
					}
				}
			}
		}
		//�ڼ��� 3�� �̻��̸�
		if (cnt >= 3) {
			//rst�� �� ����� ��ȣ ����
			rst += arr[i];
		}
	}

	printf("%d",rst);
}