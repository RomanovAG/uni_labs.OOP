#include "place.h"
#include "transition.h"

Place::Place()
{
    this->transitions_next.resize(0);
    this->tokens.resize(0);
    return;
}

Place *Place::tryJump(Token *t)
{
    for(int i = 0; i < transitions_next.size(); i++)
        if(this->transitions_next[i]->isOpened() == true)
        {
            for(int j = 0; j < this->specTransNum(this->transitions_next[i]); j++)
            {

            }
        }
}

Place &Place::addToken(Token *t)
{
    this->tokens.push_back(t);
    return *this;
}

Place &Place::addTokens(const std::vector<Token *> &tokens)
{
    for(const auto &t: tokens)
        this->tokens.push_back(t);
    return *this;
}

size_t Place::tokenNum() const
{
    return this->tokens.size();
}

int Place::specTransNum(const Transition *tr) const
{
    int n = 0;
    for(int i = 0; i < this->transitions_next.size(); i++)
        if(this->transitions_next[i] == tr)
            n++;

    return n;
}
