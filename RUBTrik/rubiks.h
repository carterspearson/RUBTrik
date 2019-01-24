#include "cluster.h"
class Cube
{
private:
	Face faces[6];
public:
	Cube();
};


class Face
{
private:
	point_3d facelets[9];
public:
	Face();
	point_3d get_facelet(int row, int col);
	void set_facelet(point_3d point, int row, int col);
};