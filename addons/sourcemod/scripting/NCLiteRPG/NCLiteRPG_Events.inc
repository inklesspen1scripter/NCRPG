void HookEvents() {
	HookEvent("round_start",	Event_RoundStart);
	HookEvent("round_end",		Event_RoundEnd);
	HookEvent("player_team",	Event_PlayerTeam);
}

public Action Event_PlayerTeam(Event event, const char[] name, bool dontBroadcast) {
	int client = GetClientOfUserId(event.GetInt("userid"));
	if(IsValidPlayer(client))
	{
		bool disconnect = event.GetBool("disconnect");
		if(!disconnect && GetPlayerArrayPosition(client) == -1)
			CreateTimer(cfg_fLoadDelay, Timer_LoadDelay, client, TIMER_FLAG_NO_MAPCHANGE);
			
	}
}

public Action Timer_LoadDelay(Handle timer, int client) {
	LoadPlayer(client);
}

public Event_RoundStart(Event event, const char[] name, bool dontBroadcast) {
	LoadAllPlayers();
}

public Event_RoundEnd(Event event, const char[] name, bool dontBroadcast) {
	for(int client = 1; client <= MaxClients; client++)
		if(IsValidPlayer(client))
		{
			SavePlayer(client);
		}
}
