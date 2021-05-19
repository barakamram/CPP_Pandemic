#include "Virologist.hpp"

pandemic::Player& pandemic::Virologist::treat(pandemic::City c) {
    if (find(cards.begin(), cards.end(), c) == cards.end() && currCity != c){
        throw std::invalid_argument("This card is not in your possession");
    }
    City temp = currCity;
    currCity = c;
    Player::treat(c);
    currCity = temp;
    cards.remove(c);
    return *this;
}
string pandemic::Virologist::role() {
    return "Virologist";
}
