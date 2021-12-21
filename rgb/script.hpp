
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    class script {
    private:
        /// Sets the color c for all pixels with coordinates (x′,y′) such that x ≤ x′ < (x+w) and y ≤ y′ < (y+h).
        void fill();
        /// Initialize image from 'filename'.
        void open();
        /// Initializes image with dimensions w × h and initial color (r,g,b) for all pixels.
        void blank();
        /// Save image to 'filename' file.
        void save();
    public:
        /// Script constructor.
        /// \param filename reference to constant string(file)
        script(const std::string& filename);
        /// Script destructor.
        ~script();
        /// Process the script operations.
        void process();
    private:
        /// Pointer to image.
        image* img;
        /// Input stream class to operate on files.
        std::ifstream input;
        /// String of root path.
        std::string root_path;
    };
}
#endif
