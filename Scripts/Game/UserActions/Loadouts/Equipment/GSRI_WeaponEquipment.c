class GSRI_WeaponEquipment : GSRI_EquipmentBase
{
	private int _slot;
	
	void GSRI_WeaponEquipment(ResourceName resource, int slot)
	{
		_slot = slot;
	}
	
	override void Equip(SCR_ChimeraCharacter chimera)
	{
		WeaponSlotComponent slot = GetSlot(chimera);
		if(!slot) { return; }
		
		Print("Insert: " + _resource);
		Resource resource = Resource.Load(_resource);
		IEntity entity = GetGame().SpawnEntityPrefab(resource);
		slot.SetWeapon(entity);
	}
	
	protected WeaponSlotComponent GetSlot(SCR_ChimeraCharacter chimera)
	{
		foreach(WeaponSlotComponent slot : GetSlots(chimera))
		{
			if(slot.GetSlotInfo().GetID() == _slot)
			{
				return slot;
			}
		}
		return null;
	}
	
	protected array<WeaponSlotComponent> GetSlots(SCR_ChimeraCharacter chimera)
	{
		array<WeaponSlotComponent> slots = {};
		chimera.GetCharacterController().GetWeaponManagerComponent().GetWeaponsSlots(slots);
		return slots;
	}
}
