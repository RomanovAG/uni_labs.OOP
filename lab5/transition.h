#ifndef TRANSITION_H
#define TRANSITION_H
#include <vector>
#include "place.h"

class Transition
{
private:
    std::vector<Place *> places_prev;
    std::vector<Place *> places_next;

public:
    Transition();

    bool isOpened() const;

    void moveToken();
};

#endif // TRANSITION_H
