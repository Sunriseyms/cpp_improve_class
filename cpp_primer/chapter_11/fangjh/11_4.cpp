#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){
    map<string,int> word_c;
    set<char> ex={',','.','?'};
    string word;
    while(cin>>word){
        if(ex.find(*word.rbegin())!=ex.end()){
            word.pop_back();
        }
        auto &c=word[0];
        c=tolower(c);
        ++word_c[word];
    }
	for(auto w:word_c){
		cout<<w.first<<" "<<w.second<<endl;
	}
    
    return 0;
}