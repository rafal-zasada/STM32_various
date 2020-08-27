/*
 * GUI_msgs.h
 *
 *  Created on: 26 Aug 2020
 *      Author: Raf
 */

#ifndef GUI_MSGS_H_
#define GUI_MSGS_H_

#define GUI_BUFFER_SIZE 200


void GUI_init(void);
void GUI_send_char(char ch);
void GUI_send_string(char *string);

#endif /* GUI_MSGS_H_ */
