/*
*   Activity 3 : 사무실 공유 프린터의 인쇄 대기 목록 시뮬레이션
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
        os << "id: " << j.id << ", 사용자: " << j.user << ", 페이지 수: " << j.pages << "장";
        return os;
    }
};

int Job::count = 0;

// 메모리에 저장할 수 있는 최대 인쇄 요청 개수를 템플릿 인자로 받음
template<size_t N>
class Printer {
    std::queue<Job> jobs;

public:
    // Job 추가
    bool addNewJob(const Job& job) {
        if (jobs.size() == N) {
            std::cout << "인쇄 대기열에 추가 실패: " << job << std::endl;
            return false;
        }

        std::cout << "인쇄 대기열에 추가: " << job << std::endl;
        jobs.push(job);
        return true;
    }

    // 프린트 수행
    void startPrinting() {
        while (!jobs.empty()) {
            std::cout << "인쇄 중: " << jobs.front() << std::endl;
            jobs.pop();
        }
    }
};

int main() {
    // 대기열이 최대 5인 프린트 생성
    Printer<5> printer;

    Job j1("광희", 10);
    Job j2("정다", 4);
    Job j3("현수", 5);
    Job j4("유미", 7);
    Job j5("채원", 8);
    Job j6("시원", 10);

    printer.addNewJob(j1);
    printer.addNewJob(j2);
    printer.addNewJob(j3);
    printer.addNewJob(j4);
    printer.addNewJob(j5);
    printer.addNewJob(j6);  // 인쇄 대기열이 가득 차 있어 추가할 수 없음
    printer.startPrinting();

    printer.addNewJob(j6);
    printer.startPrinting();

    return 0;
}