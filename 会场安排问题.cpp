#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


struct Time
{
	int t;
	bool start;
};

bool TimeBigger(Time t1,Time t2)
{
	return t1.t < t2.t;
}

int greedy(vector<Time> t)
{
	int count = 0, max = 0;
	for (size_t i = 0; i < t.size(); i++)
	{
		if (t[i].start)
		{
			count++;
		}
		else
		{
			count--;
		}
		if (count>max)
		{
			max = count;
		}
	}
	return max;
}
int main()
{

	int n;
	vector<Time> t;
	while (in>>n)
	{
		Time temp;
		for (size_t i = 0; i < n; i++)
		{
			in >> temp.t;
			temp.start = true;
			t.push_back(temp);
			in >> temp.t;
			temp.start = false;
			t.push_back(temp);
		}
		sort(t.begin(), t.end(), TimeBigger);
		out << greedy(t)<< endl;

	}
	in.close();
	out.close();
	return 0;
}