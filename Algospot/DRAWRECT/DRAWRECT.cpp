#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;

int main(){
    cin >> T;
    while (T--){
        vector<pair<int, int> > points;
        for(int i=0; i<3; i++){
            int x, y;
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }
        sort(points.begin(), points.end());
        if(points[1].first == points[2].first){
            if(points[0].second == points[1].second){
                cout << points[0].first << " " << points[2].second;
            }
            else{
                cout << points[0].first << " " << points[1].second;
            }
        }
        else if(points[0].first == points[1].first){
            if(points[0].second == points[2].second){
                cout << points[2].first << " " << points[1].second;
            }
            else{
                cout << points[2].first << " " << points[0].second;
            }
        }
        cout << "\n";
    }
    return 0;
}
