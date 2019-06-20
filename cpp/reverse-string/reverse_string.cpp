#include "reverse_string.h"

namespace reverse_string {

std::string reverse_string(const std::string& s) {
    std::string s_copy(s);  // make a copy of the input string
    std::reverse(s_copy.begin(), s_copy.end());  // reverse it in-place
    return s_copy;
}

}  // namespace reverse_string
