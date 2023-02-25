
#ifndef CONSOLE_ROUGELIKE_GAME_EVENTS_H
#define CONSOLE_ROUGELIKE_GAME_EVENTS_H
#include "objects/Objects.h"
#include <vector>

template<class ObjectType>
class AbstractEvent{
protected:
    std::vector<ObjectType*> observers;
public:
    void subscribe(ObjectType *subscriber){
      this->observers.push_back(subscriber);
    }
    virtual void callEvent() = 0;
};



class GameTick : public AbstractEvent<GameObject>{
public:
    void callEvent() override {
        for (auto &object: this->observers ){
            object->OnGameTick();
        }
    }
};

#endif
