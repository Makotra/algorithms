#include <iostream>
#include <vector>
#include <list>
using namespace std;
void dfs(vector <list <int>>& mas,vector<short>&colo,int num1,int i1,vector<int>& anss) {
    for (auto i: mas[i1]) {
        if (colo[i] == 0) {
            colo[i] = 1;
            dfs(mas, colo, num1, i, anss);
        }
    }
    anss.push_back(i1);
    return;
}
void revdfs(vector <list <int>>& mas,vector<short>&colo1,int num1,int i1,vector<short>&components,int& count)
{
    for (auto i:mas[i1])
    {
        if (colo1[i]==0)
        {
            colo1[i]=1;
            revdfs(mas,colo1,num1,i,components,count);
        }
    }
    components[i1]=count;
    return;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int num=0,cpairs=0,request=0;
    cin>>num>>cpairs>>request;
    vector <list <int>> mass(num);
    vector <list <int>> revmass(num);
    vector <short> components(num);
    vector <int> ans;
    vector <short> color(num);
    for (int i=0;i<cpairs;i++)
    {
        int j,h;
        cin>>j>>h;
        mass[j - 1].push_back(h - 1);
        revmass[h - 1].push_back(j-1);
    }
    for (int i=0;i<num;i++)
    {
        if (color[i]==0)
        {
            color[i]=1;
            dfs(mass,color,num,i,ans);
        }
    }
    int count=0;
    vector <short> color1(num);
    for (int i=num-1;i>=0;i--)
    {
        if (color1[ans[i]]==0)
        {
            count++;
            color1[ans[i]]=1;
            revdfs(revmass,color1,num,ans[i],components,count);
        }
    }
    for (int i=0;i<request;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        if (components[v1-1]==components[v2-1])
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
