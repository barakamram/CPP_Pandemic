

#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "OperationsExpert.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace pandemic;

Board board;

TEST_CASE("Board"){

		CHECK(board.is_clean() == true);
		board[City::Lima] = 3;
		CHECK_FALSE(board.is_clean());
		CHECK(board[City::Lima]==3);
		Medic m {board, City::Lima};
		m.treat(City::Lima);
		CHECK(board.is_clean() == true);
		Dispatcher d {board,City::Miami};
		board[City::Bangkok] = 2;
		CHECK(board[City::Bangkok]==2);
		d.fly_direct(City::Bangkok);
		d.treat(City::Bangkok);
		CHECK(board[City::Bangkok]==1);
		d.treat(City::Bangkok);
		CHECK(board[City::Bangkok]==0);
		CHECK(board.is_clean() == true);
		CHECK_THROWS(d.treat(City::Bangkok));
		CHECK_NOTHROW(d.drive(City::SaoPaulo));
		CHECK_NOTHROW(d.drive(City::Madrid));
		CHECK_NOTHROW(d.drive(City::Atlanta));
		CHECK_NOTHROW(d.build());
		d.take_card(City::Paris);
		CHECK_NOTHROW(d.fly_direct(City::Paris));

		d.take_card(City::Milan);
		CHECK_NOTHROW(d.fly_charter(City::Milan));

		d.take_card(City::Mumbai);
		CHECK_NOTHROW(d.fly_shuttle(City::Mumbai));

}
TEST_CASE("Players") {
	
		OperationsExpert o {board, City::Miami};
		CHECK(o.role() == "OperationsExpert");

		Dispatcher d {board, City::Miami};
		CHECK(d.role() == "Dispatcher");

		Scientist s {board, City::Miami};
		CHECK(s.role() == "Scientist");

		Researcher r {board, City::Miami};
		CHECK(r.role() == "Researcher");

		Medic m {board, City::Miami};
		CHECK(m.role() == "Medic");

		Virologist v {board, City::Miami};
		CHECK(v.role() == "Virologist");

		GeneSplicer g {board, City::Miami};
		CHECK(g.role() == "GeneSplicer");

		FieldDoctor f {board, City::Miami};
		CHECK(f.role() == "FieldDoctor");

	}
