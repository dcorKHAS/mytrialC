// Geometry.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cmath>

//Point class declaration
//2D point class
class Point
{
		private:
		//private member attributes
			double x;
			double y;

		//Methods
		public:
			//Constructors
			Point() { //Default constructor

				x = 0.0;
				y = 0.0;

			}
				
			Point(double xval, double yval) {//Constructor with coordinates

				x = xval;
				y = yval;

			}
							
			Point(const Point& p) {//Copy constructor
			
				x = p.x;
				y = p.y;
			
			}

			//Getters
			double getX() const {

				return x;
			}
			double getY() const {


				return y;
			}

			//Setters
			void setX(double xval) {

				x=xval;

			}
			void setY(double yval) {

				y=yval;
			}

			//Other methods
			//Distance to origin

			double distanceToOrigin() {

				return sqrt(x*x + y*y);

			}

			//Distance to another point

			double distanceTo(Point p) {

				return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));

			}

};	//End of Point class declaration

//Line class declaration

class Line
{
		private:
			//private member attributes
			Point p1;
			Point p2;

		public:
			//Constructors
			Line() { //Default constructor
			
							p1.setX(0.0);
							p1.setY(0.0);
							p2.setX(0.0);
							p2.setY(0.0);
			
						}

			Line(Point p1val, Point p2val) {//Constructor with coordinates
			
							p1.setX(p1val.getX());
							p1.setY(p1val.getY());
							p2.setX(p2val.getX());
							p2.setY(p2val.getY());
			
						}//Constructor with points

			Line(const Line& l) {//Copy constructor
			
							p1.setX(l.p1.getX());
							p1.setY(l.p1.getY());
							p2.setX(l.p2.getX());
							p2.setY(l.p2.getY());
			
						}

			//Constructor with coordinates
			Line(double x1val, double y1val, double x2val, double y2val) {

				p1.setX(x1val);
				p1.setY(y1val);
				p2.setX(x2val);
				p2.setY(y2val);

			}

			//Getters
			Point getP1() const {

				return p1;
			}
			Point getP2() const {
				
				return p2;

			}
			
			//Setters
			void setP1(Point p1val) {

				p1.setX(p1val.getX());
				p1.setY(p1val.getY());

			}
			void setP2(Point p2val) {

				p2.setX(p2val.getX());
				p2.setY(p2val.getY());

			}

			//Other methods
			//Length of the line
			double length() {

				return p1.distanceTo(p2);

			}

			//Is a point on the line?
			bool isOnLine(Point p) {

				return (p.distanceTo(p1) + p.distanceTo(p2) == p1.distanceTo(p2));

			}

			//Gives the slope of the line
			double slope() {

				return (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());

			}
					
			//Is a line parallel to another line?
			bool isParallel(Line l) {

				//Two lines are parallel if they have the same slope
								
				return (slope() == l.slope());
				
				
			}

			//Is a line perpendicular to another line?
			bool isPerpendicular(Line l) {

				//Two lines are perpendicular if the product of their slopes is -1
				return (slope() * l.slope() == -1);

			}

			//Intersection point of two lines

			Point intersectionPoint(Line l) {

				//Two lines intersect at a point if they are not parallel
				//The intersection point is the solution of the system of equations
				//y = m1*x + b1
				//y = m2*x + b2
				//where m1 and m2 are the slopes of the lines and b1 and b2 are the y-intercepts
				//The solution is x = (b2-b1)/(m1-m2) and y = m1*x + b1

				Point p;
				double x, y;

				if (isParallel(l)) {

					std::cout << "The lines are parallel" << std::endl;
					return p;

				}
				else {

					x = (l.getP2().getY() - getP2().getY() + getP2().getX() * slope() - l.getP2().getX() * l.slope()) / (slope() - l.slope());
					y = slope() * x + getP2().getY() - getP2().getX() * slope();

					p.setX(x);
					p.setY(y);

					return p;

				}

			}
	
};


int main()
{

	//Point class test
	Point p1;
	Point p2(1.0, 2.0);
	Point p3(p2);

	std::cout << "p1: " << p1.getX() << ", " << p1.getY() << std::endl;
	std::cout << "p2: " << p2.getX() << ", " << p2.getY() << std::endl;
	std::cout << "p3: " << p3.getX() << ", " << p3.getY() << std::endl;


	//Test the line intersection method

	Line l1(1.0, 1.0, 2.0, 2.0);
	Line l2(1.0, 2.0, 2.0, 1.0);
	//The intersection is the point (1.5, 1.5)
	Point p4 = l1.intersectionPoint(l2);

	std::cout << "The intersection point of l1 and l2 is: " << p4.getX() << ", " << p4.getY() << std::endl;


	}



