#include "StatCheck.h"
using namespace StatCheck;
	/*
	* Wood: no requirement.
Iron: 10 in either One Handed, Two Handed, Marksman, Block or Heavy Armor.
Steel, Imperial, Nordic, Silver, Ancient Nord, Scaled, Bonemold, Chithin: 20 in either One Handed, Two Handed, Marksman, Block, Light Armor or Heavy Armor.
Orcish, Dawnguard, Nordic Heavy: 30 in either One Handed, Two Handed, Marksman, Block, Light Armor or Heavy Armor.
Dwarven, Falmer, Honed Ancient Nord: 40 in either One Handed, Two Handed, Marksman, Block or Heavy Armor.
Elven: 50 in either One Handed, Two Handed, Marksman, Block or Light Armor.
Glass, Honed Falmer: 60 in either One Handed, Two Handed, Marksman, Block or Light Armor.
Ebony, Stalhrim: 70 in either One Handed, Two Handed, Marksman, Block or Heavy Armor.
Dragonbone, Dragonscale: 80 in either One Handed, Two Handed, Marksman, Block or Heavy Armor / Light Armor.
Daedric: 90 in either One Handed, Two Handed, Marksman, Block or Heavy Armor.
	*/
	void SaveSettings()
	{
	}	

	void initialize()
	{


		int sLA = RE::PlayerCharacter::PlayerSkills::Data::Skill::kLightArmor;
		int sHA = RE::PlayerCharacter::PlayerSkills::Data::Skill::kHeavyArmor;

		itemkeys.insert_or_assign("DLC2ArmorMaterialNordicHeavy", ItemKey(20, "DLC2ArmorMaterialNordicHeavy", sHA));
		itemkeys.insert_or_assign("ArmorMaterialHide", ItemKey(0, "ArmorMaterialHide"));
		itemkeys.insert_or_assign("ArmorMaterialLeather", ItemKey(0, "ArmorMaterialLeather"));
		itemkeys.insert_or_assign("ArmorMaterialForsworn", ItemKey(0, "ArmorMaterialForsworn"));
		itemkeys.insert_or_assign("ArmorMaterialIron", ItemKey(0, "ArmorMaterialIron", sHA));
		itemkeys.insert_or_assign("ArmorMaterialIronBanded", ItemKey(0, "ArmorMaterialIronBanded", sHA));
		itemkeys.insert_or_assign("ArmorMaterialSteel", ItemKey(20, "ArmorMaterialSteel", sHA));
		itemkeys.insert_or_assign("ArmorMaterialScaled", ItemKey(20, "ArmorMaterialScaled", sLA));
		itemkeys.insert_or_assign("ArmorMaterialBlades", ItemKey(20, "ArmorMaterialBlades", sLA));
		itemkeys.insert_or_assign("ArmorMaterialImperialHeavy", ItemKey(20, "ArmorMaterialImperialHeavy", sHA));
		itemkeys.insert_or_assign("ArmorMaterialImperialLight", ItemKey(20, "ArmorMaterialImperialLight", sLA));
		itemkeys.insert_or_assign("ArmorMaterialImperialStudded", ItemKey(20, "ArmorMaterialImperialStudded", sLA));
		itemkeys.insert_or_assign("ArmorMaterialOrcish", ItemKey(30, "ArmorMaterialOrcish", sHA));
		itemkeys.insert_or_assign("ArmorMaterialDwarven", ItemKey(40, "ArmorMaterialDwarven", sHA));
		itemkeys.insert_or_assign("ArmorMaterialElven", ItemKey(50, "ArmorMaterialElven", sLA));
		itemkeys.insert_or_assign("ArmorMaterialElvenGilded", ItemKey(50, "ArmorMaterialElvenGilded"));
		itemkeys.insert_or_assign("ArmorMaterialEbony", ItemKey(70, "ArmorMaterialEbony", sHA));
		itemkeys.insert_or_assign("ArmorMaterialGlass", ItemKey(60, "ArmorMaterialGlass"));
		itemkeys.insert_or_assign("ArmorMaterialDaedric", ItemKey(90, "ArmorMaterialDaedric"));
		itemkeys.insert_or_assign("ArmorMaterialDragonscale", ItemKey(80, "ArmorMaterialDragonscale"));
		itemkeys.insert_or_assign("ArmorMaterialDragonplate", ItemKey(80, "ArmorMaterialDragonplate"));
		itemkeys.insert_or_assign("DLC1ArmorMaterialDawnguard", ItemKey(30, "DLC1ArmorMaterialDawnguard"));
		itemkeys.insert_or_assign("DLC2ArmorMaterialBonemoldHeavy", ItemKey(20, "DLC2ArmorMaterialBonemoldHeavy", sHA));
		itemkeys.insert_or_assign("DLC2ArmorMaterialBonemoldLight", ItemKey(20, "DLC2ArmorMaterialBonemoldLight", sLA));
		itemkeys.insert_or_assign("DLC2ArmorMaterialChitinHeavy", ItemKey(20, "DLC2ArmorMaterialChitinHeavy", sHA));
		itemkeys.insert_or_assign("DLC2ArmorMaterialNordicHeavy", ItemKey(30, "DLC2ArmorMaterialNordicHeavy", sHA));
		itemkeys.insert_or_assign("DLC2ArmorMaterialStalhrimHeavy", ItemKey(70, "DLC2ArmorMaterialStalhrimHeavy", sHA));
		itemkeys.insert_or_assign("DLC2ArmorMaterialFalmerHeavy", ItemKey(40, "DLC2ArmorMaterialFalmerHeavy", sHA));
		itemkeys.insert_or_assign("ArmorMaterialFalmer", ItemKey(40, "ArmorMaterialFalmer", sLA));
		itemkeys.insert_or_assign("DLC1ArmorMaterialFalmerHardened", ItemKey(60, "DLC1ArmorMaterialFalmerHardened", sLA));
		itemkeys.insert_or_assign("DLC1ArmorMaterialFalmerHeavyOriginal", ItemKey(40, "DLC1ArmorMaterialFalmerHeavyOriginal", sHA));

		itemkeys.insert_or_assign("WeapMaterialWood", ItemKey(0, "WeapMaterialWood"));
		itemkeys.insert_or_assign("WeapMaterialIron", ItemKey(0, "WeapMaterialIron"));
		itemkeys.insert_or_assign("WeapMaterialSteel", ItemKey(15, "WeapMaterialSteel"));
		itemkeys.insert_or_assign("WeapMaterialSilver", ItemKey(20, "WeapMaterialSilver"));
		itemkeys.insert_or_assign("WeapMaterialDraugr", ItemKey(20, "WeapMaterialDraugr"));
		itemkeys.insert_or_assign("WeapMaterialDraugrHoned", ItemKey(30, "WeapMaterialDraugrHoned"));
		itemkeys.insert_or_assign("WeapMaterialImperial", ItemKey(20, "WeapMaterialImperial"));
		itemkeys.insert_or_assign("WeapMaterialOrcish", ItemKey(30, "WeapMaterialOrcish"));
		itemkeys.insert_or_assign("WeapMaterialDwarven", ItemKey(40, "WeapMaterialDwarven"));
		itemkeys.insert_or_assign("WeapMaterialFalmer", ItemKey(40, "WeapMaterialFalmer"));
		itemkeys.insert_or_assign("WeapMaterialElven", ItemKey(50, "WeapMaterialElven"));
		itemkeys.insert_or_assign("WeapMaterialEbony", ItemKey(70, "WeapMaterialEbony"));
		itemkeys.insert_or_assign("WeapMaterialGlass", ItemKey(60, "WeapMaterialGlass"));
		itemkeys.insert_or_assign("WeapMaterialFalmerHoned", ItemKey(60, "WeapMaterialFalmerHoned"));
		itemkeys.insert_or_assign("WeapMaterialDaedric", ItemKey(90, "WeapMaterialDaedric"));
		itemkeys.insert_or_assign("DLC1WeapMaterialDragonbone", ItemKey(80, "DLC1WeapMaterialDragonbone"));
		itemkeys.insert_or_assign("DLC2WeapMaterialStalhrim", ItemKey(70, "DLC2WeapMaterialStalhrim"));
		itemkeys.insert_or_assign("DLC2WeapMaterialNordic", ItemKey(20, "DLC2WeapMaterialNordic"));	
	}
	bool CheckSkillReq(std::string keyword, bool displayMessage)
	{
		if ((itemkeys.at(keyword)).level > StatCheck::GetPlayerSkill(keyword)) {
				if (displayMessage) {
					ItemKey ik = itemkeys.at(keyword);
					RE::DebugMessageBox(("You need to be at least level " + std::to_string(ik.level) + " " + StatCheck::GetSkillName(ik.keyword) + " " + " to equip this item.").c_str());
				}
				return false;
			}
		return true;
	}
	RE::BSString GetSkillName(ItemKey itemkey)
	{	
		switch (itemkey.whichSkill) {
		case RE::PlayerCharacter::PlayerSkills::Data::Skill::kLightArmor:
			return "Light Armor";
		case RE::PlayerCharacter::PlayerSkills::Data::Skill::kHeavyArmor:
			return "Heavy Armor";
		case RE::PlayerCharacter::PlayerSkills::Data::Skill::kOneHanded:
			return "One Handed";
		case RE::PlayerCharacter::PlayerSkills::Data::Skill::kTwoHanded:
			return "TWo Handed";
		case RE::PlayerCharacter::PlayerSkills::Data::Skill::kArchery:
			return "Marksman";
		default:
			return "{NOSKILLNAME}";
		}
	}
	int GetPlayerSkill(std::string keyword)
	{
		/*if (keyword.contains("Armor"))
		{
				if (keyword.contains("light") || keyword.contains("Light")) {
					return RE::PlayerCharacter::PlayerSkills::Data::Skills::kLightArmor;
				} else {
					return RE::PlayerCharacter::PlayerSkills::Data::Skills::kHeavyArmor;
				}
		}else */if (keyword.contains("WeapType")) {
			if (keyword.contains("WeapTypeBattleaxe") || keyword.contains("WeapTypeWarhammer") || keyword.contains("WeapTypeGreatsword")) {
				return RE::PlayerCharacter::PlayerSkills::Data::Skills::kTwoHanded;
			} else if (keyword.contains("WeapTypeBow")) {
				return RE::PlayerCharacter::PlayerSkills::Data::Skills::kArchery;
			} else {
				return RE::PlayerCharacter::PlayerSkills::Data::Skills::kOneHanded;
			}
		}
		return -1; 
	}

	void  ChangeReq(RE::StaticFunctionTag*, std::string keyToUpdate, uint32_t reqLevel)
	{
		itemkeys.insert_or_assign(keyToUpdate, ItemKey(reqLevel, keyToUpdate));
	}
	bool RegisterFuncs(RE::BSScript::IVirtualMachine* a_vm) 
	{
		//a_vm->RegisterFunction("ChangeReq", "StatCheck", StatCheck::ChangeReq);
		a_vm->RegisterFunction(format("ChangeReq"sv), format("StatCheck"sv), StatCheck::ChangeReq);
		return true;
	}

