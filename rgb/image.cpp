#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color& fill):iwidth(w),iheight(h) {
        this->pixels = new color*[w];
        for (int i = 0; i < w; ++i) {
            this->pixels[i]  = new color[h];
            for (int j = 0; j < h; ++j) {
                this->pixels[i][j] = fill;
            }
        }
    }
    image::~image() {

    }
    int image::width() const {
        return iwidth;
    }
    int image::height() const {
        return iheight;
    }
    color& image::at(int x, int y) {
        return pixels[x][y];
    }
    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }
    void image::invert() {
        for (int i = 0; i < iwidth; ++i) {
            for (int j = 0; j < iheight; ++j) {
                pixels[i][j].invert();
            }
        }
    }
    void image::to_gray_scale() {
        for (int i = 0; i < iwidth; ++i) {
            for (int j = 0; j < iheight; ++j) {
                pixels[i][j].to_gray_scale();
            }
        }
    }
    void image::fill(int x, int y, int w, int h, const color& c) {
        int widthlSize = x +w, heightlSize = y +h ;
        if(widthlSize>iwidth){
            widthlSize= iwidth;
        }
        if(heightlSize >iheight){
            heightlSize = iheight;
        }
        for (int i = 0; i < widthlSize; ++i) {
            for (int j = 0; j < heightlSize; ++j) {
                    pixels[i][j] = c;
            }
        }
    }
    void image::replace(const color& a, const color& b) {
        for (int i = 0; i < iwidth; ++i) {
            for (int j = 0; j < iheight; ++j) {
                if (pixels[i][j] == a){
                    pixels[i][j] = b;
                }
            }
        }

    }
    void image::add(const image& img, const color& neutral,
                    int x, int y) {

    }
    void image::crop(int x, int y, int w, int h) {

    }
    void image::rotate_left() {

    }
    void image::rotate_right() {

    }
    void image::mix(const image& img, int factor) {

    }
}
