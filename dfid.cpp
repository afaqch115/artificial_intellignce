#include<string>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
struct Position;		//structure
class Grid;				//class

void trasverse(Position, int,int);
void findSuccessorNode(Position);
struct Position			//declaration of structure
{
public:
	string str;
	int level;
	Position()
	{

	}
	Position(string s, int l)
	{
		str = s;
		level = l;
	}

};
class Grid					//declaration of class
{
	string *str;
	int *level;
	int arraySize;
	int end;
public:
	Grid(int size)
	{
		str = new string[size];
		level = new int[size];
		arraySize = size;
		end = 0;
	}
	bool full()				//bool function
	{
		return (end == arraySize);
	}
	bool empty()
	{
		return(end == 0);
	}
	void insert(string s,int l)		//inert value
	{
		if (!full())
		{
			this->str[end] = s;
			this->level[end]= l;
			end++;
		}
	}
	Position remove()
	{
		Position temp;
		if (!empty())
		{
			end--;
			temp.str = str[end];
			temp.level = level[end];
			return temp;
		}
	}
	void display()				//display
	{
		for (int i = 0; i < end; i++)
		{
			cout << "Position: " << str[i] << endl;
			cout << "level: " << level[i] << endl;
		}
	}
	~Grid()					//destructor
	{
		delete[] str;
		delete[] level;
	}

};
Grid l(1000);

void trasverse(Position str, int i, string goal,int depth)
{
	Position s1;
	if(depth==str.level)
	{
		return;
	}
	if (i == 0)
	{
		s1.str = str.str;
		swap(s1.str[i], s1.str[1]);
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[1]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[3]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);

	}
	else if (i == 2)
	{
		s1.str = str.str;
		swap(s1.str[i], s1.str[1]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[1]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[5]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[5]);

	}
	else if (i == 6)
	{
		s1.str = str.str;
		swap(s1.str[i], s1.str[3]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[3]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[7]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[7]);

	}
	else if (i == 8)
	{
		s1.str = str.str;
		swap(s1.str[i], s1.str[5]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[5]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[7]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[7]);

	}
	else if (i == 1)
	{
		s1.str = str.str;
		swap(s1.str[i], s1.str[0]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[0]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[2]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[2]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[4]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[4]);

	}
	else if (i == 3)
	{
		s1.str = str.str;
		swap(s1.str[i], s1.str[0]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[0]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[4]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[4]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[6]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[6]);

	}
	else if (i == 5)
	{
		s1.str = str.str;
		swap(s1.str[i], s1.str[2]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[2]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[4]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[4]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[8]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[8]);
	}
	else if (i == 7)
	{
		s1.str = str.str;
		swap(s1.str[i], s1.str[4]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[4]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[6]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[6]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[8]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[8]);

	}
	else if (i == 4)
	{
		s1.str = str.str;
		swap(s1.str[i], s1.str[1]);
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[1]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[3]);
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[3]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[5]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[5]);

		s1.str = str.str;
		swap(s1.str[i], s1.str[7]);
		 
		s1.level = str.level + 1;
		l.insert(s1.str,s1.level);
		swap(s1.str[i], s1.str[7]);
	}
}
void succeedingNode(Position s, string goal,int d)		//to check su
{
	for (int i = 0; i<s.str.length(); i++)
	{
		if (s.str[i] == '0')
			trasverse(s, i, goal,d);
	}
}

void dfid(Position s, Position g,int depth)		//itertive deeping with user's bound
{
	l.insert(s.str,s.level);
	while(!l.empty())
	{
		Position s1=l.remove();
		if(s1.str==g.str)
		{
			cout<<"Goal Found!!\n";
			return;
		}
		else
		{
			succeedingNode(s1,g.str,depth);
		}
	}
}
int main()
{	
	string st_state = "012345678";
	string gl_state = "724506831";
	Position s(st_state, 0);
	Position g(gl_state, 0);
	int d;
	cout<<"Enter Depth: ";
	cin>>d;
	dfid(s, g,d);

}
