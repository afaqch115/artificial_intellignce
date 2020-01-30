#include<iostream>
#include<algorithm>
#include <cstdlib>
#include<ctime>
#include<vector>
#include<string>

using namespace std;
struct Position;			//defination of structure
class Queue;				//defination of class
void succeedingNode(Position);
int len(Position,string);
void trasverse(Position,int);

struct Position				//declaration of structure
{
public:
	string str;
	int h_value;
	int level;
	string parent;
	Position()
	{

	}
	Position(string s, int h_val, int l,string p)
	{
		str = s;
		h_value = h_val;
		level = l;
		parent=p;
	}

};

class Queue 					//declaration of class
{
	long MAX_SIZE;
	string *node;
	int* h_value;
	int* level;
	int rear;
	string *parent;

public:
	Queue(long size)
	{
		MAX_SIZE = size;
		node = new string[size];
		h_value = new int[size];
		level = new int[size];
		rear = -1;
		parent=new string[size];
	}
	void enqueue(Position s)
	{
		if (rear!=(MAX_SIZE-1))
		{
			rear++;
			node[rear] = s.str;
			h_value[rear] = s.h_value;
			level[rear] = s.level;
			parent[rear]=s.parent;
		}
		else 
			cout << "Queue is Full!"<< endl;
	}
	Position dequeue()
	{
		if (isEmpty())
		{
			string e = "Exception Queue is already Empty Buddy!";
			throw e;
		}
		Position s(node[0],h_value[0],level[0],parent[0]);
		for (int i = 0; i !=rear;i++)
		{
			node[i] = node[i+1];
			h_value[i] = h_value[i+1];
			h_value[i] = h_value[i+1];
			parent[i] = parent[i+1];
		}
		rear--;
		return s;
	}
	void clear()
	{
		if (isEmpty())
		{
			cout << "Queue is already empty!"<<endl;
		}
		else
			rear=-1;
	}
	bool isEmpty()
	{
		if (rear == -1)
			return true;
		else 
			return false;
	}
	bool isFull()
	{
		if (rear==MAX_SIZE)
			return true;
		else 
			return false;
	}
	void showstructure()
	{
		for (int i = 0 ; i <=rear ; i++)
		{
			string s=node[i];
			cout << s[0]<<s[1]<<s[2]<<endl;
			cout << s[3]<<s[4]<<s[5]<<endl;
			cout << s[6]<<s[7]<<s[8]<<endl<<endl;
		}
	}
	bool search(Position s)
	{
		for (int i = 0 ; i <=rear ; i++)
		{
			if(s.str==node[i])
				return true;
		}
		return false;
	}
	Position getSearchedNode(Position s)
	{
		Position s1;
		for (int i = 0 ; i <=rear ; i++)
		{
			if(s.str==node[i] && s.level==level[i] && s.h_value==h_value[i])
			{
				s1.str=node[i];
				s1.level=level[i]; 
				s1.h_value=h_value[i];
				s1.parent=parent[i];
				return s1;
			}
		}
		return s1;
	}
	void sort()
	{
		for (int i = 0 ; i <=rear ; i++)
		{
			for (int j = i+1 ; j <=rear ; j++)
			{
				if(h_value[i] > h_value[j])
				{
					swap(node[i],node[j]);
					swap(h_value[i],h_value[j]);
					swap(level[i],level[j]);
					swap(parent[i],parent[j]);
				}
			}
		}
	}
	int size()
	{
		return rear;
	}
	void updateHeuristic(string s,int h,int l,string p)
	{
		for (int i = 0 ; i <=rear ; i++)
		{
			if(s==node[i])
			{
				h_value[i]=h;
				parent[i]=p;
				level[i]=l;
			}
		}
	}
	void remove(Position s)
	{
		for (int i = 0 ; i <=rear ; i++)
		{
			if(s.str==node[i] && s.h_value==h_value[i] && s.level==level[i])
			{
				for (int j = i ; j !=rear ; j++)
				{
					node[i] = node[i+1];
					h_value[i] = h_value[i+1];
					level[i] = level[i+1];
					parent[i] = parent[i+1];
				}
				rear--;
				break;
			}
		}
	}
	bool checkDuplicates()
	{
		for(int i = 0 ; i <rear ; i++)
		{
			for(int j = i+1 ; j <=rear ; j++)
			{
				if(node[i]==node[j])
				{
					cout<<"Duplicate\n";
					return true;
				}
			}
		}
		return false;
	}
	string printParent(string str)
	{
		for(int i=0;i<=rear;i++)
		{
			if(node[i]==str)
			{
				string s=node[i];
				for(int j=0;j<s.length();j++)
				{
					if(j%3==0)
						cout<<endl;
					cout<<s[j];
				}
				cout<<endl<<endl;
				return parent[i];
			}
		}
	}
	~Queue()				//destructor
	{
		delete []node;
		delete []h_value;
		delete []level;
	}
};

