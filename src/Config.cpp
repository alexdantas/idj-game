#include "Config.hpp"
#include "Log.hpp"

// Must intialize static members out of the class
ConfigFile  Config::file;
bool        Config::debugMode   = false;
bool        Config::verboseMode = false;
bool        Config::skipMenu    = false;
bool        Config::hasMusic    = true;
bool        Config::showBoundingBoxes = false;

int         Config::screenWidth       = 0;
int         Config::screenHeight      = 0;
int         Config::screenFramerate   = 0;
int         Config::screenBgColorR    = 0;
int         Config::screenBgColorG    = 0;
int         Config::screenBgColorB    = 0;
int         Config::cloudsLimit       = 30;
int         Config::playerFramerate   = 12;
float       Config::playerJump        = 68.14159265359;

float       Config::playerAcceleration = 30.0;

std::string Config::filename          = "";
int         Config::audioRate         = 0;
std::string Config::audioBg           = "";
float       Config::cameraScrollSpeed = 0;

Config::Config()
{
    reset();
}
bool Config::load(std::string fileName)
{
    filename = fileName;
    file.Open(filename.c_str());

    if (!file.IsOpen())
    {
        Log::warning("Couldn't open config file '" + fileName + "'");
        return false;
    }

    file.SelectGroup("game", false);
    debugMode = file.Read("debug_mode", debugMode);
    verboseMode = file.Read("verbose_mode", verboseMode);
    skipMenu = file.Read("skip_menu", skipMenu);
    hasMusic = file.Read("has_music", hasMusic);
    cloudsLimit = file.Read("clouds_limit", cloudsLimit);

    file.SelectGroup("screen", false);
    screenWidth     = file.Read("width",      screenWidth);
    screenHeight    = file.Read("height",     screenHeight);
    screenFramerate = file.Read("framerate",  screenFramerate);
    screenBgColorR  = file.Read("bg_color_r", screenBgColorR);
    screenBgColorG  = file.Read("bg_color_g", screenBgColorG);
    screenBgColorB  = file.Read("bg_color_b", screenBgColorB);

    file.SelectGroup("player", false);
    playerAcceleration = file.Read("acceleration", playerAcceleration);
    playerFramerate = file.Read("framerate", playerFramerate);
    playerJump = file.Read("jump", playerJump);

    file.SelectGroup("camera", false);
    cameraScrollSpeed = file.Read("scroll_speed", cameraScrollSpeed);

    file.SelectGroup("audio", false);
    audioRate = file.Read("rate", audioRate);

    return true;
}
bool Config::reload()
{
    Log::debug("Config::reload File '" + filename + "' reloaded");
    return load(filename);
}

bool Config::save()
{
    Log::debug("Config::save File '" + filename + "' saved");
    return saveAs(filename);
}
bool Config::saveAs(std::string fileName)
{
    Log::debug("Config::saveAs File '" + fileName + "' saved");
    return file.Save(fileName.c_str());
}
void Config::reset()
{
    // Is this necessary?

    debugMode   = DEFAULT_DEBUG_MODE;
    verboseMode = DEFAULT_VERBOSE_MODE;

    screenWidth     = DEFAULT_SCREEN_WIDTH;
    screenHeight    = DEFAULT_SCREEN_HEIGHT;
    screenFramerate = DEFAULT_SCREEN_FRAMERATE;
    screenBgColorR  = DEFAULT_SCREEN_BG_R;
    screenBgColorG  = DEFAULT_SCREEN_BG_G;
    screenBgColorB  = DEFAULT_SCREEN_BG_B;

    audioRate = DEFAULT_AUDIO_RATE;

    cameraScrollSpeed = DEFAULT_CAMERA_SCROLL_SPEED;
}

