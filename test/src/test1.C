
#include "../../include/aVec.H"

int main(int argc, char *argv[]){

  aVec a(1,2,3);

  aVec b(2,3,4);

  std::cout << a << std::endl;
  b=a.rotateX(M_PI/2);
  std::cout << "rotateX(90): " <<  b << std::endl;
  b=a.rotateY(M_PI/2);
  std::cout << "rotateY(90): " <<  b << std::endl;
  b=a.rotateZ(M_PI/2);
  std::cout << "rotateZ(90): " <<  b << std::endl;
  

  return 0;
}
