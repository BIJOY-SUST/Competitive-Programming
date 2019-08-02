///Problem = Timus Online Judge/1145. Rope in the Labyrinth/ট্রি ডায়ামিটার
#include<bits/stdc++.h>
using namespace std;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int mr,mc,mx=0;
char w[1000][1000];///The Input array...............
int d[1000][1000];///d == Distance...................
int r,c;
void BFS(int x,int y,int dep)
{
    queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	memset(d,100,sizeof(d));
	d[x][y]=0;
	while(!q.empty()){
		pair<int,int>top=q.front();
		q.pop();
		if(d[top.first][top.second]>mx){
			mx=d[top.first][top.second];
			mr=top.first;
			mc=top.second;
		}
		for(int k=0;k<4;k++){
			int tx=top.first+fx[k];
			int ty=top.second+fy[k];
			if(tx>=0 && tx<r && ty>=0 && ty<c && w[tx][ty]=='.' && d[top.first][top.second]+1<d[tx][ty]){
				q.push(make_pair(tx,ty));
				d[tx][ty]=d[top.first][top.second]+1;
			}
		}
	}
}
int main(){
	int sx,sy,cc=0;
	cin>>r>>c;
	swap(r,c);
	for(int i=0;i<r;i++){
        cin>>w[i];
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
            if(w[i][j]=='.'){
                sx=i;sy=j;cc++;
            }
		}
	}
	//cout<<sx<<sy<<mx<<endl;
    BFS(sx,sy,0);
	mx=0;
	//out<<mr<<mc<<mx<<endl;
	BFS(mr,mc,0);
	//cout<<mr<<mc<<mx<<endl;
	if(cc==1){
        mx=0;
	}
	cout<<mx<<endl;
	return 0;
}
