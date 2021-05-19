#include "Researcher.hpp"

const unsigned int FIVE = 5;

pandemic::Player& pandemic::Researcher::discover_cure(pandemic::Color c) {
    return Player::discover_cure(c, FIVE, false,  true);
}

string pandemic::Researcher::role() {
    return "Researcher";
}
