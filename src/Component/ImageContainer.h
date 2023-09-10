#pragma once
#include "BaseComponent.h"

class ImageContainer :
	public BaseComponent
{
public:
	ImageContainer();
	virtual ~ImageContainer();

	_shared_imp impImage = nullptr;

	bool stretch = false;

	virtual void initFromIni(const std::string& fileName);

protected:
	void freeResource();

public:
	virtual void onDraw();
	bool drawImagetoRect(Rect destRect, bool drawStretch);
};

