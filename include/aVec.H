/******************************************************************************
 * This is class aVec, a 3D vector class                                      *
 ******************************************************************************/

#ifndef _AVEC_H_
#define _AVEC_H_

#include <math.h>
#include <iostream>
#include <array>

class aVecMatrix;

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
  double operator*(const aVec &b) const;
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
  size_t size() const {return 3*sizeof(double);};
  size_t write(uint8_t *d) const;
  size_t read(const uint8_t *d);
private:
  double x,y,z;
  friend aVecMatrix;
};


class aVecMatrix{
public:
  aVecMatrix(){};
  aVecMatrix(int axis, double angle);
  ~aVecMatrix();
  void set(int row, int col, double v);
  double get(int row, int col) const;
  aVecMatrix operator*(const aVecMatrix &m) const;
  aVec operator*(const aVec &v) const;
private:
  std::array<double,9> m{};
  int rcToIndex(int row, int col) const;
};

    
aVec unit(const aVec &v);
double length(const aVec &v);
std::ostream &operator<<(std::ostream &os, aVec a);

int fwrite(FILE *fp, const aVec &);
int fread(FILE *fp, aVec &);

#endif