Queue q(8);
void trasverse(Position str,int i,string goal)
{
	Position s1;
	if(i==0)
	{
		s1.str     =  str.str;
		swap(s1.str[i],s1.str[1]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[1]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[3]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[3]);

	}
	else if(i==2)
	{
		s1.str     =  str.str;
		swap(s1.str[i],s1.str[1]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[1]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[5]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[5]);

	}
	else if(i==6)
	{
		s1.str     =  str.str;
		swap(s1.str[i],s1.str[3]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[3]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[7]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[7]);

	}
	else if(i==8)
	{
		s1.str     =  str.str;
		swap(s1.str[i],s1.str[5]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[5]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[7]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[7]);

	}
	else if(i==1)
	{
		s1.str     =  str.str;
		swap(s1.str[i],s1.str[0]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[0]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[2]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[2]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[4]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[4]);

	}
	else if(i==3)
	{
		s1.str     =  str.str;
		swap(s1.str[i],s1.str[0]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[0]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[6]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[6]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[4]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[4]);

	}
	else if(i==5)
	{
		s1.str     =  str.str;
		swap(s1.str[i],s1.str[2]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[2]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[8]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[8]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[4]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[4]);
	}
	else if(i==7)
	{
		s1.str     =  str.str;
		swap(s1.str[i],s1.str[6]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[6]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[8]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[8]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[4]);
		s1.level   =  str.level+1;
		s1.parent = str.str;
		s1.h_value =  len(str,goal);
		q.enqueue(s1);
		swap(s1.str[i],s1.str[4]);

	}
	else if(i==4)
	{
		s1.str     =  str.str;
		swap(s1.str[i],s1.str[1]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[1]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[3]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[3]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[5]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[5]);

		s1.str     =  str.str;
		swap(s1.str[i],s1.str[7]);
		s1.level   =  str.level+1;
		s1.h_value =  len(str,goal);
		s1.parent = str.str;
		q.enqueue(s1);
		swap(s1.str[i],s1.str[7]);
	}
}
void succeedingNode(Position s,string goal)
{
	for(int i=0;i<9;i++)
	{
		if(s.str[i]=='0')
		{
			trasverse(s,i,goal);
			break;
		}
	}
}
int h2(Position s,string g) // Rows+cols
{
	int count=0;
	for(int i=0;i<9;i++)
	{
		if(s.str[i]!=g[i])
		{
			count++;
			if(i==0)
			{
				if(s.str[3]!=g[i] && s.str[6]!=g[i])
					count++;
			}
			else if(i==1)
			{
				if(s.str[4]!=g[i] && s.str[7]!=g[i])
					count++;
			}
			else if(i==2)
			{
				if(s.str[5]!=g[i] && s.str[8]!=g[i])
					count++;
			}
			else if(i==3)
			{
				if(s.str[0]!=g[i] && s.str[6]!=g[i])
					count++;
			}
			else if(i==4)
			{
				if(s.str[1]!=g[i] && s.str[7]!=g[i])
					count++;
			}
			else if(i==5)
			{
				if(s.str[2]!=g[i] && s.str[8]!=g[i])
					count++;
			}
			else if(i==6)
			{
				if(s.str[0]!=g[i] && s.str[3]!=g[i])
					count++;
			}
			else if(i==7)
			{
				if(s.str[1]!=g[i] && s.str[4]!=g[i])
					count++;
			}
			else if(i==8)
			{
				if(s.str[2]!=g[i] && s.str[5]!=g[i])
					count++;
			}
		}
	}
	return count+s.level;
}
int h3(Position s, string g) //TileReversal
{
	if (s.str == g)
	{
		return 0;
	}
	int c = 0;
	for (int i = 0; i < 9; i++)
	{
		if(s.str[i]=='0')
			continue;
		if (s.str[i] != g[i])
		{
			for (int j = 0; j < 9; j++)
			{
				if (g[i] == s.str[j])
				{
					swap(s.str[i], s.str[j]);
					if (s.str[j] == g[j])
					{
						c = c + 2;
					}
					swap(s.str[i], s.str[j]);
					break;
				}
			}
		}
	}
	return c;
}
int search(string s,char c)
{
	for(int i=0;i<9;i++)
	{
		if(s[i]==c)
		{
			return i;
		}
	}
	return -1;
}
struct coordinate
{
	int x;
	int y;
};
coordinate findcoordinate(int x)
{
	coordinate cor;
	if(x==0)
	{
		cor.x=0;
		cor.y=0;
	}
	else if(x==1)
	{
		cor.x=0;
		cor.y=1;
	}
	else if(x==2)
	{
		cor.x=0;
		cor.y=2;
	}
	else if(x==3)
	{
		cor.x=1;
		cor.y=0;
	}
	else if(x==4)
	{
		cor.x=1;
		cor.y=1;
	}
	else if(x==5)
	{
		cor.x=1;
		cor.y=2;
	}
	else if(x==6)
	{
		cor.x=2;
		cor.y=0;
	}
	else if(x==7)
	{
		cor.x=2;
		cor.y=1;
	}
	else if(x==8)
	{
		cor.x=2;
		cor.y=2;
	}
	return cor;
}
int h4(Position s,string g)
{
	int count=0;
	for(int i=0;i<9;i++)
	{
		if(s.str[i]=='0')
			continue;
		if(s.str[i]!=g[i])
		{
			int x = search(g,s.str[i]);
			coordinate cor1=findcoordinate(x);
			coordinate cor2=findcoordinate(i);
			count= count + abs(cor1.x-cor2.x) + abs(cor1.y-cor2.y);
		}
	}
	return count;
}
int h5(Position s,string g)
{
	int count=0;
	for(int i=0;i<9;i++)
	{
		if(s.str[i]!=g[i])
		{
			count++;
		}
	}
	return count;
}
int len(Position s,string g)
{
	
	return h4(s,g)/3;
}

