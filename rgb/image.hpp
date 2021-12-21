//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    class image {
    private:
        /// Integer value of width.
        int iwidth;

        /// Integer value of height.
        int iheight;

        /// Array of color pointers (matrix of colors)
        color **pixels;
    public:
        /// Image constructor.
        /// \param w integer value of width
        /// \param h integer value of height
        /// \param fill all image with WHITE constant color
        image(int w, int h, const color& fill = color::WHITE);

        /// Image constructor by copy.
        /// \param image constant image to copy
        image(const image& toCopy);

        /// Destructor, free the space allocated to an array of pixels.
        ~image();

        /// Getter of the constant width.
        /// \return  Width of image
        int width() const;

        /// Getter of the constant height.
        /// \return Height of image
        int height() const;

        /// Getter/Setter (mutable reference) of the color at (x,y).
        /// \param x integer coordinate
        /// \param y integer coordinate
        /// \return Mutable reference of color at (x,y)
        color& at(int x, int y);

        /// Getter (immutable reference) of the color at (x,y).
        /// \param x integer coordinate
        /// \param y integer coordinate
        /// \return Immutable reference of color at (x,y)
        const color& at(int x, int y) const;

        /// Inverts all pixels in the image by applying color.invert().
        void invert();

        /// Converts all pixels to grayscale by applying color.to_gray_scale().
        void to_gray_scale();

        /// Changes the color of all pixels with color a to color b.
        /// \param color constant color a
        /// \param color constant color b
        void replace(const color& a, const color& b);

        /// Sets the color c for all pixels with coordinates (x′,y′) such that x ≤ x′< (x+w) and y ≤ y′ < (y+h).
        /// \param x integer coordinate
        /// \param y integer coordinate
        /// \param w integer coordinate
        /// \param h integer coordinate
        /// \param color reference of constant color c
        void fill(int x, int y, int w, int h, const color& c);

        /// Change image by mixing each pixel with corresponding pixel in img with factor 'f' applying color.mix().
        /// \param image constant image to mix
        /// \param factor integer 'f'
        void mix(const image& img, int factor);

        /// Reduces the image (by changing its dimension) to the rectangle with the top left (x,y) and dimension w x h.
        /// \param x integer coordinate
        /// \param y integer coordinate
        /// \param w integer coordinate
        /// \param h integer coordinate
        void crop(int x, int y, int w, int h);

        /// Rotate image to the left.
        void rotate_left();

        /// Rotate image to the right.
        void rotate_right();

        /// Adds 'img' content, replacing current pixels from position (x,y) except for pixels in img that have neutral color (“neutral” color in “addition”).
        /// \param image reference to constant image
        /// \param color reference to constant color 'neutral'
        /// \param x integer coordinate
        /// \param y integer coordinate
        void add(const image& img, const color& neutral, int x, int y);

        /// Assignment operator.
        /// \param image reference to copy
        /// \return Return a image reference
        image &operator=(const image &imageToCopy);
    };
}


#endif
