#pragma once

#include "Tile.hpp"
#include <alcpp.hpp>
#include <vector>

namespace io
{

class Camera2D;

/*
    NOTE: for the tilesheet, leave transparent border around sprites or repeat the border for tiling tiles in order to avoid texture bleeding.
*/
class Tilemap
{
public:
    Tilemap(int width, int height, int tileWidth, int tileHeight, alcpp::Bitmap tilesheet = alcpp::Bitmap(), alcpp::Vec2<int> offset = { 0, 0 }, alcpp::Vec2<int> padding = { 0, 0 });
    void SetTileset(alcpp::Bitmap tilesheet, alcpp::Vec2<int> offset = { 0, 0 }, alcpp::Vec2<int> padding = { 0, 0 });

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    int GetWorldWidth() const { return width * tileWidth; }
    int GetWorldHeight() const { return height * tileHeight; }

    Tile& GetTile(int x, int y);
    int GetTileX(float x) { return x / tileWidth; }
    int GetTileY(float y) { return y / tileHeight; }
    int GetTileWidth() const { return tileWidth; }
    int GetTileHeight() const { return tileHeight; }

    void Render(alcpp::Display &display, const alcpp::Vec2<int> &topLeft, const alcpp::Vec2<int> &bottomRight);
    void Render(alcpp::Display &display, const Camera2D& camera);

private:
    alcpp::Bitmap GetTilesetBitmapById(int id) const;

    alcpp::Bitmap tilesheet;
    std::vector<alcpp::Bitmap> tileset;
    int width, height;
    int tileWidth, tileHeight;
    alcpp::Vec2<int> offset;
    alcpp::Vec2<int> padding;
    std::vector<Tile> tiles;
};

}