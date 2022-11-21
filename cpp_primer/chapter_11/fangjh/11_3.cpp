#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string,int> word_count;
	string word;
	while(cin>>word){
		++word_count[word];
	}
	for(auto w:word_count){
		cout<<w.first<<" "<<w.second<<endl;
	}

   return 0;
}