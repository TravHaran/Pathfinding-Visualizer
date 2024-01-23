#include "Dijkstra.h"

Dijkstra::Dijkstra(Grid& grid, bool& canAcceptInput){
    this->grid = &grid;
    this->canAcceptInput = &canAcceptInput;
}

void Dijkstra::run(){
    drive(grid->nQueue.size());
}

void Dijkstra::drive(int){

}