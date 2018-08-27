#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n; // the number of cities in Lineland
    scanf("%d",&n);
    vector<int> value;
    value.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&value[i]);

    vector<pair<int,int> > answer; // .first : shortest, .second : longest
    answer.resize(n);

    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            answer[i].first = abs(value[i] - value[i+1]);
            answer[i].second = abs(value[i] - value[n-1]);
        }
        else if(i == n-1)
        {
            answer[i].first = abs(value[i] - value[i-1]);
            answer[i].second = abs(value[i] - value[0]);
        }
        else
        {
            if(abs(value[i] - value[i-1]) < abs(value[i] - value[i+1])) // left < right
                answer[i].first = abs(value[i] - value[i-1]);
            else
                answer[i].first = abs(value[i] - value[i+1]);

            if(abs(value[i] - value[0]) > abs(value[i] - value[n-1])) // left > right
                answer[i].second = abs(value[i] - value[0]);
            else
                answer[i].second = abs(value[i] - value[n-1]);
        }

    }

    for(int i=0;i<n;i++)
        printf("%d %d\n",answer[i].first,answer[i].second);

    return 0;
}
