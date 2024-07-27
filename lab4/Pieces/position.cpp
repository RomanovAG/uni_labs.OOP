#include "position.h"

using namespace Chess;

Position::Position(const int x, const int y) noexcept
{
    this->x = x;
    this->y = y;
    return;
}

int Position::X() const noexcept
{
    return this->x;
}

int Position::Y() const noexcept
{
    return this->y;
}

void Position::X(const int x) noexcept
{
    this->x = x;
    return;
}

void Position::Y(const int y) noexcept
{
    this->y = y;
    return;
}

const Position Position::operator +(const Position &b) const noexcept
{
    return Position(this->x + b.x, this->y + b.y);
}

Position &Position::operator +=(const Position &b) noexcept
{
    this->x += b.x;
    this->y += b.y;
    return *this;
}

bool Position::operator ==(const Position &b) const noexcept
{
    return this->x == b.x && this->y == b.y;
}
