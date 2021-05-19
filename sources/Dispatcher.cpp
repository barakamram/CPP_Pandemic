#include "Dispatcher.hpp"


pandemic::Player &pandemic::Dispatcher::fly_direct(pandemic::City c) {
    if (b.getStation(currCity) && c != currCity) {// A case where there is a research station and just make sure he is not flying from a city to himself
        currCity = c;
        return *this;
    }
    return Player::fly_direct(c);
}

string pandemic::Dispatcher::role() {
    return "Dispatcher";
}
