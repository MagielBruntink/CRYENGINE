// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include "Entity.h"
#include "Common.h"
#include <CryAudio/IAudioSystem.h>

namespace CryAudio
{
class CMuteAllTrigger final : public Control
{
public:

	CMuteAllTrigger(CMuteAllTrigger const&) = delete;
	CMuteAllTrigger(CMuteAllTrigger&&) = delete;
	CMuteAllTrigger& operator=(CMuteAllTrigger const&) = delete;
	CMuteAllTrigger& operator=(CMuteAllTrigger&&) = delete;

#if defined(INCLUDE_AUDIO_PRODUCTION_CODE)
	CMuteAllTrigger()
		: Control(MuteAllTriggerId, EDataScope::Global, s_szMuteAllTriggerName)
	{}
#else
	CMuteAllTrigger()
		: Control(MuteAllTriggerId, EDataScope::Global)
	{}
#endif // INCLUDE_AUDIO_PRODUCTION_CODE

	~CMuteAllTrigger();

	void Execute() const;
	void AddConnections(TriggerConnections const& connections);
	void Clear();

private:

	TriggerConnections m_connections;
};
} // namespace CryAudio