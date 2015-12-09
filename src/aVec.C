/******************************************************************************
 * This is class aVec, a 3D vector class                                      *
 ******************************************************************************/

#include "../include/aVec.H"

/*=============================================================================
  aVec operator+(aVec &v) - return sum of this vector and vector v
  ============================================================================*/
aVec aVec::operator+(aVec &v){
  aVec r;
  r.x=x+v.x;
  r.y=y+v.y;
  r.z=z+v.z;

  return r;
}


/*=============================================================================
  aVec operator-(aVec &v) - return this vector minus vector v
  ============================================================================*/
aVec aVec::operator-(aVec &v){
  aVec r;

  r.x=x-v.x;
  r.y=y-v.y;
  r.z=z-v.z;

  return r;
}


/*=============================================================================
  aVec operator*(double f) - return this vector multiplied by constant f
  ============================================================================*/
aVec aVec::operator*(double f){
  aVec r;

  r.x=x*f;
  r.y=y*f;
  r.z=z*f;

  return r;
}


/*=============================================================================
  aVec operator/(double f) - return this vector divided by constant f
  ============================================================================*/
aVec aVec::operator/(double f){
  aVec r;

  r.x=x/f;
  r.y=y/f;
  r.z=z/f;

  return r;
}


/*=============================================================================
  aVec &operator=(aVec &v) - set this vector equal to vector v
  ============================================================================*/
aVec &aVec::operator=(aVec &v){
  x=v.x;
  y=v.y;
  z=v.z;
  
  return this;
}


/*=============================================================================
  aVec &operator+=(aVec &v) - add vector v to this vector
  ============================================================================*/
aVec &aVec::operator+=(aVec &v){
  x+=v.x;
  y+=v.y;
  z+=v.z;

  return this;
}


/*=============================================================================
  aVec &operator-=(aVec &v) - subtract v from this vector
  ============================================================================*/
aVec &aVec::operator-=(aVec &v){
  x-=v.x;
  y-=v.y;
  z-=v.z;
  
  return this;
}


/*=============================================================================
  aVec &operator*=(double f) - multiply this vector by a scalar
  ============================================================================*/
aVec &aVec::operator*=(double f){
  x*=f;
  y*=f;
  z*=f;
  
  return this;
}


/*=============================================================================
  aVec &operator/=(double f) - divide this vector by a scalar
  ============================================================================*/
aVec &aVec::operator/=(double f){
  x/=f;
  y/=f;
  z/=f;
  
  return this;
}


/*=============================================================================
  aVec unit(aVec &v) - returns a unit vector parallel to v
  ============================================================================*/
aVec unit(aVec &v){
  return v/length(v);
}
	 

/*=============================================================================
  double length(aVec &v) - returns the length of the vector
  ============================================================================*/
double length(aVec &v){
  return sqrt(v.x()*v.x()+v.y()*v.y()+v.z()*v.z());
}