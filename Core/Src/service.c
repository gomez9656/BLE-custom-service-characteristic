/*
 * service.c
 *
 *  Created on: 26 Mar 2022
 *      Author: Juan Gomez
 */
#include <stdio.h>
#include "bluenrg1_gap.h"
#include "bluenrg1_gatt_aci.h"
#include "service.h"

//custom UUID service
uint8_t SERVICE_UUID[16] = {0x66, 0x9a, 0x0c, 0x20, 0x00, 0x08, 0x96, 0x9e, 0xe2, 0x11, 0x9e, 0xb1, 0xe0, 0xf2, 0x73, 0xd9};
uint8_t CHAR_UUID[16] = {0x66, 0x9a, 0x0c, 0x20, 0x00, 0x08, 0x96, 0x9e, 0xe2, 0x11, 0x9e, 0xb1, 0xe1, 0xf2, 0x73, 0xd9};

uint16_t my_service_handle, my_char_handle;

tBleStatus add_siemple_service(void){

	tBleStatus ret;
	Service_UUID_t service_uuid;
	Char_UUID_t char_uuid;

	BLUENRG_memcpy(service_uuid.Service_UUID_128, SERVICE_UUID, 16);

	//add service
	ret = aci_gatt_add_service(UUID_TYPE_128, &service_uuid, PRIMARY_SERVICE, 7, &my_service_handle);

	BLUENRG_memcpy(char_uuid.Char_UUID_128, CHAR_UUID, 16);

	// add custom characteristic
	ret = aci_gatt_add_char(my_service_handle, UUID_TYPE_128, &char_uuid, 1, CHAR_PROP_NOTIFY, ATTR_PERMISSION_NONE, 0, 0, 0, my_char_handle);

	return ret;
}












