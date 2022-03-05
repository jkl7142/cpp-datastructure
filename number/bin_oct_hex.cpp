#include <iostream>
#include <bitset>   // 2���� ��Ʈ �������
#include <cmath>    // �Ҽ��� �������

using namespace std;

int main() {

    // 10���� "10" ǥ���
    int dec = 10;
    int bin = 0b1010;   // 0b����
    int oct = 012;      // 0����
    int hex = 0xa;      // 0x����

    cout << std::dec << dec << endl;    // 10����
    cout << std::oct << oct << endl;    // 8����
    cout << std::hex << hex << endl;    // 16����

    // 2���� ǥ���
    char c = static_cast<char>(bin);
    cout << bitset<4>(c) << endl;       // bitset<�ڸ���>(char)

    cout.unsetf(ios::oct);
    cout.unsetf(ios::hex);

    // �Ҽ��� �ڸ� �� ���
    double f = 33.33333;
    double nf = -33.33333;
    cout << fixed;
    cout.precision(1); // �Ҽ��� 1�ڸ��� ����
    cout << f << endl;

    cout.precision(5);
    cout << f << endl;

    // �Ҽ��� �ø�, �ݿø�, ����, ����
    cout << ceil(f) << endl;
    cout << round(f) << endl;
    cout << floor(f) << endl;
    cout << trunc(f) << endl;

    // ���� �ø�, �ݿø�, ����, ����
    cout << ceil(nf) << endl;
    cout << round(nf) << endl;
    cout << floor(nf) << endl;
    cout << trunc(nf) << endl;

}