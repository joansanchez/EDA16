int bfsf(const Matrix &mf,int xx, int yy) //casilla vacia mas cercana
{
  Matrix visited(mf.size(), Row(mf[0].size(), 'F'));
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
    Cell cel;

    //Below

    cel = cell(x+1,y);
    if (x < 37 - 1 && visited[x+1][y] == 'F' && mf[x+1][y] != 'X' && cel.id == -1) {
      if (cel.owner != 0 and bot1) {
        bot1 = false;
        return 0;
      }
      else if (cel.owner != 0 and !bot1) return dir;
      Q.push(make_pair(x+1, y));
      if(bot1){
        bot1 = false;
        dQ.push(0);
      }
      else dQ.push(dir);
      visited[x+1][y] = 'T';
    }
    else bot1 = false;


    //Right
    cel = cell(x,y+1);
    if (y < 37 - 1 && visited[x][y+1] == 'F' && mf[x][y+1] != 'X' && cel.id == -1) {
      if (cel.owner != 0 and righ1) {
        righ1 = false;
        return 2;
      }
      else if (cel.owner != 0 and !righ1) return dir;
      Q.push(make_pair(x, y+1));
      if(righ1){
        righ1 = false;
        dQ.push(2);
      }
      else dQ.push(dir);
      visited[x][y+1] = 'T';
    }
    else righ1 = false;

    //Left
    cel = cell(x,y-1);
    if (y > 0 && visited[x][y-1] == 'F' && mf[x][y-1] != 'X' && cel.id == -1) {
      if (cel.owner != 0 and lef1) {
        lef1 = false;
        return 6;
      }
      else if (cel.owner != 0 and !lef1) return dir;
      Q.push(make_pair(x, (y-1)));
      if(lef1){
        lef1 = false;
        dQ.push(6);
      }
      else dQ.push(dir);
      visited[x][y-1] = 'T';
    }
    else lef1 = false; 

    //Above
    cel = cell(x-1,y);
    if (x > 0 && visited[x-1][y] == 'F' && cel.type == 0 mf[x_1][y] != 'X' && cel.id == -1) {
      if (cel.owner != 0 and abv1) {
        abv1 = false;
        return 4;
      }
      else if (cel.owner != 0 and !abv1) return dir;
      Q.push(make_pair(x-1, y));
      if(abv1){
        abv1 = false;
        dQ.push(4);
      }
      else dQ.push(dir);
      visited[x-1][y] = 'T';
    }
    else abv1 = false;
    


    Q.pop();
    dQ.pop();
  }
  //No vertexes found
  return 8;
}