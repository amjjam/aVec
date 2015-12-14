/******************************************************************************
 * This is class aVec, a 3D vector class                                      *
 ******************************************************************************/

#ifndef _AVEC_H_
#define _AVEC_H_

#include <math.h>
#include <iostream>

class aVec{
public:
  aVec(double x=0, double y=0, double z=0);
  ~aVec();
  double X() const {return x;};
  double Y() const {return y;};
  double Z() const {return z;};
  void setX(double x);
  void setY(double y);
  void setZ(double z);
  aVec operator+(const aVec &v) const;
  aVec operator-(const aVec &v) const;
  aVec operator*(double f) const;
  aVec operator/(double f) const;
  aVec &operator=(const aVec &v);
  aVec &operator+=(const aVec &v);
  aVec &operator-=(const aVec &v);
  aVec &operator*=(double f);
  aVec &operator/=(double f);
  aVec rotateX(double a) const;
  aVec rotateY(double a) const;
  aVec rotateZ(double a) const;
private:
  double x,y,z;
};

aVec unit(const aVec &v);
double length(const aVec &v);
std::ostream &operator<<(std::ostream &os, aVec a);

#endif
