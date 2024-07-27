#ifndef PLAYER_H
#define PLAYER_H
#include <ostream>

namespace Chess
{
class Player
{
private:
    char *name;
    long long rating;

public:
    Player() noexcept;
    Player(const char *name, const long long rating = 0);
    ~Player();

    void setName(const char *name);
    const char *getName() const noexcept;

    void setRating(const long long rating);
    Player &addRating(const long long value);
    Player &reduceRating(const long long value);
    long long getRating() const noexcept;

    friend std::ostream &operator <<(std::ostream &os, const Player &player);
};
} //namespace

#endif // PLAYER_H
