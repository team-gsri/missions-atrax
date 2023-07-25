class GSRI_WeaponAttachementEquipment : GSRI_WeaponEquipment
{
	void GSRI_WeaponAttachementEquipment(ResourceName resource, int slot) { }
	
	override void Equip(SCR_ChimeraCharacter chimera)
	{
		Print("Insert: " + _resource);
		Resource resource = Resource.Load(_resource);
		IEntity attachment = GetGame().SpawnEntityPrefab(resource);
		IEntity weapon = GetSlot(chimera).GetWeaponEntity();
		GetInventory(chimera).EquipWeaponAttachment(chimera, attachment);
	}
}