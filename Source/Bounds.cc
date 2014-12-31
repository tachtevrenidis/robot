////////////////////////////////////////////////////////////////////////////////
// -------------------------------------------------------------------------- //
//                                                                            //
//                       (C) 2010-2015 Robot Developers                       //
//                       See LICENSE for licensing info                       //
//                                                                            //
// -------------------------------------------------------------------------- //
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
// Prefaces                                                                   //
//----------------------------------------------------------------------------//

#include "Bounds.h"
#include "Size.h"
#include "Point.h"
namespace Robot {



//----------------------------------------------------------------------------//
// Constructors                                                        Bounds //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

Bounds::Bounds (void)
{
	X = 0;
	Y = 0;
	W = 0;
	H = 0;
}

////////////////////////////////////////////////////////////////////////////////

Bounds::Bounds (int32 x, int32 y, int32 w, int32 h)
{
	X = x;
	Y = y;
	W = w;
	H = h;
}

////////////////////////////////////////////////////////////////////////////////

Bounds::Bounds (const Point& p, const Size& s)
{
	X = p.X;
	Y = p.Y;
	W = s.W;
	H = s.H;
}



//----------------------------------------------------------------------------//
// Functions                                                           Bounds //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

bool Bounds::IsEmpty (void) const
{
	return W == 0 || H == 0;
}

////////////////////////////////////////////////////////////////////////////////

int32 Bounds::GetLeft (void) const
{
	return X;
}

////////////////////////////////////////////////////////////////////////////////

int32 Bounds::GetTop (void) const
{
	return Y;
}

////////////////////////////////////////////////////////////////////////////////

int32 Bounds::GetRight (void) const
{
	return X + W;
}

////////////////////////////////////////////////////////////////////////////////

int32 Bounds::GetBottom (void) const
{
	return Y + H;
}

////////////////////////////////////////////////////////////////////////////////

void Bounds::SetLeft (int32 l)
{
	X = l;
}

////////////////////////////////////////////////////////////////////////////////

void Bounds::SetTop (int32 t)
{
	Y = t;
}

////////////////////////////////////////////////////////////////////////////////

void Bounds::SetRight (int32 r)
{
	W = r - X;
}

////////////////////////////////////////////////////////////////////////////////

void Bounds::SetBottom (int32 b)
{
	H = b - Y;
}

////////////////////////////////////////////////////////////////////////////////

void Bounds::SetLTRB (int32 l, int32 t, int32 r, int32 b)
{
	X = l;
	Y = t;
	W = r - l;
	H = b - t;
}

////////////////////////////////////////////////////////////////////////////////

bool Bounds::Contains (const Point& p, bool inclusive) const
{
	return Contains (p.X, p.Y, inclusive);
}

////////////////////////////////////////////////////////////////////////////////

bool Bounds::Contains (int32 x, int32 y, bool inclusive) const
{
	// Normalize negative rectangles
	int32 l = X, r = X, t = Y, b = Y;
	if (W < 0) l += W; else r += W;
	if (H < 0) t += H; else b += H;

	return inclusive ?
		l <= x && x <= r && t <= y && y <= b :
		l <  x && x <  r && t <  y && y <  b;
}

////////////////////////////////////////////////////////////////////////////////

Point Bounds::GetPoint (void) const
{
	return Point (X, Y);
}

////////////////////////////////////////////////////////////////////////////////

void Bounds::SetPoint (const Point& p)
{
	X = p.X;
	Y = p.Y;
}

////////////////////////////////////////////////////////////////////////////////

void Bounds::SetPoint (int32 x, int32 y)
{
	X = x;
	Y = y;
}

////////////////////////////////////////////////////////////////////////////////

Size Bounds::GetSize (void) const
{
	return Size (W, H);
}

////////////////////////////////////////////////////////////////////////////////

void Bounds::SetSize (const Size& s)
{
	W = s.W;
	H = s.H;
}

////////////////////////////////////////////////////////////////////////////////

void Bounds::SetSize (int32 w, int32 h)
{
	W = w;
	H = h;
}



//----------------------------------------------------------------------------//
// Operators                                                           Bounds //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

bool Bounds::operator == (const Bounds& bounds) const
{
	return X == bounds.X && Y == bounds.Y &&
		   W == bounds.W && H == bounds.H;
}

////////////////////////////////////////////////////////////////////////////////

bool Bounds::operator != (const Bounds& bounds) const
{
	return X != bounds.X || Y != bounds.Y ||
		   W != bounds.W || H != bounds.H;
}

} // namespace Robot
