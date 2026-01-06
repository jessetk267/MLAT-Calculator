#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include "mlat.hpp"

namespace py = pybind11;

PYBIND11_MODULE(cmake_mlat, m) {
    m.def(
        "find_ranges",
        &findRanges, 
        py::arg("x_true"),
        py::arg("references"),
        "Compute ranges from a true position and reference points"
    );

    m.def(
        "find_point",
        &findPoint,
        py::arg("references"),
        py::arg("ranges"),
        "Calculate position from ranges and reference points"
    );

    m.def(
        "find_scalar_error",
        &findError,
        py::arg("x_true"),
        py::arg("x_est"),
        "Compute scalar error"
    );

    m.def(
        "find_error_vector",
        &findErrorVector,
        py::arg("x_true"),
        py::arg("x_est"),
        "Compute error vector"
    );
}