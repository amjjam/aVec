/******************************************************************************
 * This is class aVec, a 3D vector class                                      *
 ******************************************************************************/

#include "../include/aVec.H"

/*=============================================================================
  aVec(double x, double y, double z) - constructor
  ============================================================================*/
aVec::aVec(double x, double y, double z){
  aVec::x=x;
  aVec::y=y;
  aVec::z=z;
}


/*=============================================================================
  ~aVec() - destructor
  ============================================================================*/
aVec::~aVec(){
  
}

/*=============================================================================
  void setX(double x) - set the X-coordinate of the vector
  ============================================================================*/
void aVec::setX(double x){
  aVec::x=x;
}


/*=============================================================================
  void setY(double y) - set the Y-coordinate of the vector
  ============================================================================*/
void aVec::setY(double y){
  aVec::y=y;
}


/*=============================================================================
  void setZ(double z) - set the Z-coordinate of the vector
  ============================================================================*/
void aVec::setZ(double z){
  aVec::z=z;
}


/*=============================================================================
  aVec operator+(aVec &v) - return sum of this vector and vector v
  ============================================================================*/
aVec aVec::operator+(const aVec &v) const{
  aVec r;
  r.x=x+v.x;
  r.y=y+v.y;
  r.z=z+v.z;

  return r;
}


/*=============================================================================
  aVec operator-(aVec &v) - return this vector minus vector v
  ============================================================================*/
aVec aVec::operator-(const aVec &v) const{
  aVec r;

  r.x=x-v.x;
  r.y=y-v.y;
  r.z=z-v.z;

  return r;
}


/*=============================================================================
  double operator*(aVec &b) - return the dot product of this vector with b
  ============================================================================*/
double aVec::operator*(const aVec &b) const{
  return x*b.x+y*b.y+z*b.z;
}


/*=============================================================================
  aVec operator*(double f) - return this vector multiplied by constant f
  ============================================================================*/
aVec aVec::operator*(double f) const{
  aVec r;

  r.x=x*f;
  r.y=y*f;
  r.z=z*f;

  return r;
}


/*=============================================================================
  aVec operator/(double f) - return this vector divided by constant f
  ============================================================================*/
aVec aVec::operator/(double f) const{
  aVec r;

  r.x=x/f;
  r.y=y/f;
  r.z=z/f;

  return r;
}


/*=============================================================================
  aVec &operator=(aVec &v) - set this vector equal to vector v
  ============================================================================*/
aVec &aVec::operator=(const aVec &v){
  x=v.x;
  y=v.y;
  z=v.z;
  
  return *this;
}


/*=============================================================================
  aVec &operator+=(aVec &v) - add vector v to this vector
  ============================================================================*/
aVec &aVec::operator+=(const aVec &v){
  x+=v.x;
  y+=v.y;
  z+=v.z;

  return *this;
}


/*=============================================================================
  aVec &operator-=(aVec &v) - subtract v from this vector
  ============================================================================*/
aVec &aVec::operator-=(const aVec &v){
  x-=v.x;
  y-=v.y;
  z-=v.z;
  
  return *this;
}


/*=============================================================================
  aVec &operator*=(double f) - multiply this vector by a scalar
  ============================================================================*/
aVec &aVec::operator*=(double f){
  x*=f;
  y*=f;
  z*=f;
  
  return *this;
}


/*=============================================================================
  aVec &operator/=(double f) - divide this vector by a scalar
  ============================================================================*/
aVec &aVec::operator/=(double f){
  x/=f;
  y/=f;
  z/=f;
  
  return *this;
}


/*=============================================================================
  aVec rotateX(double a) - returns this vector rotated by angle a
  around the X-axis.
  ============================================================================*/
aVec aVec::rotateX(double a) const{
  return aVec(x,y*cos(a)-z*sin(a),y*sin(a)+z*cos(a));
}
  

/*=============================================================================
  aVec rotateY(double a) - returns this vector rotated by angle a
  around the Y-axis
  ============================================================================*/
aVec aVec::rotateY(double a) const{
  return aVec(z*sin(a)+x*cos(a),y,z*cos(a)-x*sin(a));
}


/*=============================================================================
  aVec rotateZ(double a) - return this vector rotated by angle a
  around the Z-axis.
  ============================================================================*/
aVec aVec::rotateZ(double a) const{
  return aVec(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a),z);
}


/*=============================================================================
  aVec unit(aVec &v) - returns a unit vector parallel to v
  ============================================================================*/
aVec unit(const aVec &v){
  return v/length(v);
}
	 

/*=============================================================================
  double length(aVec &v) - returns the length of the vector
  ============================================================================*/
double length(const aVec &v){
  return sqrt(v.X()*v.X()+v.Y()*v.Y()+v.Z()*v.Z());
}


/*=============================================================================
  std::ostream &operator<<(std::ostream &os, aVec a) - prints a vector
  ============================================================================*/
std::ostream &operator<<(std::ostream &os, aVec a){
  os << "(" << a.X() << "," << a.Y() << "," << a.Z() << ")";
  return os;
}
