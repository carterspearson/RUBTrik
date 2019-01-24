#include "cluster.h"
#include <vector>
#include <iostream>
#include <cstdlib> 
#include <climits>
#include <random>

std::vector<std::vector<point_3d>> k_mean_3d(std::vector<point_3d> point_list, int num_clusters, int min_coord, int max_coord)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, point_list.size() - 1); // define the range

	std::vector<point_3d> mean_holder;

	std::vector<std::vector<point_3d>> cluster_holder;
	std::vector<std::vector<point_3d>> old_cluster_holder;

	std::vector<int> used_indices;
	point_3d total_mean(0, 0, 0);

	for (int i = 0; i < point_list.size(); i++)
	{
		total_mean.add_point(point_list[i]);
	}
	total_mean.divide_point(point_list.size());
	for (int i = 0; i < num_clusters; i++)
	{
		//int random_index = rand() % point_list.size();
		int random_index = distr(eng);
		bool index_good = false;
		while (!index_good)
		{
			for (int i = 0; i < used_indices.size(); i++)
			{
				if (random_index == used_indices[i])
				{
					random_index = distr(eng);
					break;
				}
			}
			index_good = true;
		}
		used_indices.push_back(random_index);
		//std::cout << random_index << std::endl;
		point_3d centroid = point_list[random_index];
		centroid.add_point(total_mean);
		centroid.divide_point(2);
		mean_holder.push_back(centroid);
		//std::cout << "Starting point " << i << ": ";
		//mean_holder.back().print_point();
		std::vector<point_3d> cluster;
		cluster_holder.push_back(cluster);
	}

	while (!compare_cluster_holders(cluster_holder, old_cluster_holder))
	{
		old_cluster_holder = cluster_holder;
		for (int i = 0; i < cluster_holder.size(); i++)
		{
			cluster_holder[i].clear();
		}
		for (int i = 0; i < point_list.size(); i++)
		{
			int min_distance = INT_MAX;
			int closest_cluster = 0;
			for (int j = 0; j < num_clusters; j++)
			{
				if (point_list[i].get_distance(mean_holder[j]) <= min_distance)
				{
					min_distance = point_list[i].get_distance(mean_holder[j]);
					closest_cluster = j;
				}
			}
			cluster_holder[closest_cluster].push_back(point_list[i]);
		}

		for (int i = 0; i < num_clusters; i++)
		{
			point_3d mean_point = point_3d(0, 0, 0);
			for (int j = 0; j < cluster_holder[i].size(); j++)
			{
				mean_point.add_point(cluster_holder[i][j]);
				//cluster_holder[i].pop_back();
			}
			//std::sort(cluster_holder[i].begin(), cluster_holder[i].end(), compare_points);
			mean_point.divide_point(cluster_holder[i].size());
			mean_holder[i] = mean_point;
			//std::cout << "New point " << i << ": ";
			//mean_holder[i].print_point();
		}
		//print_clusters(cluster_holder);
	}
	return cluster_holder;
}

void print_clusters(std::vector<std::vector<point_3d>> cluster_holder)
{
	for (int i = 0; i < cluster_holder.size(); i++)
	{
		std::cout << "CLUSTER " << i + 1 << std::endl;
		for (int j = 0; j < cluster_holder[i].size(); j++)
		{
			cluster_holder[i][j].print_point();
		}
	}
}

bool compare_points(point_3d point1, point_3d point2)
{
	if (point1.getX() > point2.getX())
		return true;
	else if (point1.getX() < point2.getX())
		return false;
	else
	{
		if (point1.getY() > point2.getY())
			return true;
		else if (point1.getY() < point2.getY())
			return false;
		else
		{
			if (point1.getY() > point2.getY())
				return true;
			else
				return false;
		}
	}
}

bool compare_cluster_holders(std::vector<std::vector<point_3d>> cluster_holder_1, std::vector<std::vector<point_3d>> cluster_holder_2)
{
	if (cluster_holder_1.size() != cluster_holder_2.size())
		return false;
	for (int i = 0; i < cluster_holder_1.size(); i++)
	{
		if (cluster_holder_1[i].size() != cluster_holder_2[i].size())
			return false;
		std::sort(cluster_holder_1[i].begin(), cluster_holder_1[i].end(), compare_points);
		std::sort(cluster_holder_2[i].begin(), cluster_holder_2[i].end(), compare_points);
		for (int j = 0; j < cluster_holder_1[i].size(); j++)
		{
			if (!cluster_holder_1[i][j].equal_to_point(cluster_holder_2[i][j]))
				return false;
		}
	}
	return true;
}

point_3d::point_3d()
{
	x = 0;
	y = 0;
	z = 0;
}

point_3d::point_3d(double x0, double y0, double z0)
{
	x = x0;
	y = y0;
	z = z0;
}

double point_3d::getX()
{
	return x;
}

double point_3d::getY()
{
	return y;
}

double point_3d::getZ()
{
	return z;
}

double point_3d::get_distance(point_3d point)
{
	return sqrt(pow(x - point.getX(), 2) + pow(y - point.getY(), 2) + pow(z - point.getZ(), 2));
}

void point_3d::add_point(point_3d point)
{
	x = x + point.getX();
	y = y + point.getY();
	z = z + point.getZ();
}

void point_3d::divide_point(double divisor)
{
	x = x / divisor;
	y = y / divisor;
	z = z / divisor;
}

void point_3d::print_point()
{
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

bool point_3d::equal_to_point(point_3d point)
{
	return ((x == point.getX()) && (y == point.getY()) && (z == point.getZ()));
}

