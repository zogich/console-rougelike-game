#include "Factory.h"

Factory::Factory() {
    this->CreatorMap['K'] = std::make_unique<ObjectCreator<Knight>>();
    this->CreatorMap['Z'] = std::make_unique<ObjectCreator<Zombie>>();
    this->CreatorMap['D'] = std::make_unique<ObjectCreator<Dragon>>();
    this->CreatorMap['P'] = std::make_unique<ObjectCreator<Princess>>();
    this->CreatorMap['#'] = std::make_unique<ObjectCreator<Wall>>();
}

std::unique_ptr<GameObject> Factory::createObjectFromSym(const char &sym, const Point &pos) {
    this->CreatorMap[sym]->Create(pos);
}