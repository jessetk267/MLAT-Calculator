#include <pybind11/pybind11.h>

PYBIND11_MODULE(mlat_cpp, m) {
    m.def("hello", []() {
        return "hello from C++";
    });
}