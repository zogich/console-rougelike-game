#include "Factory.h"
#include <iostream>

Factory::Factory() {
    this->CreatorMap['K'] = std::make_unique<ObjectCreator<Knight>>();
    this->CreatorMap['Z'] = std::make_unique<ObjectCreator<Zombie>>();
    this->CreatorMap['D'] = std::make_unique<ObjectCreator<Dragon>>();
    this->CreatorMap['P'] = std::make_unique<ObjectCreator<Princess>>();
    this->CreatorMap['#'] = std::make_unique<ObjectCreator<Wall>>();
}

GameObject* Factory::createObjectFromSym(const char &sym, const Point &pos) {
    if (this->CreatorMap.count(sym)){
        return this->CreatorMap[sym]->Create(pos);
    }
    else{
        return nullptr;
    }
}