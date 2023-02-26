#include "Events.h"
#include "Map.h"

void SignalForUpdateObjectPositionOnMap::callEvent(const Point &old_pos, const Point &new_pos, const char &sym) {
    for ( auto &map: this->observers ){
        map->moveObjectSym(old_pos, new_pos, sym);
    }
}