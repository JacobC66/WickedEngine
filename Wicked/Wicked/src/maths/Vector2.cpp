#include <cassert>
#include <cmath>

#include "Vector2.h"

namespace wicked
{
	namespace maths
	{
		Vector2::Vector2()
			: x{ 0 },
			y{ 0 },
			magnitud{ 0 }
		{
		}

		Vector2::Vector2(float _x, float _y)
			: x{ _x },
			y{ _y },
			magnitud{ sqrt((_x * _x) + (_y * _y)) }
		{
		}

		Vector2::Vector2(const Vector2& u)
			: x{ u.x },
			y{ u.y },
			magnitud{ u.magnitud }
		{
		}

		float& Vector2::operator[](size_t index)
		{
			assert(index >= 0 && index < m_length);
			return *(&x + index);
		}

		const float& Vector2::operator[](size_t index) const
		{
			assert(index >= 0 && index < m_length);
			return *(&x + index);
		}

		Vector2& Vector2::operator=(const Vector2& u)
		{
			x = u.x;
			y = u.y;
			return *this;
		}

		void Vector2::operator+= (const Vector2& u)
		{
			x += u.x;
			y += u.y;
		}

		void Vector2::operator-= (const Vector2& u)
		{
			x -= u.x;
			y -= u.y;
		}
		void Vector2::operator*= (const Vector2& u)
		{
			x *= u.x;
			y *= u.y;
		}

		void Vector2::operator/= (const Vector2& u)
		{
			x /= u.x;
			y /= u.y;
		}

		Vector2 operator+(const Vector2& u, const Vector2& v)
		{
			return Vector2
			(
				u.x + v.x,
				u.y + v.y
			);
		}

		Vector2 operator-(const Vector2& u, const Vector2& v)
		{
			return Vector2
			(
				u.x - v.x,
				u.y - v.y
			);
		}

		Vector2 operator*(const Vector2& u, const Vector2& v)
		{
			return Vector2
			(
				u.x * v.x,
				u.y * v.y
			);
		}

		Vector2 operator/(const Vector2& u, const Vector2& v)
		{
			return Vector2
			(
				u.x / v.x,
				u.y / v.y
			);
		}

		bool operator==(const Vector2& u, const Vector2& v)
		{
			return (u.x == v.x && u.y == v.y);
		}

		bool operator!=(const Vector2& u, const Vector2& v)
		{
			return !(u == v);
		}

		float Vector2::dot(const Vector2& u, const Vector2& v)
		{
			Vector2 temp(u * v);
			return (temp.x + temp.y);
		}

		Vector2 Vector2::normalize(const Vector2& u)
		{
			return Vector2(u.x / u.magnitud, u.y / u.magnitud);
		}

		float Vector2::distance(const Vector2& u, const Vector2& v)
		{
			float x((u.x - v.x) * (u.x - v.x));
			float y((u.y - v.y) * (u.y - v.y));
			return sqrtf(x + y);
		}
	}
}