#include "ClipboardXX.hpp"
#include <bits/stdc++.h>
using   namespace  std ;

const string lowercases = "abcdefghijklmnopqrstuvwxyz" ;
const string uppercases = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
const string symbols = "~`!@#$%^&*()_-+={[}]|\\:;'<,>.?/" ;
const string digits = "0123456789" ;
const string hline(65, '-') ;

string generate(int len){
    srand(clock()) ;
    string str ;

    for(int i = 0 ; i < len ; i++){     // push a random character of specific type
        if(i % 4 == 0)
            str.push_back( lowercases[ rand() % lowercases.size() ] ) ;
        else if(i % 4 == 1)
            str.push_back( symbols[ rand() % symbols.size() ] ) ;
        else if(i % 4 == 2)
            str.push_back( uppercases[ rand() % uppercases.size() ] ) ;
        else
            str.push_back( digits[ rand() % digits.size() ] ) ;
        
        random_shuffle(str.begin(), str.end());
    }

    return str ;
}

bool prompt(){  // asks user if he/she wants to continue
    cout << "Try again? (y/n): " ;
    string s ;
    cin >> s ;
    cout << hline << endl ;
    return (s == "y" || s == "Y") ;
}

bool copy_prompt(){
    cout << "Copy to clipbaord? (y/n): " ;
    string s ;
    cin >> s ;
    cout << hline << endl ;
    return (s == "y" || s == "Y") ;
}

int main(){

cout << R"(______                                   _   _____                           _             
| ___ \                                 | | |  __ \                         | |            
| |_/ /_ _ ___ _____      _____  _ __ __| | | |  \/ ___ _ __   ___ _ __ __ _| |_ ___  _ __ 
|  __/ _` / __/ __\ \ /\ / / _ \| '__/ _` | | | __ / _ \ '_ \ / _ \ '__/ _` | __/ _ \| '__|
| | | (_| \__ \__ \\ V  V / (_) | | | (_| | | |_\ \  __/ | | |  __/ | | (_| | || (_) | |   
\_|  \__,_|___/___/ \_/\_/ \___/|_|  \__,_|  \____/\___|_| |_|\___|_|  \__,_|\__\___/|_|   
    )" << endl ;
    cout << hline << endl << "By Parvez Mia" << endl ;
    cout << "Version: 1.0.0" << endl ;
    cout << "GitHub Repo: https://github.com/pz1971/password-generator" << endl ;
    cout << hline << endl << hline << endl << endl ;

    int len ;
    do{
        cout << "Enter length(at least 8, at most 50): " ;
        cin >> len ;
        cout << hline << endl ;

        if(len < 8 || len > 50){
            cout << "invalid length... Please try again." << endl ;
            cout << hline << endl ;
        }
        else{
            string pass = generate(len) ;
            cout << "Password: " << pass << endl ;
            cout << hline << endl ;
            if(copy_prompt()){
                CClipboardXX() << pass ;
                cout << "Copied to Clipboard!" << endl ;
                cout << hline << endl ;
            }
        }
    }while(prompt()) ; // asks to continue

    cout << "Exiting Program..." << endl ;
    auto t1 = clock()  ;
    while((double) (clock() - t1) / CLOCKS_PER_SEC < 1.0) ;

    return 0;
}