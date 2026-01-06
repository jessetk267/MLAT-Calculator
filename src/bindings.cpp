#include <pybind11/pybind11.h>
#include "mlat.hpp"

PYBIND11_MODULE(mlat_cpp, m) {
    m.def("hello", []() {
        return "hello from C++";
    });
}