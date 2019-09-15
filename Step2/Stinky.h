/**
 * \file FishGolden.h
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
class CStinky : public CItem
{
public:
	/// Default constructor (disabled)
	CStinky() = delete;

	/// Copy constructor (disabled)
	CStinky(const CStinky&) = delete;

	CStinky(CAquarium* aquarium);

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y) override;

	void SetLocation(double stinkyX, double stinkyY) override;


private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; ///< Background image
};
