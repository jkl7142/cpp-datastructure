/*
*   Activity 3 : �繫�� ���� �������� �μ� ��� ��� �ùķ��̼�
*/

#include <iostream>
#include <queue>

class Job {
    int id;
    std::string user;
    int pages;

    static int count;

public:
    Job(const std::string& u, int p) : user(u), pages(p), id(++count) {}
    
    friend std::ostream& operator<<(std::ostream& os, const Job& j) {
        os << "id: " << j.id << ", �����: " << j.user << ", ������ ��: " << j.pages << "��";
        return os;
    }
};

int Job::count = 0;

// �޸𸮿� ������ �� �ִ� �ִ� �μ� ��û ������ ���ø� ���ڷ� ����
template<size_t N>
class Printer {
    std::queue<Job> jobs;

public:
    // Job �߰�
    bool addNewJob(const Job& job) {
        if (jobs.size() == N) {
            std::cout << "�μ� ��⿭�� �߰� ����: " << job << std::endl;
            return false;
        }

        std::cout << "�μ� ��⿭�� �߰�: " << job << std::endl;
        jobs.push(job);
        return true;
    }

    // ����Ʈ ����
    void startPrinting() {
        while (!jobs.empty()) {
            std::cout << "�μ� ��: " << jobs.front() << std::endl;
            jobs.pop();
        }
    }
};

int main() {
    // ��⿭�� �ִ� 5�� ����Ʈ ����
    Printer<5> printer;

    Job j1("����", 10);
    Job j2("����", 4);
    Job j3("����", 5);
    Job j4("����", 7);
    Job j5("ä��", 8);
    Job j6("�ÿ�", 10);

    printer.addNewJob(j1);
    printer.addNewJob(j2);
    printer.addNewJob(j3);
    printer.addNewJob(j4);
    printer.addNewJob(j5);
    printer.addNewJob(j6);  // �μ� ��⿭�� ���� �� �־� �߰��� �� ����
    printer.startPrinting();

    printer.addNewJob(j6);
    printer.startPrinting();

    return 0;
}