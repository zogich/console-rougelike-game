

#ifndef CONSOLE_ROUGELIKE_GAME_FACTORY_H
#define CONSOLE_ROUGELIKE_GAME_FACTORY_H
#include <memory>
#include <map>
#include "objects/Objects.h"

class AbstractCreator {
public:
    virtual GameObject* Create(const Point &pos) = 0;
    virtual ~AbstractCreator() = default;
};

//! @brief Создатель объектов, использующийся в фабрике для заполнения карты.

template <class Object>
class ObjectCreator : public AbstractCreator {
public:
    GameObject* Create(const Point &pos) override{
        return new Object(pos);
    }
};

//! @brief Фабрика, заполняющая карту объектами.

class Factory{
    private:
       std::map<char, std::unique_ptr<AbstractCreator>> CreatorMap;
    public:
        Factory();
        //! @brief Метод используемый для создания объекта.
        //! @param sym Символ объекта, который сообщает фабрике какой объект нужно создать.
        //! @param pos Позиция на карте, куда должен быть помещен объект.
        GameObject* createObjectFromSym(const char &sym, const Point &pos);
};


#endif //CONSOLE_ROUGELIKE_GAME_FACTORY_H
