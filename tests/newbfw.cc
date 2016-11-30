int bfsw(const Matrix &mw,int xx, int yy) //casilla vacia mas cercana. En uso
  {
  Matrix visited(mw.size(), Row(mw[0].size(), 'F'));
  queue< pair<int, int> >  Q;
  queue<int> dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(8);
  visited[xx][yy] = 'T';
  vector<bool> direc (4, true); //serveix per comprovar que es a primera veegada que sortim d-aquella posicio
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dir = dQ.front();
    Cell cel;
    Pos a(x, y);
    for (int i = 0; i < 8; i += 2){
      Pos p = a+ Dir(i);
      cel = cell(p);
      if(p.j > 0 and p.j < (int)mf[0].size() - 1 and p.i > 0 and p.i < (int)mf.size() - 1 && visited[p.i][p.j] == 'F' && mf[p.i][p.j] != 'X' mf[p.i][p.j] != 'A' && cel.type == 0 && cel.id == -1) {
        if ((cel.id != -1 and (unit(cel.id).type == Farmer or unit(cel.id).type == Knight) and unit(cel.id).player != 0) and direc[i/2]) {
        direc[i/2] = false;
        //mw[p.i][p.j] = 'A';
        return i;
      }
      else if ((cel.id != -1 and (unit(cel.id).type == Farmer or unit(cel.id).type == Knight) and !direc[i/2]){ 
        //mw[p.i][p.j] = 'A';
        return dir;
      }
      Q.push(make_pair(p.i, p.j));
      if(direc[i/2]){
        direc[i/2] = false;
        dQ.push(i);
      }
      else dQ.push(dir);
      visited[p.i][p.j] = 'T';
      }
      else direc[i/2] = false;
    }
     Q.pop();
    dQ.pop();
  }
  
  //No vertexes found
  return 8;
  }