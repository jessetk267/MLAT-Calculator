#include <iostream>
#include <vector>
#include <Eigen/Dense>

//Compile with:
/**
 * g++ -std=c++17 main.cpp \
    -I /opt/homebrew/include/eigen3 \
    -O2 -o mlat
 */

std::vector<double> findRanges(const Eigen::Vector3d x_true, const std::vector<Eigen::Vector3d> references) {
    using Eigen::Vector3d;
    using Eigen::MatrixXd;
    using Eigen::VectorXd;

    const int n = references.size();

    std::vector<double> S(n);

    for(int i = 0; i < n; ++i) {
        S[i] = (x_true - references[i]).norm();
    }

    return S;
}

Eigen::Vector3d findPoint(const std::vector<Eigen::Vector3d> references, const std::vector<double> ranges) {
    using Eigen::Vector3d;
    using Eigen::MatrixXd;
    using Eigen::VectorXd;

    const int n = references.size();

    MatrixXd A(n - 1, 3);
    VectorXd b(n - 1);

    const Vector3d& p1 = references[0];
    const double S1 = ranges[0];

    for (int i = 1; i < n; ++i)
    {
        const Vector3d& pi = references[i];
        const double Si = ranges[i];

        A.row(i - 1) = 2.0 * (p1 - pi).transpose();

        b(i - 1) =
            Si * Si - S1 * S1
            + p1.squaredNorm()
            - pi.squaredNorm();
    }

    Vector3d x_est = A.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(b);

    return x_est;
}

double findError(const Eigen::Vector3d x_true, const Eigen::Vector3d x_est) {
    return (x_est - x_true).norm();
}

int main() {
    using Eigen::Vector3d;

    Vector3d x_true(0.1, 0.3, 0.8);

    std::vector<Vector3d> references = {
        {0.0, 0.0, 0.0},
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    };

    std::vector<double> ranges = findRanges(x_true, references);

    Vector3d x_est = findPoint(references, ranges);

    double error = findError(x_true, x_est);

    std::cout << "True position:\n" << x_true.transpose() << "\n\n";
    std::cout << "Estimated position:\n" << x_est.transpose() << "\n\n";
    std::cout << "Position error:\n" << error << std::endl;

    return 0;
}