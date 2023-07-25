//---
//! This user action replaces current players equipement with a LAT loadout
class GSRI_SetLoadoutOperatorUserAction : ScriptedUserAction
{
	protected ref GSRI_OperatorPreset GetPreset() { return new GSRI_OperatorPreset(); }
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
	{
		SCR_ChimeraCharacter chimera = SCR_ChimeraCharacter.Cast(pUserEntity);
		if(!chimera) { return; }
		
		GSRI_OperatorPreset preset = GetPreset();
		GSRI_LoadoutAdapter adapter = new GSRI_LoadoutAdapter(chimera);
		adapter.Apply(preset);
	}
	
	override bool CanBeShownScript(IEntity user)
	{
		return true;
	}

	override bool CanBePerformedScript(IEntity user)
	{
		return true;
	}

	override bool HasLocalEffectOnlyScript()
	{
		return true;
	}
}

class GSRI_SetLoadoutGrenadierUserAction : GSRI_SetLoadoutOperatorUserAction
{
	override ref protected GSRI_OperatorPreset GetPreset() { return new GSRI_GrenadierPreset(); }
}