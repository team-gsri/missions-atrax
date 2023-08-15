class GSRI_setNightAction : SCR_ScriptedUserAction
{
	[Attribute(defvalue: "0", desc: "Is it night time already ?")]
	protected bool isNight;
	
	void GSRI_setNightAction()
	{
		float time = GetGame().GetTimeAndWeatherManager().GetTimeOfTheDay();
		if (time > 22)
		{
			this.isNight = false;
		} else {
			this.isNight = true;
		}
	}
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
	{
		if(this.isNight)
		{
			Print("Night is already here", LogLevel.NORMAL);
			return;
		}
		Print("Setting night time...", LogLevel.NORMAL);
		GetGame().GetTimeAndWeatherManager().SetTimeOfTheDay(23.5, true);
		this.isNight = true;
	}
}