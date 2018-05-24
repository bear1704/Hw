#ifndef KMUCS_GRAPHICS_TRANSFORM_HPP
#define KMUCS_GRAPHICS_TRANSFORM_HPP

#include<iostream>
#include<cmath>
#include<cstdarg>

#define _USE_MATH_DEFINES

namespace kmuvcl {
	namespace math {

		template <unsighed int N, typename T>
		class transform {

		public:
			transform() {
				set_to_zero();
			}






			void set_to_zero()
			{
				std::fill(val, val + M*N, 0);
			}

		}



	}
}

#endif