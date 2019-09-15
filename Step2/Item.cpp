/**
 * \file Item.cpp
 *
 * \author Tu Le
 */

#include "pch.h"
#include "Item.h"
#include "Aquarium.h"

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

/**
 * Destructor
 */
CItem::~CItem()
{
}

/**
* Constructor
* \param aquarium The aquarium this item is a member of
*/
CItem::CItem(CAquarium* aquarium) : mAquarium(aquarium) {}


/**
 * Nudge this fish away from some other fish.
 * \param stinkyX Fish x location to nudge away from
 * \param stinkyY Fish y location to nudge away from
 */
void CItem::Nudge(double stinkyX, double stinkyY)
{
	// Create a vector in the direction we are from the nudger
	double dx = mX - stinkyX;
	double dy = mY - stinkyY;

	// Determine how far away we are
	double distance = sqrt(dx * dx + dy * dy);
	if (distance > 0 && distance < MinDistance)
	{
		// Distance is less than our minimum
		dx *= MinDistance / distance;
		dy *= MinDistance / distance;

		mX = stinkyX + dx;
		mY = stinkyY + dy;

		mX = max(mX, MinX);
		mX = min(mX, MaxX);
		mY = max(mY, MinY);
		mY = min(mY, MaxY);
	}
}
