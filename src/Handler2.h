#pragma once
#include <PCH.h>
class Handler2
{
public:
	static void TestInstall();
	static void	thunk(RE::ActorEquipManager* a_this, RE::Actor* a_actor, RE::TESBoundObject* a_object, RE::ExtraDataList* a_extraData, std::uint32_t a_count, const RE::BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow);
	static inline REL::Relocation<decltype(thunk)>  func;
	static void thunk2(RE::ActorEquipManager* a_this, RE::Actor* a_actor, RE::TESBoundObject* a_object, RE::ExtraDataList* a_extraData, std::uint32_t a_count, const RE::BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow);
	static inline REL::Relocation<decltype(thunk2)> func2;
};
