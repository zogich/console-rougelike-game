
#ifndef CONSOLE_ROUGELIKE_GAME_EVENTS_H
#define CONSOLE_ROUGELIKE_GAME_EVENTS_H
#include "objects/Objects.h"
#include <vector>

template<class ObjectType>
class AbstractEvent{
protected:
    std::vector<ObjectType> observers;
public:
    void subscribe(ObjectType* method_for_trigger_event){
      this->observers.push_back(method_for_trigger_event);
    }
    virtual void callEvent();
};

#endif //CONSOLE_ROUGELIKE_GAME_EVENTS_H
