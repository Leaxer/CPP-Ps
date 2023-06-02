#include <iostream>
#include <time.h>

using namespace std;

int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);

int main()
{
    int humanScore = 0,computerScore = 0;
    srand(time(0));
    while(humanScore < 100 && computerScore < 100) {
        cout<<"Player 1's turn-----------------------------------------------"<<endl;
        humanScore += humanTurn(humanScore);
        if(humanScore >= 100) {
            cout<<"First player won"<<endl;
        }
        cout<<endl;
        cout<<"Player 2's turn-----------------------------------------------"<<endl;
        computerScore += computerTurn(computerScore);
        if(computerScore >= 100) {
            cout<<"Second player won"<<endl;
        }
        cout<<endl;
    }
    return 0;
}

int humanTurn(int humanTotalScore) {
    char input;
    int dice,sum = 0;
    cout<<"Enter any key for first dice"<<endl;
    cin>>input;
    do {
        dice = rand()%6 + 1;
        if(dice == 1) {
            cout<<"Rolled 1"<<endl;
            return 0;
        }else {
            cout<<"Rolled "<<dice<<endl;
            sum += dice;
            cout<<"Player 1's total score is "<<humanTotalScore + sum<<endl;
            if(humanTotalScore+sum >= 100) return sum;
        }
        cout<<"Please enter 'r' to roll again or enter 'h' to hold points"<<endl;
        cin>>input;
        while(input != 'h' && input != 'r') {
            cout<<"You can enter only 'r' or 'h'"<<endl;
            cin>>input;
        }
    }while(input != 'h');
    return sum;
}
int computerTurn(int computerTotalScore) {
    int dice,sum = 0;
    do {
        dice = rand()%6 + 1;
        if(dice == 1) {
            cout<<"Rolled 1"<<endl;
            return 0;
        }else {
            cout<<"Rolled "<<dice<<endl;
            sum += dice;
            cout<<"Player 2's total score is "<<computerTotalScore+sum<<endl;
            if(computerTotalScore+sum >= 100) return sum;
        }
    }while(sum < 20);
    return sum;
}