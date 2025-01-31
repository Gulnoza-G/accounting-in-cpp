#include <iostream>
#include<fstream>
#include<string>

using namespace std;
string username, pw;
int start()
{
    int option, counter=0;
    do {
        cout << "********************************************\n";
        cout << "   _____________     _____________________\n";
        cout << "   |           |     |                   |\n";
        cout << "   | 1. Log in |     | 2. Create accaunt |\n";
        cout << "   |___________|     |___________________|\n\n";
        cout << "********************************************\n\n";
        if (counter > 0)
            cout << "Please, Choose the option 1 or 2.\n\n";
        else
            cout << endl << endl;
        cout << "OPTION: "; cin >> option;
        counter++;
        system("cls");
    } while (option < 1 || option>2);
    return option;
}
void create()
{
    string username, password, balance, x;
    cout << "UserName: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "balance: ";
    cin >> balance;
    system("cls");
    fstream file;
    file.open("logIn"+username+".txt", ios::out);
    if (file.is_open()) {
        file << password << endl << balance << endl;
        file.close();
        cout << "\n\n\n\n\n\n        Your accaunt has been successfully created!";
        file.open("accaunts.txt", ios::app);
        file << username << endl;
        file.close();
    }
    else
        cout << "\n\n\n\n\n\n        Failed to create a file";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n                           Enter any key to continue...\n";
    cout << "                           ________________________________";
    cin >> x;

}
int logIn() {
    system("cls");
    string password, pw;
    int option;
    cout << "\n UserName: ";
    cin >> username;
    cout << " Password: ";
    cin >> password;
    fstream file;
    file.open("logIn" + username + ".txt",ios::in);
    if (file.is_open()) {
        file >> pw;
        if (password == pw)
            return 1;
        else {
            system("cls");
            cout << "\n Wrong password!\n\n";
            cout << "  -------------\n  1. Try again\n\n  2. Back\n  -------------\n\n  option :";
            cin >> option;
            switch (option) {
            case 1:logIn();
                return 1; break;
            case 2:break;
            }
            system("cls");
            return 2;
        }
    }
    else {
        system("cls");
        cout << "\n The ussername '" << username << "' does not create an accaunt yet.\n" << endl;
        cout << "  -------------\n  1. Try again\n\n  2. Back\n  -------------\n\n  option :";
        cin >> option;
        switch (option) {
        case 1:logIn(); break;
        case 2:break;
        }
        system("cls");
        return 2;
    }
}
void accaunt()
{
    string pw2, pw3, accaunts, username2, line, line1, line2, line3, line4, line5;
    int option2, deposit, withdraw, sendTo, balance, balance2;
    fstream file,f;
    file.open("logIn" + username + ".txt",ios::in);
    if (file.is_open()) {
        file >> pw2;
        file >> balance;
        file >> line;
        file >> line1;
        file >> line2;
        file >> line3;
        file >> line4;
        file >> line5;
        file.close();
        do {
            do {
                cout << "\n  Hello dear " << username << endl << endl;
                cout << "  Your balance is $" << balance << endl << endl;
                cout << "  " << line << " " << line1 << " " << line2 << " " << line3 << " " << line4 << " " << line5 << endl << endl;
                cout << "    1. Deposit\n    2. Withdraw\n    3. Send to\n    4. Exit\n\n Option: ";
                cin >> option2;
                system("cls");
                if (option2 < 1 || option2>4)
                    cout << "   Wrong option! Please try again\n   -----------------------------\n";
            } while (option2 < 1 || option2>4);
            switch (option2) {
            case 1:cout << " How much? "; cin >> deposit;
                balance -= deposit;
                file.open("logIn" + username + ".txt", ios::out);
                file << pw2 << endl << balance;
                file.close();
                break;
            case 2:cout << " How much? "; cin >> withdraw;
                balance += withdraw;
                file.open("logIn" + username + ".txt", ios::out);
                file << pw2 << endl << balance;
                file.close();
                break;
            case 3:cout << " To who do yo want to send money?" << endl << endl;
                f.open("accaunts.txt", ios::in);
                while (!f.eof()) {
                    f >> accaunts;
                    cout << "    " << accaunts << endl;
                }
                f.close();
                cout << " Username: ";
                cin >> username2;
                file.open("logIn" + username2 + ".txt", ios::in);
                if (file.is_open())
                {
                    cout << "How much? "; cin >> sendTo;
                    file >> pw3;
                    file >> balance2;
                    file.close();
                    balance -= sendTo;
                    balance2 += sendTo;
                    file.open("logIn" + username2 + ".txt", ios::out);
                    file << pw3 << endl << balance2 << endl;
                    file << "(You received $" << sendTo << " from " << username << ")";
                    file.close();
                    file.open("logIn" + username + ".txt", ios::out);
                    file << pw2 << endl;
                    file << balance << endl;
                    file.close();
                }
                break;
            case 4:  file.open("logIn" + username + ".txt", ios::out);
                file << pw2 << endl << balance;
                file.close();
            }
            system("cls");
        } while (option2!=4);
    }
    else
        cout << "Failed to open file";
}
int main()
{
    if (start() == 1)
    {
        if (logIn() == 1) {
            accaunt();
        }
        else
            main();
    }
    else
        create();
    system("cls");
    main();
        
}
   

