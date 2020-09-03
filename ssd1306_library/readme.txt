
Library operation for characters (my notes):
1. 	Characters are stored in arrays, one element of array stores one horizontal pixel line for that character. Number of array elements allocated for 
	once character is associated with font height. Elements are 16 bits, each bit is one pixel in given line - so it means they can store fonts no wider 
	than 16 pixels.
2.	All pixels of character are handled one by one and are arranged in SSD1306_Buffer in specific order to meet page addressing protocol before they are sent
	to OLED through I2C.