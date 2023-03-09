
//#include "EventHandler.h"
#include "SKSE/API.h"
#include "Handler2.h"
#include "StatCheck.h"
#include <unordered_map>
//void Init()
//{
//	SKSE::AllocTrampoline(14);
//
//	//auto messaging = SKSE::GetMessagingInterface();
//	//messaging->RegisterListener(callback)
//	EventHandler::GetSingleton()->Register();
//	//StatRequireHandler::GetSingleton()->Install();
//	//REL::Relocation<std::uintptr_t> PlayerCharacter_BSTEventSink_BSTesEquipEvent(REL::ID(261918));
//}
//	//void handleMessages(SKSE::MessagingInterface::EventCallback)
////{
////	return;
////}

void InitializeLog()
{
#ifndef NDEBUG
	auto sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
#else
	auto path = logger::log_directory();
	if (!path) {
		util::report_and_fail("Failed to find standard logging directory"sv);
	}

	*path /= fmt::format("{}.log"sv, Plugin::NAME);
	auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
#endif

#ifndef NDEBUG
	const auto level = spdlog::level::trace;
#else
	const auto level = spdlog::level::info;
#endif

	auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));
	log->set_level(level);
	log->flush_on(level);

	spdlog::set_default_logger(std::move(log));
	spdlog::set_pattern("[%l] %v"s);
}

extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* a_skse)
{
#ifndef NDEBUG
	while (!IsDebuggerPresent()) {};
#endif

#ifdef SKYRIMAE
	InitializeLog();
#endif
	SKSE::AllocTrampoline(1 << 8);
	//SKSE::AllocTrampoline(14);
	Handler2::TestInstall();
	logger::info("Loaded plugin");

	SKSE::Init(a_skse);
	return true;
}

extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Query(const SKSE::QueryInterface* a_skse, SKSE::PluginInfo* a_info)
{
	InitializeLog();
	a_info->infoVersion = SKSE::PluginInfo::kVersion;
	a_info->name = Plugin::NAME.data();
	a_info->version = Plugin::VERSION.pack();

	if (a_skse->IsEditor()) {
		logger::critical("Loaded in editor, marking as incompatible"sv);
		return false;
	}

	const auto ver = a_skse->RuntimeVersion();
	if (ver != RUNTIME) {
		logger::critical(FMT_STRING("Unsupported runtime version {}"sv), ver.string());
		return false;
	}
	return true;

}
extern "C" DLLEXPORT bool APIENTRY RegisterNativeFunctions()
{
	auto papyrus = SKSE::GetPapyrusInterface();
	if (!papyrus->Register(StatCheck::RegisterFuncs)) {
		return false;
	}
	return true;
}

#ifdef SKYRIMAE
extern "C" DLLEXPORT constinit SKSE::PluginVersionData SKSEPlugin_Version = []() {
	SKSE::PluginVersionData v;
	v.PluginVersion(Plugin::VERSION);
	v.PluginName(Plugin::NAME);
	v.UsesAddressLibrary(true);

	return v;
}();
#endif
