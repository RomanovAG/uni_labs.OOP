#ifndef QPAWN_H
#define QPAWN_H

#include <QObject>
#include <QGraphicsItem>

#include "D:\Labs\OOP\lab4\game.h"

class QPawn :QGraphicsItem, Chess::Pawn
{
    Q_OBJECT
        public:
    QPawn(QObject *parent = nullptr, Chess::Pawn::Color color = Chess::Piece::WHITE);

signals:

};

#endif // QPAWN_H
