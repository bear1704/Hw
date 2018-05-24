#include <iostream>
//#include "vec2.hpp"
//#include "vec3.hpp"

//using kmuvcl::math::vec2f;
//using kmuvcl::math::vec3f;

#include "vec.hpp"
#include "mat.hpp"
#include "transform.hpp"

//using kmuvcl::math::vec2f;
//using kmuvcl::math::vec3f;
//using kmuvcl::math::mat3x3f;

//typedef kmuvcl::math::mat<3, 2, float> mat3x2f;
//typedef kmuvcl::math::mat<2, 3, float> mat2x3f;

int main()
{
  kmuvcl::math::vec2f   w(2, 1);
  kmuvcl::math::vec3f   x(3, 5, 7);
  kmuvcl::math::vec3f   y;
  kmuvcl::math::vec3f   z;
  //kmuvcl::math::vec3f	k;//test code
  
  //mat3x2f   A;
  //mat2x3f   B;
  kmuvcl::math::mat<3, 2, float>  A;
  kmuvcl::math::mat<2, 3, float>  B;

  //A(0, 0) = +1;   A(0, 1) = +2;   A(0, 2) = -1;
  //A(1, 0) = +2;   A(1, 1) = +1;   A(1, 2) = +0;
  //A(2, 0) = +3;   A(2, 1) = -2;   A(2, 2) = +1;
  
  A(0, 0) = +1;   A(0, 1) = +2;   
  A(1, 0) = +2;   A(1, 1) = +1;   
  A(2, 0) = +3;   A(2, 1) = -2;   
  
	
  std::cout << A;

  // vector = operator  
  y = x;
  
  std::cout << y << std::endl;

  // vector += operator
  y += x;
  std::cout << y << std::endl;
  
  // vector -=operator
  y -= x;
  std::cout << y << std::endl;

  // mat transpose
  B = A.transpose();
  
  std::cout << B;
  
  
  // get mat B row
  kmuvcl::math::vec3f B_row;

  B.get_ith_row(0, B_row);
  std::cout << B_row << std::endl;
  B.get_ith_row(1, B_row);
  std::cout << B_row << std::endl;
 
  // get mat B col
  kmuvcl::math::vec2f B_col;

  B.get_ith_column(0, B_col);
  std::cout << B_col << std::endl;
  B.get_ith_column(1, B_col);
  std::cout << B_col << std::endl;
  B.get_ith_column(2, B_col);
  std::cout << B_col << std::endl;

  //std::cout << "------------";

  //kmuvcl::math::vec<2,float> kk(1, 1);
  //B.set_ith_column(1, kk);
  //B.set_ith_column(2, kk);
  //B.getVal();
  //std::cout << std::endl;
  //std::cout << "---------------" << std::endl; //test code
 
  // operator cross
  y = kmuvcl::math::vec3f(1,0,0);

  z = cross(x, y);
  std::cout << z << std::endl;

  // operator dot
  float val;

  val = dot(x, y);
  std::cout << val << std::endl;
 
  // operator *
  y = 3.0f * x;
  std::cout << y << std::endl;
  
  // operator mat x vector
  y = A * w;
  std::cout << y << std::endl;
  
  transform tt = new transform();
  


  // operator vector x mat
  w = x * A;
  std::cout << w << std::endl;

  // get mat column
  kmuvcl::math::vec3f A_col;
  
  A.get_ith_column(0, A_col);
  std::cout << A_col << std::endl;
  A.get_ith_column(1, A_col);
  std::cout << A_col << std::endl;

  // get mat row
  kmuvcl::math::vec2f A_row;
  A.get_ith_row(0, A_row);
  std::cout << A_row << std::endl;
  A.get_ith_row(1, A_row);
  std::cout << A_row << std::endl;
  A.get_ith_row(2, A_row);
  std::cout << A_row << std::endl;

  // operator mat x mat
  kmuvcl::math::mat<3, 3, float>  C;
  C = A * B;
  std::cout << C << std::endl; 


  return  0;
}
