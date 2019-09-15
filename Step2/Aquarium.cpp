/**
 * \file Aquarium.cpp
 *
 * \author Tu Le
 */

#include "pch.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include <algorithm>

using namespace Gdiplus;
using namespace std;
/**
 * Aquarium Constructor
 */

 /// Maximum allowed X value
const double MaxX = 950;

/// Minimum allowed X value
const double MinX = 100;

/// Maximum allowed Y value
const double MaxY = 750;

/// Minimum allowed Y value
const double MinY = 50;

/// Minimum distance from a nudging fish
const double MinDistance = 200;

CAquarium::CAquarium()
{
	mBackground = unique_ptr<Gdiplus::Bitmap>(
		Bitmap::FromFile(L"images/background1.png"));
	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/background1.png");
	}
}

/**
 * Destructor
 */
CAquarium::~CAquarium()
{
}

 /** Draw the aquarium
 * \param graphics The GDI+ graphics context to draw on
 */
void CAquarium::OnDraw(Gdiplus::Graphics* graphics)
{
	graphics->DrawImage(mBackground.get(), 0, 0, mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
}

/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/**
 * Tells other fish to move from stinky fish
 * \param stinkyX and \param stinkyY Location of stinky fish
 */
void CAquarium::MoveFromStinky(double stinkyX, double stinkyY)
{
	for (auto item = mItems.rbegin(); item != mItems.rend(); item++)
	{
		double fishX = (*item)->GetX();
		double fishY = (*item)->GetY();
		// fishX, fishY is the position of a fish
		// stinkyX, stinkyY is the position of the stinky 

		// Create a vector in the direction we are from the nudger
		double dx = fishX - stinkyX;
		double dy = fishY - stinkyY;

		// Determine how far away we are
		double distance = sqrt(dx * dx + dy * dy);
		if (distance > 0 && distance < MinDistance)
		{
			// Distance is less than our minimum
			dx *= MinDistance / distance;
			dy *= MinDistance / distance;

			fishX = stinkyX + dx;
			fishY = stinkyY + dy;

			// Ensure fishX, fishY remain in the specified bounds
			if (fishX > MinX && fishX < MaxX && fishY > MinY && fishY < MaxY)
			{
				(*item)->CItem::SetLocation(fishX, fishY);
			}
		}		
	}
}



/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}
	

/**
 * Remove an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Remove(std::shared_ptr<CItem> item)
{
	auto loc = find(begin(mItems), end(mItems), item);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
}
