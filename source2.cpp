#include <iostream>
#include "Simple.h"
int main(void) {
	BestCom::Simple();
	ProgCom::Simple();

	return 0;
}

// 헤더파일 : main을 제외한 함수 '선언'
// 소스파일1 : main을 제외한 함수 '정의'
// 소스파일2 : main 실행
// 헤더를 제외한 파일은 다른 곳에 '헤더파일 선언'
