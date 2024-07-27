#ifndef TOKEN_H
#define TOKEN_H
#include "place.h"

class Token
{
private:
    Place *place_parent;

    void changeParent(Place *p);

public:
    Token(Place *place_parent);

    bool tryJump();
};

#endif // TOKEN_H