void bfs(Position s,string goal)
{
	string save=s.str;
	Queue openQueue(99999);
	Queue closeQueue(99999);
	openQueue.enqueue(s);
	while(!openQueue.isEmpty())
	{
		Position s1 = openQueue.dequeue();
		if(s1.str==goal)
		{
			closeQueue.enqueue(s1);
			cout<<"Goal Position Reached!!\n";
			string str=s1.str;
			int count=1;
			while(str!=save)
			{
				count++;
				str = closeQueue.printParent(str);
			}
			closeQueue.printParent(str);
			cout<<"Total Moves: "<<count<<endl;
			return;
		}
		else
		{
			succeedingNode(s1,goal);
			while(!q.isEmpty())
			{
				Position s2=q.dequeue();
				if(openQueue.search(s2)==false)
				{
					if(closeQueue.search(s2)==false)
					{
						openQueue.enqueue(s2);
					}
				}
				else if(openQueue.search(s2))
				{
					Position s3=openQueue.getSearchedNode(s2);
					if(s3.h_value>s2.h_value)
					{
						openQueue.updateHeuristic(s3.str,s2.h_value,s2.level,s2.parent);
					}
				}
				else if(closeQueue.search(s2))
				{
					Position s3=closeQueue.getSearchedNode(s2);
					if(s3.h_value>s2.h_value)
					{
						closeQueue.updateHeuristic(s3.str,s2.h_value,s2.level,s2.parent);
						closeQueue.remove(s2);
						openQueue.enqueue(s3);
					}
				}
			}
			closeQueue.enqueue(s1);
			openQueue.sort();	
		}
	}
	cout<<"Goal Not Found!!!\n";
}
int main()
{
	string start="012345678";
	string goal= "724506831";
	Position s(start,0,0,start);
	s.h_value=len(s,goal);
	bfs(s,goal);
}


