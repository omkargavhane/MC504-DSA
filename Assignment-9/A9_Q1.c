/make two separate MST for men and women and check if all node are present in it or not/

#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>>adj[1001];

pair<int,pair<int,int>>p[100001];

int par1[1001],par2[1001];

int find1(int a)

{

if(par1[a]<0)

return a;

return par1[a]=find1(par1[a]);

}

void merge1(int a,int b){

 

par1[a]=b;

}

int find2(int a)

{

if(par2[a]<0)

return a;

return par2[a]=find2(par2[a]);

}

void merge2(int a,int b){

 

par2[a]=b;

}

int main(){

ios_base::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);

int n,m;

cin>>n>>m;

int val[n+1]={0};

for(int i=1;i<=n;i++)

par1[i]=par2[i]=-1;

for(int i=0;i<m;i++)

{

int u,v,w;

cin>>u>>v>>w;

p[i]={w,{u,v}};

adj[u].push_back({v,w});

adj[v].push_back({u,w});

}

sort(p,p+m,greater<pair<int,pair<int,int>>>());

int cnt=0,cnt1=0,cnt2=0;

for(int i=0;i<m;i++)

{

if(p[i].first==3)

{

int a=p[i].second.first,b=p[i].second.second;

int x=find1(a),y=find1(b);

if(x!=y)

{

cnt++;

merge1(x,y);

}

x=find2(a),y=find2(b);

if(x!=y)

{

cnt++;

merge2(x,y);

}

}

else if(p[i].first==2)

{

int a=p[i].second.first,b=p[i].second.second;

int x=find2(a),y=find2(b);

if(x!=y)

{

cnt2++;

merge2(x,y);

}

}

else

{

int a=p[i].second.first,b=p[i].second.second;

int x=find1(a),y=find1(b);

if(x!=y)

{

cnt1++;

merge1(x,y);

}

}

}

if(cnt/2 +cnt1==n-1&&cnt/2 +cnt2==n-1)

{

cout<<m-cnt/2 -cnt1-cnt2;

}

else

cout<<"-1\n";

 

}
