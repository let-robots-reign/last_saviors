#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "game_state.h"
#include "loader_manager.h"
#include "renderer_manager.h"

using ::testing::Return;

class MockLoader : public Manager {
public:
    MOCK_METHOD(LoadingResult, loadResources, ());
    MOCK_METHOD(LoadingResult, loadTextures, ());
    MOCK_METHOD(LoadingResult, loadFonts, ());
    MOCK_METHOD(int, processEvent, (const Event &event));
};

class MockRenderer : public Manager {
public:
    MOCK_METHOD(RenderingResult, renderMenu, ());
    MOCK_METHOD(RenderingResult, renderLevel, ());
    MOCK_METHOD(RenderingResult, renderTowersMenu, ());
    MOCK_METHOD(RenderingResult, renderPuzzleMenu, ());
    MOCK_METHOD(RenderingResult, renderGameOver, ());
    MOCK_METHOD(RenderingResult, renderGrid, ());
    MOCK_METHOD(RenderingResult, renderEnemies, ());
    MOCK_METHOD(RenderingResult, renderWidgets, ());
    MOCK_METHOD(void, updateState, (GameState newState));
    MOCK_METHOD(int, processEvent, (const Event &event));
};

TEST(TestManagers, testLoader) {
    MockLoader mLoader;
    EXPECT_CALL(mLoader, loadResources()).Times(1);
    EXPECT_CALL(mLoader, loadTextures()).Times(1);
    EXPECT_CALL(mLoader, loadFonts()).Times(1);

    LoadingResult res = mLoader.loadResources();
    ASSERT_THAT(res, LOADING_SUCCESS);
    res = mLoader.loadTextures();
    ASSERT_THAT(res, LOADING_SUCCESS);
    res = mLoader.loadFonts();
    ASSERT_THAT(res, LOADING_SUCCESS);

//    Event event = Event(EverythingLoaded, NoInfoEvent());
//    EXPECT_CALL(mLoader, processEvent(event)).Times(1);
}

TEST(TestManagers, testRenderer) {
    MockRenderer mRenderer;

    EXPECT_CALL(mRenderer, renderMenu()).Times(1);

    mRenderer.updateState(InGame);
    EXPECT_CALL(mRenderer, renderLevel()).Times(1);

    mRenderer.updateState(InPuzzle);
    EXPECT_CALL(mRenderer, renderPuzzleMenu()).Times(1);

    mRenderer.updateState(GameOver);
    EXPECT_CALL(mRenderer, renderGameOver()).Times(1);
}
