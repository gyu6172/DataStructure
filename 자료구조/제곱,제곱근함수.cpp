#include <stdio.h>
#include <math.h> // pow(), sqrt() �Լ��� ���ǵ� ��� ����

int main(void)
{
    // 2�� 10�°� 2�� 20�� 
    printf("%.0lf, %.0lf\n", pow(2, 10), pow(2, 20)); // 1024, 1048576

    // 9�� ������
    printf("%.0lf\n", sqrt(9)); // 3

    return 0;
}
