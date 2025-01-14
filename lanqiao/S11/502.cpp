#include <iostream> 
#include <vector>
using namespace std;
int main(){
    int p, temp;
    vector<int> g;
    vector<int> y;
    cin >> p;
    for (int i = 0; i < p; i++) {
        cin >> temp;
        if (temp >= 85) {
            y.push_back(temp);
        } else if (temp >= 60) {
            g.push_back(temp);
        }
    }
    int gn, yn;
    int a = g.size();
    gn = ((g.size()+y.size()) * 100.0 / p) + 0.5; 
    yn = (y.size() * 100.0 / p) + 0.5; 
    cout << gn << "%" << endl;
    cout << yn << "%" << endl;
    return 0;
}
