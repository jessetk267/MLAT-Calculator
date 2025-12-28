#include <iostream>
#include <vector>
#include <Eigen/Dense>

//Compile with:
/**
 * g++ -std=c++17 main.cpp \
    -I /opt/homebrew/include/eigen3 \
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
        {0.0, 0.0, 1.0}
    };

    const int n = references.size();

    Vector3d x_true(0.5, 0.5, 0.5);

    std::vector<double> S(n);

    for(int i = 0; i < n; ++i) {
        S[i] = (x_true - references[i]).norm();
    }

    MatrixXd A(n - 1, 3);
    VectorXd b(n - 1);

    const Vector3d& p1 = references[0];
    const double S1 = S[0];

    for (int i = 1; i < n; ++i)
    {
        const Vector3d& pi = references[i];
        const double Si = S[i];

        A.row(i - 1) = 2.0 * (p1 - pi).transpose();

        b(i - 1) =
            Si * Si - S1 * S1
            + p1.squaredNorm()
            - pi.squaredNorm();
    }

    Vector3d x_est =
        A.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV)
         .solve(b);


    double error = (x_est - x_true).norm();

    std::cout << "True position:\n" << x_true.transpose() << "\n\n";
    std::cout << "Estimated position:\n" << x_est.transpose() << "\n\n";
    std::cout << "Position error:\n" << error << std::endl;

    return 0;
}