class GSRI_GrenadierPreset : GSRI_OperatorPreset
{
	private ResourceName _launcher = "{9C5C20FB0E01E64F}Prefabs/Weapons/Launchers/M72/Launcher_M72A3.et";
	
	override GSRI_Resource GetResources()
	{		
		GSRI_Resource base = super.GetResources();
		base.Insert(new GSRI_WeaponEquipment(_launcher, 1));
		return base;
	}
}