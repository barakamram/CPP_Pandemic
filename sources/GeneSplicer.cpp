#include "GeneSplicer.hpp"

const unsigned int FIVE = 5;


pandemic::Player& pandemic::GeneSplicer::discover_cure(pandemic::Color c) {
    return Player::discover_cure(c, FIVE, true, false);
}

string pandemic::GeneSplicer::role() {
    return "GeneSplicer";
}
