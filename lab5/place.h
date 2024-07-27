#ifndef PLACE_H
#define PLACE_H
#include <vector>
//#include "transition.h"
//#include "token.h"

class Token;
class Transition;

class Place
{
public:
    std::vector<Transition *> transitions_next;

    std::vector<Token *> tokens;

public:
    Place();

    Place *tryJump(Token *t);

    Place &addToken(Token *t);
    Place &addTokens(const std::vector<Token *> &tokens);

    Place &reduceTokens();

    size_t tokenNum() const;

    int specTransNum(const Transition *tr) const;
};

#endif // PLACE_H
