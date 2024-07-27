#ifndef CLOCK_H
#define CLOCK_H
#include <ostream>

namespace Chess
{
class Clock
{
public:
    enum PlayerColor
    {
        PLAYER_WHITE = 1,
        PLAYER_BLACK
    };

private:
    long long player_white_time_sec, player_black_time_sec;

    char *getTimeStr(const PlayerColor player_color) const;

public:
    Clock() noexcept;

    void setTimeSec(const long long time, const PlayerColor player_color);
    Clock &addTimeSec(const long long value, const PlayerColor player_color);

    long long getTimeSec(const PlayerColor player_color) const;
    void printTime(std::ostream &os, const PlayerColor player_color) const;

    void reset() noexcept;
};
} //namespace

#endif // CLOCK_H
