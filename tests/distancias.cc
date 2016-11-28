void distancies( Graph &G,  int xx, int yy, int maxdist)
{
  Graph visited(G.size(), Row(G[0].size(), 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(0);
  visited[xx][yy] = 'T';
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dist = dQ.front() + 1;
    Cell cel;
    //Left
    cel = cell(x,y-1);
    if (y > 0 && visited[x][y-1] == 'F' && cel.type == 0 && dist <= maxdist) {
      Q.push(make_pair(x, y-1));
      dQ.push(dist);
      visited[x][y-1] = 'T';
      G[x][y-1] = 'R';
    }
    //Right
    cel = cell(x,y+1);
    if (y < G[0].size() - 1 && visited[x][y+1] == 'F' && cel.type == 0 && dist <= maxdist) {
      Q.push(make_pair(x, y+1));
      dQ.push(dist);
      visited[x][y+1] = 'T';
      G[x][y+1] = 'R';
    }
    //Above
    if (x > 0 && visited[x-1][y] == 'F' && cel.type == 0 && dist <= maxdist) {
      Q.push(make_pair(x-1, y));
      dQ.push(dist);
      visited[x-1][y] = 'T';
      G[x-1][y] = 'R';
    }
    //Right
    if (x < G.size() - 1 && visited[x+1][y] == 'F' && cel.type == 0 && dist <= maxdist) {
      Q.push(make_pair(x+1, y));
      dQ.push(dist);
      visited[x+1][y] = 'T';
      G[x+1][y] = 'R';
    }
    Q.pop();
    dQ.pop();
  }
}