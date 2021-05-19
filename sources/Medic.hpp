#pragma once
#include "Player.hpp"

namespace pandemic{
  class Medic : public Player{
  public:
      Medic(Board& b, City c): Player(b, c){treat();};// Automatically checks in the city he is in if there is a cure

       Player& drive(City) override;

       Player& treat(City) override;

       Player& fly_direct(City) override;

       Player& fly_charter(City) override;

       Player& fly_shuttle(City) override;

       void treat();

       string role() override;

  };
}
