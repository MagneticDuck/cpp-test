#include "util.h"

/**********************************************************************************************************************/
/* dir, loc
/**********************************************************************************************************************/

loc::loc(int col, int row) : x(col), y(row) { }

loc::loc(dir some_dir) {
    switch (some_dir) {
        case dir::Up: {
            y = -1, x = 0;
            break;
        }
        case dir::Down: {
            y = 1, x = 0;
            break;
        }
        case dir::Left: {
            y = 0, x = -1;
            break;
        }
        case dir::Right: {
            y = 0, x = 1;
            break;
        }
    }
}

loc::loc() : x(0), y(0) { }

void loc::operator+=(loc a_loc) {
    this->x += a_loc.x;
    this->y += a_loc.y;
}

loc operator+(loc a, loc b) {
    return loc(a.x + b.x, a.y + b.y);
}

void loc::clamp(int max_x, int max_y) {
    x = std::min(x, max_x);
    y = std::min(y, max_y);

    x = std::max(x, 0);
    y = std::max(y, 0);
}

boost::optional<dir> key_to_dir(int a_key) {
    switch (a_key) {
        case 260: return boost::optional<dir>(dir::Left);
        case 261: return boost::optional<dir>(dir::Right);
        case 259: return boost::optional<dir>(dir::Up);
        case 258: return boost::optional<dir>(dir::Down);
        default: return boost::optional<dir>();
    }
}

std::string show_dir(dir a_dir) {
    switch (a_dir) {
        case dir::Up: return "^";
        case dir::Down: return "v";
        case dir::Left: return "<";
        case dir::Right: return ">";
    }
}

/**********************************************************************************************************************/
/* tickertape
/**********************************************************************************************************************/

tickertape::tickertape(const int disp_width, const int str_width)
        : disp_width(disp_width), str_width(str_width),
          loop_length(std::max(disp_width, str_width)) { }

void tickertape::tick() {
    iter = (iter + 1) % loop_length;
}

std::string tickertape::print() {
    std::string result = "";
    const int loop_len_v = loop_length;
    for (int i = 0; i < disp_width; i++) {
        result += at_index((iter + i) % loop_len_v);
    }
    return result;
}

