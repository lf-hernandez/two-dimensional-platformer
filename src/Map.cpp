#include "Map.hpp"

#include <fstream>
#include <string>

#include "Game.hpp"

Map::Map() {}

Map::~Map() {}

void Map::loadMap(std::string path, int sizeX, int sizeY) {
  char tile;
  std::fstream mapFile;

  mapFile.open(path);

  for (int column = 0; column < sizeY; column++) {
    for (int row = 0; row < sizeX; row++) {
      mapFile.get(tile);
      Game::addTile(atoi(&tile), row * 32, column * 32);
      mapFile.ignore();
    }
  }

  mapFile.close();
}
