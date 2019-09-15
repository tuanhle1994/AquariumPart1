/**
 * \file Item.cpp
 *
 * \author Tu Le
 */

#include "pch.h"
#include "Item.h"
#include "Aquarium.h"

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
