#include "clock.h"
#include <stdexcept>
#include <iostream>

using namespace Chess;

Clock::Clock() noexcept
{
    this->player_white_time_sec = this->player_black_time_sec = 0;
    return;
}

void Clock::setTimeSec(const long long time, const PlayerColor player_color)
{
    if (time < 0)
        throw std::invalid_argument("Invalid player time");

    if (player_color < this->PLAYER_WHITE || player_color > this->PLAYER_BLACK)
        throw std::invalid_argument("Invalid player index");

    if (player_color == this->PLAYER_WHITE)
        this->player_white_time_sec = time;
    else
        this->player_black_time_sec = time;
    return;
}

Clock &Clock::addTimeSec(const long long value, const PlayerColor player_color)
{
    if (value < 0)
        throw std::invalid_argument("Invalid player time");

    if (player_color < this->PLAYER_WHITE || player_color > this->PLAYER_BLACK)
        throw std::invalid_argument("Invalid player index");

    if (player_color == this->PLAYER_WHITE)
        this->player_white_time_sec += value;
    else
        this->player_black_time_sec += value;
    return *this;
}

long long Clock::getTimeSec(const PlayerColor player_color) const
{
    if (player_color < this->PLAYER_WHITE || player_color > this->PLAYER_BLACK)
        throw std::invalid_argument("Invalid player index");

    if (player_color == this->PLAYER_WHITE)
        return this->player_white_time_sec;
    return this->player_black_time_sec;
}

char *Clock::getTimeStr(const PlayerColor player_color) const
{
    if (player_color < this->PLAYER_WHITE || player_color > this->PLAYER_BLACK)
        throw std::invalid_argument("Invalid player index");

    int sec, min, hour;
    if (player_color == this->PLAYER_WHITE)
    {
        sec = this->player_white_time_sec % 60;
        min = this->player_white_time_sec / 60 % 60;
        hour = this->player_white_time_sec / 3600;
    }
    else
    {
        sec = this->player_black_time_sec % 60;
        min = this->player_black_time_sec / 60 % 60;
        hour = this->player_black_time_sec / 3600;
    }
    char *buff = new char [32];
    std::snprintf(buff, 32, "%d : %d : %d", hour, min, sec);
    return buff;
}

void Clock::printTime(std::ostream &os, const PlayerColor player_color) const
{
    char *time = this->getTimeStr(player_color);
    os << time;
    delete [] time;
    return;
}

void Clock::reset() noexcept
{
    this->player_white_time_sec = this->player_black_time_sec = 0;
    return;
}
