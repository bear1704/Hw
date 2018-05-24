#ifndef KMUVCL_GRAPHICS_OPERATOR_HPP
#define KMUVCL_GRAPHICS_OPERATOR_HPP

#include "vec.hpp"
#include "mat.hpp"
//#include "transform.hpp"

namespace kmuvcl {
  namespace math {

    /// y_n = s * x_n
    template <unsigned int N, typename T>
    vec<N, T> operator* (const T s, const vec<N, T>& x)
    {

		
      // TODO: Fill up this function properly 
      vec<N, T>  y;
	  
	  for (int i = 0; i < N; i++) {
		  y(i) = s * x(i);
	  }
      return  y;
    }

    /// s = u_n * v_n (dot product)
    template <unsigned int N, typename T>
    T dot(const vec<N, T>& u, const vec<N, T>& v)
    {
      T val = 0;
      
	  for (int i = 0; i < N; i++) {
		  val += u(i)*v(i);
	  }

      return  val;
    }

    /// w_3 = u_3 x v_3 (cross product, only for vec3)
    template <typename T>
    vec<3,T> cross(const vec<3, T>& u, const vec<3, T>& v)
    {
      // TODO: Fill up this function properly 
      vec<3, T>  w;

	  w(0) = u(1)*v(2) - u(2)*v(1);
	  w(1) = u(2)*v(0) - u(0)*v(2);
	  w(2) = u(0)*v(1) - u(1)*v(0);

      return  w;
    }

    /// y_m = A_{mxn} * x_n
    template <unsigned int M, unsigned int N, typename T>
    vec<M, T> operator* (const mat<M, N, T>& A, const vec<N, T>& x)
    {
      vec<M, T>   y, col;
	  vec<N, T> temp_row;

	  for (int i = 0; i < M; i++) {
		  A.get_ith_row(i, temp_row);
			
		  y(i) = dot(temp_row, x);  // 차피 nx1행렬의 곱셈은 내적과 같으니..
		  //주어진 요소(col)을 안썼는데 이거 물어봐야지
	  }

      return  y;
    }

    /// y_n = x_m * A_{mxn}
    template <unsigned int M, unsigned int N, typename T>
    vec<N, T> operator* (const vec<M, T>& x, const mat<M, N, T>& A)
    {
		vec<M, T> temp_col;
		vec<N, T>   y;
		for (int i = 0; i < N; i++) {
			A.get_ith_column(i, temp_col);

				y(i) = dot(x, temp_col);
		}
      // TODO: Fill up this function properly 
      
      
      return  y;
    }

    /// C_{mxl} = A_{mxn} * B_{nxl}
    template <unsigned int M, unsigned int N, unsigned int L, typename T>
    mat<M, L, T> operator* (const mat<M, N, T>& A, const mat<N, L, T>& B)
    {
		vec<N, T> temp_row;
		vec<N, T> temp_col;
      mat<M, L, T>   C;

	  for (int i = 0; i < M; i++) {
		  for (int j = 0; j < L; j++) {
			  A.get_ith_row(i, temp_row);
			
			  B.get_ith_column(j, temp_col);
			
			  
			  //여기 안됨
			  C(j, i) = dot(temp_row, temp_col);
		  }
	  }
       
	  //std::cout << "M : " << M << "  N : " << N << std::endl;
      return  C;
    }

    /// ostream for vec class
    template <unsigned int N, typename T>
	std::ostream& operator << (std::ostream& os, const vec<N, T>& v)
	{

		os << "Vector output";
		os << std::endl;
		for (int i = 0; i < N; i++) {
			os << v(i) << " ";
		}
		os << std::endl;

      // TODO: Fill up this function properly 

      return  os;
    }

    /// ostream for mat class
    template <unsigned int M, unsigned int N, typename T>
    std::ostream& operator << (std::ostream& os, const mat<M, N, T>& A)
    {
		os << "Matrix output";
		std::cout << std::endl;
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				os << A(i, j);
				os << " ";
			}
			os << std::endl;
		}
      return  os;
    }


  } // math
} // kmuvcl

#endif // KMUVCL_GRAPHICS_OPERATOR_HPP
