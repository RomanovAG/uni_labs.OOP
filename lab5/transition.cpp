#include "transition.h"

Transition::Transition()
{
    this->places_prev.resize(0);
    this->places_next.resize(0);
    return;
}

bool Transition::isOpened() const
{
    for(int i = 0; i < this->places_prev.size(); i++)
        if(this->places_prev[i]->tokenNum() <= this->places_prev[i]->specTransNum(this))
            return false;

    return true;
}

void Transition::moveToken()
{
    if(this->places_prev.size() == this->places_next.size() == 1)
    {
        this->places_next[0]->addToken(places_prev[0]->tokens.back());
        places_prev[0]->tokens.pop_back();
        this->places_prev[0]->tokens.resize(0);
    }
}
