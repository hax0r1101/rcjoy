#include "usbh_hid_common.h"
#include "inttypes.h"
#include "usbh_def.h"



uint8_t usb_buffer[256];
uint8_t usb_repd_buffer[1024];
uint16_t usb_rep_desc_len;
uint16_t usb_rep_len;
volatile uint8_t usb_data_valid = FALSE;


uint16_t VendorID;
uint16_t ProductID;

#ifdef DEBUG_USB

#define DEBUG_BUFFER_LEN 8192

uint8_t debug_buffer[DEBUG_BUFFER_LEN];
volatile uint32_t debug_buffer_pos = 0;
volatile uint32_t debug_buffer_active = 0;

#endif

USBH_StatusTypeDef USBH_HID_CommonInit(USBH_HandleTypeDef *phost)
{
	HID_HandleTypeDef *HID_Handle = phost->pActiveClass->pData;

	HID_Handle->pData = usb_buffer;
	fifo_init(&HID_Handle->fifo, phost->device.Data, HID_QUEUE_SIZE * HID_Handle->length);

	VendorID = phost->device.DevDesc.idVendor;
	ProductID = phost->device.DevDesc.idProduct;
}


void USBH_HID_EventCallback(USBH_HandleTypeDef *phost)
{
	HID_HandleTypeDef *HID_Handle = phost->pActiveClass->pData;

	usb_rep_len = HID_Handle->length;

	if (HID_Handle->length == 0)
	{
		usb_data_valid = FALSE;
		return;
	}

	usb_data_valid = (fifo_read(&HID_Handle->fifo, usb_buffer, HID_Handle->length) == HID_Handle->length);

#ifdef DEBUG_USB
	if (!usb_data_valid) return;
	if (!debug_buffer_active) return;

	uint16_t i;

	debug_buffer[0] = HID_Handle->length;

	for (i = 0; i < HID_Handle->length && debug_buffer_pos < DEBUG_BUFFER_LEN; i++, debug_buffer_pos++)
	{
		debug_buffer[debug_buffer_pos] = usb_buffer[i];
	}

	debug_buffer_active = (debug_buffer_pos < DEBUG_BUFFER_LEN);
#endif
}

void USB_HID_ReportReadCallback(USBH_HandleTypeDef *phost)
{
	HID_HandleTypeDef *HID_Handle = phost->pActiveClass->pData;
	
	usb_rep_desc_len = HID_Handle->HID_Desc.wItemLength;
	uint16_t i;

	for (i = 0; i < usb_rep_desc_len; i++)
		*(usb_repd_buffer +i) = *(phost->device.Data + i);
}

uint8_t *USB_HID_GetLastReport()
{
	if (usb_data_valid)
		return usb_buffer;
	else
		return NULL;
}

uint16_t USB_HID_GetReportLength()
{
	return usb_rep_len;
}

void USB_GetReportDescriptor(uint16_t *l, uint8_t **b)
{
	if (usb_rep_desc_len)
	{
		*l = usb_rep_desc_len;
		*b = usb_repd_buffer;
	}
	else
		*l = 0;
}

uint8_t CheckJoystick(uint16_t vendor, uint16_t product)
{
	return (VendorID == vendor) && (ProductID == product);
}

void GetJoyInfo(uint16_t *pVendor, uint16_t *pProduct)
{
	*pVendor = VendorID;
	*pProduct = ProductID;
}

#ifdef DEBUG_USB

void  USBStartCollectingDebug()
{
	uint16_t i;
	
	for (i = 0; i < DEBUG_BUFFER_LEN; i++)
		debug_buffer[i] = 0;

	debug_buffer_pos = 1;
	debug_buffer_active = 1;
}

void USBGetCollectedDebug(uint8_t** b, uint32_t *len)
{
	*len = DEBUG_BUFFER_LEN;
	*b = debug_buffer;
}

#endif