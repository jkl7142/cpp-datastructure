/*
*   Exercise 16 : �̸��� �ּ� �ߺ� �˻�
*/

#include <iostream>
#include <vector>
#include <openssl/md5.h>

class BloomFilter {
    int nHashes;
    // ��� ����
    std::vector<bool> bits;

    static constexpr int hashSize = 128 / 8;     // 128bits (16bytes)

    // �ؽ� �� ����
    unsigned char hashValue[hashSize];

public:
    BloomFilter(int size, int hashes) : bits(size), nHashes(hashes) {
        if (nHashes > hashSize) {   // 16bytes �̻��� �ؽ� �Լ� ����� �Ұ���
            throw("�ؽ� �Լ� ������ �ʹ� �����ϴ�.");
        }

        if (size > 255) {   // �� �ؽ� ���� 1byte�̹Ƿ� 255�� �ʰ��� �� ����
            throw("��� ���� ũ�Ⱑ 255���� Ŭ �� �����ϴ�.");
        }
    }

    // MD5�� �̿��� �ؽ� �Լ�
    void hash(const std::string& key) {
        MD5(reinterpret_cast<const unsigned char*>(key.data()), key.length(), hashValue);
    }

    // �̸��� �ּ� �߰�
    void add(const std::string& key) {
        hash(key);
        for (auto it = &hashValue[0]; it < &hashValue[nHashes]; it++) {
            bits[*it & bits.size()] = true;
        }

        std::cout << "��� ���Ϳ� �߰�: " << key << std::endl;
    }

    // �̸��� �ּ� �˻�
    bool mayContatin(const std::string& key) {
        hash(key);
        for (auto it = &hashValue[0]; it < &hashValue[nHashes]; it++) {
            if (!bits[*it % bits.size()]) {
                std::cout << key << " : ����� �� �ִ� �̸����Դϴ�." << std::endl;
                return false;
            }
        }

        // ��� ���� ���� ���� true��
        std::cout << key << " : �̹� ��� ���Դϴ�." << std::endl;
        return true;
    }
};

int main() {

    BloomFilter bloom(128, 5);
    bloom.add("abc@gilbut.com");
    bloom.add("xyz@gilbut.com");

    bloom.mayContatin("abc");
    bloom.mayContatin("xyz@gilbut.com");
    bloom.mayContatin("xyz");

    bloom.add("abcd@gilbut.com");
    bloom.add("ab@gilbut.com");

    bloom.mayContatin("abcd");
    bloom.mayContatin("ab@gilbut.com");

    return 0;
}