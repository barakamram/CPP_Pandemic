#pragma once
#include "Player.hpp"

namespace pandemic{
    class Scientist: public Player{
    private:
      int num;
    public:
      Scientist(Board& b, City c, int n): Player(b, c), num(n){};
      Player& discover_cure(Color) override;
      string role() override;
    };
}
