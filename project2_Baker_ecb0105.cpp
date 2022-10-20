#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#define TOTAL_RUNS 10000
#define A_ACCURACY 1/3
#define B_ACCURACY 1/2
using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    bool valueList[3] = {A_alive, B_alive, C_alive};
    int num_of_true = 0;

    for (int i = 0; i < 3; i++) {
        if valueList[i] == true{
            num_of_true++;
        }
    } 
    
    if (num_of_true >= 2) {
        return true;
    }
    else {
        return false;
    }
}

void test_at_least_two_alive(void){
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));

    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));

    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));

    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));

    cout << "\tCase 5: Aaron dead, Bob dead, Charlie Alive\n";
    assert(false == at_least_two_alive(false, false, true ));

    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));

    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead";
    assert(false == at_least_two_alive(false, false, false));
    }

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    assert(true == B_alive || C_alive);
    int shootResult = rand() % 100;
    if (C_alive) {
        if (shootResult <= A_ACCURACY) {
            C_alive = false;
        }
    }
    else {
        if (shootResult <= A_ACCURACY) {
            B_alive = false;
        }
    }
}

void test_Aaron_shoots1(void) {

}

void Bob_shoots(bool& A_alive, bool& C_alive) {
    assert(true == A_alive || C_alive);
    int shootResult = rand() % 100;
    if (C_alive) {
        if (shootResult <= B_ACCURACY) {
            C_alive = false;
        }
    }
    else {
        if (shootResult <= B_ACCURACY) {
            A_alive = false;
        }
    }
}

void test_Bob_shoots(void) {

}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
    assert(true == A_alive || B_alive);
    int shootResult = rand() % 100;
    if (B_alive) {
        B_alive = false;
    }
    else {
        A_alive = false;
    }
}

void test_Charlie_shoots(void){

}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    assert(true == B_alive, C_alive);
    int shootResult = rand() % 100;
    Bob_shoots(true, C_alive);
    Aaron_shoots1(B_alive, C_alive);
}

void test_Aaron_shoots2(bool& B_alive, bool& C_alive) {

}

void Press_any_key(void) {
    cout << "Press any key to continue...";
    cin.ignore().get();
}

int main() {
    cout << "***Welcome to Elliott's Duel Simulator***\n";
    srand(time(0));
    test_at_least_two_alive();
    Press_any_key();
    test_Aaron_shoots1();
    Press_any_key();
    test_Bob_shoots();
    Press_any_key();
    test_Charlie_shoots();
    Press_any_key();
    test_Aaron_shoots2();
    Press_any_key();

    bool aaronAlive = true;
    bool bobAlive = true;
    bool charlieAlive = true;

    double aaronWins = 0.0;
    double bobWins = 0.0;
    double charlieWins = 0.0; 

    cout << "Ready to test strategy 1 (run 10000 times);\n";
    Press_any_key();
    for(int i = 0; i < TOTAL_RUNS; i++) {
        while (test_at_least_two_alive(aaronAlive, bobAlive, charlieAlive)){
            if (aaronAlive) {
                Aaron_shoots1(bobAlive, charlieAlive);
            }
            if(bobAlive) {
                Bob_shoots(aaronAlive, charlieAlive);
            }
            if(charlieAlive) {
                Charlie_shoots(aaronAlive, bobAlive);
            }
        }
        if (aaronAlive) aaronWins++;
        if (bobAlive) bobWins++;
        if (charlieAlive) charlieWins++;
    }

    cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / 
        TOTAL_RUNS * 100 << "%\n"
        << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS 
        * 100 << "%\n"
        << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / 
        TOTAL_RUNS * 100 << "%\n"
        << endl;
}
