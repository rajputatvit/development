#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
//enum color
//{
//	RED,
//	BLACK,
//	BLUE,
//	WHITE
//}card_color;
//
//class card
//{
//public:
//	enum card_color
//};
class deck
{
	vector<int>cards;
	int size;
public:
	deck()
	{
		size = 52;

		for (int i = 0; i < size; ++i)
		{
			cards.push_back(i + 1);
		}	
	}

	void display()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << cards[i] << endl;
		}
	}

	void shuffle()
	{
		for (int i = 0; i < 26; ++i)
		{
			srand(time(0));

			int ind_i = i ;
			cout << ind_i <<  " : ";
			int ind_j = rand() % size;
			cout << ind_j << endl;

			//swap
			int k = cards[ind_i];
			cards[ind_i] = cards[ind_j];
			cards[ind_j] = k;
		}
	}
};

using namespace std;

int main()
{
	deck deck_obj;
	//deck_obj.display();
	deck_obj.shuffle();
	deck_obj.display();

	return 0;
}