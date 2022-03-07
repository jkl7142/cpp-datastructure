#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <time.h>

#include <Windows.h>	// Sleep()

using namespace std;

// ������ (1�� 1�� 1��)�κ��� Ư���� ������ ��¥ ��(day)
int totalDays(int year, int month, int day) {
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int total = 0;

	// 4�� �������� Ƚ�� - 100���� �������� Ƚ��(���) + 400���� �������� Ƚ��
	total = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	if (year % 4 == 0 && year % 100 > 0 || year % 400 == 0)
		months[1]++;
	for (int i = 0; i < month - 1; i++)
		total += months[i];
	total += day;

	return total;
}

// Ư������ ���� ���
string weekDay(int days) {
	string week_day[] = { "��", "��", "ȭ", "��", "��", "��", "��" };
	return week_day[days % 7];
}


int main() {

	// 1. ��¥ & �ð� ��� �Լ�
	
	// prev ��¥���� curr �������� ��(day) �� ���
	int curr = totalDays(2022, 3, 7);
	int prev = totalDays(2022, 1, 1);

	cout << curr - prev << "�� ����\n";	// ���̳��� �� �� ���
	
	string week = weekDay(curr);
	cout << week << "���� �Դϴ�.\n";

	cout << totalDays(2022, 3, 7) - totalDays(2019, 1, 2) << "�� ����\n";

	/////////////////////////////////
	// TODO : ��¥ ��� �� ���� ó��
	/////////////////////////////////

	// 2. ���̺귯���� Ȱ���� �ð� ��� (C++ : ctime, C : time.h)

	time_t now;
	time(&now);	// ���� �ð�
	cout << ctime(&now);	// time_t ��ü�� ���ڿ��� ��ȯ
	cout << asctime(localtime(&now)) << "\n";	// tm ����ü�� ���ڿ��� ��ȯ


	// time_t ��ü�� Ȱ���� �ð� ���� ���
	time_t startT = time(NULL);
	//////////////////////
	// �۾� ����
	Sleep(1000);
	//////////////////////
	time_t endT = time(NULL);
	
	double diff = difftime(endT, startT);	// �ð� end - start�� second�� ��ȯ
	cout << diff << "\n";	// time()�� ���, 1�� ���ϴ� ����
	

	// clock_t ��ü�� Ȱ���� �ð� ���� ���
	clock_t startC = clock();
	//////////////////////
	// �۾� ����
	Sleep(1000);
	//////////////////////
	clock_t endC = clock();

	diff = (double)(endC - startC) / CLK_TCK;

	cout << diff << "\n";

	return 0;
}