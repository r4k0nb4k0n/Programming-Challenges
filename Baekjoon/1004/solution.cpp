/* Programming-Challenges
 * Baekjoon
 * 1004
 * 2018-11-05 r4k0nb4k0n
 */

#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
};

struct PlaneterySystem
{
    Point c;
    int r;
};

int T, n, count=0;
Point depart, arrival;
vector<PlaneterySystem> list;

bool isIncluded(PlaneterySystem ps, Point p)
{
    int dx = ps.c.x - p.x;
    int dy = ps.c.y - p.y;

    if(dx * dx + dy * dy <= ps.r * ps.r) return true;
    else return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;
    while(T--){
        // Initialization.
        list.clear(); count = 0;

        // Input.
        cin >> depart.x >> depart.y >> arrival.x >> arrival.y;
        cin >> n;
        list.resize(n);
        for(int i=0; i<n; i++){
            cin >> list[i].c.x >> list[i].c.y >> list[i].r;
        }

        // Count if depart xor arrival point(not both) is included in the planetery system.
        for(PlaneterySystem i : list){
            if(isIncluded(i, depart) ^ isIncluded(i, arrival)) count += 1;
        }

        cout << count << "\n";
    }

    return 0;
}