#include <vector>

class point_3d
{
private:
	double x, y, z;
public:
	point_3d();
	point_3d(double x0, double y0, double z0);
	double getX();
	double getY();
	double getZ();
	double get_distance(point_3d point);
	void add_point(point_3d point);
	void divide_point(double divisor);
	void print_point();
	bool equal_to_point(point_3d point);
};
std::vector<std::vector<point_3d>> k_mean_3d(std::vector<point_3d>, int num_clusters, int min_coord, int max_coord);
void print_clusters(std::vector<std::vector<point_3d>> cluster_holder);
bool compare_points(point_3d point1, point_3d point2);
bool compare_cluster_holders(std::vector<std::vector<point_3d>> cluster_holder_1, std::vector<std::vector<point_3d>> cluster_holder_2);
