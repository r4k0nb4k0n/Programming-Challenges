#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int C;  // The number of test cases.
int n, m;   // The number of students, The number of friendly pairs.
bool are_friends[10][10];

int count_cases(bool paired[10]){
    // In left students, find first earlier-numbered student.
    int first_not_paired = -1;
    for(int i=0; i<n; i++){
        if(!paired[i]){
            first_not_paired = i;
            break;
        }
    }
    // If all students got matched, count 1 and done.
    if(first_not_paired == -1) return 1;
    int ret = 0;
    for(int who_will_be_paired = first_not_paired + 1; who_will_be_paired < n; who_will_be_paired++){
        // If they are not paired each other yet and are friends?
        if(!paired[who_will_be_paired] && are_friends[first_not_paired][who_will_be_paired]){
            paired[first_not_paired] = paired[who_will_be_paired] = true;
            ret += count_cases(paired);
            paired[first_not_paired] = paired[who_will_be_paired] = false;
        }
    }
    return ret;
}

int main(){
    cin >> C;
    while(C--){
        memset(are_friends, false, sizeof(are_friends));
        cin >> n >> m;
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            are_friends[u][v] = are_friends[v][u] = true;
        }
        bool paired[10];
        memset(paired, false, sizeof(paired));
        cout << count_cases(paired) << "\n";
    }   
    return 0;
}
