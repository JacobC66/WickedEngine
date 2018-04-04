#include <cassert>
#include <cmath>

#include "Vector4.h"

namespace wicked
{
	namespace maths
	{
		Vector4::Vector4()
			: x{ 0 },
			  y{ 0 },
			  z{ 0 },
			  w{ 0 }
		{
		}

		Vector4::Vector4(float _x, float _y, float _z, float _w)
			: x{ _x },
			  y{ _y },
			  z{ _z },
			  w{ _w }
		{
		}

		Vector4::Vector4(const Vector4& u)
			: x{ u.x },
			  y{ u.y },
			  z{ u.z },
			  w{ u.w }
		{
		}

		float& Vector4::operator[](size_t index)
		{
			assert(index >= 0 && index < m_length);
			return *(&x + index);
		}

		const float& Vector4::operator[](size_t index) const
		{
			assert(index >= 0 && index < m_length);
			return *(&x + index);
		}

		Vector4& Vector4::operator=(const Vector4& u)
		{
			x = u.x;
			y = u.y;
			z = u.z;
			w = u.w;
			return *this;
		}

		Vector4 operator+(const Vector4 & u, float a)
		{
			return Vector4
			(
				u.x + a,
				u.y + a,
				u.z + a,
				u.w + a
			);
		}

		Vector4 operator+(float a, const Vector4 & u)
		{
			return Vector4
			(
				a + u.x,
				a + u.y,
				a + u.z,
				a + u.w
			);
		}

		Vector4 operator+(const Vector4& u, const Vector4& v)
		{
			return Vector4
			(
				u.x + v.x,
				u.y + v.y,
				u.z + v.z,
				u.w + v.w
			);
		}

		Vector4 operator-(const Vector4 & u, float a)
		{
			return Vector4
			(
				u.x - a,
				u.y - a,
				u.z - a,
				u.w - a
			);
		}

		Vector4 operator-(float a, const Vector4 & u)
		{
			return Vector4
			(
				a - u.x,
				a - u.y,
				a - u.z,
				a - u.w
			);
		}

		Vector4 operator-(const Vector4& u, const Vector4& v)
		{
			return Vector4
			(
				u.x - v.x,
				u.y - v.y,
				u.z - v.z,
				u.w - v.w
			);
		}

		Vector4 operator*(const Vector4 & u, float a)
		{
			return Vector4
			(
				u.x * a,
				u.y * a,
				u.z * a,
				u.w * a
			);
		}

		Vector4 operator*(float a, const Vector4 & u)
		{
			return Vector4
			(
				a * u.x,
				a * u.y,
				a * u.z,
				a * u.w
			);
		}

		Vector4 operator*(const Vector4& u, const Vector4& v)
		{
			return Vector4
			(
				u.x * v.x,
				u.y * v.y,
				u.z * v.z,
				u.w * v.w
			);
		}

		Vector4 operator/(const Vector4 & u, float a)
		{
			return Vector4
			(
				u.x / a,
				u.y / a,
				u.z / a,
				u.w / a
			);
		}

		Vector4 operator/(float a, const Vector4 & u)
		{
			return Vector4
			(
				a / u.x,
				a / u.y,
				a / u.z,
				a / u.w
			);
		}

		Vector4 operator/(const Vector4& u, const Vector4& v)
		{
			return Vector4
			(
				u.x / v.x,
				u.y / v.y,
				u.z / v.z,
				u.w / v.w
			);
		}

		bool operator==(const Vector4& u, const Vector4& v)
		{
			return (u.x == v.x && u.y == v.y && u.z == v.z && u.w == v.w);
		}

		bool operator!=(const Vector4& u, const Vector4& v)
		{
			return !(u == v);
		}

		float Vector4::dot(const Vector4& u, const Vector4& v)
		{
			Vector4 temp(u * v);
			return (temp.x + temp.y + temp.z + temp.w);
		}

		float Vector4::magnitud(const Vector4 & u)
		{
			float x{ u.x * u.x };
			float y{ u.y * u.y };
			float z{ u.z * u.z };
			float w{ u.w * u.w };
			return sqrtf(x + y + z + w);
		}

		Vector4 Vector4::normalize(const Vector4& u)
		{
			float x{ u.x * u.x };
			float y{ u.y * u.y };
			float z{ u.z * u.z };
			float w{ u.z * u.w };
			float magnitud{ sqrtf(x + y + z + w) };
			return Vector4(x / magnitud, y / magnitud, z / magnitud, w / magnitud);
		}

		float Vector4::distance(const Vector4& u, const Vector4& v)
		{
			float x((u.x - v.x) * (u.x - v.x));
			float y((u.y - v.y) * (u.y - v.y));
			float z((u.z - v.z) * (u.z - v.z));
			float w((u.w - v.w) * (u.w - v.w));
			return sqrtf(x + y + z + w);
		}
	}
}