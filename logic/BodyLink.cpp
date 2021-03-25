//
// Created by shahar on 23/03/2021.
//

#include "BodyLink.h"

Location BodyLink::getLinkLocation() const {
    return LinkLocation;
}

void BodyLink::setLinkLocation(const Location &linkLocation) {
    LinkLocation = linkLocation;
}

BodyLink *BodyLink::getNextLink() const {
    return NextLink;
}

void BodyLink::setNextLink(BodyLink *next) {
    BodyLink::NextLink = next;
}

BodyLink::BodyLink(Location location) {
    this->LinkLocation = location;
    this->NextLink = nullptr;
}
