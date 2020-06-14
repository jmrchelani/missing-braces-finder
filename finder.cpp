#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int getUnused(int arr[])
{
	for(int a = 0; a < 100; a++)
	{
		if(arr[a] == -1) return a;
	}
}

int main()
{
	string name;
	cout<<"enter name of file: "; getline(cin, name);
	cin;
	ifstream file;
	file.open(name.c_str());
	if(!file.is_open()) return 0;
	string line;
	int oC = 0, cC = 0, linenumber = 1, openBrace[100], ezpz = 0, meh = -1, lastIn[100];
	for(int zz = 0; zz < 100; zz++) { openBrace[zz] = -1; lastIn[zz] = -1;}
	while(getline(file, line))
	{
		for(int i = 0, len = line.length(); i < len; i++)
		{
			if(line[i] == '{')
			{
				meh = getUnused(openBrace);
				openBrace[meh] = linenumber;
				lastIn[ezpz] = meh;
				ezpz++;
			}
			if(line[i] == '}')
			{
				ezpz--;
				openBrace[lastIn[ezpz]] = -1;
			}
		}
		linenumber++;
	}
	for(int b = 0; b < 100; b++){
		if(openBrace[b] != -1){
			cout<<"There is an unclosed brace at line number: " << openBrace[b] <<endl;
		}
	}
}
