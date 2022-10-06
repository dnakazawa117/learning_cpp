#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    try {
        unique_ptr<Account> account1 = 
            make_unique<Checking_Account>("Denis", -100.0);
    } catch (const IllegalBalanceException &ex) {
        cerr << ex.what() << endl; 
    }

    unique_ptr<Account> account2 = make_unique<Checking_Account>("Sarahi", 100.0);
    try {
        account2->withdraw(800.0); 
    } catch (const InsufficientFundsException &ex) {
        cerr << ex.what() << endl; 
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

