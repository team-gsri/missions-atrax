class GSRI_StorageEquipment : GSRI_EquipmentBase
{
	private LoadoutAreaType _area;
	
	void GSRI_StorageEquipment(ResourceName resource, LoadoutAreaType area)
	{
		_area = area;
	}	
	
	override protected BaseInventoryStorageComponent GetStorage(SCR_InventoryStorageManagerComponent inventory)
	{
		return inventory.GetCharacterStorage().GetStorageFromLoadoutSlot(_area);
	}
}
