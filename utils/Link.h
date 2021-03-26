//
// Created by Shahar on 3/26/2021.
//

#ifndef SDL_SNAKE_LINK_H
#define SDL_SNAKE_LINK_H

template <class T>
class Link {
private:
    T Data;
    Link * NextLink;
public:
    Link(T data):Data(data), NextLink(nullptr){}
    Link(const Link<T> & link): Data(link.getData()), NextLink(link.getNextLink()){};

    T getData() const {
        return Data;
    }

    void setData(T data) {
        Data = data;
    }

    Link *getNextLink() const {
        return NextLink;
    }

    void setNextLink(Link *nextLink) {
        NextLink = nextLink;
    }
};


#endif //SDL_SNAKE_LINK_H
