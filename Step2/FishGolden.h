/**
 * \file FishGolden.h
 *
 * \author Tu Le
 *
 * Class the implements a Golden fish
 */

#pragma once
#include "Item.h"
#include<memory>

 /**
  * Implements a Golden fish
  */
class CFishGolden : public CItem
{
public:
	/// Default constructor (disabled)
	CFishGolden() = delete;

	/// Copy constructor (disabled)
	CFishGolden(const CFishGolden&) = delete;

	CFishGolden(CAquarium* aquarium);

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y) override;

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; ///< Background image
};
