#include "player.h"
#include <cstring>
#include <stdexcept>

using namespace Chess;

Player::Player() noexcept
{
    this->name = nullptr;
    this->rating = 0;
    return;
}

Player::Player(const char *name, const long long rating)
{
    this->setName(name);
    this->setRating(rating);
    return;
}

Player::~Player()
{
    if (this->name != nullptr)
        delete [] this->name;
    return;
}

void Player::setName(const char *name)
{
    if (name == nullptr)
        throw std::invalid_argument("Invalid player name");
    if (this->name != nullptr)
        delete [] this->name;
    size_t len = std::strlen(name) + 1;
    try
    {
        this->name = new char [len];
    }
    catch (std::out_of_range e)
    {
        throw e;
    }
    std::strncpy(this->name, name, len);
    return;
}

const char *Player::getName() const noexcept
{
    return this->name;
}

void Player::setRating(const long long rating)
{
    if (rating < 0)
        throw std::invalid_argument("Invalid player rating");
    this->rating = rating;
    return;
}

Player &Player::addRating(const long long value)
{
    if (rating < 0)
        throw std::invalid_argument("Invalid value");
    this->rating += value;
    return *this;
}

Player &Player::reduceRating(const long long value)
{
    if (rating < 0)
        throw std::invalid_argument("Invalid value");
    this->rating -= value;
    return *this;
}

long long Player::getRating() const noexcept
{
    return this->rating;
}

std::ostream &Chess::operator <<(std::ostream &os, const Player &player)
{
    if (player.name == nullptr)
        return os;
    return os << "Name: " << player.name << "\nRating: " << player.rating;
}
