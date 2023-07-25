class GSRI_LoadoutAdapter
{
	private SCR_ChimeraCharacter _chimera;
	
	void GSRI_LoadoutAdapter(notnull SCR_ChimeraCharacter chimera)
	{
		_chimera = chimera;
	}
	
	void Apply(GSRI_OperatorPreset preset)
	{
		Clear();
		
		foreach(GSRI_EquipmentBase equipment : preset.GetResources())
		{
			equipment.Equip(_chimera);
		}
	}	
	
	private void Clear()
	{
		GarbageManager garbage = GetGame().GetGarbageManager();
		SCR_InventoryStorageManagerComponent inventory = GetInventory();
		SCR_CharacterInventoryStorageComponent storage = inventory.GetCharacterStorage();
		foreach(IEntity item : GetRootItems())
		{
			Print("Remove: " + item.GetPrefabData().GetPrefabName());
			inventory.TryRemoveItemFromStorage(item, storage);
			garbage.Insert(item);
		}
		
		garbage.Flush();
	}	
	
	private SCR_InventoryStorageManagerComponent GetInventory()
	{
		InventoryStorageManagerComponent inventory = _chimera.GetCharacterController().GetInventoryStorageManager();
		return SCR_InventoryStorageManagerComponent.Cast(inventory);
	}
	
	private array<IEntity> GetRootItems()
	{
		array<IEntity> items = new array<IEntity>();
		GetInventory().GetAllRootItems(items);
		return items;
	}
}