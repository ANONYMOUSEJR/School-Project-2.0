#pragma once

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

/*
TODO (Line is just a general location):
Add intro with rules...
line 21: try to remove the 99.
line 61: add in a point system.
line 76: try to fix the warning for the time counter.
line 82: Should i even bother with attempting to to make it so that there is a rand return for the users answer?
*/

class math{
private:
	unsigned short pts = 0;
public:
	unsigned short x, n, quest;
	int ans, studAns, multMin, multMax, num[99], secondMult;
	double duration;
	clock_t start; //Declaring the counter.

	void getRange() {
		cout << endl << "What is your Multiplication range? (x * 1 -> x * 12)" << endl;
		cout << "From: ";
		cin >> multMin;
		cout << "To: ";
		cin >> multMax; cout << endl;
	}
	// Counter.
	void getNumber() {
		cout << endl << "How many numbers do you want to use as your base for the questions? (x * 1 -> x * 12; Where 'x' is base)" << endl << "Amount ~> ";
		cin >> n;
		cout << "And what are those numbers? (Define what 'x' might be)" << endl;
		for (unsigned short i = 0; i < n; i++) {
			switch (i + 1) {
			case 1:
				cout << "1st Number ~> ";
				cin >> num[i];
				cout << endl;
				break;
			
			case 2:
				cout << "2nd Number ~> ";
				cin >> num[i];
				cout << endl;
				break;

			case 3:
				cout << "3rd Number ~> ";
				cin >> num[i];
				cout << endl;
				break;

			default:
				cout << i + 1 << "th Number ~> ";
				cin >> num[i];
				cout << endl;
				break;
			}
		}
	}
	void processQuest() {
		ask:
		cout << "How many questions do you want to answer?" << endl << "Positive Amount ~> ";
		cin >> quest; cout << endl;

		if (quest >= 1) {
			random_shuffle(&num[0], &num[n - 1]);
		}
		else if (quest <= 0) {
			cout << "Try Again";
			this_thread::sleep_for(1s); cout << "."; this_thread::sleep_for(1s); cout << "."; this_thread::sleep_for(1s); cout << "."; this_thread::sleep_for(1s);
			goto ask;
		}

		for (int i = 0; i < quest; i++) {
			secondMult = rand() % multMax + multMin;
			cout << "What is " << num[i] << " X " << secondMult << "?" << endl << "ANSWER ~> ";
			ans = num[i] * secondMult;
			start = clock(); //get current time.
			cin >> studAns;
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;// duration - 1; // Evening things out...
			if (ans == studAns) {
				cout << "Well done, your answer is CORRECT and it only took you " << duration << " Seconds to Prevail!" << endl;
			}
			else {
				cout << "The correct Answer is: " << ans << endl;
			}
		}
	}
};