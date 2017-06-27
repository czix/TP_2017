#include "stdafx.h"
#include "draw.h"

class Human
{
	public:
		
		int pos_x;
		int pos_y;
		int finish_floor;
		int start_floor;
		bool w_windzie;
		bool delate;

		Human::Human(int x, int y)
		{
			start_floor = x;
			finish_floor = y;
			w_windzie = false;
			delate = false;
		}

};

class Floor
{
	private:

		int number;
		int start_x;
		int start_y;

	public:

		int how;
		bool stop;
		bool tab[max_on_floor];

		Floor::Floor(int n, int x, int y)
		{
			number = n;
			start_x = x;
			start_y = y;
			how = 0;
			stop = false;

			for (int i = 0; i < max_on_floor; i++)
				tab[i] = false;
		}

		int Floor::get_y()
		{
			return start_y;
		}

		int Floor::new_x()
		{
			int x;

			if (number == 0 || number == 2 || number == 4)
				x = start_x - how * 30;

			if (number == 1 || number == 3)
				x = start_x + how * 30;

			return x;
		}
};

class Winda
{
	public:
		int how;
		int pos_y;
		int pos_x;
		bool up;

		Winda::Winda()
		{
			how = 0;
			pos_y = 628;
			up = true;
		}

		int Winda::new_pos()
		{
			int x;

			x = 260 + how * 30;

			pos_x = x;
			return x;
		}
};