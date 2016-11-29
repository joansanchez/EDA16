#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Joan


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */
  typedef vector<int> VE;
  typedef vector<char> Row;
  typedef vector<Row> Matrix;

  void distancies(Matrix &G,  int xx, int yy, int maxdist)
  {
  Matrix visited(G.size(), Row(G[0].size(), 'F'));
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
      G[x][y-1] = 'X';
    }
    //Right
    cel = cell(x,y+1);
    if (y < (int)G[0].size() - 1 && visited[x][y+1] == 'F' && cel.type == 0 && dist <= maxdist) {
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
    if (x < (int)G.size() - 1 && visited[x+1][y] == 'F' && cel.type == 0 && dist <= maxdist) {
      Q.push(make_pair(x+1, y));
      dQ.push(dist);
      visited[x+1][y] = 'T';
      G[x+1][y] = 'X';
    }
    Q.pop();
    dQ.pop();
  }
}


  void omplir_farmers(Matrix &mf){
    //bruixes
    Cell com;
    Pos pos;
    int x;
    int y;
    for(int wp = 0; wp < 4; ++wp){
      VE wit = witches(wp);
      for (int id : wit) {
        pos = unit(id).pos;
        x = pos.i;
        y = pos.j;
        mf[x][y] = 'X';
        distancies(mf, x, y, 3);
      }
    }


    //Cavallers
    for(int kp = 1; kp < 4; ++kp){
      VE kni = knights(kp);
      for (int id : kni) {
        pos = unit(id).pos;
        x = pos.i;
        y = pos.j;
        mf[x][y] = 'X';
        distancies(mf, x, y, 1);
        if(mf[x][y-1]=='X' and mf[x-1][y]=='X') mf[x-1][y-1] = 'X';
        if(mf[x][y+1]=='X' and mf[x-1][y]=='X') mf[x-1][y+1] = 'X';
        if(mf[x][y-1]=='X' and mf[x+1][y]=='X') mf[x+1][y-1] = 'X';
        if(mf[x][y+1]=='X' and mf[x+1][y]=='X') mf[x+1][y+1] = 'X';
      }
    }


    /*for (int ii = 0; ii < (int)mf.size(); ++ii){
      for (int jj = 0; jj < (int)mf[0].size(); ++jj){
        if (mf[ii][jj] != 'X') cerr << "." << " ";
        else cerr << mf[ii][jj] << " ";
      }
      cerr << endl;
    } */
  }

  void omplir_knights(Matrix &mk){
    Cell com;
    Pos pos;
    int x;
    int y;
    for(int wp = 0; wp < 4; ++wp){
      VE wit = witches(wp);
      for (int id : wit) {
        pos = unit(id).pos;
        x = pos.i;
        y = pos.j;
        mk[x][y] = 'X';
        distancies(mk, x, y, 3);
      }
    }
  }

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
    if (x < 37 - 1 && visited[x+1][y] == 'F' && mf[x+1][y] != 'X' && cel.type == 0 && cel.id == -1) {
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
    if (y < 37 - 1 && visited[x][y+1] == 'F' && mf[x][y+1] != 'X' && cel.type == 0 && cel.id == -1) {
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
    if (y > 0 && visited[x][y-1] == 'F' && mf[x][y-1] != 'X' && cel.type == 0 && cel.id == -1) {
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
    if (x > 0 && visited[x-1][y] == 'F'  && mf[x-1][y] != 'X' && cel.type == 0 && cel.id == -1) {
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
int bfsk(const Matrix &mk,int xx, int yy) //casilla vacia mas cercana
  {
    return 8;
  }


  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
  
  Matrix matfarmers(rows(), Row(cols())); //zones on el farmer no pot anar: bruixes i cavallers
  omplir_farmers(matfarmers);
  Matrix matknights(rows(), Row(cols())); //zones on els cavallers no poden anar: bruixes
  omplir_knights(matknights);
  Matrix matwitches(rows(), Row(cols()));
  

  //farmers
  VE f = farmers(0);
    for (int id : f) {
      Pos pos = unit(id).pos;
      int x = pos.i;
      int y = pos.j;
      command(id, Dir(bfsf(matfarmers, x, y)));
    }

// if (round()==5)while(1){}
  //knights
    VE k = knights(0);
    for (int id : k) {
      Pos pos = unit(id).pos;
      int x = pos.i;
      int y = pos.j;
      command(id, Dir(bfsk(matknights, x, y)));
    }
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
