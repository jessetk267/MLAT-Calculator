#include <vector>
#include <Eigen/Dense>

std::vector<double> findRanges(const Eigen::Vector3d x_true, const std::vector<Eigen::Vector3d> references);

std::vector<Eigen::Vector3d> findRangeVectors(const Eigen::Vector3d& x_true, const std::vector<Eigen::Vector3d>& references);

Eigen::Vector3d findPoint(const std::vector<Eigen::Vector3d> references, const std::vector<double> ranges);

double findError(const Eigen::Vector3d x_true, const Eigen::Vector3d x_est);

Eigen::Vector3d findErrorVector (const Eigen::Vector3d x_true, const Eigen::Vector3d x_est);