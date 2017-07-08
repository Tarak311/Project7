#include<iostream>
#include<iomanip>
#include<conio.h>
#include<map>
#include<math.h>
using namespace std;
void set_arrary(map<int, bool*> &mappedkey, int no_states_connected, int bin_len);
void print(map<int, bool*>	&mappedkey, int no_states_connected, int bin_len);
void attach_map(map<int, bool*> mappedkey1, map<int, bool*> mappedkey2, map<int, bool*> &mappedkey3, int no_states_connected,int no_of_ip, int no_states, int bin_len);
struct cell
{
	int o;
};

cell*** Grey_matrix(int r, int c);

void const_matrix(int r, int c,cell*** matrix );



void main()
{
	int no_of_ip, no_states,no_states_connected,bin_len;
	no_of_ip = 3, no_states = 3, no_states_connected = 2, bin_len = 6;
	map<int, bool*> states_relation;
	map<int, bool*> input;
	map<int, bool*> total_relation;
	set_arrary(states_relation, no_states_connected, no_states);
	print(states_relation, no_states_connected, no_states);
	set_arrary(input, no_states_connected, no_of_ip);
	attach_map(states_relation, input, total_relation, no_states_connected, no_of_ip, no_states, bin_len);
	print(total_relation, no_states_connected, bin_len);
	cell ***Grey_mat = Grey_matrix(3, 3);
	const_matrix(3, 3, Grey_mat);
	
	
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
void attach_map(map<int, bool*> mappedkey1, map<int, bool*> mappedkey2, map<int, bool*> &mappedkey3, int no_states_connected, int no_of_ip, int no_states, int bin_len)
{
	for (int i = 0; i < no_states_connected; i++)
	{
		bool *bino0 = new bool[bin_len];
		bool *bino1 = new bool[no_of_ip];
		bool *bino2 = new bool[no_of_ip];
		mappedkey3[i] = bino0;
		bool *a,*b;
		a = (mappedkey1[0]);
		b = (mappedkey2[0]);
		
		for (int j = 0; j <bin_len; j++)
		{
			if (j < no_of_ip)
			{
				
				*bino0 = *a;
				a++;
				bino0++;
			}
			else
			{
				*bino0 = *b;
				b++;
				bino0++;

			}
		}
	}

}

cell*** Grey_matrix(int r, int c)
{
	
	r = c;
	cell*** Grey_Matrix = new cell**[r];
	for (int i = 0; i < r; ++i)
		Grey_Matrix[i] = new cell*[c];
	return Grey_Matrix;
}

void const_matrix(int r, int c, cell*** matrix )
{
	for (int x = 0; x < r; x++)
	{
		for (int y = 0; y < c; y++)
		{
			cell i;
			matrix[x][y] = &i;
			cout << hex << &i;
			cout<<"  ";
		}
		cout << "/n"<<endl;
	}
}
