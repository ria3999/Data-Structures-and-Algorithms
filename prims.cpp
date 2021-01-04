#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int minNotVisited(int *visited,int *weight,int v)
{
    int index=-1;
    for(int i=0;i<v;++i)
    {
        if(visited[i]==0)
        {
            if(index==-1 || weight[index]>weight[i])
            {
            index=i;
            }
        }
    }
    return index;
}
bool allvisited(int *visited,int v)
{
    for(int i=0;i<v;++i)
    {
        if(visited[i]==0)
        return false;
    }
    return true;
}
void primsUtil(vector<vector<pair<int,int> > > g,int *parent,int *visited,int *weight,int v,int e, int src)
{
    weight[src]=0;
    while(!allvisited(visited,v))
    {
        int index=minNotVisited(visited,weight,v);
        for(int i=0;i<g[index].size();++i)
        {
            int des=g[index][i].first;
            int w=g[index][i].second;
            if(visited[des]==0 && weight[des]>w)
            {
                weight[des]=w;
                parent[des]=index;
            }
        }
        visited[index]=1;
    }

}
void prims(vector<vector<pair<int,int> > > &g,int e)
{
    int  v=g.size();
    cout<<"v="<<v<<endl;
    int parent[v],visited[v],weight[v];
    for(int i=0; i<v;++i)
    {
        parent[i]=-1;
        visited[i]=0;
        weight[i]=INT_MAX;
    }
    int src=0;
    primsUtil(g,parent,visited,weight,v,e,src);
    for(int i=0;i<v;i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<weight[i]<<" ";
    }
}
int main()
{
    int v,e,s,d,w;
    cin>>v>>e;
    vector<vector<pair<int,int> > >g(v);
    for(int i=0;i<e;i++)
    {
        cin>>s>>d>>w;
        g[s].push_back(make_pair(d,w));
        g[d].push_back(make_pair(s,w));
    }
    cout<<"Printing graph"<<endl;
    for(int i=0;i<g.size();++i)
    {
        for(int j=0;j< g[i].size();j++)
        {
            cout<< i<<" "<<g[i][j].first<<" "<<g[i][j].second<<endl;
        }

    }
    prims(g,e);
    return 0;
}
