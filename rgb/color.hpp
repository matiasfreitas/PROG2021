//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    /// Definition type of rgb_value.
    typedef unsigned char rgb_value;

    class color {
    private:
        /// Unsigned char to define red component.
        rgb_value r;
        /// Unsigned char to define green component.
        rgb_value g;
        /// Unsigned char to define blue component.
        rgb_value b;
    public:
        /// Macro for RED color constant
        static const color RED;
        /// Macro for GREEN color constant
        static const color GREEN;
        /// Macro for BLUE color constant
        static const color BLUE;
        /// Macro for BLACK color constant
        static const color BLACK;
        /// Macro for WHITE color constant
        static const color WHITE;

        /// Color constructor without parameters, initializes every component with 0.
        color();

        /// Constructor by copy.
        /// \param color to copy
        color(const color &c);

        /// Color constructor with parameters.
        /// \param red unsigned char value of red component
        /// \param green unsigned char value of green component
        /// \param blue unsigned char value of blue component
        color(rgb_value r, rgb_value g, rgb_value b);

        /// Getter of the red component.
        /// \return Unsigned char value of red
        rgb_value red() const;

        /// Get reference of red component.
        rgb_value& red();

        /// Getter of the green component.
        /// \return Unsigned char value of green
        rgb_value green() const;

        /// Get reference of green component.
        rgb_value& green();

        /// Getter of the blue component.
        /// \return Unsigned char value of blue
        rgb_value blue() const;

        /// Get reference of blue component.
        rgb_value& blue();

        /// Assignment operator
        /// \param color to assign
        /// \return Return a color reference
        color& operator=(const color&c);

        /// Invert all the RGB components, (r,g,b)->(255−r,255−g,255−b).
        void invert();

        /// Turn the RGB components in gray scale, (r,g,b)->(v,v,v) where v=(r+g+b)/3.
        void to_gray_scale();

        /// Blend with color c with a factor f between 0 and 100: (r,g,b)->(m(r,cr),m(g,cg),m(b,cb)) where m(a,b)=((100−f)a+fb)/100.
        /// \param color to mix
        /// \param int factor
        void mix (const color &c, int f);

        /// Equality operator.
        /// \param color to compare
        /// \return Return true if equal and false otherwise
        bool operator==(const color &rhs) const;

        /// Inequality operator.
        /// \param color to compare
        /// \return Return false if equal and true otherwise
        bool operator!=(const color &rhs) const;
    };
}
#endif
