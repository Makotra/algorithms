#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;
void bfs(vector <list <int>>& mas,queue <int>& queue,vector<int>& anss)
{
    while (!queue.empty())
    {
        int u=queue.front();
        queue.pop();
        for (auto v: mas[u])
        {
            if (anss[v]==-10000)
            {
                anss[v]=anss[u]+1;
                queue.push(v);
            }
        }
    }
    return;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int num=0,cpairs=0,destination=0;
    cin>>num;
    cin>>cpairs>>destination;
    vector <list <int>> mass(num);
    queue <int> queue;
    vector <int> ans(num,INT_MIN);
    for (int i=0;i<cpairs;i++)
    {
        int j,h;
        cin>>j>>h;
        mass[j-1].push_back(h-1);
        mass[h-1].push_back(j-1);
    }
    ans[0]=0;
    queue.push(0);
    bfs(mass,queue,ans);
    bool found = false;
    for (int i = 0; i < num; i++)
    {
            if (ans[i] == destination) {
                cout << i + 1 << '\n';
                found = true;
            }
    }

    if (!found) {
        cout << "NO";
    }
    return 0;
}
