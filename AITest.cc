#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Test
#define ROWSCOL 37

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
typedef vector<Row> Graph;

int bfs(Pos pf)
{
  int xx = pf.first;
  int yy = pf.second;
  Graph visited(37, Row(37, 'F')); //tenemos que mirar si realmente se tiene que poner todo falso
  queue< pair<int, int> >  Q;
  queue< pair<int, int> > dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(make_pair(0, 8));
  visited[xx][yy] = 'T';
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    int dist = (dQ.front()).first + 1;
    //Above
    if (y > 0 && visited[x][y-1] == 'F' && G[x][y-1] != 'X') {
      if (G[x][y-1] == 't') return dist;
      Q.push(make_pair(x, y-1));
      dQ.push(dist);
      visited[x][y-1] = 'T';
    }
    //Below
    if (y < (int)G[0].size() - 1 && visited[x][y+1] == 'F' && G[x][y+1] != 'X') {
      if (G[x][y+1] == 't') return dist;
      Q.push(make_pair(x, y+1));
      dQ.push(dist);
      visited[x][y+1] = 'T';
    }
    //Left
    if (x > 0 && visited[x-1][y] == 'F' && G[x-1][y] != 'X') {
      if (G[x-1][y] == 't') return dist;
      Q.push(make_pair(x-1, y));
      dQ.push(dist);
      visited[x-1][y] = 'T';
    }
    //Right
    if (x < (int)G.size() - 1 && visited[x+1][y] == 'F' && G[x+1][y] != 'X') {
      if (G[x+1][y] == 't') return dist;
      Q.push(make_pair(x+1, y));
      dQ.push(dist);
      visited[x+1][y] = 'T';
    }
    Q.pop();
    dQ.pop();
  }
  //No vertexes found
  return -1;
}

  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    VE f = farmers(0);
    for (int id : f) {
      Pos pos = unit(id).pos;
      Cell c;
      c = cell(pos + Dir(0));
      cerr << c.type <<endl;
      if((c = cell(pos + Dir(0))).type == 0 and !(c = cell(pos + Dir(0))).haunted) command(id, Dir(0));
      else if ((c = cell(pos + Dir(2))).type == 0 and !(c = cell(pos + Dir(2))).haunted) command(id, Dir(2));
      else if ((c = cell(pos + Dir(4))).type == 0 and !(c = cell(pos + Dir(4))).haunted) command(id, Dir(4));
      else if ((c = cell(pos + Dir(6))).type == 0 and !(c = cell(pos + Dir(6))).haunted) command(id, Dir(6));
      else command(id, Dir(7));
    }

  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
