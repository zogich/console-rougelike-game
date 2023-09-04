#include "Events.h"
#include "Map.h"


bool SignalForUpdateObjectPositionOnMap::callEvent(const Point &old_pos, const Point &new_pos, const char &sym) {
    for ( auto &map: this->observers ){
        if ( new_pos.x < 0 || new_pos.y < 0 || new_pos.y >= map->getTiles().size() || new_pos.x >= map->getTiles()[0].size()) {
            return false;
        }
        map->moveObjectSym(old_pos, new_pos, sym);
    }
    return true;
}