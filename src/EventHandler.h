#include <RE/A/Actor.h>
#include <RE/A/ActorEquipManager.h>
#include <RE/E/ExtraDataList.h>
#include <RE/F/FormTypes.h>
#include <RE/P/PlayerCharacter.h>
#include <RE/T/TESBoundObject.h>
#include <RE/T/TESForm.h>
using EventResult = RE::BSEventNotifyControl;
class EventHandler : public RE::BSTEventSink<RE::TESEquipEvent>
{
public:
	static EventHandler* GetSingleton();
	static void          Register();
	virtual EventResult ProcessEvent(const RE::TESEquipEvent* a_event, RE::BSTEventSource<RE::TESEquipEvent>* a_eventSource) override;
	void                 on_equipped(RE::Actor* a, RE::TESEquipEvent* a_event);

private:
	EventHandler() = default;
	EventHandler(const EventHandler&) = delete;
	EventHandler(EventHandler&&) = delete;
	virtual ~EventHandler() = default;

	EventHandler& operator=(const EventHandler&) = delete;
	EventHandler& operator=(EventHandler&&) = delete;

};
