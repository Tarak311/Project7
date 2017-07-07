#include<iostream>
#include<iomanip>
#include<conio.h>
#include<map>
#include<math.h>
using namespace std;
void set_arrary(map<int, bool*> &mappedkey, int no_states_connected, int bin_len);
void print(map<int, bool*>	&mappedkey, int no_states_connected, int bin_len);


void main()
{
	int no_of_ip, no_states,no_states_connected,bin_len;
	no_of_ip = 2, no_states = 4, no_states_connected = 2, bin_len = 4;

	map<int, bool*> states_relation;

	map<int, bool*> input;

	map<int, bool*> total_relation;
	set_arrary(states_relation, no_states_connected, bin_len);
	print(states_relation, no_states_connected, bin_len);
	system("pause");
	 

}

void set_arrary(map<int, bool*>	&mappedkey, int no_states_connected, int bin_len)
{
	for (int i = 0; i < no_states_connected; i++)
	{
		bool *bino = new bool[bin_len];
		mappedkey[i] = bino;
		cout << "Enter value" << i << ":" << endl;
		for (int j = 0; j < bin_len; j++)
		{
			bool a;
			cin >> a;
			*bino = a;
			bino++;
		}
	}
}

void print(map<int, bool*>	&mappedkey, int no_states_connected, int bin_len)
{
	bool *r;
	r = (mappedkey[0]);
	for (int i = 0; i < bin_len; i++)
	{
		cout << *r << endl; r++;
	}
	
}