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
        for (int i = 0; i < iwidth; ++i) delete[] pixels[i];
        delete[] pixels;
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
        for (int i = 0; i < width(); ++i) {
            for (int j = 0; j < height(); ++j) {
                at(i,j).invert();
            }
        }
    }
    void image::to_gray_scale() {
        for (int i = 0; i < width(); ++i) {
            for (int j = 0; j < height(); ++j) {
                at(i,j).to_gray_scale();
            }
        }
    }
    void image::fill(int x, int y, int w, int h, const color& c) {
        int widthlSize = x +w, heightlSize = y +h ;
        if(widthlSize > width()){
            widthlSize= width();
        }
        if(heightlSize > height()){
            heightlSize = height();
        }
        for (int i = x; i < widthlSize; ++i) {
            for (int j = y; j < heightlSize; ++j) {
                    at(i,j) = c;
            }
        }
    }
    void image::replace(const color& a, const color& b) {
        for (int i = 0; i < width(); ++i) {
            for (int j = 0; j < height(); ++j) {
                if (at(i, j) == a) at(i, j) = b;
            }
        }
    }
    void image::add(const image& img, const color& neutral, int x, int y) {
        for (int i = 0; i < img.width(); ++i) {
            for (int j = 0; j < img.height(); ++j) {
                if (img.at(i, j) != neutral) at(i+x, j+y) = img.at(i, j);
            }
        }

    }
    void image::crop(int x, int y, int w, int h) {
        image pixelsTemp(w, h, color(0,0,0));
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                pixelsTemp.at(i, j) = at(i+x, j+y);
            }
        }
        *this = pixelsTemp;
    }
    void image::rotate_left() {
        image pixelsTemp(height(), width(), color::BLACK);
        for(int i=0; i<this->iheight; i++){
            for(int j=0; j<this->iwidth; j++){
                pixelsTemp.at(i, j)=at(width()-j-1, i);
            }
        }
        *this = pixelsTemp;
    }
    void image::rotate_right() {
        image pixelsTemp(height(), width(), color::BLACK);
        for(int i=0; i<height(); i++){
            for(int j=0; j<this->width(); j++){
                pixelsTemp.at(i, j)=at(j, height()-i-1);
            }
        }
        *this = pixelsTemp;
    }
    void image::mix(const image& img, int factor) {
        for (int i = 0; i < width(); ++i) {
            for (int j = 0; j < height(); ++j) {
                at(i, j).mix(img.at(i, j), factor);
            }
        }
    }

    image &image::operator=(const image &imageToCopy) {
        for (int i = 0; i < width(); ++i) {
            delete[] pixels[i];
        }
        delete[] pixels;
        pixels = new color*[imageToCopy.width()];
        for (int i = 0; i < imageToCopy.width(); ++i) {
            this->pixels[i]  = new color[imageToCopy.height()];
            for (int j = 0; j < imageToCopy.height(); ++j) {
                at(i, j) = imageToCopy.at(i, j);
            }
        }
        this->iwidth = imageToCopy.width();
        this->iheight = imageToCopy.height();
        return *this;
    }
}
