/*
 * Copyright 2010 by Seth N. Hetu
 *
 * Please refer to the end of the file for licensing information
 */

#ifndef _DISPLAY_METHOD
#define _DISPLAY_METHOD

#include <windows.h>
#include <string>
#include "Settings/Types.h"
#include "Settings/Encoding.h"

class DisplayMethod {
public:
	virtual ~DisplayMethod(){}

	//Struct-like properties
	std::wstring id;
	Encoding encoding;
	TYPES type;

	//Allow map comparison 
	bool operator<(const DisplayMethod& other) const {
		return id < other.id;
	}

	//Allow logical equals and not equals
	bool operator==(const DisplayMethod &other) const {
		return id == other.id;
	}
	bool operator!=(const DisplayMethod &other) const {
		return id != other.id;
	}

	//Allow eq/neq on strings, too
	bool operator==(const std::wstring& other) const {
		return id == other;
	}
	bool operator!=(const std::wstring& other) const {
		return id != other;
	}


	//Initialization
	virtual void init(char *data, unsigned long size, HDC currDC, unsigned int defaultColor) = 0;
	virtual void init(HRSRC resource, HGLOBAL dataHandle, HDC currDC, int devLogPixelsY, unsigned int defaultColor) = 0;

	//Functionality
	virtual void drawString(HDC bufferDC, const std::wstring &str, int xPos, int yPos) = 0;
	virtual void drawString(HDC bufferDC, const std::string &str, int xPos, int yPos) = 0;
	virtual void drawChar(HDC bufferDC, char letter, int xPos, int yPos) = 0;
	virtual int getStringWidth(const std::wstring &str, HDC currDC) = 0;
	virtual int getHeight(HDC currDC) = 0;
	virtual void setColor(COLORREF rgb) { 
		this->currColor = rgb; 
		this->currColor = ((GetRValue(rgb)*0x10000) + (GetGValue(rgb)*0x100) + GetBValue(rgb))&0xFFFFFF;
	}

protected:
	unsigned currColor;
	COLORREF currColorRGB;

};



#endif //_DISPLAY_METHOD

/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
