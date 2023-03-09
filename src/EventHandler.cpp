#include "EventHandler.h"

void EventHandler::Register()
{
    auto scriptEventSourceHolder = RE::ScriptEventSourceHolder::GetSingleton();
    scriptEventSourceHolder->GetEventSource<RE::TESEquipEvent>()->AddEventSink(EventHandler::GetSingleton());
}
EventHandler* EventHandler::GetSingleton()
{
    static EventHandler singleton;
    return std::addressof(singleton);
}
EventResult ProcessEvent(RE::TESEquipEvent* a_event, RE::BSTEventSource<RE::TESEquipEvent>*)
{
	if (a_event && a_event->actor.get()) {
		auto a = a_event->actor.get()->As<RE::Actor>();
		if (a)
			EventHandler::GetSingleton()->on_equipped(a, a_event);
	}
	return EventResult::kContinue;
}
void on_equipped(RE::Actor* a, const RE::TESEquipEvent *a_event)
{
	if (a_event->equipped) {
		if (a->IsPlayerRef()) {
			RE::DebugMessageBox("onequip1");
			//TESForm* form = TESForm::LookUpByHandle(a_event->originalRefr);
			RE::TESForm* form = RE::TESForm::LookupByID(a_event->baseObject);
			if (form->IsWeapon())
				if (50 > RE::PlayerCharacter::GetSingleton()->GetBaseActorValue(RE::ActorValue::kOneHanded)) {
					{
						RE::TESBoundObject* tesbo = (RE::TESBoundObject*)form;
						RE::ActorEquipManager::GetSingleton()->UnequipObject(a, tesbo);  //, RE::ExtraDataList* a_extraData = nullptr, std::uint32_t a_count = 1, const RE::BGSEquipSlot* a_slot = nullptr, bool a_queueEquip = true, bool a_forceEquip = false, bool a_playSounds = true, bool a_applyNow = false, const BGSEquipSlot* a_slotToReplace = nullptr);
					}
				}
		}
	}
}
