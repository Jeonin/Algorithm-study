#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<string> words;
bool alphabet[26];
int ans = 0;

bool check(const string& word)
{
	
	for (int i = 0; i < word.length(); ++i)
	{

		if (alphabet[word[i] - 'a'] == false)
			return false;		
	}
	return true;
}

void Read(int idx, int cnt)
{
	if (cnt == k)
	{
		int sum = 0;
		for (auto it : words)
		{
			if (check(it))
				sum++;
		}

		ans = max(ans, sum);
		return;
	}


	for (int i = idx; i < 26; ++i)
	{		
		if(alphabet[i]) continue;

		alphabet[i] = true;		
		Read(i, cnt + 1);
		alphabet[i] = false;
	}
}

int main()
{	
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i)
	{
		string word;
		cin >> word;
		words.emplace_back(word);
	}

	
	if (k < 5)
	{
		cout << 0;
		return 0;
	}

	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;

	k -= 5;
	Read(0, 0);

	cout << ans;
	return 0;
}