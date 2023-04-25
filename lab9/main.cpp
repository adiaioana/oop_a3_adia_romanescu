#include <string>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("A.txt");

map<string, int> fr;

class Comp {
public:
	bool operator()(pair<string,int> below, pair<string,int> above)
	{
		if (below.second < above.second) {
			return true;
		}
		else if (below.second == above.second
			&& below.first > above.first) {
			return true;
		}

		return false;
	}
};

priority_queue <pair<string, int>, vector<pair<string, int>>, Comp> pq;

string tokens = ". ;,'?!~`:";
inline void scan(string &in);
inline void split(string in);
//inline void double_alloc(string*& in);
inline void printwords();
inline void frequency(string A);
inline void sort_priority();

int main()
{
	int dim = 0;
	string str; str.clear();


	scan(str);
	cout << str << endl;
	split(str);

	sort_priority();
	printwords();
	return 0;
}

inline void sort_priority()
{
	for (auto it : fr)
		pq.push({ it.first,it.second });
}

inline void printwords()
{
	cout << pq.size() << endl;
	while(!pq.empty())
	{
		pair<string,int> it = pq.top(); pq.pop();
		cout << it.first << " => " << it.second << endl;
	}
}
inline void frequency(string S)
{
		map<string,int>::iterator it = fr.find(S);
		if (it != fr.end())
		{
			int cpy = it->second;
			fr.erase(it);
			fr.insert({ S, cpy + 1 });
		}
		else {
			fr.insert({ S,1 });
		}

}

inline void scan(string &in)
{
	getline(fin,in);
}

inline void split(string in)
{

	int end = -1;
	int inc = in.find_first_not_of(tokens, 0);

	while (inc != string::npos)
	{
		end = in.find_first_of(tokens, inc + 1);
		//cout << inc << ' ' << end << endl;
		//cout << it << ' ' << nxt << endl;
		if (inc < end)
		{
			string aux = in.substr(inc, end - inc);
			for (int i = 0; i < aux.size(); ++i)
				if (aux[i] >= 'A' && aux[i] <= 'Z')
					aux[i] = aux[i] - 'A' + 'a';
			frequency(aux);
		}
		else {
			string aux = in.substr(inc, in.size() - inc);
			for (int i=0; i<aux.size(); ++i)
				if (aux[i] >= 'A' && aux[i] <= 'Z')
					aux[i] = aux[i] - 'A' + 'a';
			frequency(aux);
		}
		inc = in.find_first_not_of(tokens, end);
	}
}
/*
inline void double_alloc(string* &in)
{
	string* aux = new string[2 * max_size];
	for (int i = 0; i < max_size; ++i)
		aux[i] = in[i];
	for (int i = 0; i < max_size; ++i)
		in[i].clear();
	delete[] in;
	in = new string[2 * max_size];
	max_size *= 2;
	for (int i = 0; i < max_size; ++i)
		in[i] = aux[i];
}*/