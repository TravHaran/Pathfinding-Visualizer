#include "Grid.h"

Grid::Grid(){
    // set start and end nodes
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int type = nodes[j * n + i].getType();
            if(type == SOURCE) {
                start = &nodes[j * n + i];
            } else if (type == DEST) {
                end = &nodes[j * n + i];
            }
        }
    }

    // convert to 2d array
    //TODO: replace memset with std::fill
    memset(mapn, 0, sizeof(mapn[0][0])*n*n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mapn[j][i] = nodes[j * n + i];
        }
    }

    //add starting point
    nQueue.push(*start);
}

bool Grid::gridHasSource(){
    for(int i = 0; i < n; i++){
        if(nodes[i].getType() == SOURCE) return true;
    }
    return false;
}

bool Grid::gridHasDest(){
    for(int i = 0; i < n; i++){
        if(nodes[i].getType() == DEST) return true;
    }
    return false;
}

bool Grid::hasNodePlaced(Node n) {
    int type = n.getType();
    if(type == PATH || type == SOURCE || type == DEST || type == WALL || type == CHECKED)
        return true;
    return false;
}

bool Grid::hasSourceAndDest(){
    int nodeCount = 0;
    if(nodes.size()>0){
        for(size_t i = 0; i < nodes.size(); i++){
            if(nodes[i].getType() == SOURCE || nodes[i].getType() == DEST){
                nodeCount++;
                if(nodeCount==2) return true;
            }
        }
    }
    return false;
}

void Grid::addPoints(int x, int y){
    int posx = x / (screenWidth / n);
    int posy = y / (screenHeight / n);
    int x;
    int y;
    for(size_t i = 0; i < nodes.size(); i++){
        x = nodes[i].getGridPositionX();
        y = nodes[i].getGridPositionY();
        if((x == posx && y == posy) && !hasNodePlaced(nodes[i])){
           if(startEndNodes == 0) {
                Node node = Node(posx, posy, SOURCE, true, 0);
                nodes[i] = node;
                startEndNodes = 1;
           } else if(startEndNodes == 1){
                Node node = Node(posx, posy, DEST, false, INF);
                nodes[i] = node;
                startEndNodes = 2;
           } else if(startEndNodes >= 2){
                Node node = Node(posx, posy, WALL, false, INF);
                nodes[i] = node;
                startEndNodes++;
           }
           break;
        }
    }
}

void Grid::removePoints(int x, int y){
    int posx = x / (screenWidth / n);
    int posy = y / (screenHeight / n);
    int x;
    int y;
    for(size_t i = 2; i < nodes.size(); i++){
        x = nodes[i].getGridPositionX();
        y = nodes[i].getGridPositionY();
        if((x == posx && y == posy) && hasNodePlaced(nodes[i])) {
            Node node = Node(posx, posy, EMPTY, false, INF);
            nodes[i] = node;
            startEndNodes--;
            break;
        }
    }
}

void Grid::showPath(int value){
    if(mapn[end->getGridPositionX()][end->getGridPositionY()].getType() != INF) {
        Node cur = mapn[end->getGridPositionX()][end->getGridPositionY()];
        while(cur.getType() != SOURCE && cur.getParent().x != NULL && cur.getParent().y != NULL) {
            cur = mapn[cur.getParent().x][cur.getParent().y];
            if(cur.getType() != start->getType()){
                nodes[cur.getGridPositionX() * n + cur.getGridPositionY()].setType(PATH);
            }
        }
        glutPostRedisplay();
    }
}

void Grid::reset(){
    flag = 0;
    memset(mapn, NULL, sizeof(mapn[0][0])*n*n);
    while(nQueue.empty()){
        nQueue.pop();
    }
    path.clear();
    vector<Node>().swap(nodes);
    nodes.shrink_to_fit();
    Node node;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            node = Node(i, j, EMPTY, false, INF);
            nodes.push_back(node);
        }
    }
    startEndNodes = 0;
    glutPostRedisplay();
}