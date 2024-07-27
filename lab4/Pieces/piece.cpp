#include "piece.h"
#include <stdexcept>

using namespace Chess;

Piece::~Piece()
{
    return;
}

void Piece::setColor(const Color color)
{
    if (color != this->BLACK && color != this->WHITE)
        throw std::invalid_argument("Invalid piece color");
    this->color = color;
    return;
}

void Piece::setName(const Name name)
{
    if (name < this->KING || name > this->PAWN)
        throw std::invalid_argument("Invalid piece name");
    this->name = name;
    return;
}

Piece::Color Piece::getColor() const noexcept
{
    return this->color;
}

Piece::Name Piece::getName() const noexcept
{
    return this->name;
}
