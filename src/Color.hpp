#ifndef COLOR_H_DEFINED
#define COLOR_H_DEFINED

#include <stdint.h>
#include <string>

/// General, platform-independent way to represent RGBA colors.
///
/// Will be used as an intermediate with the engine's "true" colors.
///
/// @note This class was based on the Color class from Guichan.
///
class Color
{
public:
    /// Creates a black opacque color.
    Color();

    /// Creates an opacque color based on a mask (you can use HTML's
    //  hex form).
    //
    //  ## Example
    //    *Color(0xFF00FF)* should give you a bright pink.
    //    *Color(0x0000FF)* should give you full blue.
    //    *Color(0xC0FFEE)* I don't know what this will give but it's
    //                      a nice name for a color.
    Color(int color_mask);

    /// Creates a RGBA color.
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255);

    /// Creates a opaque color based on a color name.
    ///
    /// You know, "red", "black", "cyan"...
    Color(std::string colorName);

    /// Adds the RGB values of two colors.
    //  @note If the alpha value is different, defaults to opacque.
    //  @note If the value is out of range, it's padded.
    Color operator+(const Color& color) const;

    /// Subtracts the RGB values of two colors.
    //  @note If the alpha value is different, defaults to opacque.
    //  @note If the value is out of range, it's padded.
    Color operator-(const Color& color) const;

    /// Tests if two RGBA colors are completely equal.
    bool  operator==(const Color& color) const;

    /// Tests if two RGBA colors are different.
    bool  operator!=(const Color& color) const;

    uint8_t r();
    uint8_t g();
    uint8_t b();
    uint8_t a();

    /// Transforms this color into a random one.
    //  @note This doesn't touch the alpha - for that you
    //        need to call randomizeAlpha().
    void randomize();

    /// Transforms this color's alpha into a random one.
    void randomizeAlpha();

    /// Inverts whole color or individial components.
    void invert(bool R=true, bool G=true, bool B=true);

private:
    uint8_t red;   ///< Red component of the color (0 is none, 255 is full).
    uint8_t green; ///< Green component of the color (0 is none, 255 is full).
    uint8_t blue;  ///< Blue component of the color (0 is none, 255 is full).
    uint8_t alpha; ///< Alpha component of the color (0 is transparent, 255 is opacque).
};

#endif /* COLOR_H_DEFINED */
