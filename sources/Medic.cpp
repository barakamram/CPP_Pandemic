#include "Medic.hpp"

pandemic::Player& pandemic::Medic::drive(pandemic::City c) {
    Player::drive(c);
    treat();
    return *this;
}
pandemic::Player& pandemic::Medic::treat(pandemic::City c) {
    if(b[currCity] <= 0){
        throw std::invalid_argument("There were no more disease-cubes left in this city ");
    }
    b[currCity] = 0;
    return *this;
}
pandemic::Player& pandemic::Medic::fly_direct(pandemic::City c) {
    Player::fly_direct(c);
    treat();
    return *this;
}
pandemic::Player& pandemic::Medic::fly_charter(pandemic::City c) {
    Player::fly_charter(c);
    treat();
    return *this;
}
pandemic::Player& pandemic::Medic::fly_shuttle(pandemic::City c) {
    Player::fly_shuttle(c);
    treat();
    return *this;
}
void pandemic::Medic::treat() {
    if(b.getCure(currCity)){
        b[currCity]=0;
    }
}

string pandemic::Medic::role() {
    return "Medic";
}
