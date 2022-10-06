// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // Checking 
    
    vector<Checking_Account> ch_accounts; 
    ch_accounts.push_back(Checking_Account {}); 
    ch_accounts.push_back(Checking_Account {"Luke Skywalker"}); 
    ch_accounts.push_back(Checking_Account {"Kylo Ren", 10}); 
    ch_accounts.push_back(Checking_Account {"Darth Vader", 10000000}); 

    display(ch_accounts); 
    deposit(ch_accounts, 50000); 
    withdraw(ch_accounts, 450); 

    // Trust 

    vector<Trust_Account> tr_accounts; 
    tr_accounts.push_back(Trust_Account {});
    tr_accounts.push_back(Trust_Account {"Eleven"});
    tr_accounts.push_back(Trust_Account {"Steve Harrington", 10000, 0.07});
    tr_accounts.push_back(Trust_Account {"Eddie Munson", 1000000, 0.05});

    display(tr_accounts); 
    deposit(tr_accounts, 5000); 
    withdraw(tr_accounts, 100); 
    withdraw(tr_accounts, 200); 
    withdraw(tr_accounts, 100000); 
    withdraw(tr_accounts, 50); 
    
    return 0;
}

