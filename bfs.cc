int xx = pf.i;
  int yy = pf.j;
  cerr << "position" << xx<< " "<<yy<<endl; //chivato
  Matrix visited(37, Row(37, 'F')); //tenemos que mirar si realmente se tiene que poner todo falso
  queue< pair<int, int> >  Q;
  queue< pair<int, int> > dQ;
  Q.push(make_pair(xx, yy));
  dQ.push(make_pair(0, 8));
  visited[xx][yy] = 'T';
  bool abv1, bot1, lef1, righ1;
  abv1 = bot1 = lef1 = righ1 = false;
  Cell cbfs;
  while (!Q.empty()) {
    pair<int, int> actual = Q.front();
    int x = actual.first;
    int y = actual.second;
    cerr<< "actual x: "<< x<<" actual y: " <<y<<endl; //chivato
    pair<int, int> dist;
    dist.first = (dQ.front()).first + 1;
    dist.second = (dQ.front()).second;
    cerr<< "distancia  "<< dist.first<<" direccion  " <<dist.second<<endl; //chivato

    //Above
    Pos pf1(x, y-1);
    cbfs = cell(pf1);
    cerr <<"cbfs type "<<cbfs.type<<endl; //entra
    if (y > 0 && visited[x][y-1] == 'F' && cbfs.type == 0 ) {
      if (cbfs.owner != 0 and not abv1) return 4;
      else if (cbfs.owner != 0 and abv1) return dist.second;
      Q.push(make_pair(x, y-1));
      if (not abv1){
        abv1 = true;
        dQ.push(make_pair(dist.first, 4));
      }
      else dQ.push(make_pair(dist.first, dist.second));
      visited[x][y-1] = 'T';
    }

    //Below
    Pos pf2(x, y + 1);
    cbfs = cell(pf2);
    if (y < 36 && visited[x][y+1] == 'F'  ) {
      if (cbfs.owner != 0 and not bot1) return 0;
      else if (cbfs.owner != 0) return dist.second;
      Q.push(make_pair(x, y+1));
      if (not bot1){
        bot1 = true;
        dQ.push(make_pair(dist.first, 0));
      }
      else dQ.push(make_pair(dist.first, dist.second));
      visited[x][y+1] = 'T';
    }

    //Left
    Pos pf3(x-1, y);
    cbfs = cell(pf3);
    if (x > 0 && visited[x-1][y] == 'F' ) {
      if (cbfs.owner != 0 and not lef1) return 6;
      else if (cbfs.owner != 0) return dist.second;
      Q.push(make_pair(x-1, y));
      if (not lef1){
        lef1 = true;
        dQ.push(make_pair(dist.first, 6));
      }
      else dQ.push(make_pair(dist.first, dist.second));
      visited[x-1][y] = 'T';
    }

    //Right
    Pos pf4(x+1, y);
    cbfs = cell(pf4);
    if (x < 36 && visited[x+1][y] == 'F'  ) {
      if (cbfs.owner != 0 and not righ1) return 2;
      else if (cbfs.owner != 0) return dist.second;
      Q.push(make_pair(x+1, y));
      if (not righ1){
        righ1 = true;
        dQ.push(make_pair(dist.first, 2));
      }
      else dQ.push(make_pair(dist.first, dist.second));
      visited[x+1][y] = 'T';
    }
    Q.pop();
    dQ.pop();
  }
  
  //No vertexes found
  return 8;