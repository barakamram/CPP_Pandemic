#pragma once
#include <vector>
#include <string>
#include <map>
#include <list>
#include "City.hpp"
#include "Color.hpp"

using namespace std;
namespace pandemic {
    class Board {
    private:
      map<City, Color> colors;
      map<City, int> cubes;
      map<Color, bool> cures;
      map<City, list<City>> nei;
      map<City, bool> stations;

    public:
      static map<City, string> cities;
      friend ostream &operator<<(ostream &os, Board &b);
      Board();
      int& operator[](City);
      bool neighbors(City c1, City c2);
      void buildStation(City c, bool s);
      bool getStation(City);
      void setCure(Color);
      bool getCure(Color);
      bool getCure(City);
      Color getColor(City);
      bool is_clean();
      void remove_cures();
      void remove_stations();
    };
}
