#include <iostream>
#include <set>

using namespace std;

int main(){
    string s;
    cin >> s;
    set<string> box;
    for(int i=1;i<=s.length();i++){
        for(int j=0;j<s.length();j++){
            if(j+i-1<s.length()){
                box.insert(s.substr(j,i));
            }
        }
    }

    cout << box.size();


    return 0;
}