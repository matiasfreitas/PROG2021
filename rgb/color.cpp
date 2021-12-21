#include <rgb/color.hpp>

namespace rgb {
    const color color::BLACK(0,0,0);
    const color color::WHITE(255,255,255);
    const color color::RED(255,0,0);
    const color color::GREEN(0,255,0);
    const color color::BLUE(0,0,255);
    color::color():r(0), g(0), b(0) {

    }
    color::color(const color& other): r(other.r), g(other.g), b(other.b) {

    }
    color::color(rgb_value red, rgb_value green, rgb_value blue): r(red), g(green), b(blue) {

    }
    rgb_value color::red() const {
        return r;
    }
    rgb_value color::green() const {
        return g;
    }
    rgb_value color::blue() const {
        return b;
    }
    rgb_value& color::red()  {
        return r;
    }
    rgb_value& color::green()  {
        return g;
    }
    rgb_value& color::blue()  {
        return b;
    }
    color& color::operator=(const color& c) {
        this->r = c.red();
        this->g = c.green();
        this->b = c.blue();
        return *this;
    }

    void color::invert() {
        this->r = 255 - this->r;
        this->g = 255 - this->g;
        this->b = 255 - this->b;

    }
    void color::mix(const color& c, int f) {
        this->r = (((100-f)*this->r)+ (c.red()*f))/100;
        this->g = (((100-f)*this->g)+ (c.green()*f))/100;
        this->b = (((100-f)*this->b)+ (c.blue()*f))/100;
    }
    void color::to_gray_scale() {
        int gray = int(this->r + this->g + this->b)/3.0;
        this->r = gray;
        this->g = gray;
        this->b = gray;
    }

    bool color::operator==(const color &rhs) const {
        return r == rhs.red() && g == rhs.green() && b == rhs.blue();
    }

    bool color::operator!=(const color &rhs) const {
        return !(rhs == *this);
    }
}