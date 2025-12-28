#include <iostream>
#include <vector>
#include <Eigen/Dense>

//Compile with:
/**
 * g++ -std=c++17 main.cpp \
    -I /opt/homebrew/include \
    -O2 -o mlat
 */


int main() {

    using Eigen::Vector3d;
    using Eigen::MatrixXd;
    using Eigen::VectorXd;

    //Change anchor positions in future to be set by objects
    std::vector<Vector3d> references = {
        {0.0, 0.0, 0.0},
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {1.0, 1.0, 0.0}
    }; //Square planar layout is not optimal, later find optimal layout

    const int n = references.size();

    Vector3d x_true(0.5, 0.5, 0.5);

    std::vector<double> S(n);

    for(int i = 0; i < n, ++i) {
        S[i] = (x_true - references[i]).norm();
    }



    std::cout << "Hello World" << std:: endl;
    return 0;
}