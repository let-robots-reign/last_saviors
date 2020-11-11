#include "event.h"

Event::Event() : type(EmptyEvent), info(NoInfoEvent()) {}

Event::Event(EventType ptype, EventInfo pinfo) : type(ptype), info(pinfo) {}

void Event::setType(EventType ptype) {
    Event::type = ptype;
}

void Event::setInfo(const EventInfo &pinfo) {
    Event::info = pinfo;
}
