#pragma once
//A vector class to hold a pair of a type, also overloaded with a bunch of useful operators
template <typename T>
class Vec2
{
public:
	Vec2() = default;
	Vec2(T _x, T _y)
		:
		x(_x),
		y(_y)
	{}

	T GetX() const { return x; }
	T GetY() const { return y; }
	void SetX(T _x) { x = _x; }
	void SetY(T _y) { y = _y; }

public:
	bool operator==(const Vec2& rhs) const
	{
		return(x == rhs.x && y == rhs.y);
	}
	bool operator!=(const Vec2& rhs) const
	{
		return !(*this == rhs);
	}
	Vec2 operator+(const Vec2& rhs) const
	{
		return { x + rhs.x, y + rhs.y };
	}
	Vec2 operator+(const int rhs) const
	{
		return { x + rhs, y + rhs };
	}
	Vec2 operator-(const Vec2& rhs) const
	{
		return { x - rhs.x, y - rhs.y };
	}
	Vec2 operator-(const int rhs) const
	{
		return { x - rhs, y - rhs };
	}
	Vec2& operator+=(const Vec2& rhs)
	{
		return *this = *this + rhs;
	}
	Vec2& operator-=(const Vec2 rhs)
	{
		return *this = *this - rhs;
	}
	Vec2 operator*(const Vec2& rhs) const
	{
		return { x * rhs.x, y * rhs.y };
	}
	Vec2 operator*(const int rhs) const
	{
		return { x * rhs, y * rhs };
	}
	Vec2 operator*=(const Vec2 rhs)
	{
		return *this = *this * rhs;
	}
private:
	T x;
	T y;
};