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
  aVecMatrix(int axis, double angle) - create a matrix with a rotation
  of angle (in radians) around axis (0 for x, 1 for y, 2 for z)
  ============================================================================*/
aVecMatrix::aVecMatrix(int axis, double angle){
  double ca=cos(angle),sa=sin(angle);
  int axis1=(axis+1)%3,axis2=(axis+2)%3;
  set(axis,axis,1);
  set(axis1,axis1,ca);
  set(axis1,axis2,-sa);
  set(axis2,axis1,sa);
  set(axis2,axis2,ca);
}


/*=============================================================================
  ~aVecMatrix() - destructor
  ============================================================================*/
aVecMatrix::~aVecMatrix(){

}


/*=============================================================================
  void set(int row, int col, double v) - set the value of a matrix element
  ============================================================================*/
void aVecMatrix::set(int row, int col, double v){
  m[rcToIndex(row,col)]=v;
}


/*=============================================================================
  int get(int row, int col) - get the value of a matrix element
  ============================================================================*/
double aVecMatrix::get(int row, int col) const{
  return m[rcToIndex(row,col)];
}


/*=============================================================================
  aVecMatrix opeator*(aVecMatrix &m) - multipley this matrix with
  matrix m, this matrix is first, m is second
  ============================================================================*/
aVecMatrix aVecMatrix::operator*(const aVecMatrix &m) const{
  aVecMatrix result;
  int row,col,i;
  double sum;
  for(row=0;row<3;row++)
    for(col=0;col<3;col++){
      sum=0;
      for(i=0;i<3;i++)
	sum+=(*this).get(row,i)*m.get(i,col);
      result.set(row,col,sum);
    }
  return result;
}


/*=============================================================================
  aVec operator*(aVec &v) - multipley this matrix with a a vector v,
  this matrix is first, v is second.
  ============================================================================*/
aVec aVecMatrix::operator*(const aVec &v) const{
  aVec result;
  result.x=get(0,0)*v.x+get(0,1)*v.y+get(0,2)*v.z;
  result.y=get(1,0)*v.x+get(1,1)*v.y+get(1,2)*v.z;
  result.z=get(2,0)*v.x+get(2,1)*v.y+get(2,2)*v.z;

  return result;
}


/*=============================================================================
  int rcToIndex(int row, int col) - convert row and colum to linear
  array index
  ============================================================================*/
int aVecMatrix::rcToIndex(int row, int col) const{
  return 3*row+col;
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
