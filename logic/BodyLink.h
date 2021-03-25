//
// Created by shahar on 23/03/2021.
//

#ifndef TRYINGOUTSDL_BODYLINK_H
#define TRYINGOUTSDL_BODYLINK_H

#include "../utils/Utils.h"

class BodyLink {
private:
    Location LinkLocation;
    BodyLink *NextLink;
public:
    BodyLink(Location location);

    Location getLinkLocation() const;
    void setLinkLocation(const Location &linkLocation);
    BodyLink *getNextLink() const;
    void setNextLink(BodyLink *next);
};


#endif //TRYINGOUTSDL_BODYLINK_H
