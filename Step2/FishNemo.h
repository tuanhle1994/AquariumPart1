/**
 * \file FishNemo.h
 *
 * \author Tu Le
 *
 * Class the implements a Nemo fish
 */

#pragma once
#include "Item.h"
#include<memory>

 /**
  * Implements a Nemo fish
  */
class CFishNemo : public CItem
{
public:
	/// Default constructor (disabled)
	CFishNemo() = delete;

	/// Copy constructor (disabled)
	CFishNemo(const CFishNemo&) = delete;

	CFishNemo(CAquarium* aquarium);

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y) override;

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; ///< Background image
};



