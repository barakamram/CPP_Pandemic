#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <algorithm>

#include <string>
#include <iostream>

using namespace std;
using namespace pandemic;
const unsigned int FIVE = 5;
  Player::Player(Board &b, City c) : b(b), currCity(c) {}

  pandemic::Player &pandemic::Player::build() {
      if (find(cards.begin(), cards.end(), currCity) == cards.end()) {
          throw std::invalid_argument("This card is not in your possession ");
      }
      cards.remove(currCity);
      b.buildStation(currCity, true);
      return *this;
  }
  pandemic::Player &pandemic::Player::drive(pandemic::City c) {
      if (c == currCity) {
          throw std::invalid_argument("You are in the current city ");
      }
      if (!b.neighbors(c, currCity)) {
          throw std::invalid_argument("It is not possible to drive to this city,you need to take a flight :-) ");
      }
      currCity = c;
      return *this;
  }
  pandemic::Player &pandemic::Player::treat(pandemic::City c) {
      if (c != currCity) {
          throw std::invalid_argument("you are not in this city ");
      }
      if (b[currCity] <= 0) {
          throw std::invalid_argument("There were no more disease-cubes left in this city ");
      }
      if (b.getCure(currCity)) {
        b[currCity] = 0;
      }
      else {
        b[currCity]--;
      }
      return *this;
  }
  pandemic::Player &pandemic::Player::fly_charter(pandemic::City c) {
      if (c == currCity) {
          throw std::invalid_argument("You are in the current city ");
      }
      if (find(cards.begin(), cards.end(), currCity) == cards.end()) {
          throw std::invalid_argument("This card is not in your possession ");
      }
      cards.remove(currCity);
      currCity = c;
      return *this;
  }
  pandemic::Player &pandemic::Player::fly_direct(pandemic::City c) {
      if (c == currCity) {
          throw std::invalid_argument("cYou are in the current city ");
      }
      if (find(cards.begin(), cards.end(), c) == cards.end()) {
          throw std::invalid_argument("This card is not in your possession ");
      }
      cards.remove(c);
      currCity = c;
      return *this;
  }
  pandemic::Player &pandemic::Player::fly_shuttle(pandemic::City c) {
      if (c == currCity) {
          throw std::invalid_argument("You are in the current city ");
      }
      if (!b.getStation(currCity) || !b.getStation(c)) {
          throw std::invalid_argument("There is no research-station in the city ");
      }
      currCity = c;
      return *this;
  }
  pandemic::Player &pandemic::Player::take_card(pandemic::City c) {
      if (find(cards.begin(), cards.end(), c) == cards.end()) {
          cards.push_front(c);
      }
      return *this;
  }
  pandemic::Player &Player::discover_cure(Color c, int num, bool color, bool station) {
      if (!station && !b.getStation(currCity)) {
          throw std::invalid_argument("There is no research-station in this city ");
      }

      vector <City> v;
      for (auto card: cards) {
          if (color || b.getColor(card) == c) {
              v.push_back(card);
          }
      }
      if (v.size() < num) {// In case we do not have enough cards, check only if they have already discovered a cure because their age just goes out otherwise throws an error
          if (b.getCure(c)) {
              return *this;
          }
          throw std::invalid_argument("You do not have enough cards ");
      }
      for (unsigned int i = 0; i < num; ++i) {
          cards.remove(v[i]);
      }
      b.setCure(c);

      return *this;
  }
  pandemic::Player &pandemic::Player::discover_cure(pandemic::Color c) {
      return discover_cure(c, FIVE, false, false);
  }
  pandemic::Player &pandemic::Player::remove_cards() {
      cards.clear();
      return *this;

  }
  string Player::role() {
      return "";
  }
