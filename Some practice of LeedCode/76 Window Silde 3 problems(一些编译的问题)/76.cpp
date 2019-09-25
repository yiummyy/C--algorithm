#include <iostream>
#include <string.h>
using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char minwindow(string s,string t)
{
	int start = 0, minlen = INI_MAX;
	int left,right = 0;
	unordered_map<char, int> window;
    unordered_map<char, int> needs;
    for(char c : t) needs[c]++;
	while(right < s.size())
	{
		char c1 = s[right];
		if(needs.count(c1))
		{
			window[c1]++;
			if(window[c1]==needs[c1]) match++;
		}
		while(match == needs.size())
		{
			if(right - left<minlen)
			{
				start = left;
				minlen = right - left;
			}
			char c2 = s[left];
			if(needs.count(c2))
			{
				windows[c2]--;
				if(windows[c2] < needs[c2]) match--;
			}
		}	
	}
	return minlen == INI_MAX?"":s.substr(start, minlen);
} 
int main(int argc, char** argv) 
{
	string minwindow("cbaebabacd","abc");
}
