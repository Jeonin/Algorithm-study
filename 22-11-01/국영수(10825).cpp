#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct info
{
	int hangel;
	int english;
	int math;
	string name;
};

int main()
{
	int n;
	cin >> n;
	vector<info> student_info;

	for (int i = 0; i < n; ++i)
	{
		string studentname;
		int hangelscore, englishscore, mathscore;

		cin >> studentname >> hangelscore >> englishscore >> mathscore;
		student_info.push_back({ hangelscore, englishscore, mathscore, studentname });
	}

	sort(student_info.begin(), student_info.end(), [](info a, info b)->bool
	{
		if (a.hangel != b.hangel) return a.hangel > b.hangel;
		if (a.english != b.english) return a.english < b.english;
		if (a.math != b.math) return a.math > b.math;
		
		return a.name < b.name;
	});

	for (auto it : student_info)
		cout << it.name << '\n';

	return 0;
}
