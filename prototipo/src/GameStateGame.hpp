#ifndef GAMESTATEGAME_H_DEFINED
#define GAMESTATEGAME_H_DEFINED

// Gaaah, #include hell!
#include <vector>
#include <cstdlib>
#include "GameState.hpp"
#include "SDL.hpp"
#include "Sprite.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"
#include "Music.hpp"
#include "Animation.hpp"
#include "Explosion.hpp"
#include "ProgressBar.hpp"
#include "Font.hpp"
#include "Text.hpp"
#include "Menu.hpp"
#include "DropDownConsole.hpp"
#include "Player.hpp"
#include "PlatformManager.hpp"
#include "CloudContainer.hpp"

/// This represents the actual game taking place.
///
/// Here is defined all the game logic and rules.
///
class GameStateGame: public GameState
{
public:
    GameStateGame();
    virtual ~GameStateGame();

    /// Constructs everything necessary for the game.
    void load(int stack=0);

    /// Destroys anything builded during the game
    int unload();

    /// Updates all possible things on the game.
    ///
    /// @return A status code indicating what to do (should we
    ///         change states/quit the game?). The codes are
    ///         defined on GameState.hpp.
    int update(uint32_t dt);

    /// Shows everything onscreen;
    void render();

    static bool showBoundingBoxes;

private:

    // Such a mess, right?
	Sprite* bg;

	bool will_quit;
    bool game_over;

    Camera* camera;

    Music* bgmusic;

    Player* apterus;

    ProgressBar* lifeBar;
    Font* lifeBarFont;
    Text* lifeBarText;

    // Internal state-specific functions

    /// Constructs the game map
    void buildMap();

	/// Creates a planet at a random position onscreen.
	void addPlanet();

	/// Destroys any planet that's dead.
	void checkPlanets();

	/// Controls events (primairly keyboard input).
	void processEvents();

    /// Checks all possible collisions during this state.
    ///
    /// It handles the effects (updates the objects) internally.
    void checkCollision();

    bool isPaused;

    Font* font;
    Text* pausedTitle;

    Font* consoleFont;
    DropDownConsole* console;

    PlatformManager* platforms;

    CloudContainer* cloudContainer;
    Sprite* cloudSprite;
};

#endif //GAMESTATEGAME_H_DEFINED

