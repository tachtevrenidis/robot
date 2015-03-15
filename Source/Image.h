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

#ifndef ROBOT_IMAGE_H
#define ROBOT_IMAGE_H

#include "Global.h"
namespace Robot {
	class Color;
	class Size;
	class Point;



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class ROBOT_EXPORT Image
{
public:
				 Image			(void);
				~Image			(void);

				 Image			(const Image&  image);
				 Image			(      Image&& image);

	explicit	 Image			(const  Size&  size);
	explicit	 Image			(uint16 w, uint16 h);

public:
	bool		IsValid			(void) const;

	void		Create			(const  Size&  size);
	void		Create			(uint16 w, uint16 h);
	void		Destroy			(void);

	uint16		GetWidth		(void) const { return mWidth;	}
	uint16		GetHeight		(void) const { return mHeight;	}
	uint32		GetLength		(void) const { return mLength;	}
	uint32*		GetData			(void) const { return mData;	}
	uint32		GetLimit		(void) const { return mLimit;	}

	Color		GetPixel		(const Point& point) const;
	Color		GetPixel		(uint16 x, uint16 y) const;

	void		Fill			(const Color& color);
	void		Fill			(uint8 r, uint8 g,
								 uint8 b, uint8 a);

	bool		GetSwitched		(const char* sw,
								 Image* result) const;
	bool		GetMirrored		(bool h, bool v,
								 Image* result) const;

public:
	Image&		operator =		(const Image&  image);
	Image&		operator =		(      Image&& image);

	bool		operator ==		(const Image& image) const;
	bool		operator !=		(const Image& image) const;

private:
	uint16		mWidth;			// Bitmap width
	uint16		mHeight;		// Bitmap height
	uint32		mLength;		// Pixel data length

	uint32*		mData;			// Pixel data (ARGB)
	uint32		mLimit;			// Pixel data limit
};

}
#endif // ROBOT_IMAGE_H
