#include "pch.h"
#include "Template.h"
#include "Disks.h"
#include <iostream>
#include <string>

using namespace std;

void Display_disk(Disks  disk) {
	char symbol = disk.getChar();
	int value = disk.getSize();
	cout << "\t   " << symbol << value << symbol << "\t";
}


void printArray(Stack <Disks> s1, Stack <Disks> s2, Stack <Disks> s3, Stack <Disks> s4, Stack <Disks> s5) {
	int count = 0;
	while (true) {
		if (count != 0 && count <= s1.MaxSize) {
			for (int i = s1.MaxSize - 1; i >= 0; i--) {
				if (s1.UserStack[i].getSize() <= s1.MaxSize && s1.UserStack[i].getSize() >= 1) {
					Display_disk(s1.UserStack[i]);
				}
				else {
					cout << "\t    |\t";
				}
				if (s2.UserStack[i].getSize() <= s1.MaxSize && s2.UserStack[i].getSize() >= 1) {
					Display_disk(s2.UserStack[i]);
				}
				else {
					cout << "\t    |\t";
				}
				if (s3.UserStack[i].getSize() <= s1.MaxSize && s3.UserStack[i].getSize() >= 1) {
					Display_disk(s3.UserStack[i]);
				}
				else {
					cout << "\t    |\t";
				}
				if (s4.UserStack[i].getSize() <= s1.MaxSize && s4.UserStack[i].getSize() >= 1) {
					Display_disk(s4.UserStack[i]);
				}
				else {
					cout << "\t    |\t";
				}
				if (s5.UserStack[i].getSize() <= s1.MaxSize && s5.UserStack[i].getSize() >= 1) {
					Display_disk(s5.UserStack[i]);
				}
				else {
					cout << "\t    |\t";
				}
				cout << endl;
				count++;
			}
		}
		else if (count > s1.MaxSize) {
			break;
		}
		else {
			cout << "\t Rod One \t Rod Two \t Rod Three \t Rod Four \t Rod Five" << endl << endl;
			cout << "\t    |\t\t    |\t\t    |\t\t    |\t\t    |" << endl;
		}
		count++;
	}
	cout << endl;
}

int main() {

	cout << "Welcome to our version of \"Towers of Hanoi\" " << endl << "This is a two player game" << endl << "Player One's disks will be denoted with -1-" << endl << "Player Two's disks will be denoted with +1+ " << endl;
	cout << "Only one player may move at a time, and that player must make a move \n Good Luck!!" << endl << endl;

	int numDisks;

	bool first_player_turn = true;
	string player = "One";

	cout << "How many disks do you want to play with?: " << endl;
	cin >> numDisks;
	cout << endl;

	//pole declarations
	Stack<Disks> GameStacks[5]{ {numDisks},{numDisks},{numDisks},{numDisks},{numDisks} };

	//filling stack 2 with numDisks
	Disks * array;
	array = new Disks[numDisks];
	for (int i = numDisks; i > 0; i--)
	{
		array[i].setSize(i);
		array[i].setplayer(true);
		GameStacks[1].push(&array[i]);
	}



	//filling stack 4 with numDisks
	for (int i = numDisks; i > 0; i--)
	{
		array[i].setSize(i);
		array[i].setplayer(false);
		GameStacks[3].push(&array[i]);
	}



	while (true) {

		printArray(GameStacks[0], GameStacks[1], GameStacks[2], GameStacks[3], GameStacks[4]);

		cout << "Player " << player << " please take your turn" << endl << endl;


		int stackTake = 0;
		while (true) {
			cout << "Which stack do you want to pull from?(1,2,3,4,5): " << endl;
			cin >> stackTake;
			stackTake -= 1;
			if (GameStacks[stackTake].size() != 0 && GameStacks[stackTake].peek()->playerOne() == !first_player_turn) {
							cout << "It is not your turn! Player " << player << " please take your turn!" << endl << endl;
							}
			else if (stackTake < 5 && stackTake >= 0 && GameStacks[stackTake].size() != 0){
				break;
			}
			
		}

		int stackPlace;
		while (true) {
			cout << "Which stack to you want to move to?(1,2,3,4,5): " << endl;
			cin >> stackPlace;
			stackPlace -= 1;
			if (stackPlace < 5 && stackPlace >= 0 && stackPlace != stackTake && GameStacks[stackPlace].size() != numDisks) {
				break;
			}
		}

		if (GameStacks[stackPlace].isEmpty() || !(GameStacks[stackPlace].peek()->getSize() < GameStacks[stackTake].peek()->getSize())) {
			GameStacks[stackPlace].push(GameStacks[stackTake].peek());
			GameStacks[stackTake].pop();
		}
		else {
			cout << GameStacks[stackPlace].peek()->getSize() << " is less then " << GameStacks[stackTake].peek()->getSize() << " , this is an illigal move." << endl;
		}

		if (GameStacks[0].Win() || GameStacks[4].Win()) {
			cout << endl << "\tPlayer " << player << " won! Way to go sport!" << endl << endl;
			printArray(GameStacks[0], GameStacks[1], GameStacks[2], GameStacks[3], GameStacks[4]);
			GameStacks[0].Empty();
			GameStacks[1].Empty();
			GameStacks[2].Empty();
			GameStacks[3].Empty();
			GameStacks[4].Empty();
			break;
		}

		cout << endl << "------------------------------------------------------------------------------" << endl << endl;

		if (first_player_turn == true) {
			first_player_turn = false;
			player = "Two";
		}
		else {
			first_player_turn = true;
			player = "One";
		}
	}
	return 0;
}
