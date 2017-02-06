#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int N, answer=0;
    vector<pair<int,int> > v; // pair(value, index)
    scanf("%d",&N);
    v.resize(N);
    for(int i=0; i<N; i++){
        scanf("%d",&v[i].first); // value
        v[i].second = i; // index
    }
    sort(v.begin(),v.end());
    for(int i=0; i<N; i++)
        answer = max(answer, v[i].second-i);
    printf("%d",answer+1);
    return 0;
}
