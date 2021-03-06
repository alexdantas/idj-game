#ifndef LOADINGSCREEN_H_DEFINED
#define LOADINGSCREEN_H_DEFINED

#include <string>
#include "Font.hpp"
#include "Text.hpp"
#include "ProgressBar.hpp"
#include "Sprite.hpp"

/// General loading screen for the transition between states.
///
/// This is a temporary class. Generally must be used on the
/// *load()* methods of each state.
///
/// For a clear example, check out *GameStateGame*'s *load()*
/// method.
///
class LoadingScreen
{
public:
    /// Creates a loading screen with *text*, to be rendered
    /// by the font at *fontPath*.
    //If amount = 0, then we don't know how many things will be loaded
    LoadingScreen(std::string title, std::string subtitle="", int amount = 0);

    ~LoadingScreen();

    /// Increase loading bar's percentage by *ammount*.
    void increase(unsigned int ammount = 0);

    /// Set loading bar's percentage by *ammount*.
    void set(unsigned int ammount);

    /// Sets the loading screen's title (big text onscreen).
    void setTitle(std::string text);

    /// Sets the loading screen's subtitle (text that appears
    /// above the loading bar).
    void setSubtitle(std::string text);

    /// Sets the background image of the loading screen.
    void setBg(std::string filepath);

private:
    Font* titleFont;    ///< Font that will draw the title loading text.
    Font* subtitleFont; ///< Font that will draw the subtitle loading text.

    Text title;    ///< Big text.
    Text subtitle; ///< Text that appears above the loading bar.

    ProgressBar progressBar;

    Sprite* bg; ///< Background of the loading screen.
    Sprite* loadingBar; ///< Fancy loading

    int amount; ///< How many objects will be loaded
    int percent; ///< How much loading bar will be increased
};

#endif //LOADINGSCREEN_H_DEFINED
