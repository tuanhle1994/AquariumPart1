/**
 * \file FishStinky.h
 *
 * \author Tu Le
 *
 * Class the implements a Stinky fish
 */

#pragma once
#include "Item.h"
#include<memory>

 /**
  * Implements a Stinky fish
  */
class CFishStinky : public CItem
{
public:
	/// Default constructor (disabled)
	CFishStinky() = delete;

	/// Copy constructor (disabled)
	CFishStinky(const CFishStinky&) = delete;

	CFishStinky(CAquarium* aquarium);

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y) override;

	void SetLocation(double stinkyX, double stinkyY) override;


private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; ///< Background image
};
