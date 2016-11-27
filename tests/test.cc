#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Player.hh"
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Matrix;

int bfsf(Pos pf)
{
  Matrix visited(37, Row(37, 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(pf.i, pf.j));
  dQ.push(8);
  visited[pf.i][pf.j] = 'T';
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();
    //Above
    Cell cel = cell(x,y-1);
    cerr << y-1<<endl;
    if (y > 0 && visited[x][y-1] == 'F' && cel.type != -1) {
      if (cel.owner != 0 and dir == 8) return 4;
      else if (cel.owner != 0 and dir != 8) return dir;
      Q.push(make_pair(x, (y-1)));
      if(dir == 8)dQ.push(4);
      else dQ.push(dir);
      visited[x][y-1] = 'T';
    }
    //Left
    cel = cell(x-1,y);
    if (x > 0 && visited[x-1][y] == 'F' && cel.type != -1) {
      if (cel.owner != 0 and dir == 8) return 6;
      else if (cel.owner != 0 and dir != 8) return dir;
      Q.push(make_pair(x-1, y));
      if(dir == 8)dQ.push(6);
      else dQ.push(dir);
      visited[x-1][y] = 'T';
    }
    //Right
    cel = cell(x+1,y);
    if (x < 37 - 1 && visited[x+1][y] == 'F' && cel.type != -1) {
      if (cel.owner != 0 and dir == 8) return 2;
      else if (cel.owner != 0 and dir != 8) return dir;
      Q.push(make_pair(x+1, y));
      if(dir == 8)dQ.push(2);
      else dQ.push(dir);
      visited[x+1][y] = 'T';
    }

    //Below
    cel = cell(x,y+1);
    if (y < 37 - 1 && visited[x][y+1] == 'F' && cel.type != -1) {
      if (cel.owner != 0 and dir == 8) return 0;
      else if (cel.owner != 0 and dir != 8) return dir;
      Q.push(make_pair(x, y+1));
      if(dir == 8)dQ.push(0);
      else dQ.push(dir);
      visited[x][y+1] = 'T';
    }
    
    Q.pop();
    dQ.pop();
  }
  //No vertexes found
  return 8;
}

int main (){
  Matrix test(37, Row(37));
  for (int i=0; i<37; ++i){
    for(int j=0; j<37; ++j){
      cin>>test[i][j];
    }
  }
Pos pt(5,5);
int dir = bfsf(pt);
cout<< dir<< endl;
}