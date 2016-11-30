int bfsf(const Matrix &mf,int xx, int yy) //casilla vacia mas cercana. En uso
  {
  Matrix visited(mk.size(), Row(mk[0].size(), 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(8);
  visited[xx][yy] = 'T';
  vector<bool> direc (7, true); //serveix per comprovar que es a primera veegada que sortim d-aquella posicio
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();
    Cell cel;
    Pos a(x, y);
    for (int i = 0; i < 8; ++i){
      Pos p = a+ Dir(i);
      cel = cell(p);
      if(p.j > 0 and p.j < (int)mk[0].size() - 1 and p.i > 0 and p.i < (int)mk.size() - 1 && visited[p.i][p.j] == 'F' && mk[p.i][p.j] != 'X' && cel.type == Empty) {
        if ((cel.id != -1 and (unit(cel.id).type == Farmer or unit(cel.id).type == Knight) and unit(cel.id).player != 0) and direc[i]) {
        direc[i] = false;
        return i;
      }
      else if ((cel.id != -1 and (unit(cel.id).type == Farmer or unit(cel.id).type == Knight) and unit(cel.id).player != 0) and !direc[i]) return dir;
      Q.push(make_pair(p.i, p.j));
      if(direc[i]){
        direc[i] = false;
        dQ.push(i);
      }
      else dQ.push(dir);
      visited[p.i][p.j] = 'T';
      }
      else direc[i] = false;
    }
     Q.pop();
    dQ.pop();
  }
  
  //No vertexes found
  return 8;
  }