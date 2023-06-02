#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

const int NUM_DUELS = 10000;

int AaronShoot(int aaron, int &bob, int &charlie);
int BobShoot(int bob, int &charlie, int &aaron);
int CharlieShoot(int charlie, int &bob, int &aaron);

int main(){
    srand(time(0));
    int aaron = 1,bob = 1,charlie = 1,finishGame = 0;
    float aaronScore = 0,bobScore = 0,charlieScore = 0;
    for(int i = 0;i < NUM_DUELS;++i) {
        aaron = 1;
        bob = 1;
        charlie = 1;
        finishGame = 0;
        while(finishGame != 2) {
            if(AaronShoot(aaron,bob,charlie) == 1) {
                ++finishGame;
            }
            if(BobShoot(bob,charlie,aaron) == 1) {
                ++finishGame;
            }
            if(CharlieShoot(charlie,bob,aaron) == 1) {
                ++finishGame;
            }
        }
        if(aaron == 1) {
            ++aaronScore;
            if(i == 0) {
                cout << "Aaron won first round" << endl;
            }
        }else if(bob == 1) {
            ++bobScore;
            if(i == 0) {
                cout << "Bob won first round" << endl;
            }
        }else if(charlie == 1) {
            ++charlieScore;
            if(i == 0) {
                cout << "Charlie won first round" << endl;
            }
        }
    }
    cout << "Aaron won " << aaronScore << "/10000 duels or " << static_cast<double>(aaronScore) / 10000 * 100 << "%" << endl;
    cout << "Bob won " << bobScore << "/10000 duels or " << static_cast<double>(bobScore) / 10000 * 100 << "%" << endl;
    cout << "Charlie won " << charlieScore << "/10000 duels or " << static_cast<double>(charlieScore) / 10000 * 100 << "%" << endl;
    return 0;
}

int AaronShoot(int aaron, int &bob, int &charlie) {
    int num;
    if(aaron == 1) {
        num = rand()%3;
        if(num == 0) {
            if(charlie == 1) {
                charlie = 0;
            }else if(bob == 1) {
                bob = 0;
            }
            return 1;
        }else {
            return 0;
        }
    }else { return 0;}
}

int BobShoot(int bob, int &charlie, int &aaron) {
    int num;
    if(bob == 1) {
        num = rand()%2;
        if(num == 0) {
            if(charlie == 1) {
                charlie = 0;
            }else if(aaron == 1) {
                aaron = 0;
            }
            return 1;
        }else { return 0;}
    }else { return 0;}
}

int CharlieShoot(int charlie, int &bob, int &aaron) {
    int num;    
    if(charlie == 1) {
        if(bob == 1) {
            bob = 0;
        }else if(aaron == 1) {
            aaron = 0;
        }
        return 1;
    }else { return 0;}
}