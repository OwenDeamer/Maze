#include<iostream>

/*
* Model a point in 2d space in any of the 4 quadrents
*
* author: Owen Deamer
*/
using namespace std;

#ifndef POINT_2D
#define POINT_2D

class Point2D
{
private:
	int x;
	int y;

public:

	/*
	* Constuctor for the Point2D object
	* if the user specifies 0 parameters, then
	* both x and y are initialized as 0. if the user
	* specifies 1 parameter, then x will be assigned
	* that value and y will be initialized to 0.
	* if the user specifies 2 parameters, then
	* x will be assigned the first paramerter
	* and y the second parameter.
	*
	* param int x takes the first value
	* param int y takes the second value
	*
	* author: Owen Deamer
	*/
	Point2D(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}

	/*
	* removes the Point2D from memory allowing that memory to
	* be reused.
	*/
	~Point2D()
	{

	}

	/*
	* accessor for the x coordinate
	*
	* return the x coordinate
	*/
	 int getX() const
	{
		return this->x;
	}

	 /*
	 * accessor for the y coordinate
	 *
	 * return the y coordinate
	 */
	 int getY() const
	{
		return this->y;
	}

	 /*
	 * mutator for the x coordinate
	 *
	 * param int x is the user supplied value for 
	 * the coordinate x
	 */
	 void setX(int x)
	 {
		 this->x = x;
	 }

	 /*
	 * mutator for the y coordinate
	 *
	 * param int y is the user supplied value for
	 * the coordinate y
	 */
	 void setY(int y)
	 {
		 this->y = y;
	 }

	 /*
	 * this will overload the + operator to allow us to
	 * add two objects together 
	 * 
	 * Author: Owen Deamer
	 */
	 Point2D& operator+(const Point2D& rhs) const
	 {
		 return Point2D(this->getX() + rhs.getX(), this->getY() + rhs.getY());
	 }

	 /*
	 * this will overload the - operator to allow us to
	 * subtract the objects 
	 *
	 * Author: Owen Deamer
	 */
	 Point2D& operator-(const Point2D& rhs) const
	 {
		 return Point2D(this->getX() - rhs.getX(), this->getY() - rhs.getY());
	 }

	 /*
	 * Defines how to insert a Point2D into a stream
	 * The workd friend gives us the ability to have
	 *		dissimilar type on the left and right of the operator
	 *		has access to all data fields in the class regardless of access modifiers (public, private, protected)
	 *		marks this method as a free function 
	 *
	 * param os stream where we wil insert into
	 * param is a constant reference to the Point2D object we intend to insert
	 *
	 * return os so that we can chain this stream to multiple objects
	 *
	 */
	 friend ostream& operator<<(ostream& os, const Point2D& p)
	 {
		 os << "(" << p.getX() << "," << p.getY() << ")";
		 return os; 
	 }
	
};

#endif
