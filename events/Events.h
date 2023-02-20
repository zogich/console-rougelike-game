
#ifndef CONSOLE_ROUGELIKE_GAME_EVENTS_H
#define CONSOLE_ROUGELIKE_GAME_EVENTS_H
#include "objects/Objects.h"
#include <vector>

template<class ObjectType>
class AbstractEvent{
protected:
    std::vector<std::shared_ptr<ObjectType>> observers;
public:
    void subscribe(std::shared_ptr<ObjectType> &method_for_trigger_event){
      this->observers.push_back(method_for_trigger_event);
    }
    virtual void callEvent() = 0;
};



class GameTick : public AbstractEvent<GameObject>{
    void callEvent() override {
        for (auto &object: this->observers ){
            object->OnGameTick();
        }
    }
};

#endif
