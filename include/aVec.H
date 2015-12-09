/******************************************************************************
 * This is class aVec, a 3D vector class                                      *
 ******************************************************************************/

#ifndef _AVEC_H_
#define _AVEC_H_

class aVec{
public:
  aVec(double x=0, double y=0, double z=0);
  ~aVec();
  double x(){return x;};
  double y(){return y;};
  double z(){return z;};
  aVec operator+(aVec &v);
  aVec operator-(aVec &v);
  aVec operator*(double f);
  aVec operator/(double f);
  aVec &operator=(aVec &v);
  aVec &operator+=(aVec &v);
  aVec &operator-=(aVec &v);
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
