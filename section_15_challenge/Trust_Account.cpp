#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate, 
                             int num_withdrawals)
    : Savings_Account{name, balance, int_rate}, num_withdrawals {num_withdrawals}
{
    ; 
}

bool Trust_Account::deposit(double amount)
{
    if (amount >= 5000.0)
    {
        amount += 50.0;
    }

    return Savings_Account::deposit(amount); 
}

bool Trust_Account::withdraw(double amount)
{
    if ((amount > (0.2 * balance)) || (num_withdrawals == 3))
    {
        return false; 
    }
    else 
    {
        ++num_withdrawals; 
        return Savings_Account::withdraw(amount); 
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

/*** end of file ***/