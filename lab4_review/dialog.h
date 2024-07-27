#ifndef DIALOG_H
#define DIALOG_H

#include "game.h"

int getNum(int *number);

int dStart(Chess::Game &game);
int dContinue(Chess::Game &game);

int dChangePlNames(Chess::Game &game);

int dPrintHistory(Chess::Game &game);

int dSaveGame(Chess::Game &game);

int dLoadGame(Chess::Game &game);

#endif // DIALOG_H
