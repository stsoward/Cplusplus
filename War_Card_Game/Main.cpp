#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include "QueueLinkedList.h"
#include "Stack.h"

using namespace std;

int main() {

	srand(time(NULL));
	int GameType, WinningNumGames = 10000000, x;

	cout << "Welcome to War" << endl << endl;

	while (true) {
		cout << "How would you like to play? \n\t0 = Till the Player/Opponent deck is empty \n\t1 = First to X rounds won" << endl;
		cin >> GameType;

		if ((GameType == 1 || GameType == 0))
			break;
		else
			cout << "ERROR: You did not enter a valid value, please try again." << endl << endl;
	}

	if (GameType) {
		while (true) {
			cout << endl << "How many rounds must the winner win?" << endl;
			cin >> WinningNumGames;
			if (WinningNumGames > 0)
				break;
			else
				cout << "ERROR: Please provide a positive number." << endl;
		}
	}

	int DeckCards[52] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	int DeckHolder[52] = { 2,3,4,5,6,7,8,9,10,11,12,13,14,2,3,4,5,6,7,8,9,10,11,12,13,14,2,3,4,5,6,7,8,9,10,11,12,13,14,2,3,4,5,6,7,8,9,10,11,12,13, 14 };

	cout << endl << "***NOTE: The display of the card will be integers and they are as follows:" << endl << "2 = 2" << endl << "3 = 3" << endl << "4 = 4" << endl << "5 = 5" << endl << "6 = 6" << endl << "7 = 7" << endl << "8 = 8" << endl << "9 = 9" << endl << "10 = 10" << endl << "11 = Jack" << endl << "12 = Queen" << endl << "13 = King" << endl << "14 = Ace" << endl << endl;

	QueueLinkedList* PlayerStack = new QueueLinkedList();
	QueueLinkedList* ComputerStack = new QueueLinkedList();

	for (int i = 0; i < 26; i++) {

		while (true) {
			x = rand() % 52;
			if (DeckHolder[x] != 0)
				break;
		}

		PlayerStack->insert(&DeckCards[x]);
		DeckHolder[x] = 0;

		while (true) {
			x = rand() % 52;
			if (DeckHolder[x] != 0)
				break;
		}

		ComputerStack->insert(&DeckCards[x]);
		DeckHolder[x] = 0;
	}

	cout << "-------------------------------------------------------------------" << endl << "Let the game of War begin" << endl << "-------------------------------------------------------------------" << endl << endl;

	while (PlayerStack->getNumCards() > 0 && ComputerStack->getNumCards() > 0 && PlayerStack->getRoundsWon() < WinningNumGames && ComputerStack->getRoundsWon() < WinningNumGames) {

		int * PlayerCard = PlayerStack->Peek();
		int * CompCard = ComputerStack->Peek();
		int * SideStackPeek = nullptr;

		int choice1;
		while (true) {
			cout << "PEEK: Sources say your next card will be a : " << *PlayerCard << " : Would you like to...\n\t1 = Play this card alone" << endl;
			if (PlayerStack->getSideStackSize() > 0) { cout << "\t2 = Pull a card from your side stack" << endl; }
			if (PlayerStack->getSideStackSize() < 5) { cout << "\t3 = Place this card into your side stack and play the next card" << endl; }
			cin >> choice1;

			if (choice1 == 1 || (PlayerStack->getSideStackSize() > 0 && choice1 == 2) || (PlayerStack->getSideStackSize() < 5 && choice1 == 3))
				break;
			else
				cout << "ERROR: You did not enter a valid value, try again." << endl;
		}

		if (choice1 == 1) {
			if (*PlayerCard > *CompCard) {
				cout << "Player's Card = " << *PlayerCard << endl << "Computer's Card = " << *CompCard << endl << "Player wins round!" << endl;
				PlayerStack->deleteitem();
				PlayerStack->insert(PlayerCard);
				ComputerStack->deleteitem();
				PlayerStack->insert(CompCard);
				PlayerStack->AddRoundWon();
			}
			else {
				cout << "Player's Card = " << *PlayerCard << endl << "Computer's Card = " << *CompCard << endl << "Computer wins round!" << endl;
				ComputerStack->deleteitem();
				ComputerStack->insert(PlayerCard);
				PlayerStack->deleteitem();
				ComputerStack->insert(CompCard);
				ComputerStack->AddRoundWon();
			}
		}
		else if (choice1 == 2) {
			SideStackPeek = PlayerStack->SideStackPeek();

			if (*PlayerCard + *SideStackPeek > *CompCard) {
				cout << "Player's Card + Side Stack Card = " << *PlayerCard + *SideStackPeek << endl << "Computer's Card = " << *CompCard << endl << "Player wins round!" << endl;
				PlayerStack->deleteitem();
				PlayerStack->SideStackPop();
				PlayerStack->insert(PlayerCard);
				PlayerStack->insert(SideStackPeek);
				ComputerStack->deleteitem();
				PlayerStack->insert(CompCard);
				PlayerStack->AddRoundWon();
			}
			else {
				cout << "Player's Card + Side Stack Card = " << *PlayerCard + *SideStackPeek << endl << "Computer's Card = " << *CompCard << endl << "Computer wins round!" << endl;
				ComputerStack->deleteitem();
				ComputerStack->insert(PlayerCard);
				ComputerStack->insert(PlayerCard);
				PlayerStack->deleteitem();
				PlayerStack->SideStackPop();
				ComputerStack->insert(CompCard);
				ComputerStack->insert(SideStackPeek);
				ComputerStack->AddRoundWon();
			}
		}
		else {

			PlayerStack->SideStackInsert(PlayerCard);
			PlayerStack->deleteitem();
			PlayerCard = PlayerStack->Peek();

			if (*PlayerCard > *CompCard) {
				cout << "Player's Card = " << *PlayerCard << endl << "Computer's Card = " << *CompCard << endl << "Player wins round!" << endl;
				PlayerStack->deleteitem();
				PlayerStack->insert(PlayerCard);
				ComputerStack->deleteitem();
				PlayerStack->insert(CompCard);
				PlayerStack->AddRoundWon();
			}
			else {
				cout << "Player's Card = " << *PlayerCard << endl << "Computer's Card = " << *CompCard << endl << "Computer wins round!" << endl;
				ComputerStack->deleteitem();
				ComputerStack->insert(PlayerCard);
				PlayerStack->deleteitem();
				ComputerStack->insert(CompCard);
				ComputerStack->AddRoundWon();
			}
		}

		cout << "------------------------------------------------------------------------------------" << endl
			<< "Player Card Count = " << PlayerStack->getNumCards() << endl
			<< "Computer Card Count = " << ComputerStack->getNumCards() << endl
			<< "Player Round Wins = " << PlayerStack->getRoundsWon() << endl
			<< "Computer Round Wins = " << ComputerStack->getRoundsWon() << endl << endl;

	}

	if (PlayerStack->getNumCards() == 0 && ComputerStack->getRoundsWon() == WinningNumGames)
		cout << endl << "Computer Wins The Great War Of 2019";
	else
		cout << endl << "Player Wins The Great War Of 2019";

	return 0;
}
