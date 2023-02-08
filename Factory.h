

#ifndef CONSOLE_ROUGELIKE_GAME_FACTORY_H
#define CONSOLE_ROUGELIKE_GAME_FACTORY_H
#include <memory>
#include <map>
#include "objects/Objects.h"

class AbstractCreator {
public:
    virtual std::unique_ptr<GameObject> Create(const Point &pos) = 0;
};

template <class Object>
class ObjectCreator : public AbstractCreator {
public:
    std::unique_ptr<GameObject> Create(const Point &pos) override{
        return std::make_unique<Object>(pos);
    }
};

class Factory{
    private:
       std::map<char, std::unique_ptr<AbstractCreator>> CreatorMap;
    public:
        Factory();
        std::unique_ptr<GameObject> createObjectFromSym(const char &sym, const Point &pos);
};


#endif //CONSOLE_ROUGELIKE_GAME_FACTORY_H
