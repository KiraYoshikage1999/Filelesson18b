#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class User {
    string name;
    string nick;
    int age;
public:
    User() {
        name = "Boryslav";
        nick = "Ireland";
        age = 222;
    }

    User(string name, string nick ,int age) {
        this->name = name;
        this->age = age;
        this->nick = nick;
    }

    void setNick(string nick) {
        this->nick = nick;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    string getNick() {
        return this->nick;
    }

    string getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }

    void WriteUserToFile() {
        ofstream outFile("users.txt", ios::app); // Відкриття файлу на запис
        outFile << this->name << endl;
        outFile.close();

        ofstream outSecondFile("age.txt", ios::app);
        outSecondFile << this->age << endl;
        outSecondFile.close();

        ofstream outThirdFile("nicks.txt", ios::app);
        outThirdFile << this->nick << endl;
        outThirdFile.close();
    }
};


class Group {
    User* user;
    int amountOfUsers;
public:
    Group() {
        ifstream inFile("users.txt");
        string line;
        int counter = 0;
        while (getline(inFile, line)) {
            counter++;
            cout << line << endl;
        }
        amountOfUsers = counter;
        user = new User[amountOfUsers];
    }

    void ReadAllUsersFromFile() {
        string* usersName = new string[amountOfUsers];
        string* usersNick = new string[amountOfUsers];
        int* usersAge = new int[amountOfUsers];



        ifstream inFile("users.txt"); // Відкриття файлу на читання
        string line;
        int counter = 0;
        while (getline(inFile, line)) {
            usersName[counter] = line;
            counter++;
        }
        inFile.close();

        counter = 0;
        ifstream inSecondFile("age.txt");
        while (getline(inSecondFile, line)) {
            usersAge[counter] = stoi(line); // stoi = string to int
            counter++;
        }
        inSecondFile.close();

        ifstream inThirdFile("nicks.txt"); // Відкриття файлу на читання
        counter = 0;
        while (getline(inThirdFile, line)) {
            usersNick[counter] = line;
            counter++;
        }
        inThirdFile.close();

        for (int i = 0; i < amountOfUsers; i++) {
            user[i].setName(usersName[i]);
            user[i].setAge(usersAge[i]);
            user[i].setNick(usersNick[i]);
        }

        delete[] usersName;
        usersName = nullptr;

        delete[] usersAge;
        usersAge = nullptr;

        delete[] usersNick;
        usersNick = nullptr;
    }

    void PrintAllUsers() {
        for (int i = 0; i < amountOfUsers; i++) {
            cout << "UserName: " << this->user[i].getName() << endl;
            cout << "Age: " << this->user[i].getAge() << endl;
            cout << "Nick: " << this->user[i].getNick() << endl;
        }
    }
};

int main()
{
    User obj = User("Ivan", "Ireland", 10 );
    obj.WriteUserToFile();

    Group group;
    group.ReadAllUsersFromFile();
    group.PrintAllUsers();
}