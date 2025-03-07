#include <iostream>
#include <vector>
#include <list>
using namespace std;
void dfs(vector <list <int>>& mas,vector<short>&colo,int num1,int i1,vector<int>& anss,int& ind_ele)
{
 for (auto i:mas[i1])
    {
     if (colo[i]==0)
     {
         colo[i]=1;
         dfs(mas,colo,num1,i,anss,ind_ele);
     }
 }
 anss[i1]=ind_ele;
 ind_ele--;
 return;
}
int main() {
    int num=0,cpairs=0;
    cin>>num>>cpairs;
    vector <list <int>> mass(num);
    vector <short> color(num);
    vector <int> ans(num);
    int ind_elem=num;
    for (int i=0;i<cpairs;i++)
    {
        int j,h;
        cin>>j>>h;
        mass[j-1].push_back(h-1);
    }
    for (int i=0;i<num;i++)
    {
        if (color[i]==0)
        {
            color[i]=1;
            dfs(mass,color,num,i,ans,ind_elem);
        }
    }
    for (auto i: ans)
    {
        cout<<i<<" ";
    }
    return 0;
}
