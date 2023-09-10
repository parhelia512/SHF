﻿#include "StateMenu.h"
#include "../GameManager/GameManager.h"

StateMenu::StateMenu()
{
	init();
	visible = false;
}

StateMenu::~StateMenu()
{
	freeResource();
}

void StateMenu::updateLabel()
{
	labLevel->setStr(convert::formatString("%d", gm->player->level));
	labExp->setStr(convert::formatString("%d", gm->player->exp));
	labExpUp->setStr(convert::formatString("%d", gm->player->levelUpExp));
	labAttack->setStr(convert::formatString("%d", gm->player->info.attack));
	labDefend->setStr(convert::formatString("%d", gm->player->info.defend));
	labEvade->setStr(convert::formatString("%d", gm->player->info.evade));
	labLife->setStr(convert::formatString("%d/%d", gm->player->life, gm->player->info.lifeMax));
	labThew->setStr(convert::formatString("%d/%d", gm->player->thew, gm->player->info.thewMax));
	labMana->setStr(convert::formatString("%d/%d", gm->player->mana, gm->player->info.manaMax));
}


void StateMenu::init()
{
	freeResource();
	initFromIni("ini\\ui\\state\\window.ini");
	image = addImageContainer("ini\\ui\\state\\image.ini");
	title = addImageContainer("ini\\ui\\state\\title.ini");
	labLevel = addLabel(convert::GBKToUTF8_InWinOnly("ini\\ui\\state\\lab等级.ini"));
	labExp = addLabel(convert::GBKToUTF8_InWinOnly("ini\\ui\\state\\lab经验.ini"));
	labExpUp = addLabel(convert::GBKToUTF8_InWinOnly("ini\\ui\\state\\lab升级.ini"));
	labAttack = addLabel(convert::GBKToUTF8_InWinOnly("ini\\ui\\state\\lab攻击.ini"));
	labDefend = addLabel(convert::GBKToUTF8_InWinOnly("ini\\ui\\state\\lab防御.ini"));
	labEvade = addLabel(convert::GBKToUTF8_InWinOnly("ini\\ui\\state\\lab闪避.ini"));
	labLife = addLabel(convert::GBKToUTF8_InWinOnly("ini\\ui\\state\\lab生命.ini"));
	labThew = addLabel(convert::GBKToUTF8_InWinOnly("ini\\ui\\state\\lab体力.ini"));
	labMana = addLabel(convert::GBKToUTF8_InWinOnly("ini\\ui\\state\\lab内力.ini"));
	setChildRectReferToParent();
}

void StateMenu::onEvent()
{
	updateLabel();
}

void StateMenu::freeResource()
{
	if (impImage != nullptr)
	{
		IMP::clearIMPImage(impImage);
		//delete impImage;
		impImage = nullptr;
	}
	freeCom(image);
	freeCom(title);
	freeCom(labAttack);
	freeCom(labDefend);
	freeCom(labEvade);
	freeCom(labLevel);
	freeCom(labExp);
	freeCom(labExpUp);
	freeCom(labLife);
	freeCom(labMana);
	freeCom(labThew);

}

