

#ifndef CONSOLE_ROUGELIKE_GAME_FACTORY_H
#define CONSOLE_ROUGELIKE_GAME_FACTORY_H
#include <memory>
#include <map>
#include "objects/Objects.h"

//!
class AbstractCreator {
public:
    virtual GameObject* Create(const Point &pos) = 0;
    virtual ~AbstractCreator() = default;
};

template <class Object>
class ObjectCreator : public AbstractCreator {
public:
    GameObject* Create(const Point &pos) override{
        return new Object(pos);
    }
};

class Factory{
    private:
       std::map<char, std::unique_ptr<AbstractCreator>> CreatorMap;
    public:
        Factory();
        GameObject* createObjectFromSym(const char &sym, const Point &pos);
};


#endif //CONSOLE_ROUGELIKE_GAME_FACTORY_H
