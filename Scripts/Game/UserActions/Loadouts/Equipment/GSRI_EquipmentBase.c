class GSRI_EquipmentBase
{
	protected ResourceName _resource;
	
	void GSRI_EquipmentBase(ResourceName resource)
	{
		_resource = resource;
	}
	
	void Equip(SCR_ChimeraCharacter chimera)
	{
		Print("Insert: " + _resource);
		SCR_InventoryStorageManagerComponent inventory = GetInventory(chimera);
		BaseInventoryStorageComponent storage = GetStorage(inventory);
		inventory.TrySpawnPrefabToStorage(_resource, storage);
	}
	
	protected SCR_InventoryStorageManagerComponent GetInventory(SCR_ChimeraCharacter chimera)
	{
		InventoryStorageManagerComponent inventory = chimera.GetCharacterController().GetInventoryStorageManager();
		return SCR_InventoryStorageManagerComponent.Cast(inventory);
	}
	
	protected BaseInventoryStorageComponent GetStorage(SCR_InventoryStorageManagerComponent inventory)
	{
		return inventory.GetCharacterStorage();
	}
	
}