#include "FieldDoctor.hpp"

  pandemic::Player& pandemic::FieldDoctor::treat(pandemic::City c) {
      if(!b.neighbors(c,currCity)){
          throw std::invalid_argument("The cities are not neighbors");
      }
      City temp = currCity;
      currCity = c;
      Player::treat(c);
      currCity = temp;
      return *this;
  }

  string pandemic::FieldDoctor::role() {
      return "FieldDoctor";
  }
