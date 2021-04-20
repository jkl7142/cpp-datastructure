/*
*   Activity 2 : 카드 게임 시뮬레이션
*/

#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>

struct card {

    int number;

    enum suit {
        HEART,
        SPADE,
        CLUB,
        DIAMOND
    } suit;

    // 카드 정보 출력
    std::string to_string() const {
        std::ostringstream os;
        if (number > 0 && number <= 10)
            os << number;
        else {
            switch (number) {
            case 1:
                os << "Ace";
                break;
            case 11:
                os << "Jack";
                break;
            case 12:
                os << "Queen";
                break;
            case 13:
                os << "King";
                break;
            default:
                return "Invalid card";
            }
        }

        os << " of ";

        switch (suit) {
        case HEART:
            os << "hearts";
            break;
        case SPADE:
            os << "spades";
            break;
        case CLUB:
            os << "clubs";
            break;
        case DIAMOND:
            os << "diamonds";
            break;
        }

        return os.str();
    }
};

struct game {
    std::array<card, 52> deck;
    std::vector<card> player1, player2, player3, player4;

    // deck 배열에 카드 52장 생성
    void buildDeck() {
        for (int i = 0; i < 13; i++)
            deck[i] = card {i + 1, card::HEART};
        for (int i = 0; i < 13; i++)
            deck[i + 13] = card {i + 1, card::SPADE};
        for (int i = 0; i < 13; i++)
            deck[i + 26] = card {i + 1, card::CLUB};
        for (int i = 0; i < 13; i++)
            deck[i + 39] = card {i + 1, card::DIAMOND};
    }

    // 카드를 섞고 player에게 나눠주기
    void dealCards() {
        // std::chrono::system_clock::now() : 현재 시간
        // now().time_since_epoch() : 현재 시간과 epoch 시간 차
        // now().time_since_epoch().count() : 초 단위로 변환
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        // shuffle(begin, end, g) : begin부터 end까지 g(난수)에 의해 셔플
        // std::default_random_engine(seed) : mt19937 엔진으로 seed에 맞춰 난수 생성
        std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));

        player1 = {deck.begin(), deck.begin() + 13};
        player2 = {deck.begin() + 13, deck.begin() + 26};
        player3 = {deck.begin() + 26, deck.begin() + 39};
        player4 = {deck.begin() + 39, deck.end()};
    }

    // 게임 로직 : 카드를 비교하여 숫자가 같으면 제거
    bool compareAndRemove(std::vector<card>& p1, std::vector<card>& p2) {
        if (p1.back().number == p2.back().number) {
            p1.pop_back();
            p2.pop_back();
            return true;    // 같으면 true
        }
        return false;       // 다르면 false
    }

    // 라운드 로직
    void playOneRound() {
        // player1 기준으로 비교
        if (compareAndRemove(player1, player2)) {
            compareAndRemove(player3, player4);
            return;
        }
        else if (compareAndRemove(player1, player3)) {
            compareAndRemove(player2, player4);
            return;
        }
        else if (compareAndRemove(player1, player4)) {
            compareAndRemove(player2, player3);
            return;
        }
        // player2 기준으로 비교 (player1은 다른 player와 겹치는 카드가 없다)
        else if (compareAndRemove(player2, player3)) {
            return;
        }
        else if (compareAndRemove(player2, player4)) {
            return;
        }
        // player1, 2는 겹치는 카드가 없어 나머지 비교
        else if (compareAndRemove(player3, player4)) {
            return;
        }

        // 일치하는 카드가 없으면 player들의 카드를 다시 셔플
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(player1.begin(), player1.end(), std::default_random_engine(seed));
        std::shuffle(player2.begin(), player2.end(), std::default_random_engine(seed));
        std::shuffle(player3.begin(), player3.end(), std::default_random_engine(seed));
        std::shuffle(player4.begin(), player4.end(), std::default_random_engine(seed));
    }

    // 게임 종료 검사
    bool isGameComplete() const {
        return player1.empty() || player2.empty() || player3.empty() || player4.empty();
    }

    // 게임이 안 끝났다면 라운드 진행
    void playGame() {
        while (!isGameComplete()) {
            playOneRound();
        }
    }

    // 승자 판별기
    int getWinner() const {
        if (player1.empty())
            return 1;
        if (player2.empty())
            return 2;
        if (player3.empty())
            return 3;
        if (player4.empty())
            return 4;
    }
};

int main() {

    game newGame;
    newGame.buildDeck();
    newGame.dealCards();
    newGame.playGame();
    auto winner = newGame.getWinner();
    std::cout << winner << "번 플레이어가 이겼습니다!" << std::endl;

    return 0;
}