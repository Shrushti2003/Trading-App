#include<bits/stdc++.h>    // This header file is usedfor competitive coding ,which includes most of standard library like vector,iostream ,algorithms for using in one go.
using namespace std;
class Account{
int dogecoin, balance;
int bitcoin;
int deposit; 
int withdraw;
int total_equity = 100;
int predict;
int dogecoin_value;
int  bitcoin_value;
int crypto_invest;
int crypto_return;

vector<pair<string,int>> transactions; // vector declared for "transactions" to make an dynamic array that can grow or shrink in size as needed & can store anonoymous number as per the size.
                                       // where string stores description of the transaction (like "Deposit", "Withdraw", "Bitcoin Sold", etc.) & the int stores the amount of money.

public:
bool Deposit(int money){       
    deposit += money;                    // deposit = deposit + money;
    balance += money;                     // balance = balance + money;
    transactions.push_back({"Deposit : ", money});
}
void get_Account_Information(){
    cout<<" Money Details : \n";
    cout<<" Bank Balance : "<<balance<<endl;
    cout<<" Dogecoin : "<<dogecoin<<endl;
    cout<<" Bitcoin : "<<bitcoin<<endl;
}
bool Withdraw(int money){
    if(money > balance){
        return false;
    }
    withdraw += money;
    balance -= money;
    transactions.push_back({"Withdraw : ", money});
    return true;
}
bool buy_crypto(){
    /*
    int option;
    cout<<" Want to purchase Dogecoin press 1 else "
           "Bitcoin press 2 \n";
    cin>>option;
    
    // checking equity
    if(total_equity != 0){
        srand(time(NULL));
        int luck = rand();
        // Checking if random number is divisible by
            // 251 to check (random case for buying  crypto
            // used)
        if(luck % 251 == 0){
        if(option == 1){
        dogecoin += 1;                       //  one unit of Dogecoin is being added to the user's holdings.account
        balance -= dogecoin_value;
        crypto_invest += (dogecoin)*dogecoin_value;
        }
        else{
        bitcoin += 1;
        balance -= bitcoin_value;
        crypto_invest += bitcoin_value;
        }
          }
        else{
            return false;
        }
         }
        else{
            return false;
        }
        return true;
    }
    */
    // bool buy_crypto(){
    int option;
    cout << "Want to purchase Dogecoin press 1 else Bitcoin press 2 \n";
    cin >> option;

    // Checking equity
    if(total_equity != 0){
        if(option == 1){
            // Check if user has enough balance for Dogecoin
            if(balance >= dogecoin_value){
                dogecoin += 1; // One unit of Dogecoin is being added to the user's holdings
                balance -= dogecoin_value;
                crypto_invest += dogecoin_value;
            } else {
                cout << "Not enough balance to purchase Dogecoin" << endl;
                return false;
            }
        } else if(option == 2){
            // Check if user has enough balance for Bitcoin
            if(balance >= bitcoin_value){
                bitcoin += 1;
                balance -= bitcoin_value;
                crypto_invest += bitcoin_value;
            } else {
                cout << "Not enough balance to purchase Bitcoin" << endl;
                return false;
            }
        } else {
            cout << "Invalid option selected" << endl;
            return false;
        }
    } else {
        cout << "No equity available for crypto purchase" << endl;
        return false;
    }
    return true;
}

       
    bool sell_crypto(){
        
        int option;
        cout<<" Want to Sell Dogecoin press 1 else for "
               "Bitcoin press 2 \n";
        cin>>option;
        if(option == 2){
            if(bitcoin == 0)
                return false;
                crypto_return += bitcoin_value;
                balance += bitcoin_value;
                transactions.push_back({"Bitcoin Sold: ", bitcoin_value});
                bitcoin -= 1;
        }
            else{
                if(dogecoin == 0)
                    return false;
                crypto_return += dogecoin_value;
                balance += dogecoin_value;
                transactions.push_back({"Dogecoin Sold : ", dogecoin_value});
                dogecoin -= 1;
            }
            return true;
        }   
        

      /**
    int option;
    cout << "Want to Sell Dogecoin press 1 else for Bitcoin press 2 \n";
    cin >> option;

    if (option == 1) {
        // Selling Dogecoin
        if (dogecoin > 0) {
            // Logic to sell Dogecoin
            // ...
            return true;
        } else {
            cout << "Not enough Dogecoin to sell" << endl;
            return false;
        }
    } else if (option == 2) {
        // Selling Bitcoin
        if (bitcoin > 0) {
            // Logic to sell Bitcoin
            // ...
            return true;
        } else {
            cout << "Not enough Bitcoin to sell" << endl;
            return false;
        }
    } else {
        cout << "Invalid option selected" << endl;
        return false;
    }
}    */

    void History(){
        cout<<"Displaying all transactions \n";
        for(auto it : transactions){
            cout<<it.first<<" "<<it.second<<endl;
        }
        char temp;
        cout<<"Do you want to clear all transactions: Y or N \n";    // Yes or No
        cin>>temp;
        int N = transactions.size();
        if(temp == 'Y'){
            transactions.clear();
            cout<<"Total Transaction cleared! "<<N<<endl;
            
        }
        else{
            cout<<" Total Transactions : "<<N<<endl;
        }
    }

        Account(){
            crypto_invest = 0;
            crypto_return = 0;
            total_equity = 100;

            balance = 50000;
            dogecoin = 0;
            bitcoin = 0;
            withdraw = 0;
            deposit = 0;
            dogecoin_value = 100;
            bitcoin_value = 500;

        }
    };

    int main(){
        Account Person;
        int amount, choice;
        while(1){
            cout<<" ";
                  "*****************************************************";
                      "**************************************** \n";
        cout<<endl;
        cout<<"Press 1 if you want to have your Account Info"<<endl;
        cout<<"Press 2 if you want to Deposit your money"<<endl;
        cout<<"Press 3 if you want to Withdraw your money"<<endl;
        cout<<"Press 4 if you want to know your Account History"<<endl;
        cout<<"Press 5 if you want to know your Buy Crypto "<<endl;
        cout<<"Press 6 if you want to know your Sell Crypto"<<endl;
        cout<<"Else press any invalid key for exit \n";
        cout<<" ";
              "*****************************************************";
                   "**************************************** \n";
        cout<<endl;
        cin>>choice;
        int ans;
        switch(choice){
        case 1 :
        Person.get_Account_Information();
        break;

        case 2:
        cout<<"Enter amount for Deposit : ";
        cin>>amount;
        ans = Person.Deposit(amount);
        if(ans)
            cout<<"Successfully deposited money"<<endl;
            else
                cout<<"Failed \n";
            break;

        case 3:
        cout<<"Enter amount for Withdrawal : ";
        cin>>amount;
        ans = Person.Withdraw(amount);
        if(ans)
            cout<<"Successfully withdrawn amount"<<endl;
            else
                cout<<"Not enough balance left \n";
            break;
        
        case 4:
        Person.History();
        break;

        case 5:
        ans = Person.buy_crypto();
        if(ans)
            cout<<"Successful Transaction"<<endl;
        else
            cout<<"Better luck next time! \n";
        break;

        case 6:
        ans = Person.sell_crypto();
        if(ans)
            cout<<"Successful Transaction"<<endl;
        else
            cout<<"Not enough Cryptocoins \n";
        break;

        default:
        exit(0);
        break;
        }
    }     
 }
    
    

