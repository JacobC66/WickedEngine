#include <cassert>
#include <cmath>

#include "Vector3.h"

namespace wicked
{
	namespace maths
	{
		Vector3::Vector3()
			: x{ 0 },
			y{ 0 },
			z{ 0 }
		{
		}

		Vector3::Vector3(float _x, float _y, float _z)
			: x{ _x },
			y{ _y },
			z{ _z }
		{
		}

		Vector3::Vector3(const Vector3& u)
			: x{ u.x },
			y{ u.y },
			z{ u.z }
		{
		}

		float& Vector3::operator[](size_t index)
		{
			assert(index >= 0 && index < m_length);
			return *(&x + index);
		}

		const float& Vector3::operator[](size_t index) const
		{
			assert(index >= 0 && index < m_length);
			return *(&x + index);
		}

		Vector3& Vector3::operator=(const Vector3& u)
		{
			x = u.x;
			y = u.y;
			z = u.z;
			return *this;
		}

		Vector3 operator+(const Vector3 & u, float a)
		{
			return Vector3
			(
				u.x + a,
				u.y + a,
				u.z + a
			);
		}

		Vector3 operator+(float a, const Vector3& u)
		{
			return Vector3
			(
				a + u.x,
				a + u.y,
				a + u.z
			);
		}

		Vector3 operator+(const Vector3& u, const Vector3& v)
		{
			return Vector3
			(
				u.x + v.x,
				u.y + v.y,
				u.z + v.z
			);
		}

		Vector3 operator-(const Vector3 & u, float a)
		{
			return Vector3
			(
				u.x - a,
				u.y - a,
				u.z - a
			);
		}

		Vector3 operator-(float a, const Vector3& u)
		{
			return Vector3
			(
				a - u.x,
				a - u.y,
				a - u.z
			);
		}

		Vector3 operator-(const Vector3& u, const Vector3& v)
		{
			return Vector3
			(
				u.x - v.x,
				u.y - v.y,
				u.z - v.z
			);
		}

		Vector3 operator*(const Vector3 & u, float a)
		{
			return Vector3
			(
				u.x * a,
				u.y * a,
				u.z * a
			);
		}

		Vector3 operator*(float a, const Vector3& u)
		{
			return Vector3
			(
				a * u.x,
				a * u.y,
				a * u.z
			);
		}

		Vector3 operator*(const Vector3& u, const Vector3& v)
		{
			return Vector3
			(
				u.x * v.x,
				u.y * v.y,
				u.z * v.z
			);
		}

		Vector3 operator/(const Vector3 & u, float a)
		{
			return Vector3
			(
				u.x / a,
				u.y / a,
				u.z / a
			);
		}

		Vector3 operator/(float a, const Vector3& u)
		{
			return Vector3
			(
				a / u.x,
				a / u.y,
				a / u.z
			);
		}

		Vector3 operator/(const Vector3& u, const Vector3& v)
		{
			return Vector3
			(
				u.x / v.x,
				u.y / v.y,
				u.z / v.z
			);
		}

		bool operator==(const Vector3& u, const Vector3& v)
		{
			return (u.x == v.x && u.y == v.y && u.z == v.z);
		}

		bool operator!=(const Vector3& u, const Vector3& v)
		{
			return !(u == v);
		}

		float Vector3::dot(const Vector3& u, const Vector3& v)
		{
			Vector3 temp(u * v);
			return (temp.x + temp.y + temp.z);
		}

		float Vector3::magnitud(const Vector3 & u)
		{
			float x{ u.x * u.x };
			float y{ u.y * u.y };
			float z{ u.z * u.z };
			return sqrtf(x + y + z);
		}

		Vector3 Vector3::normalize(const Vector3& u)
		{
			float x{ u.x * u.x };
			float y{ u.y * u.y };
			float z{ u.z * u.z };
			float magnitud{ sqrtf(x + y + z) };
			return Vector3(x / magnitud, y / magnitud, z / magnitud);
		}

		Vector3 Vector3::cross(const Vector3& u, const Vector3& v)
		{
			return Vector3
			(
				(u.y * v.z) - (u.z * v.y),
				-((u.x * v.z) - (u.z * v.x)),
				(u.x * v.y) - (u.y * v.x)
			);
		}

		float Vector3::distance(const Vector3& u, const Vector3& v)
		{
			float x((u.x - v.x) * (u.x - v.x));
			float y((u.y - v.y) * (u.y - v.y));
			float z((u.z - v.z) * (u.z - v.z));
			return sqrtf(x + y + z);
		}
	}
}