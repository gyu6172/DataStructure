#include <stdio.h>
#define MAX(a,b) a>b?a:b
int main() {
	int n;
	scanf("%d",&n);

	//트리 표현하는 2차원 배열
	//tree[5][3] = 1
	//tree[5][9] = 1 이면 5번노드의 자식은 3번과 9번
	int tree[300][300]={{0}};

	//노드 번호가 저장될 배열
	int arr[300];

	//노드 번호중 가장 큰 번호
	int maxn=0;
	for (int i = 0; i < n; i++) {
		//입력받음
		int p,c1,c2;	//부모노드(p), 자식노드1(c1), 자식노드2(c2)
		scanf("%d %d %d",&p,&c1,&c2);

		arr[i] = p;
		tree[p][c1] = 1;
		tree[p][c2] = 1;

		//maxn 업데이트
		maxn = MAX(maxn, p);
		maxn = MAX(maxn, c1);
		maxn = MAX(maxn, c2);
	}

	//최종 출력할 값. 연산을 진행하면서 자손이 3개 이상이면 rst에 그 노드의 번호를 더할 것임.
	int rst = 0;

	for (int i = 0; i < n; i++) {
		//arr[i]번 노드의 자식노드가 저장될 변수 cnt
		int cnt = 0;

		//arr[i]번 노드의 자식을 쭉 찾음
		for (int j = 0; j < n; j++) {
			if (tree[arr[i]][arr[j]] == 1) {
				//찾으면 cnt 1증가
				cnt++;
				for (int k = 0; k < n; k++) {
					//arr[j]번 노드의 자식을 쭉 찾음
					if (tree[arr[j]][arr[k]] == 1) {
						//찾으면 cnt 1증가
						cnt++;
						//arr[k]번 노드의 자식을 쭉 찾음
						for (int l = 0; l < n; l++) {
							if (tree[arr[k]][arr[l]] == 1) {
								//찾으면 cnt 1 증가
								cnt++;
							}
						}
					}
				}
			}
		}
		//자손이 3개 이상이면
		if (cnt >= 3) {
			//rst에 그 노드의 번호 더함
			rst += arr[i];
		}
	}

	printf("%d",rst);
}