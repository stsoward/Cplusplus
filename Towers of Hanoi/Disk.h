#pragma once
class Disks
{
	int Size;
	bool player;
public:
	Disks();
	Disks(int x, bool y);
	int getSize();
	bool playerOne();
	void setSize(int x);
	void setplayer(bool y);
	char getChar();
};
