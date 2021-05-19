#include "Scientist.hpp"


pandemic::Player& pandemic::Scientist::discover_cure(pandemic::Color c) {
    return Player::discover_cure(c, num, false, false);
}

string pandemic::Scientist::role() {
    return "Scientist";
}
