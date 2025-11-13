/*This file is part of FFB Arcade Plugin.
FFB Arcade Plugin is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
FFB Arcade Plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with FFB Arcade Plugin.If not, see < https://www.gnu.org/licenses/>.
*/

#include "ProjectR.h"

static bool outputinit;
static wchar_t* settingsFilename = TEXT(".\\FFBPlugin.ini");
static int EnableOutputs = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableOutputs"), 0, settingsFilename);

void ProjectR::FFBLoop(EffectConstants* constants, Helpers* helpers, EffectTriggers* triggers) {
	helpers->log("In the ffb loop");
	if (!outputinit)
	{
		helpers->log("About to enable outputs vaue is: " );
		if (EnableOutputs == 1)
		{
			outputinit = true;
			helpers->log("loading up outputblaster");
			LoadLibraryA("OutputBlaster.dll");
			helpers->log("loaded up outputblaster");
		}
	}
}