#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "Stud.h"
#include "math.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

/*
|/ ~ Create class with stud. name, class, age and points.
|/ ~ Add in a system to input both amount of students and student info.
| ~ Serialization for student information (optional: make a password in order to access save game).
| ~ Add sound to the Program (Usefull link: https://youtu.be/9WeDQHi6sJs)...
*/

int main()
{
    unsigned short x, Cy;

    cout << "What year is it?" << endl << "Current Year ~> ";
    cin >> Cy; cout << endl;

    // Sorry 'bout this... just wanted to test smth out lol...

    cout << "3" << endl; sleep_for(1s); cout << "2" << endl; sleep_for(1s); cout << "1" << endl; sleep_for(1s);

    cout << "Hello and Welcome to the minigame!" << endl;

    // Stud Info gathering

    cout << "Please state how many students you would wish to add to the mini-game (Your choice cannot be changed later so be careful!)" << endl << "Students ~> ";
    cin >> x;
    cout << endl << endl;

    system("cls");

    vector<Stud> st(x);
    cout << "Now please input the information of your student('s)" << endl << endl;

    sleep_for(2s);

    for (unsigned short i = 0; i < x; i++) {
        cout << "Student Number " << i + 1 << ", What is your Name? " << endl;
        cout << "Name ~> ";
        st[i].getName();
        while (1){
            st[i].getName();
            break;
        }
        cout << endl;

        cout << "What grade are you from, " << st[i].name << "?" << endl;
        cout << "Grade ~> ";
        st[i].getGrade();
        cout << endl;

        cout << "What year where you born in, " << st[i].name << "?" << endl;
        cout << "Birth Year ~> ";
        cin >> st[i].By;

        cout << endl << endl;
    }

    // Let the games Begin!

    cout << "Now that that's done, lets begin with the game:";
    sleep_for(2s);

    cout << endl << "Each student will set up their own range of comfort";
    sleep_for(1s); cout << "."; sleep_for(1s); cout << "."; sleep_for(1s); cout << "."; sleep_for(1s);

    for (unsigned short i = 0; i < x; i++) {
        system("cls");
    
       cout << endl <<  st[i].name << " It's your turn to play.";

        st[i].getRange();

        st[i].getNumber();

        st[i].processQuest();

        cout << "Continue?";
        cin.get();
    }


    cout << "Check!";
    return 0;
}
