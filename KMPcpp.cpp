#include<iostream>
#include<vector>
#include<string>
using namespace std;

class KMP_match
{
public:
	vector<int> nexts;
	string s;
	string m;//表示match字符串
	KMP_match(string s_str, string m_str)
	{
		s = s_str;
		m = m_str;
	}
	void get_nexts();
	int get_index();
	
};
void KMP_match::get_nexts()
{
	nexts.resize(m.size());
	if (m.size() < 1)
		return;
	nexts[0] = -1;
	nexts[1] = 0;
	int cur_idx = 2;
	int cm =nexts[cur_idx-1];//0
	while (cur_idx < m.size())
	{
		if (m[cur_idx - 1] == m[cm])
		{
			nexts[cur_idx] = ++cm;
			cur_idx++;
		}
		else if (cm > 0)
			cm = nexts[cm];
		else
			nexts[cur_idx++] = 0;
	}
	return;
}

int KMP_match::get_index()//在字符串s中找到匹配字符串m的字符串的起始索引
{
	if (s.size() < 1 || m.size() < 1 || m.size() > s.size())
		return -1;
	int i = 0, j = 0;
	while (i < s.size() && j < m.size())
	{
		if (s[i] == m[j])
		{
			i++;
			j++;
		}
		else if (j == 0)//nexts[j]==-1
		{
			i++;
		}
		else
		{
			j = nexts[j];
		}
	}
	return j == m.size() ? i - j : -1;
}
int main()
{
	string str1 = "aabaabaac";
	string str2 = "aabaac";
	KMP_match kmp(str1, str2);
	kmp.get_nexts();
	int res = kmp.get_index();
	cout << res << endl;
	return 0;
}
