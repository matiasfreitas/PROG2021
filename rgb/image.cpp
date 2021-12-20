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
        for (int i = 0; i < iwidth; ++i) {
            delete pixels[i];
        }
        delete pixels;
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
        for (int i = x; i < widthlSize; ++i) {
            for (int j = y; j < heightlSize; ++j) {
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
        for (int i = 0; i < img.width(); ++i) {
            for (int j = 0; j < img.height(); ++j) {
                if (img.pixels[i][j] != neutral){
                    pixels[i+x][j+y] = img.pixels[i][j];
                }
            }
        }

    }
    void image::crop(int x, int y, int w, int h) {
        image pixelsTemp(w, h, color(0,0,0));
        for (int i = 0; i < w; ++i) {
            pixelsTemp.pixels[i]  = new color[h];
            for (int j = 0; j < h; ++j) {
                pixelsTemp.pixels[i][j] = this->pixels[i+x][j+y];
            }
        }
        *this = pixelsTemp;
    }
    void image::rotate_left() {
        image pixelsTemp(this->height(), this->iwidth, color(0,0,0));
        for(int i=0; i<this->iheight; i++){
            for(int j=0; j<this->iwidth; j++){
                pixelsTemp.pixels[i][j]=this->pixels[this->iwidth-j-1][i];
            }
        }
        *this = pixelsTemp;
    }
    void image::rotate_right() {
        image pixelsTemp(this->height(), this->iwidth, color(0,0,0));
        for(int i=0; i<this->iheight; i++){
            for(int j=0; j<this->iwidth; j++){
                pixelsTemp.pixels[i][j]=this->pixels[j][this->iheight-i-1];
            }
        }
        *this = pixelsTemp;
    }
    void image::mix(const image& img, int factor) {
        for (int i = 0; i < iwidth; ++i) {
            for (int j = 0; j < iheight; ++j) {
                this->pixels[i][j].mix(img.pixels[i][j], factor);
            }
        }
    }
    image &image::operator=(const image &imageToCopy) {
        for (int i = 0; i < iwidth; ++i) {
            delete pixels[i];
        }
        delete pixels;
        pixels = new color*[imageToCopy.width()];
        for (int i = 0; i < imageToCopy.width(); ++i) {
            this->pixels[i]  = new color[imageToCopy.height()];
            for (int j = 0; j < imageToCopy.height(); ++j) {
                this->pixels[i][j] = imageToCopy.pixels[i][j];
            }
        }
        this->iwidth = imageToCopy.width();
        this->iheight = imageToCopy.height();
        return *this;
    }
}
