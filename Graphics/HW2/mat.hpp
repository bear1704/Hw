#ifndef KMUVCL_GRAPHICS_MAT_HPP
#define KMUVCL_GRAPHICS_MAT_HPP

#include <iostream>
#include <cstring>
#include <cstdarg>

namespace kmuvcl {
  namespace math {

    template <unsigned int M, unsigned int N, typename T>
    class mat
    {
    public:
      mat()
      {
        set_to_zero();
      }

      mat(const T elem)
      {
        std::fill(val, val + M*N, elem); //행렬 초기화 생성자
      }
	  
      T& operator()(unsigned int r, unsigned int c)
      { 
		  return  val[r*N+c];
      }

	  T getVal() {
		  for (int i = 0; i < M*N; i++) std::cout << val[i] << " ";

		  return 0;
		  // Test Method;
	  } 
	  
      const T& operator()(unsigned int r, unsigned int c) const //뒤에 const붙은건 인자를 변경하지 않겠다.
      {
		  return  val[r*N+c];
      }

      // type casting operator
      const T* operator()() const
      {
        return  val;
      }

      void set_to_zero()
      {
		  std::fill(val, val + M*N, 0);
      }

      void get_ith_column(unsigned int i, vec<M, T>& col) const
      {/*
		  vec<M, T> temp_vector;
		  temp_vector.set_to_zero();

		  for (int a = 0; a < M; a++) {
			  temp_vector(a) = val[a*N + i];
		  }

		  col = temp_vector;
		 */ 
		  vec<M, T> temp_vector;
		  temp_vector.set_to_zero();

		  for (int a = 0; a < M; a++) {
			  temp_vector(a) = val[i*N + a];
		  }

		  col = temp_vector;
      }

      void set_ith_column(unsigned int i, const vec<M, T>& col)
      {	/*
		  vec<M, T> temp_vector = col;

		  for (int a = 0; a < M; a++) {
			  val[a*N + i] = temp_vector(a);
		  }*/
		  vec<M, T> temp_vector = col;

		  for (int a = 0; a < M; a++) {
			  val[i*M + a] = temp_vector(a);
		  }
      }

      void get_ith_row(unsigned int i, vec<N, T>& row) const
      {
		  /*
		  vec<N, T> temp_vector;
		  temp_vector.set_to_zero();

		  for (int a = 0; a < N; a++) {
			  temp_vector(a) = val[i*N + a];
		  }

		  row = temp_vector;
       */

		  vec<N, T> temp_vector;
		  temp_vector.set_to_zero();

		  for (int a = 0; a < N; a++) {
			  temp_vector(a) = val[a*N + i];
		  }

		  row = temp_vector;
      }

      void set_ith_row(unsigned int i, const vec<N, T>& row)
      {
		 /* vec<N, T> temp_vector = row;
		  for (int a = 0; a < N; a++) {
			  val[i*N + a] = temp_vector(a);
		  }*/
		  vec<N, T> temp_vector = row;

		  for (int a = 0; a < N; a++) {
			  val[a*N + i] = temp_vector(a);
		  }
        
      }

      mat<N, M, T> transpose() const
      {
        mat<N, M, T>  trans;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				trans(i, j) = val[j*N+i];
			}
		}
        return  trans;
      }

    protected:
      T val[M*N];   // column major
    };

    typedef mat<3, 3, float>    mat3x3f;
    typedef mat<3, 3, double>   mat3x3d;

    typedef mat<4, 4, float>    mat4x4f;
    typedef mat<4, 4, double>   mat4x4d;

  } // math
} // kmuvcl

#include "operator.hpp"

#endif // #ifndef KMUVCL_GRAPHICS_MAT_HPP
