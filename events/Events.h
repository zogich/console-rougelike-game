
#ifndef CONSOLE_ROUGELIKE_GAME_EVENTS_H
#define CONSOLE_ROUGELIKE_GAME_EVENTS_H
#include "objects/Objects.h"
#include <vector>

class Map;

//! @brief Абстрактное событие, от которого наследуются все прочие события. Реализует паттерн Observer.
template<class ObjectType>
class AbstractEvent{
protected:
    std::vector<ObjectType*> observers;
public:

    //! @brief Метод, реализующий подписку игрового объекта на событие.
    //! @param subscriber Игровой объект, который будет реагировать на событие.
    void subscribe(ObjectType *subscriber){
      this->observers.push_back(subscriber);
    }

    //! @brief Виртуальный метод, описывающий действия при вызове события.
    virtual void callEvent() = 0;
};


//! @brief Событие, вызывающееся каждый игровой тик.
class GameTick : public AbstractEvent<GameObject>{
public:
    //! @brief Вызов у игровых объектов метода onGameTick.
    void callEvent() override {
        for (auto &object: this->observers ){
            object->OnGameTick();
        }
    }
};

//! @brief Событие, вызываемое когда игровой объект должен поменять свою позицию.
class SignalForUpdateObjectPositionOnMap: public AbstractEvent<Map>{
public:
    void callEvent() override{};

    /** @brief Метод выполняет проверку, на возможность передвжения игрового объекта, и если это возможно,
     * перемещает символ объекта на карте. Саму позицию объекта он не меняет.
     * @param old_pos Старая позиция объекта на карте.
     * @param new_pos Новая позиция объекта на карте.
     * @param sym Символ объекта на карте.
    **/
    bool callEvent(const Point &old_pos, const Point &new_pos, const char &sym);
};

#endif
