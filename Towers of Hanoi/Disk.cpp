#include "pch.h"
#include "Disks.h"
#include <iostream>


Disks::Disks()
{
}


Disks::Disks(int x, bool y)
{
	x = Size;
	y = player;
}



int Disks::getSize() {
	
	return Size;
}


bool Disks::playerOne() {
	
	return player;

}

void Disks::setSize(int x) {

	Size = x;
}

void Disks::setplayer(bool y) {

	player = y;
}

char Disks::getChar() {
	char symbol = '+';
	if (player == true) {
		symbol = '-';
	}

	return symbol;
}
