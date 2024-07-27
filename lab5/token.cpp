#include "token.h"

Token::Token(Place *place_parent)
{
    this->place_parent = place_parent;
    return;
}

void Token::changeParent(Place *p)
{
    if (p == nullptr)
        return;
    this->place_parent = p;
    return;
}

bool Token::tryJump()
{
    Place *p;
    if((p = this->place_parent->tryJump(this)) != nullptr)
    {
        this->changeParent(p);
        return true;
    }
    return false;
}
