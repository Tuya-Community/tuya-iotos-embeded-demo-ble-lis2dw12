#ifndef __TUYA_APP_LIS2DW12_H__
#define __TUYA_APP_LIS2DW12_H__

typedef unsigned char LIS2DW12_STATUS;
#define DRDY_STATUS			0x01U //data ready status
#define FF_IA_STATUS		0x02U
#define SIXD_IA_STATUS		0x04U
#define SINGLE_TAP_STATUS	0x08U
#define DOUBLE_TAP_STATUS	0x10U
#define SLEEP_STATUS		0x20U
#define WU_IA_STATUS		0x40U
#define FIFO_THS_STATUS		0x80U

/* Event detection status register */
#define LIS2DW12_STATUS_DUP	0x37U
#define DRDY			0x01U //Data-ready status.(0: not ready; 1: X-, Y- and Z-axis new data available)
#define FF_IA			0x02U //Free-fall event detection status.(0: free-fall event not detected; 1: free-fall event detected)
#define SIXD_IA			0x04U //Source of change in position portrait/landscape/face-up/face-down.(0: no event detected; 1: a change in position is detected)
#define SINGLE_TAP		0x08U //Single-tap event status:(0: Single-tap event not detected; 1: Single-tap event detected)
#define DOUBLE_TAP		0x10U //Double-tap event status:(0: Double-tap event not detected; 1: Double-tap event detected)
#define SLEEP_STATE_IA	0x20U //Sleep event status.(0: Sleep event not detected; 1: Sleep event detected)
#define DRDY_T			0x40U //Temperature status.(0: data not available; 1: a new set of data is available)
#define OVR				0x80U //FIFO overrun status flag.(0: FIFO is not completely filled;1: FIFO is completely filled and at least one sample has been overwritten)

/** I2C Device Address 8 bit format  if SA0=0 -> 31 if SA0=1 -> 33 **/
#define LIS2DW12_I2C_ADD_L   0x31U
#define LIS2DW12_I2C_ADD_H   0x33U


/** Device Identification (Who am I) **/
#define LIS2DW12_ID			0x44U

#define LIS2DW12_WHO_AM_I	0x0FU

#define LIS2DW12_CTRL1		0x20U
#define LIS2DW12_CTRL2		0x21U
#define LIS2DW12_CTRL4		0x23U
#define LIS2DW12_CTRL6		0x25U
#define LIS2DW12_CTRL7		0x3FU

#define LIS2DW12_OUT_T_L	0x0DU
#define LIS2DW12_OUT_T_H	0x0EU
#define LIS2DW12_OUT_T		0x26U
#define STATUS				0x27U
#define LIS2DW12_OUT_X_L	0x28U
#define LIS2DW12_OUT_X_H	0x29U
#define LIS2DW12_OUT_Y_L	0x2AU
#define LIS2DW12_OUT_Y_H	0x2BU
#define LIS2DW12_OUT_Z_L	0x2CU
#define LIS2DW12_OUT_Z_H	0x2DU

#define ALL_INT_SRC			0x3BU

unsigned char lis2dw12_init(void);
short get_lis2dw12_x_value(void);
short get_lis2dw12_y_value(void);
short get_lis2dw12_z_value(void);

long get_lis2dw12_x_mg(void);
long get_lis2dw12_y_mg(void);
long get_lis2dw12_z_mg(void);

unsigned char lis2dw12_status(LIS2DW12_STATUS status);
short get_lis2dw12_temperature(void);

#endif /* __TUYA_APP_LIS2DW12_H */
