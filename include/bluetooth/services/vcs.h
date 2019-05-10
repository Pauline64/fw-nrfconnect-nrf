/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#ifndef BT_GATT_VCS_H_
#define BT_GATT_VCS_H_

/**@file
 * @defgroup bt_gatt_lbs VCS Button Service API
 * @{
 * @brief API for the LED Button Service (LBS).
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/types.h>

/** @def BT_UUID_VCS
 *  @brief Device Information Service
 */
#define BT_UUID_VCS                       BT_UUID_DECLARE_16(0x18ff)
#define BT_UUID_VCS_MUTE                  BT_UUID_DECLARE_16(0x19ff)


/** @brief Callback type for when an MUTE state change is received. */
typedef void (*vcs_mute_cb_t)(const bool mute_state);

/** @brief Callback type for when the button state is pulled. */
typedef bool (*vcs_lvl_cb_t)(u8_t lvl);

/** @brief Callback struct used by the LBS Service. */
struct bt_gatt_vcs_cb {
	/** LED state change callback. */
	vcs_mute_cb_t    mute_cb;
	/** Button read callback. */
	vcs_lvl_cb_t lvl_cb;
};

/** @brief Initialize the LBS Service.
 *
 * This function registers a BLE service with two characteristics: Button
 * and LED. Enable notifications for the Button Characteristic to let a
 * connected BLE unit know when the button state changes.
 * Write to the LED Characteristic to change the state of the LED on the
 * board.
 *
 * @param[in] callbacks Struct containing pointers to callback functions
 *			used by the service. This pointer can be NULL
 *			if no callback functions are defined.
 *
 *
 * @retval 0 If the operation was successful.
 *           Otherwise, a (negative) error code is returned.
 */
int bt_gatt_vcs_init(struct bt_gatt_vcs_cb *callbacks);

/** @brief Send the button state.
 *
 * This function sends a binary state, typically the state of a
 * button, to the connected BLE unit.
 *
 * @param[in] button_state The state of the button.
 *
 * @retval 0 If the operation was successful.
 *           Otherwise, a (negative) error code is returned.
 */
int bt_gatt_vcs_send_button_state(bool button_state);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* BT_GATT_VCS_H_ */
