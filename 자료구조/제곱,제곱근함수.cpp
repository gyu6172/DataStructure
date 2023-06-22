#include <stdio.h>
#include <math.h> // pow(), sqrt() 함수가 정의된 헤더 파일

int main(void)
{
    // 2의 10승과 2의 20승 
    printf("%.0lf, %.0lf\n", pow(2, 10), pow(2, 20)); // 1024, 1048576

    // 9의 제곱근
    printf("%.0lf\n", sqrt(9)); // 3

    return 0;
}
