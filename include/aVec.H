/******************************************************************************
 * This is class aVec, a 3D vector class                                      *
 ******************************************************************************/

#ifndef _AVEC_H_
#define _AVEC_H_

#include <math.h>

class aVec{
public:
  aVec(double x=0, double y=0, double z=0);
  ~aVec();
  double X(){return x;};
  double Y(){return y;};
  double Z(){return z;};
  void setX(double x);
  void setY(double y);
  void setZ(double z);
  aVec operator+(const aVec &v);
  aVec operator-(const aVec &v);
  aVec operator*(double f);
  aVec operator/(double f);
  aVec &operator=(const aVec &v);
  aVec &operator+=(const aVec &v);
  aVec &operator-=(const aVec &v);
  aVec &operator*=(double f);
  aVec &operator/=(double f);
  aVec rotateX(double a);
  aVec rotateY(double a);
  aVec rotateZ(double a);
private:
  double x,y,z;
};

aVec unit(aVec &v);
double length(aVec &v);

#endif
