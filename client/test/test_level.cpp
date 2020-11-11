#include "gtest/gtest.h"
#include "entities/level.h"

TEST(TestLevel, testLevelCreation) {
    Level level("");
    ASSERT_FALSE(level.getGrid().isInitialized());
    level.initScene();
    ASSERT_TRUE(level.getGrid().isInitialized());
}

TEST(TestLevel, testTiles) {
    Level level("");
    level.initScene();

    const Grid grid = level.getGrid();
    grid.updateTileAt(1, 2, BlockTile);
    Tile tile = grid.getTileAt(1, 2);
    EXPECT_TRUE(tile.canPlaceTower());
    EXPECT_FALSE(tile.canPlaceShaft());

    grid.updateTileAt(1, 2, EmptyTile);
    tile = grid.getTileAt(1, 2);
    EXPECT_FALSE(tile.canPlaceTower());
    EXPECT_TRUE(tile.canPlaceShaft());

    grid.updateTileAt(1, 2, RoadTile);
    tile = grid.getTileAt(1, 2);
    EXPECT_FALSE(tile.canPlaceTower());
    EXPECT_FALSE(tile.canPlaceShaft());

    grid.updateTileAt(1, 2, CitadelTile);
    tile = grid.getTileAt(1, 2);
    EXPECT_FALSE(tile.canPlaceTower());
    EXPECT_FALSE(tile.canPlaceShaft());

    grid.updateTileAt(1, 2, PlacedTowerTile);
    tile = grid.getTileAt(1, 2);
    EXPECT_FALSE(tile.canPlaceTower());
    EXPECT_FALSE(tile.canPlaceShaft());

    grid.updateTileAt(1, 2, PlacedShaftTile);
    tile = grid.getTileAt(1, 2);
    EXPECT_FALSE(tile.canPlaceTower());
    EXPECT_FALSE(tile.canPlaceShaft());
}
