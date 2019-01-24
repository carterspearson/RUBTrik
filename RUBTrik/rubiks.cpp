#include "cluster.h"
#include "rubiks.h"

Face::Face()
{
	std::fill_n(facelets, 9, point_3d(0, 0, 0));
}

point_3d Face::get_facelet(int row, int col)
{
	return facelets[col + row * 3];
}

void Face::set_facelet(point_3d point, int row, int col)
{
	facelets[col + row * 3] = point;
}