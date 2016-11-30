void distancies(Matrix &G,  int xx, int yy, int maxdist)
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
    Pos p(x, y);
    for (int i = 0; i < 8; i += 2){
      p += Dir(i);
      if(y > 0 and y < G[0].size() - 1 and x > 0 and x < G.size() - 1 and visited[p.i][p.j]=='F' and cel.type == 0 and dist <= maxdist){
        Q.push(make_pair(p.i, p.j));
        dq(dist);
        visited[p.i][p.j] = 'T';
        G[p.i][p.j]='X';
      }
    }
    Q.pop();
    dQ.pop();
  }
}





//basura

    //Left
    cel = cell(x,y-1);
    if (y > 0 && visited[x][y-1] == 'F' && cel.type == 0 && dist <= maxdist) {
      Q.push(make_pair(x, y-1));
      dQ.push(dist);
      visited[x][y-1] = 'T';
      G[x][y-1] = 'X';
    }
    //Right
    cel = cell(x,y+1);
    if (y < G[0].size() - 1 && visited[x][y+1] == 'F' && cel.type == 0 && dist <= maxdist) {
      Q.push(make_pair(x, y+1));
      dQ.push(dist);
      visited[x][y+1] = 'T';
      G[x][y+1] = 'X';
    }
    //Above
    if (x > 0 && visited[x-1][y] == 'F' && cel.type == 0 && dist <= maxdist) {
      Q.push(make_pair(x-1, y));
      dQ.push(dist);
      visited[x-1][y] = 'T';
      G[x-1][y] = 'X';
    }
    //Right
    if (x < G.size() - 1 && visited[x+1][y] == 'F' && cel.type == 0 && dist <= maxdist) {
      Q.push(make_pair(x+1, y));
      dQ.push(dist);
      visited[x+1][y] = 'T';
      G[x+1][y] = 'X';
    }
    Q.pop();
    dQ.pop();
  }
}