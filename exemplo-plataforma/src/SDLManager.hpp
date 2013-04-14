#ifndef SDLMANAGER_H_DEFINED
#define SDLMANAGER_H_DEFINED

#include <string>
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_framerate.h"

//* Handles all direct SDL calls
//  A simple SDL object wrapper
class SDLManager
{
public:
    SDLManager();
    virtual ~SDLManager();

	/// Starts all things related to SDL.
	//  The constructor only allocates stuff, here's where the
	//  action begins.
	//  @return true if OK, false if something's wrong
	//  @note   I encourage you to call `delete` if this returns -1.
	bool init(int width, int height, int framerate=60);

	/// Pauses the whole program for #delay milliseconds (1/1000 of a second).
	void delay_ms(int delay);

	/// Effectively draws everything that's onscreen.
	//  @note Need to be called constantly.
	void refreshScreen();

    /// Clears whole screen to black.
	void clearScreen();

	/// Places the surface #source (on #position and #cropped) onscreen.
	//  @note Need to call refreshScreen() after.
	void renderSurface(SDL_Surface* source, SDL_Rect* crop, SDL_Rect* position);

	/// The main loop of the game.
	//  Here's where the whole game hangs up.
	void run();

	/// Stores a buffer of input chars and print them onscreen.
    void bufferInput(SDLKey key, Uint16 unicode);

	/// Loads image specified by #filename.
	//  @return The pointer to it if OK, NULL if something strange happened.
	//  @note   Remember to call freeImage() if loaded sucessfully.
	static SDL_Surface* loadImage(std::string filename);

	/// Cleans #image from memory, safe-checking if NULL.
	static void freeImage(SDL_Surface* image);

    /// Prints #msg on standard error output.
	//  Defaults to the console.
    static void errorLog(std::string msg);

    /// Tells if there's any music playing anywhere on the game.
	static bool musicPlaying();

    /// Tells if there's any paused music anywhere on the game.
	static bool musicPaused();

    /// Pauses any music that could be playing.
    //  It safe-checks so you don't have to.
    static void pauseMusic();

    /// Resumes any music that may be paused.
    //  It safe-checks so you don't have to.
    static void resumeMusic();

    /// Stops any music that may be playing or paused.
    //  It safe-checks so you don't have to.
    //  @note Any subsequent calls to pauseMusic() and resumeMusic()
    //        will be ignored.
    static void stopMusic();

	void framerateWait();

private:
	/// Represents the whole game screen.
	SDL_Surface* screen;
    int screenW;
    int screenH;
    bool willQuit;

    Uint32 framerate;
	FPSmanager framerateManager;

    /// Tells if the #key can be displayer onscreen (not a control key).
	bool isPrintable(SDLKey key);
};

//* Singleton global SDL Manager
//  Pretty much everyone depends on this
//  @note Must be initialized with init()
extern SDLManager* global_sdl_manager;

#endif /* SDLMANAGER_H_DEFINED */