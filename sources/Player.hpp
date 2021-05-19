#pragma once
#include <iostream>
#include <string>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic {
    class Player {
    protected:
        Board &b;
        list<City> cards;
        City currCity;

      public:
        Player(Board& b, City c);
        virtual Player& build();
        virtual Player& drive(City);
        virtual Player& treat(City);
        virtual Player& fly_charter(City);
        virtual Player& fly_direct(City);
        virtual Player& fly_shuttle(City);
        virtual Player& take_card(City);
        virtual Player& discover_cure(Color);
        Player &discover_cure(Color, int, bool, bool);
        Player &remove_cards();
        virtual string role();

    };
}
