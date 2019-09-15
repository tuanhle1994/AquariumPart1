/**
 * \file Aquarium.h
 *
 * \author Tu Le
 *
 * Class that describes an Aquarium.
 *
 */

#pragma once
#include<memory>
#include<vector>
#include"Item.h"
#include"Stinky.h"

 /**
  * Class that describes an aquarium.
  */
class CAquarium
{
private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;

public:
	CAquarium();
	virtual ~CAquarium();

	void OnDraw(Gdiplus::Graphics* graphics);

	void Add(std::shared_ptr<CItem> item);
	void Remove(std::shared_ptr<CItem> item);

	void MoveFromStinky(double stinkyX, double stinkyY);

	std::shared_ptr<CItem> CAquarium::HitTest(int x, int y);
};

