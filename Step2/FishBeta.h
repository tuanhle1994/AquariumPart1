/**
 * \file FishBeta.h
 *
 * \author Tu Le
 *
 * Class the implements a Beta fish
 */

#pragma once
#include "Item.h"
#include<memory>

 /**
  * Implements a Beta fish
  */
class CFishBeta : public CItem
{
public:
	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta&) = delete;

	CFishBeta(CAquarium* aquarium);

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y) override;

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; ///< Background image
};

