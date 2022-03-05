#include <iostream>
#include <bitset>   // 2진수 비트 헤더파일
#include <cmath>    // 소수점 헤더파일

using namespace std;

int main() {

    // 10진수 "10" 표기법
    int dec = 10;
    int bin = 0b1010;   // 0b숫자
    int oct = 012;      // 0숫자
    int hex = 0xa;      // 0x숫자

    cout << std::dec << dec << endl;    // 10진수
    cout << std::oct << oct << endl;    // 8진수
    cout << std::hex << hex << endl;    // 16진수

    // 2진수 표기법
    char c = static_cast<char>(bin);
    cout << bitset<4>(c) << endl;       // bitset<자릿수>(char)

    cout.unsetf(ios::oct);
    cout.unsetf(ios::hex);

    // 소수점 자릿 수 출력
    double f = 33.33333;
    double nf = -33.33333;
    cout << fixed;
    cout.precision(1); // 소수점 1자리로 고정
    cout << f << endl;

    cout.precision(5);
    cout << f << endl;

    // 소수점 올림, 반올림, 내림, 버림
    cout << ceil(f) << endl;
    cout << round(f) << endl;
    cout << floor(f) << endl;
    cout << trunc(f) << endl;

    // 음수 올림, 반올림, 내림, 버림
    cout << ceil(nf) << endl;
    cout << round(nf) << endl;
    cout << floor(nf) << endl;
    cout << trunc(nf) << endl;

}