typedef array<ref GSRI_EquipmentBase> GSRI_Resource;

class GSRI_OperatorPreset
{
	private ResourceName _jacket = "{1CF302A33F29FBEF}Prefabs/Characters/Uniforms/Jacket_FROG_Combat_Shirt.et";	
	private ResourceName _pants = "{76D80043D6BFFB57}Prefabs/Characters/Uniforms/Pants_FROG_Trousers.et";	
	private ResourceName _backpack = "{9A26D311900C33EE}Prefabs/Items/Equipment/Backpacks/FILBE_hydration_pack.et";	
	private ResourceName _vest = "{1300A5F6CA51B204}Prefabs/Characters/Vests/Vest_PCGen_III/Variants/Vest_PCGen_III_rifleman.et";	
	private ResourceName _helmet = "{50CAAEEDC59F23C6}Prefabs/Characters/HeadGear/Helmet_ECH/Helmet_ECH_lc.et";
	private ResourceName _shoes = "{320FA1CD5B1D5601}Prefabs/Characters/Footwear/Boots_USMC_Combat/Footwear_USMC_Combat.et";	
	
	private ResourceName _peltor = "{EB916F0BF524EF25}Prefabs/Characters/HeadGear/Headphones_Peltor/Headphones_Peltor_black.et";
	private ResourceName _strobe = "{643AB339663E92F7}Prefabs/Items/Equipment/Nightvision/MS2000/Marker_MS2000.et";
	private ResourceName _googles = "{B7BA7694F821F556}Prefabs/Items/Equipment/Nightvision/PVS14/NVG_PVS14Dual.et";
	
	private ResourceName _rifle = "{66AAEDA477051298}Prefabs/Weapons/Rifles/M27IAR/Rifle_M27IAR_SU230.et";
	private ResourceName _laser = "{0FFFB0BCE1A21A2E}Prefabs/Weapons/Attachments/Lasers/anpeq16/Laser_ANPEQ16.et";
	private ResourceName _scope = "{7DB681643152613C}Prefabs/Weapons/Attachments/Optics/su230/Optic_SU230_MRDS.et";
	
	private ResourceName _ammo = "";
	
	GSRI_Resource GetResources()
	{
		return {
			new GSRI_EquipmentBase(_jacket),
			new GSRI_EquipmentBase(_pants),
			new GSRI_EquipmentBase(_backpack),
			new GSRI_EquipmentBase(_vest),
			new GSRI_EquipmentBase(_helmet),
			new GSRI_EquipmentBase(_shoes),
			
			new GSRI_StorageEquipment(_peltor, new LoadoutHeadCoverArea()),
			new GSRI_StorageEquipment(_strobe, new LoadoutHeadCoverArea()),
			new GSRI_StorageEquipment(_googles, new LoadoutHeadCoverArea()),
			
			new GSRI_WeaponEquipment(_rifle, 0),
			new GSRI_WeaponAttachementEquipment(_laser, 0),
			new GSRI_WeaponAttachementEquipment(_scope, 0)
		};
	}
	
	
}