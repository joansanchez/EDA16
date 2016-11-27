#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
 
typedef vector<char> Row;
typedef vector<Row> Graph;
 
 
int bfs(const Graph &G, int xx, int yy)
{
  Graph visited(G.size(), Row(G[0].size(), 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(8);
  visited[xx][yy] = 'T';
  bool abv1, bot1, lef1, righ1;
  abv1 = bot1 = lef1 = righ1 = true;
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();
    //Left
    if (y > 0 && visited[x][y-1] == 'F' && G[x][y-1] != 'X') {
      cout<<"Left"<<endl;
      if (G[x][y-1] == 't' and lef1) {
        lef1 = false;
        return 6;
      }
      else if (G[x][y-1] == 't' and !lef1) return dir;
      Q.push(make_pair(x, y-1));
      if(lef1){
        lef1 = false;
        dQ.push(6);
      }
      else dQ.push(dir);
      visited[x][y-1] = 'T';
    }
    else lef1 = false; 
    //Right
    if (y < G[0].size() - 1 && visited[x][y+1] == 'F' && G[x][y+1] != 'X') {
      cout<< "Right"<<endl;
      if (G[x][y+1] == 't' and righ1) {
        righ1 = false;
        return 2;
      }
      else if (G[x][y+1] == 't' and !righ1) return dir;
      Q.push(make_pair(x, y+1));
      if(righ1){
        righ1 = false;
        dQ.push(2);
      }
      else dQ.push(dir);
      visited[x][y+1] = 'T';
    }
    else righ1 = false;
    //Above
    if (x > 0 && visited[x-1][y] == 'F' && G[x-1][y] != 'X') {
      cout<<"Above"<<endl;
      if (G[x-1][y] == 't' and abv1) {
        abv1 = false;
        return 4;
      }
      else if (G[x-1][y] == 't' and !abv1) return dir;
      Q.push(make_pair(x-1, y));
      if(abv1){
        abv1 = false;
        dQ.push(4);
      }
      else dQ.push(dir);
      visited[x-1][y] = 'T';
    }
    else abv1 = false;
    //Below
    if (x < G.size() - 1 && visited[x+1][y] == 'F' && G[x+1][y] != 'X') {
      cout<<"Below"<<endl;
      if (G[x+1][y] == 't' and bot1) {
        bot1 = false;
        return 0;
      }
      else if (G[x+1][y] == 't' and !bot1) return dir;
      Q.push(make_pair(x+1, y));
      if(bot1){
        bot1 = false;
        dQ.push(0);
      }
      else dQ.push(dir);
      visited[x+1][y] = 'T';
    }
    else bot1 = false;
    Q.pop();
    dQ.pop();
  }
  //No vertexes found
  return 8;
}
 
int main()
{
  int n, m;
  cin >> n >> m;
  Graph G(n, Row(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> G[i][j];
  int x, y;
  cin >> x >> y;
  int res = bfs(G, x-1, y-1);
  if (res == 8) cout << "no es pot arribar a cap tresor" << endl;
  else cout << "direccio: " << res << endl;
}