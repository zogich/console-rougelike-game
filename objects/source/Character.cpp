#include "objects/Objects.h"
#include "events/Events.h"

SignalForUpdateObjectPositionOnMap *Character::signal_upd_pos = nullptr;


void Character::movePosWithOffset(const int &x_offset, const int &y_offset) {
    if (Character::signal_upd_pos->callEvent({this->GetPos().x, this->GetPos().y},
                                             {this->GetPos().x+x_offset, this->GetPos().y+y_offset},
                                             this->GetSym())){
        this->SetPos({this->GetPos().x + x_offset, this->GetPos().y + y_offset});
    }
}