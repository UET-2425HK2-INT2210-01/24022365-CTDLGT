#include <bits/stdc++.h>

using namespace std;

void dao(string a){
    reverse(a.begin(), a.end());
    cout << a;
}
int main(){
    string a;
    getline(cin, a);
    dao(a);
    return 0;
}