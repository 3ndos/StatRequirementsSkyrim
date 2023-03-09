#pragma once
#include "Handler2.h"
#include "PCH.h"
#include "RE/B/BSString.h"
#include <StatCheck.h>
#include <string.h>
#include <unordered_map>
namespace StatCheck
{
	struct ItemKey
	{
		int         level;
		std::string keyword;
		int         whichSkill;
		ItemKey(int level, std::string keyword)
		{
			this->level = level;
			this->keyword = keyword;
			this->whichSkill = -1;
		}
		ItemKey(int level, std::string keyword, int whichSkill)
		{
			this->level = level;
			this->keyword = keyword;
			this->whichSkill = whichSkill;
		}
	};
	void                                     ChangeReq(RE::StaticFunctionTag*, std::string keyToUpdate, uint32_t reqLevel);
	void                                     RegisterFuncs(RE::BSScript::IVirtualMachine* a_vm);
	int                                      GetPlayerSkill(std::string keyword);
	bool                                     CheckSkillReq(std::string, bool displayMessage);
	void                                     SaveSettings();
	std::unordered_map<std::string, ItemKey> itemkeys;
	std::string                              GetSkillName(std::string keyword);
	

}
