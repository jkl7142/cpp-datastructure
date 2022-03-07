#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <time.h>

#include <Windows.h>	// Sleep()

using namespace std;

// 기준일 (1년 1월 1일)로부터 특정일 사이의 날짜 수(day)
int totalDays(int year, int month, int day) {
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int total = 0;

	// 4로 나눠지는 횟수 - 100으로 나눠지는 횟수(평년) + 400으로 나눠지는 횟수
	total = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	if (year % 4 == 0 && year % 100 > 0 || year % 400 == 0)
		months[1]++;
	for (int i = 0; i < month - 1; i++)
		total += months[i];
	total += day;

	return total;
}

// 특정일의 요일 계산
string weekDay(int days) {
	string week_day[] = { "일", "월", "화", "수", "목", "금", "토" };
	return week_day[days % 7];
}


int main() {

	// 1. 날짜 & 시간 계산 함수
	
	// prev 날짜부터 curr 날까지의 일(day) 수 계산
	int curr = totalDays(2022, 3, 7);
	int prev = totalDays(2022, 1, 1);

	cout << curr - prev << "일 차이\n";	// 차이나는 일 수 출력
	
	string week = weekDay(curr);
	cout << week << "요일 입니다.\n";

	cout << totalDays(2022, 3, 7) - totalDays(2019, 1, 2) << "일 차이\n";

	/////////////////////////////////
	// TODO : 날짜 계산 시 윤년 처리
	/////////////////////////////////

	// 2. 라이브러리를 활용한 시간 계산 (C++ : ctime, C : time.h)

	time_t now;
	time(&now);	// 현재 시간
	cout << ctime(&now);	// time_t 객체를 문자열로 변환
	cout << asctime(localtime(&now)) << "\n";	// tm 구조체를 문자열로 변환


	// time_t 객체를 활용한 시간 차이 계산
	time_t startT = time(NULL);
	//////////////////////
	// 작업 진행
	Sleep(1000);
	//////////////////////
	time_t endT = time(NULL);
	
	double diff = difftime(endT, startT);	// 시간 end - start를 second로 반환
	cout << diff << "\n";	// time()의 경우, 1초 이하는 버림
	

	// clock_t 객체를 활용한 시간 차이 계산
	clock_t startC = clock();
	//////////////////////
	// 작업 진행
	Sleep(1000);
	//////////////////////
	clock_t endC = clock();

	diff = (double)(endC - startC) / CLK_TCK;

	cout << diff << "\n";

	return 0;
}