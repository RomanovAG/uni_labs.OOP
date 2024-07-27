#ifndef POSITION_H
#define POSITION_H

namespace Chess
{
class Position
{
private:
    int x, y;

public:
    Position(const int x = 0, const int y = 0) noexcept;

    int X() const noexcept;
    int Y() const noexcept;

    void X(const int x) noexcept;
    void Y(const int y) noexcept;

    const Position operator +(const Position &b) const noexcept;

    Position &operator +=(const Position &b) noexcept;

    bool operator ==(const Position &b) const noexcept;
};
} //namespace

#endif // POSITION_H
