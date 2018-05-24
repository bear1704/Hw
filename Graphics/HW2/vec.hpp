#ifndef KMUCS_GRAPHICS_VEC_HPP
#define KMUCS_GRAPHICS_VEC_HPP

#include <iostream>
#include <algorithm>

namespace kmuvcl {
  namespace math {

    template <unsigned int N, typename T>
    class vec
    {
    public:
      vec()
      {
        set_to_zero();
      }

      vec(const T elem)
      {
		  std::fill(val, val + N, elem); //검증필요
      }

      vec(const T s, const T t) : vec()
      {
		  std::fill(val, val + N, 0);
		  val[0] = s;
		  val[1] = t; //검증필요
      }

      vec(const T s, const T t, const T u) : vec()
      {
		  std::fill(val, val + N, 0);
		  val[0] = s;
		  val[1] = t;
		  val[2] = u; //검증필요
      }

      vec(const T s, const T t, const T u, const T v) : vec()
      {
		  std::fill(val, val + N, 0);
		  val[0] = s;
		  val[1] = t;
		  val[2] = u;
		  val[3] = v;
      }
      
      vec(const vec<N, T>& other)
      {
		  std::fill(val, val + N, 0);
		  for (int i = 0; i < N; i++) {
			  val[i] = other.val[i]; // 검증이 필요하지만 돌아는 간다.
		  }
      }

	  
	 void getvec() { //test code
		 std::cout << "-----------------" << std::endl;
		 for (int i = 0; i < N; i++)  std::cout << val[i] << " ";
		
		 std::cout<<std::endl<<"--------------" << std::endl;
	  }

      vec& operator= (const vec<N, T>& other)
      {
		  std::fill(val, val + N, 0);
		  
		  for (int i = 0; i < N; i++) {
			  val[i] = other.val[i];
		  }
		 
        return  *this;
      }

      T& operator()(unsigned int i)
      { 
        return  val[i];
      }

      const T& operator()(unsigned int i) const
      {
		  return val[i];
		  //같은 코드로 보이는데 const를 붙이는 이유가?
        
      }

      // type casting operators
      operator const T* () const
      {
        return  val;
      }

      operator T* ()
      {
        return  val;
      }

      vec& operator+=(const vec<N, T>& other)
      {
		  for (int i = 0; i < N; i++) {
			  val[i] += other.val[i];
		  }
        return *this;
      }

      vec& operator-=(const vec<N, T>& other)
      {
		  for (int i = 0; i < N; i++) {
			  val[i] -= other.val[i];
		  }
        return *this;
      }

      void set_to_zero()
      {
		  std::fill(val, val + N, 0);
      }

    protected:
      T val[N];
    };

    // typedef
    typedef vec<2, float>   vec2f;
    typedef vec<2, double>  vec2d;

    typedef vec<3, float>   vec3f;
    typedef vec<3, double>  vec3d;
    
    typedef vec<4, float>   vec4f;
    typedef vec<4, double>  vec4d;


	

  } // namespace math
} // namespace kmuvcl


#include "operator.hpp"

#endif // KMUCS_GRAPHICS_VEC_HPP
